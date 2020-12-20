#if !defined(__A_GAME_H__)
#define __A_GAME_H__


#if defined(_WIN32)
#include <Windows.h>
#endif

extern HANDLE       hInstanceMutex;

extern WNDPROC      oldProc;
extern HICON        icon;

extern int windowborderwidth;
extern int windowborderheight;

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

#endif