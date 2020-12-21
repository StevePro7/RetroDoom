//stevepro
#include "doomvars.h"
#include "doomdef.h"

// d_main.c
char                *packageconfig;
char                *packagewad;

// doomstat.h
// Game Mode - identify IWAD as shareware, retail etc.
GameMode_t      gamemode = indetermined;
GameMission_t   gamemission = doom;
char            gamedescription[ 255 ];
dboolean        hacx;


// i_video.c
dboolean            returntowidescreen;
//dboolean            vid_widescreen = vid_widescreen_default;

// d_main.c
#if defined(_WIN32)
char                *previouswad;
#endif

//#if defined(_WIN32)
//char                *wad = wad_default;
//#endif