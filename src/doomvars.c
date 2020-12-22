//stevepro
#include "doomvars.h"
#include "doomdef.h"


// d_main.c
char                *packageconfig;
char                *packagewad;
dboolean            advancetitle;

// g_game.c
int             gametime = 0;


// m_menu.h
extern dboolean         menuactive;     // Menu overlaid?

// m_config.c
int                 vid_capfps = vid_capfps_default;


// doomstat.c
// Set if homebrew PWAD stuff has been added.
dboolean        modifiedgame;

// c_cmds.c
alias_t             aliases[ MAXALIASES ];

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