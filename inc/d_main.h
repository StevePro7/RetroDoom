#if !defined(__D_MAIN_H__)
#define __D_MAIN_H__

#include "d_event.h"
#include "doomdef.h"

extern char     **episodes[];
extern char     **expansions[];
extern char     **skilllevels[];
extern char     *packageconfig;
extern char     *pwadfile;
extern dboolean advancetitle;
extern dboolean splashscreen;
extern dboolean dowipe;
extern int      titlesequence;
extern int      fadecount;

void D_Display(void);

//
// D_DoomMain()
// Not a globally visible function, just included for source reference,
// calls all startup code, parses command line options.
// If not overridden by user input, calls D_AdvanceTitle.
//
void D_DoomMain(void);

// Called by IO functions when input is detected.
void D_PostEvent(event_t *ev);

//
// BASE LEVEL
//
void D_PageTicker(void);
void D_PageDrawer(void);
void D_AdvanceTitle(void);
void D_DoAdvanceTitle(void);
void D_StartTitle(int page);
void D_FadeScreenToBlack(void);
void D_FadeScreen(void);

#endif
