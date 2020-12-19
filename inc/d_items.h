#if !defined(__D_ITEMS_H__)
#define __D_ITEMS_H__

#include "doomdef.h"
#include "doomtype.h"

#define BFGCELLS    40

// Weapon info: sprite frames, ammunition use.
typedef struct
{
    char            description[255];
    ammotype_t      ammotype;
    int             minammo;
    int             upstate;
    int             downstate;
    int             readystate;
    int             atkstate;
    int             flashstate;
    int             recoil;
    int             strength;
    int             tics;
    int             prev;
    int             next;
    char            spritename[9];
    dboolean        altered;
} weaponinfo_t;

extern weaponinfo_t weaponinfo[NUMWEAPONS];

#endif
