#if !defined(__SPRITES_H__)
#define __SPRITES_H__

#include "doomenum.h"
#include "doomtype.h"

typedef struct
{
    char        name[9];
    short       x, y;
    short       width;
    short       height;
    dboolean    sprfix18;
} offset_t;

extern char     *sprnames[];
extern offset_t sproffsets[];

#endif
