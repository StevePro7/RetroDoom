
#include "z_zone.h"
//#include "i_system.h"
#include <stdbool.h>
#include <stdlib.h>

// Minimum chunk size at which blocks are allocated
#define CHUNK_SIZE  32

typedef struct memblock_s
{
	struct memblock_s   *next;
	struct memblock_s   *prev;
	size_t              size;
	void                **user;
	unsigned char       tag;
} memblock_t;

// size of block header
// cph - base on sizeof(memblock_t), which can be larger than CHUNK_SIZE on
// 64bit architectures
static const size_t headersize = ( sizeof( memblock_t ) + CHUNK_SIZE - 1 ) & ~( CHUNK_SIZE - 1 );

static memblock_t   *blockbytag[ PU_MAX ];

//
// Z_Malloc
// You can pass a NULL user if the tag is < PU_PURGELEVEL.
//
// cph - the algorithm here was a very simple first-fit round-robin
//  one - just keep looping around, freeing everything we can until
//  we get a large enough space
//
// This has been changed now; we still do the round-robin first-fit,
// but we only free the blocks we actually end up using; we don't
// free all the stuff we just pass on the way.
//
void *Z_Malloc( size_t size, int tag, void **user )
{
	memblock_t  *block = NULL;

	if( !size )
		return ( user ? ( *user = NULL ) : NULL );          // malloc(0) returns NULL

	size = ( size + CHUNK_SIZE - 1 ) & ~( CHUNK_SIZE - 1 ); // round to chunk size

	while( !( block = malloc( size + headersize ) ) )
	{
//		if( !blockbytag[ PU_CACHE ] )
			//I_Error( "Z_Malloc: Failure trying to allocate %lu bytes", ( unsigned long ) size );

		Z_FreeTags( PU_CACHE, PU_CACHE );
	}

	if( !blockbytag[ tag ] )
	{
		blockbytag[ tag ] = block;
		block->next = block->prev = block;
	}
	else
	{
		blockbytag[ tag ]->prev->next = block;
		block->prev = blockbytag[ tag ]->prev;
		block->next = blockbytag[ tag ];
		blockbytag[ tag ]->prev = block;
	}

	block->size = size;

	block->tag = tag;                                   // tag
	block->user = user;                                 // user
	block = ( memblock_t * ) ( ( char * ) block + headersize );

	if( user )                                           // if there is a user
		*user = block;                                  // set user to point to new block

	return block;
}

void *Z_Calloc( size_t n1, size_t n2, int tag, void **user )
{
	return ( ( n1 *= n2 ) ? memset( Z_Malloc( n1, tag, user ), 0, n1 ) : NULL );
}

void Z_Free( void *ptr )
{
	memblock_t  *block = ( memblock_t * ) ( ( char * ) ptr - headersize );

	if( block->user )                                    // Nullify user if one exists
		*block->user = NULL;

	if( block == block->next )
		blockbytag[ block->tag ] = NULL;
	else if( blockbytag[ block->tag ] == block )
		blockbytag[ block->tag ] = block->next;

	block->prev->next = block->next;
	block->next->prev = block->prev;

	free( block );
}

void Z_FreeTags( int lowtag, int hightag )
{
	if( lowtag <= PU_FREE )
		lowtag = PU_FREE + 1;

	if( hightag > PU_CACHE )
		hightag = PU_CACHE;

	for( ; lowtag <= hightag; lowtag++ )
	{
		memblock_t  *block = blockbytag[ lowtag ];
		memblock_t  *end_block;

		if( !block )
			continue;

		end_block = block->prev;

		while( true )
		{
			memblock_t  *next = block->next;

			Z_Free( ( char * ) block + headersize );

			if( block == end_block )
				break;

			block = next;                               // Advance to next block
		}
	}
}

void Z_ChangeTag( void *ptr, int tag )
{
	memblock_t  *block;

	if( !ptr )
		return;

	block = ( memblock_t * ) ( ( char * ) ptr - headersize );

	// proff - do nothing if tag doesn't differ
	if( tag == block->tag )
		return;

	if( block == block->next )
		blockbytag[ block->tag ] = NULL;
	else if( blockbytag[ block->tag ] == block )
		blockbytag[ block->tag ] = block->next;

	block->prev->next = block->next;
	block->next->prev = block->prev;

	if( !blockbytag[ tag ] )
	{
		blockbytag[ tag ] = block;
		block->next = block->prev = block;
	}
	else
	{
		blockbytag[ tag ]->prev->next = block;
		block->prev = blockbytag[ tag ]->prev;
		block->next = blockbytag[ tag ];
		blockbytag[ tag ]->prev = block;
	}

	block->tag = tag;
}
