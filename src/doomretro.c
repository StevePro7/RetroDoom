#include "doomretro.h"

static HANDLE       hInstanceMutex;

static STICKYKEYS   g_StartupStickyKeys = { sizeof( STICKYKEYS ), 0 };
static TOGGLEKEYS   g_StartupToggleKeys = { sizeof( TOGGLEKEYS ), 0 };
static FILTERKEYS   g_StartupFilterKeys = { sizeof( FILTERKEYS ), 0 };

int main( int argc, char **argv )
{
	myargc = argc;
	myargv = argv;

#if defined(_WIN32)
	hInstanceMutex = CreateMutex( NULL, true, PACKAGE_MUTEX );

//	if( GetLastError() == ERROR_ALREADY_EXISTS )
//	{
//		if( hInstanceMutex )
//			CloseHandle( hInstanceMutex );
//
//		SetForegroundWindow( FindWindow( PACKAGE_MUTEX, NULL ) );
//		return 1;
//	}

// Save the current sticky/toggle/filter key settings so they can be restored later
	//SystemParametersInfo( SPI_GETSTICKYKEYS, sizeof( STICKYKEYS ), &g_StartupStickyKeys, 0 );
	//SystemParametersInfo( SPI_GETTOGGLEKEYS, sizeof( TOGGLEKEYS ), &g_StartupToggleKeys, 0 );
	//SystemParametersInfo( SPI_GETFILTERKEYS, sizeof( FILTERKEYS ), &g_StartupFilterKeys, 0 );

	//I_AccessibilityShortcutKeys( false );

	//I_SetProcessDPIAware();
#endif

	//set_log_level( LOG_EVERYTHING );
	//log_init( "", "output", "log" );

	//logd( "my number: %d\n", 2 );
	//logd( "my string: %s\n", "string one" );

	//loge( "log session 1 finished\n" );

	D_DoomMain();

	//flush_log();
	//close_log();

	return 0;
}