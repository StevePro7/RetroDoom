#if !defined(__R_PATCH_H__)
#define __R_PATCH_H__

typedef struct
{
    int             topdelta;
    int             length;
} rpost_t;

typedef struct
{
    int             numposts;
    rpost_t         *posts;
    unsigned char   *pixels;
} rcolumn_t;

typedef struct
{
    int             width;
    int             height;
    unsigned int    widthmask;

    int             leftoffset;
    int             topoffset;

    // this is the single malloc'ed/free'd array
    // for this patch
    unsigned char   *data;

    // these are pointers into the data array
    unsigned char   *pixels;
    rcolumn_t       *columns;
    rpost_t         *posts;
} rpatch_t;

const rpatch_t *R_CachePatchNum(int id);

const rpatch_t *R_CacheTextureCompositePatchNum(int id);

const rcolumn_t *R_GetPatchColumnWrapped(const rpatch_t *patch, int columnIndex);
const rcolumn_t *R_GetPatchColumnClamped(const rpatch_t *patch, int columnIndex);

void R_InitPatches(void);

#endif
