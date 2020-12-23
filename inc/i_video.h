#if !defined(__I_VIDEO_H__)
#define __I_VIDEO_H__

#include "SDL.h"

#include "doomdef.h"
#include "doomtype.h"

//#define MAX_MOUSE_BUTTONS   8
//
//#define GAMMALEVELS         31

//dboolean MouseShouldBeGrabbed(void);
//void I_InitKeyboard(void);
void I_ShutdownKeyboard(void);
dboolean GetCapsLockState(void);
//
//// Called by D_DoomMain,
//// determines the hardware configuration
//// and sets up the video mode
void I_InitGraphics(void);
//void I_RestartGraphics(void);
void I_ShutdownGraphics(void);
void I_CapFPS(int cap);

void GetWindowPosition(void);
void GetWindowSize(void);
void GetScreenResolution(void);
//
//// Takes full 8 bit values.
void I_SetPalette(byte *playpal);
//void I_SetExternalAutomapPalette(void);
//void I_SetSimplePalette(byte *playpal);
//void I_SetPaletteWithBrightness(byte *playpal, double brightness);
//
//void I_UpdateBlitFunc(dboolean shake);
void I_CreateExternalAutomap(int outputlevel);
//void I_DestroyExternalAutomap(void);
//
//void I_ToggleFullscreen(void);
//void I_SetPillarboxes(void);
//void I_SetMotionBlur(int percent);

void I_SetGamma(float value);

//#if defined(_WIN32)
//void I_WindowResizeBlit(void);
//#endif

extern void (*blitfunc)(void);
extern void (*mapblitfunc)(void);

// steveproTODO
extern dboolean     sendpause;
extern dboolean     quitting;

extern int          keydown;

extern int          gammaindex;
extern const float  gammalevels[GAMMALEVELS];

extern int          windowx;
extern int          windowy;
extern int          windowheight;
extern int          windowwidth;

extern dboolean     windowfocused;

extern SDL_Window   *window;
extern SDL_Renderer *renderer;

extern SDL_Window   *mapwindow;
extern SDL_Renderer *maprenderer;
extern byte         *mapscreen;

extern byte         *PLAYPAL;

extern dboolean     returntowidescreen;
extern dboolean     altdown;

#endif
