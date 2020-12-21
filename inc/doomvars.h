#if !defined(__DOOMVARS_H__)
#define __DOOMVARS_H__

#include "doomenum.h"
#include "doomtype.h"

// d_main.h
extern char     *packageconfig;


// w_wad.c
extern char *packagewad;


// doomstat.h
// Game Mode - identify IWAD as shareware, retail etc.
//
extern GameMode_t       gamemode;
extern GameMission_t    gamemission;
extern char             gamedescription[ 255 ];
extern dboolean         hacx;


// i_video.h
extern dboolean     returntowidescreen;
//extern dboolean     vid_widescreen;

// d_main.h
#if defined(_WIN32)
extern char *previouswad;
#endif
//#if defined(_WIN32)
//extern char         *wad;
//#endif


#endif
