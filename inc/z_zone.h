#if !defined(__Z_ZONE_H__)
#define __Z_ZONE_H__

// Include system definitions so that prototypes become
// active before macro replacements below are in effect.
#include <string.h>
#include <assert.h>

//
// ZONE MEMORY
// PU - purge tags.
//
enum
{
    PU_FREE,       // a free block
    PU_STATIC,     // static entire execution time
    PU_LEVEL,      // static until level exited
    PU_LEVSPEC,    // a special thinker in a level
    PU_CACHE,
    PU_MAX         // Must always be last -- killough
};

#define PU_PURGELEVEL    PU_CACHE    // First purgeable tag's level

void *Z_Malloc(size_t size, int tag, void **user);
void *Z_Calloc(size_t n1, size_t n2, int tag, void **user);
void Z_Free(void *ptr);
void Z_FreeTags(int lowtag, int hightag);
void Z_ChangeTag(void *ptr, int tag);

#endif
