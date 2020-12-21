#define __STDC_WANT_LIB_EXT1__  1

#include <time.h>

#if defined(_WIN32)
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <commdlg.h>
#include <mmsystem.h>
#endif

#include "logger.h"
#include "d_iwad.h"
#include "d_main.h"
#include "doomtype.h"
#include "doomvars.h"
#include "m_argv.h"
#include "m_misc.h"
#include "version.h"

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
	int     p = M_CheckParmWithArgs( "-config", 1, 1 );
	//int     choseniwad = 0;
	//char    lumpname[ 6 ];
	char    *appdatafolder = M_GetAppDataFolder();
	char    *iwadfile;
	//int     startloadgame;
	char    *resourcefolder = M_GetResourceFolder();
//	char    *seconds;

	packagewad = M_StringJoin( resourcefolder, DIR_SEPARATOR_S, PACKAGE_WAD, NULL );
	free( resourcefolder );

	M_MakeDirectory( appdatafolder );
	packageconfig = ( p ? M_StringDuplicate( myargv[ p + 1 ] ) : M_StringJoin( appdatafolder, DIR_SEPARATOR_S, PACKAGE_CONFIG, NULL ) );

#if !defined(__APPLE__)
	free( appdatafolder );
#endif

//	C_Output( "" );
//	C_PrintCompileDate();
//
//#if defined(_WIN32)
//	I_PrintWindowsVersion();
//#endif
//
//	I_PrintSystemInfo();
//
//	C_PrintSDLVersions();

	iwadfile = D_FindIWAD();

	//modifiedgame = false;

	//for( int i = 0; i < MAXALIASES; i++ )
	//{
	//	aliases[ i ].name[ 0 ] = '\0';
	//	aliases[ i ].string[ 0 ] = '\0';
	//}

}

//
// D_DoomMain
//
void D_DoomMain(void)
{
    D_DoomMainSetup();          // CPhipps - setup out of main execution stack

    D_DoomLoop();               // never returns
}
