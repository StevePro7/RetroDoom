#if !defined(__A_GAME_H__)
#define __A_GAME_H__

#if defined(_WIN32)
#include <Windows.h>
#endif

#include "doomtype.h"

extern HANDLE       hInstanceMutex;

extern WNDPROC      oldProc;
extern HICON        icon;

extern int windowborderwidth;
extern int windowborderheight;

extern dboolean     vid_fullscreen;

// i_video.c
extern dboolean MouseShouldBeGrabbed( void );
extern void I_ToggleFullscreen( void );
extern void I_WindowResizeBlit( void );

// i_gamepad.c
//void I_ShutdownGamepad( void );
//void I_InitGamepad( void );

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

#endif