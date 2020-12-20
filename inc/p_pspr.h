#if !defined(__P_PSPR_H__)
#define __P_PSPR_H__

// stevepro
#include "doomenum.h"
#include "doomtype.h"
#include "m_fixed.h"
#include "states.h"

// Basic data types.
// Needs fixed point, and BAM angles.
//#include "tables.h"

//
// Needs to include the precompiled
//  sprite animation tables.
// Header generated by multigen utility.
// This includes all the data for thing animation,
// i.e. the Thing Attributes table
// and the Frame Sequence table.
//#include "states.h"

//
// Frame flags:
// handles maximum brightness (torches, muzzle flare, light sources)
//
#define FF_FULLBRIGHT   0x8000  // flag in thing->frame
#define FF_FRAMEMASK    0x7FFF

//
// Overlay psprites are scaled shapes
// drawn directly on the view screen,
// coordinates are given for a 320*200 view screen.
//
//enum
//{
//    ps_weapon,
//    ps_flash,
//    NUMPSPRITES
//};

typedef struct
{
    state_t *state; // a NULL state means not active
    int     tics;
    fixed_t sx, sy;
} pspdef_t;

//dboolean P_CheckAmmo(weapontype_t weapon);
//void P_EquipWeapon(weapontype_t weapon);

extern dboolean skippsprinterp;

#endif
