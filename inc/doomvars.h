#if !defined(__DOOMVARS_H__)
#define __DOOMVARS_H__

#include "doomdef.h"
#include "doomenum.h"
#include "doomtype.h"
#include "doomstruct.h"

// d_main.h
extern char     *packageconfig;
extern dboolean advancetitle;

// w_wad.c
extern char *packagewad;


// doomstat.h
extern int              gametime;


// m_menu.c
dboolean        menuactive;


// m_config.h
extern int          vid_capfps;


// doomstat.h
// Set if homebrew PWAD stuff has been added.
extern dboolean         modifiedgame;

// c_cmds.h
extern alias_t          aliases[ MAXALIASES ];


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
