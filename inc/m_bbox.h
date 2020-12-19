#if !defined(__M_BBOX_H__)
#define __M_BBOX_H__

#include <limits.h>

#include "m_fixed.h"

// Bounding box coordinate storage.
enum
{
    BOXTOP,
    BOXBOTTOM,
    BOXLEFT,
    BOXRIGHT
};

// Bounding box functions.
void M_ClearBox(fixed_t *box);

void M_AddToBox(fixed_t *box, fixed_t x, fixed_t y);

#endif
