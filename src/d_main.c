#define __STDC_WANT_LIB_EXT1__  1

#include "logger.h"
#include <time.h>

#if defined(_WIN32)
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <commdlg.h>
#include <mmsystem.h>
#endif

#include "d_main.h"

#if !defined(_WIN32)
#include <dirent.h>
#include <fnmatch.h>
#include <libgen.h>

#if !defined(__OpenBSD__) && !defined(__HAIKU__)
#include <wordexp.h>
#endif
#endif



//
// D_DoomLoop
//
static void D_DoomLoop(void)
{
    
}



//
// D_DoomMainSetup
//
// CPhipps - the old contents of D_DoomMain, but moved out of the main
//  line of execution so its stack space can be freed
static void D_DoomMainSetup( void )
{
}

//
// D_DoomMain
//
void D_DoomMain(void)
{
    D_DoomMainSetup();          // CPhipps - setup out of main execution stack

    D_DoomLoop();               // never returns
}
