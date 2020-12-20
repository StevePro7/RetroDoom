//stevepro
#include "doomvars.h"
#include "doomdef.h"

// i_video.c
dboolean            returntowidescreen;
dboolean            vid_widescreen = vid_widescreen_default;

// d_main.c
#if defined(_WIN32)
char                *previouswad;
#endif

#if defined(_WIN32)
char                *wad = wad_default;
#endif