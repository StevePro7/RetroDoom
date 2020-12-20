#include "a_game.h"
#include "doomtype.h"

HANDLE       hInstanceMutex;

WNDPROC      oldProc;
HICON        icon;

int windowborderwidth = 0;
int windowborderheight = 0;

//LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
//{
//	if( msg == WM_SETCURSOR )
//	{
//		if( LOWORD( lParam ) == HTCLIENT && !MouseShouldBeGrabbed() )
//		{
//			SetCursor( LoadCursor( NULL, IDC_ARROW ) );
//			return true;
//		}
//	}
//	else if( msg == WM_SYSCOMMAND )
//	{
//		if( ( wParam & 0xFFF0 ) == SC_MAXIMIZE )
//		{
//			I_ToggleFullscreen();
//			return true;
//		}
//		else if( ( wParam & 0xFFF0 ) == SC_KEYMENU )
//			return false;
//	}
//	else if( msg == WM_SYSKEYDOWN )
//	{
//		if( wParam == VK_RETURN && !( lParam & 0x40000000 ) )
//		{
//			I_ToggleFullscreen();
//			return true;
//		}
//	}
//	else if( msg == WM_DEVICECHANGE )
//	{
//		I_ShutdownGamepad();
//		I_InitGamepad();
//	}
//	else if( msg == WM_SIZE )
//	{
//		if( !vid_fullscreen )
//			I_WindowResizeBlit();
//	}
//	else if( msg == WM_GETMINMAXINFO )
//	{
//		LPMINMAXINFO    minmaxinfo = ( LPMINMAXINFO ) lParam;
//
//		minmaxinfo->ptMinTrackSize.x = VANILLAWIDTH + windowborderwidth;
//		minmaxinfo->ptMinTrackSize.y = VANILLAWIDTH * 3 / 4 + windowborderheight;
//
//		return false;
//	}
//
//	return CallWindowProc( oldProc, hwnd, msg, wParam, lParam );
//}