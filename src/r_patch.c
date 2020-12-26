#include "r_patch.h"
#include "doomvars.h"

//#include "c_console.h"
//#include "doomstat.h"
#include "i_swap.h"
#include "logger.h"
#include "m_misc.h"
//#include "p_setup.h"
#include "r_data.h"
#include "w_wad.h"
#include "z_zone.h"
#include <assert.h>

//
// Patches.
// A patch holds one or more columns.
// Patches are used for sprites and all masked pictures,
// and we compose textures from the TEXTURE1/2 lists
// of patches.
//

// Re-engineered patch support
static rpatch_t *patches;
static rpatch_t *texture_composites;

static short    BIGDOOR7;
static short    FIREBLU1;
static short    SKY1;
static short    STEP2;

//extern int      numspritelumps;

static dboolean getIsSolidAtSpot(const column_t *column, int spot)
{
    if (!column)
        return false;

    while (column->topdelta != 0xFF)
    {
        if (spot < column->topdelta)
            return false;

        if (spot <= column->topdelta + column->length)
            return true;

        column = (const column_t *)((const byte *)column + 3 + column->length + 1);
    }

    return false;
}

// Checks if the lump can be a DOOM patch
static dboolean CheckIfPatch(int lump)
{
    int             size = W_LumpLength(lump);
    int             width;
    int             height;
    const patch_t   *patch;
    dboolean        result;

    // minimum length of a valid DOOM patch
    if (size < 13)
        return false;

    patch = W_CacheLumpNum(lump);

    width = SHORT(patch->width);
    height = SHORT(patch->height);

    if ((result = (height > 0 && height <= 16384 && width > 0 && width <= 16384 && width < size / 4)))
    {
        // The dimensions seem like they might be valid for a patch, so
        // check the column directory for extra security. All columns
        // must begin after the column directory, and none of them must
        // point past the end of the patch.
        for (int x = 0; x < width; x++)
        {
            unsigned int    ofs = LONG(patch->columnofs[x]);

            // Need one byte for an empty column (but there's patches that don't know that!)
            if (ofs < (unsigned int)width * 4 + 8 || ofs >= (unsigned int)size)
            {
                result = false;
                break;
            }
        }
    }

    W_ReleaseLumpNum(lump);
    return result;
}

static void createPatch(int id)
{
    rpatch_t            *patch;
    const int           patchNum = id;
    const patch_t       *oldPatch;
    const column_t      *oldColumn;
    int                 pixelDataSize;
    int                 columnsDataSize;
    int                 postsDataSize;
    int                 dataSize;
    int                 *numPostsInColumn;
    int                 numPostsTotal;
    const unsigned char *oldColumnPixelData;
    int                 numPostsUsedSoFar;

    if (!CheckIfPatch(patchNum) && patchNum < numlumps)
    {
		if( lumpinfo[ patchNum ]->size > 0 )
		{
			//C_Warning( 1, "The <b>%s</b> patch is in an unknown format.", lumpinfo[ patchNum ]->name );
			loge( "The <b>%s</b> patch is in an unknown format.\n", lumpinfo[ patchNum ]->name );
		}

        return;
    }

    oldPatch = (const patch_t *)W_CacheLumpNum(patchNum);

    patch = &patches[id];
    patch->width = SHORT(oldPatch->width);
    patch->widthmask = 0;
    patch->height = SHORT(oldPatch->height);
    patch->leftoffset = SHORT(oldPatch->leftoffset);
    patch->topoffset = SHORT(oldPatch->topoffset);

    // work out how much memory we need to allocate for this patch's data
    pixelDataSize = (patch->width * patch->height + 4) & ~3;
    columnsDataSize = sizeof(rcolumn_t) * patch->width;

    // count the number of posts in each column
    numPostsInColumn = malloc(sizeof(int) * patch->width);
    numPostsTotal = 0;

    for (int x = 0; x < patch->width; x++)
    {
        oldColumn = (const column_t *)((const byte *)oldPatch + LONG(oldPatch->columnofs[x]));
        numPostsInColumn[x] = 0;

        while (oldColumn->topdelta != 0xFF)
        {
            numPostsInColumn[x]++;
            numPostsTotal++;
            oldColumn = (const column_t *)((const byte *)oldColumn + oldColumn->length + 4);
        }
    }

    postsDataSize = numPostsTotal * sizeof(rpost_t);

    // allocate our data chunk
    dataSize = pixelDataSize + columnsDataSize + postsDataSize;
    patch->data = Z_Calloc(1, dataSize, PU_CACHE, (void **)&patch->data);

    // set out pixel, column, and post pointers into our data array
    patch->pixels = patch->data;
    patch->columns = (rcolumn_t *)((unsigned char *)patch->pixels + pixelDataSize);
    patch->posts = (rpost_t *)((unsigned char *)patch->columns + columnsDataSize);

    // sanity check that we've got all the memory allocated we need
    assert((((byte *)patch->posts + numPostsTotal * sizeof(rpost_t)) - (byte *)patch->data) == dataSize);

    memset(patch->pixels, 0xFF, (size_t)patch->width * patch->height);

    // fill in the pixels, posts, and columns
    numPostsUsedSoFar = 0;

    for (int x = 0; x < patch->width; x++)
    {
        int top = -1;

        oldColumn = (const column_t *)((const byte *)oldPatch + LONG(oldPatch->columnofs[x]));

        // setup the column's data
        patch->columns[x].pixels = &patch->pixels[x * patch->height];
        patch->columns[x].numposts = numPostsInColumn[x];
        patch->columns[x].posts = patch->posts + numPostsUsedSoFar;

        while (oldColumn->topdelta != 0xFF)
        {
            int len = oldColumn->length;

            //e6y: support for DeePsea's true tall patches
            if (oldColumn->topdelta <= top)
                top += oldColumn->topdelta;
            else
                top = oldColumn->topdelta;

            // Clip posts that extend past the bottom
            if (top + oldColumn->length > patch->height)
                len = patch->height - top;

            if (len > 0)
            {
                // set up the post's data
                patch->posts[numPostsUsedSoFar].topdelta = top;
                patch->posts[numPostsUsedSoFar].length = len;

                // fill in the post's pixels
                oldColumnPixelData = (const byte *)oldColumn + 3;

                for (int y = 0; y < len; y++)
                    patch->pixels[x * patch->height + top + y] = oldColumnPixelData[y];
            }

            oldColumn = (const column_t *)((const byte *)oldColumn + oldColumn->length + 4);
            numPostsUsedSoFar++;
        }
    }

    // copy the patch image down and to the right where there are
    // holes to eliminate the black halo from bilinear filtering
    for (int x = 0; x < patch->width; x++)
    {
        const rcolumn_t *column = R_GetPatchColumnClamped(patch, x);
        const rcolumn_t *prevColumn = R_GetPatchColumnClamped(patch, x - 1);

        if (column->pixels[0] == 0xFF)
        {
            // force the first pixel (which is a hole), to use
            // the color from the next solid spot in the column
            for (int y = 0; y < patch->height; y++)
                if (column->pixels[y] != 0xFF)
                {
                    column->pixels[0] = column->pixels[y];
                    break;
                }
        }

        // copy from above or to the left
        for (int y = 1; y < patch->height; y++)
        {
            if (getIsSolidAtSpot(oldColumn, y))
                continue;

            if (column->pixels[y] != 0xFF)
                continue;

            // this pixel is a hole
            if (x && prevColumn->pixels[y - 1] != 0xFF)
                column->pixels[y] = prevColumn->pixels[y];  // copy the color from the left
            else
                column->pixels[y] = column->pixels[y - 1];  // copy the color from above
        }
    }

    W_ReleaseLumpNum(patchNum);
    free(numPostsInColumn);
}

typedef struct
{
    unsigned short  patches;
    unsigned short  posts;
    unsigned short  posts_used;
} count_t;

static void switchPosts(rpost_t *post1, rpost_t *post2)
{
    rpost_t dummy;

    dummy.topdelta = post1->topdelta;
    dummy.length = post1->length;
    post1->topdelta = post2->topdelta;
    post1->length = post2->length;
    post2->topdelta = dummy.topdelta;
    post2->length = dummy.length;
}

static void removePostFromColumn(rcolumn_t *column, int post)
{
    if (post < column->numposts)
        for (int i = post; i < column->numposts - 1; i++)
        {
            rpost_t *post1 = &column->posts[i];
            rpost_t *post2 = &column->posts[i + 1];

            post1->topdelta = post2->topdelta;
            post1->length = post2->length;
        }

    column->numposts--;
}

static void createTextureCompositePatch(int id)
{
    rpatch_t            *composite_patch = &texture_composites[id];
    texture_t           *texture = textures[id];
    texpatch_t          *texpatch;
    int                 patchNum;
    const patch_t       *oldPatch;
    const column_t      *oldColumn;
    int                 count;
    int                 pixelDataSize;
    int                 columnsDataSize;
    int                 postsDataSize;
    int                 dataSize;
    int                 numPostsTotal;
    const unsigned char *oldColumnPixelData;
    int                 numPostsUsedSoFar;
    count_t             *countsInColumn;

    composite_patch->width = texture->width;
    composite_patch->height = texture->height;
    composite_patch->widthmask = texture->widthmask;
    composite_patch->leftoffset = 0;
    composite_patch->topoffset = 0;

    // work out how much memory we need to allocate for this patch's data
    pixelDataSize = (composite_patch->width * composite_patch->height + 4) & ~3;
    columnsDataSize = sizeof(rcolumn_t) * composite_patch->width;

    // count the number of posts in each column
    countsInColumn = (count_t *)calloc(composite_patch->width, sizeof(count_t));
    numPostsTotal = 0;

    for (int i = 0; i < texture->patchcount; i++)
    {
        texpatch = &texture->patches[i];
        patchNum = texpatch->patch;
        oldPatch = (const patch_t *)W_CacheLumpNum(patchNum);

        for (int x = 0; x < SHORT(oldPatch->width); x++)
        {
            int tx = texpatch->originx + x;

            if (tx < 0)
                continue;

            if (tx >= composite_patch->width)
                break;

            countsInColumn[tx].patches++;

            oldColumn = (const column_t *)((const byte *)oldPatch + LONG(oldPatch->columnofs[x]));

            while (oldColumn->topdelta != 0xFF)
            {
                countsInColumn[tx].posts++;
                numPostsTotal++;
                oldColumn = (const column_t *)((const byte *)oldColumn + oldColumn->length + 4);
            }
        }

        W_ReleaseLumpNum(patchNum);
    }

    postsDataSize = numPostsTotal * sizeof(rpost_t);

    // allocate our data chunk
    dataSize = pixelDataSize + columnsDataSize + postsDataSize;
    composite_patch->data = Z_Calloc(1, dataSize, PU_STATIC, (void **)&composite_patch->data);

    // set out pixel, column, and post pointers into our data array
    composite_patch->pixels = composite_patch->data;
    composite_patch->columns = (rcolumn_t *)((unsigned char *)composite_patch->pixels + pixelDataSize);
    composite_patch->posts = (rpost_t *)((unsigned char *)composite_patch->columns + columnsDataSize);

    // sanity check that we've got all the memory allocated we need
    assert((((byte *)composite_patch->posts + numPostsTotal * sizeof(rpost_t)) - (byte *)composite_patch->data) == dataSize);

    memset(composite_patch->pixels, 0xFF, (size_t)composite_patch->width * composite_patch->height);

    numPostsUsedSoFar = 0;

    for (int x = 0; x < texture->width; x++)
    {
        // setup the column's data
        composite_patch->columns[x].pixels = &composite_patch->pixels[x * composite_patch->height];
        composite_patch->columns[x].numposts = countsInColumn[x].posts;
        composite_patch->columns[x].posts = composite_patch->posts + numPostsUsedSoFar;
        numPostsUsedSoFar += countsInColumn[x].posts;
    }

    // fill in the pixels, posts, and columns
    for (int i = 0; i < texture->patchcount; i++)
    {
        texpatch = &texture->patches[i];
        patchNum = texpatch->patch;
        oldPatch = (const patch_t *)W_CacheLumpNum(patchNum);

        for (int x = 0; x < SHORT(oldPatch->width); x++)
        {
            int top = -1;
            int tx = texpatch->originx + x;

            if (tx < 0)
                continue;

            if (tx >= composite_patch->width)
                break;

            oldColumn = (const column_t *)((const byte *)oldPatch + LONG(oldPatch->columnofs[x]));

            while (oldColumn->topdelta != 0xFF)
            {
                int     oy = texpatch->originy;
                rpost_t *post = &composite_patch->columns[tx].posts[countsInColumn[tx].posts_used];

                // e6y: support for DeePsea's true tall patches
                if (oldColumn->topdelta <= top)
                    top += oldColumn->topdelta;
                else
                    top = oldColumn->topdelta;

                oldColumnPixelData = (const byte *)oldColumn + 3;
                count = oldColumn->length;

                // [BH] use incorrect y-origin for certain textures
                if (id == BIGDOOR7 || id == FIREBLU1 || id == SKY1 || (id == STEP2 && modifiedgame))
                    oy = 0;

                // set up the post's data
                post->topdelta = top + oy;
                post->length = count;

                if (post->topdelta + post->length > composite_patch->height)
                {
                    if (post->topdelta > composite_patch->height)
                        post->length = 0;
                    else
                        post->length = composite_patch->height - post->topdelta;
                }

                if (post->topdelta < 0)
                {
                    if (post->topdelta + post->length <= 0)
                        post->length = 0;
                    else
                        post->length -= post->topdelta;

                    post->topdelta = 0;
                }

                // fill in the post's pixels
                for (int y = 0; y < count; y++)
                {
                    int ty = oy + top + y;

                    if (ty < 0)
                        continue;

                    if (ty >= composite_patch->height)
                        break;

                    composite_patch->pixels[tx * composite_patch->height + ty] = oldColumnPixelData[y];
                }

                oldColumn = (const column_t *)((const byte *)oldColumn + oldColumn->length + 4);
                countsInColumn[tx].posts_used++;
                assert(countsInColumn[tx].posts_used <= countsInColumn[tx].posts);
            }
        }

        W_ReleaseLumpNum(patchNum);
    }

    for (int x = 0; x < texture->width; x++)
    {
        rcolumn_t   *column;
        int         i = 0;

        if (countsInColumn[x].patches <= 1)
            continue;

        // cleanup posts on multipatch columns
        column = &composite_patch->columns[x];

        while (i < column->numposts - 1)
        {
            rpost_t *post1 = &column->posts[i];
            rpost_t *post2 = &column->posts[i + 1];

            if (post2->topdelta - post1->topdelta < 0)
                switchPosts(post1, post2);

            if (post1->topdelta + post1->length >= post2->topdelta)
            {
                int length = post1->length + post2->length - (post1->topdelta + post1->length - post2->topdelta);

                if (post1->length < length)
                    post1->length = length;

                removePostFromColumn(column, i + 1);
                i = 0;
                continue;
            }

            i++;
        }
    }

    // copy the patch image down and to the right where there are
    // holes to eliminate the black halo from bilinear filtering
    for (int x = 0; x < composite_patch->width; x++)
    {
        const rcolumn_t *column = R_GetPatchColumnClamped(composite_patch, x);
        const rcolumn_t *prevColumn = R_GetPatchColumnClamped(composite_patch, x - 1);

        if (column->pixels[0] == 0xFF)
        {
            // force the first pixel (which is a hole), to use
            // the color from the next solid spot in the column
            for (int y = 0; y < composite_patch->height; y++)
                if (column->pixels[y] != 0xFF)
                {
                    column->pixels[0] = column->pixels[y];
                    break;
                }
        }

        // copy from above or to the left
        for (int y = 1; y < composite_patch->height; y++)
        {
            if (column->pixels[y] != 0xFF)
                continue;

            // this pixel is a hole
            if (x && prevColumn->pixels[y - 1] != 0xFF)
                column->pixels[y] = prevColumn->pixels[y];      // copy the color from the left
            else
                column->pixels[y] = column->pixels[y - 1];      // copy the color from above
        }
    }

    free(countsInColumn);
}

void R_InitPatches(void)
{
    patches = calloc(numlumps, sizeof(rpatch_t));

    texture_composites = calloc(numtextures, sizeof(rpatch_t));

    BIGDOOR7 = R_CheckTextureNumForName("BIGDOOR7");
    FIREBLU1 = R_CheckTextureNumForName("FIREBLU1");
    SKY1 = R_CheckTextureNumForName("SKY1");
    STEP2 = R_CheckTextureNumForName("STEP2");

    for (int i = 0; i < numspritelumps; i++)
        createPatch(firstspritelump + i);

    for (int i = 0; i < numtextures; i++)
        createTextureCompositePatch(i);
}

//const rpatch_t *R_CachePatchNum(int id)
//{
//    return &patches[id];
//}
//
//const rpatch_t *R_CacheTextureCompositePatchNum(int id)
//{
//    return &texture_composites[id];
//}
//
//const rcolumn_t *R_GetPatchColumnWrapped(const rpatch_t *patch, int columnIndex)
//{
//    while (columnIndex < 0)
//        columnIndex += patch->width;
//
//    return &patch->columns[columnIndex % patch->width];
//}

const rcolumn_t *R_GetPatchColumnClamped( const rpatch_t *patch, int columnIndex )
{
	return &patch->columns[ BETWEEN( 0, columnIndex, patch->width - 1 ) ];
}
