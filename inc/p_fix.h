#if !defined(__P_FIX_H__)
#define __P_FIX_H__

#include "m_fixed.h"

#define DEFAULT 0x7FFF
#define REMOVE  0

#define E2M2    (gamemission == doom && gameepisode == 2 && gamemap == 2 && canmodify)
#define E4M3    (gamemission == doom && gameepisode == 4 && gamemap == 3 && canmodify)
#define MAP04   (gamemission == doom2 && gamemap == 4 && canmodify)
#define MAP12   (gamemission == doom2 && gamemap == 12 && canmodify)

typedef struct
{
    int     mission;
    int     episode;
    int     map;
    int     vertex;
    int     oldx, oldy;
    int     newx, newy;
} vertexfix_t;

extern vertexfix_t  vertexfix[];

typedef struct
{
    int     mission;
    int     episode;
    int     map;
    int     linedef;
    int     side;
    char    *toptexture;
    char    *middletexture;
    char    *bottomtexture;
    fixed_t offset;
    fixed_t rowoffset;
    int     flags;
    int     special;
    int     tag;
} linefix_t;

extern linefix_t    linefix[];

typedef struct
{
    int     mission;
    int     episode;
    int     map;
    int     sector;
    char    *floorpic;
    char    *ceilingpic;
    int     floorheight;
    int     ceilingheight;
    int     special;
    int     tag;
} sectorfix_t;

extern sectorfix_t  sectorfix[];

typedef struct
{
    int     mission;
    int     episode;
    int     map;
    int     thing;
    int     type;
    int     oldx, oldy;
    int     newx, newy;
    int     angle;
    int     options;
} thingfix_t;

extern thingfix_t   thingfix[];

#endif
