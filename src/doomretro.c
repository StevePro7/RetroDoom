#include "doomretro.h"

int main(int argc, char **argv)
{
    myargc = argc;
    myargv = argv;

#if defined(_WIN32)
    hInstanceMutex = CreateMutex(NULL, true, PACKAGE_MUTEX);
//
//    if (GetLastError() == ERROR_ALREADY_EXISTS)
//    {
//        if (hInstanceMutex)
//            CloseHandle(hInstanceMutex);
//
//        SetForegroundWindow(FindWindow(PACKAGE_MUTEX, NULL));
//        return 1;
//    }
//
//    // Save the current sticky/toggle/filter key settings so they can be restored later
//    SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &g_StartupStickyKeys, 0);
//    SystemParametersInfo(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &g_StartupToggleKeys, 0);
//    SystemParametersInfo(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &g_StartupFilterKeys, 0);
//
//    I_AccessibilityShortcutKeys(false);
//
//    I_SetProcessDPIAware();
#endif

	set_log_level( LOG_EVERYTHING );
	log_init( "", "output", "log" );
	// example
	//logd( "my number: %d\n", 2 );
	//logd( "my string: %s\n", "string one" );

    D_DoomMain();

    return 0;
}
