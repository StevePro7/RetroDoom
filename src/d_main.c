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
#include "doomdef.h"
#include "doomtype.h"
#include "doomvars.h"
#include "g_game.h"
#include "i_system.h"
#include "i_timer.h"
#include "m_argv.h"
#include "m_config.h"
#include "m_fixed.h"
#include "m_misc.h"
#include "v_video.h"
#include "version.h"
#include "w_wad.h"

#include "SDL_messagebox.h"

#if !defined(_WIN32)
#include <dirent.h>
#include <fnmatch.h>
#include <libgen.h>

#if !defined(__OpenBSD__) && !defined(__HAIKU__)
#include <wordexp.h>
#endif
#endif

#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#endif

#define FADETICS    40

char **episodes[] =
{
	&s_M_EPISODE1,
	&s_M_EPISODE2,
	&s_M_EPISODE3,
	&s_M_EPISODE4,
	&s_M_EPISODE5
};

char **expansions[] =
{
	&s_M_EXPANSION1,
	&s_M_EXPANSION2
};

char **skilllevels[] =
{
	&s_M_SKILLLEVEL1,
	&s_M_SKILLLEVEL2,
	&s_M_SKILLLEVEL3,
	&s_M_SKILLLEVEL4,
	&s_M_SKILLLEVEL5
};

static char *iwadsrequired[] =
{
	"doom.wad",
	"doom2.wad",
	"tnt.wad",
	"plutonia.wad",
	"nerve.wad",
	"doom2.wad"
};

// Location where savegames are stored
//char                *savegamefolder;

char                *pwadfile = "";

dboolean            fade = fade_default;
char                *iwadfolder = iwadfolder_default;
dboolean            melt = melt_default;
int                 turbo = turbo_default;
int                 units = units_default;

#if defined(_WIN32)
char                *wad = wad_default;
#endif

//char                *packageconfig;
//char                *packagewad;

//static char         dehwarning[ 256 ] = "";

//#if defined(_WIN32)
//char                *previouswad;
//#endif
//
//dboolean            devparm;                // started game with -devparm
//dboolean            fastparm;               // checkparm of -fast
//dboolean            freeze;
//dboolean            nomonsters;             // checkparm of -nomonsters
//dboolean            pistolstart;            // [BH] checkparm of -pistolstart
//dboolean            regenhealth;
//dboolean            respawnitems;
//dboolean            respawnmonsters;        // checkparm of -respawn

uint64_t            stat_runs = 0;

//skill_t             startskill;
//int                 startepisode;
static int          startmap;
//dboolean            autostart;

//dboolean            advancetitle;
//dboolean            dowipe;
static dboolean     forcewipe;

//static byte         fadescreen[ SCREENWIDTH * SCREENHEIGHT ];
//static int          fadeheight;
int                 fadecount = 0;

dboolean            splashscreen = true;

static int          startuptimer;

//dboolean            realframe;
static dboolean     error;
static dboolean     guess;

struct tm           gamestarttime;

#if defined(_WIN32)
extern HANDLE       CapFPSEvent;
#endif

static void D_ProcessDehCommandLine( void )
{
	int p = M_CheckParm( "-deh" );

	if( p || ( p = M_CheckParm( "-bex" ) ) )
	{
		dboolean    deh = true;

		while( ++p < myargc )
			if( *myargv[ p ] == '-' )
				deh = ( M_StringCompare( myargv[ p ], "-deh" ) || M_StringCompare( myargv[ p ], "-bex" ) );
			else if( deh )
			{
				// stevepro TODO? skip deh file
				//ProcessDehFile( myargv[ p ], 0, false );
			}
	}
}

static dboolean D_CheckParms( void )
{
	dboolean    result = false;

	if( myargc == 2 && M_StringEndsWith( myargv[ 1 ], ".wad" ) )
	{
		// steveproTODO	ripped out all of this logic 
	}

	return result;
}

static dboolean D_IsDOOMIWAD( char *filename )
{
	return ( M_StringEndsWith( filename, "DOOM.WAD" ) || M_StringEndsWith( filename, "DOOM1.WAD" )
		|| M_StringEndsWith( filename, "DOOM2.WAD" ) || M_StringEndsWith( filename, "PLUTONIA.WAD" )
		|| M_StringEndsWith( filename, "TNT.WAD" ) || ( hacx = M_StringEndsWith( filename, "HACX.WAD" ) ) );
}

static dboolean D_IsUnsupportedIWAD( char *filename )
{
	const struct
	{
		char    *iwad;
		char    *title;
	} unsupported[] = {
		{ "heretic.wad",  "Heretic" },
		{ "heretic1.wad", "Heretic" },
		{ "hexen.wad",    "Hexen" },
		{ "hexdd.wad",    "Hexen" },
		{ "strife0.wad",  "Strife" },
		{ "strife1.wad",  "Strife" },
		{ "voices.wad",   "Strife" }
	};

	for( int i = 0; i < arrlen( unsupported ); i++ )
		if( M_StringEndsWith( filename, unsupported[ i ].iwad ) )
		{
			char    buffer[ 1024 ];

			M_snprintf( buffer, sizeof( buffer ), PACKAGE_NAME " doesn't support %s.", unsupported[ i ].title );
			SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_WARNING, PACKAGE_NAME, buffer, NULL );

#if defined(_WIN32)
			if( previouswad )
				wad = M_StringDuplicate( previouswad );
#endif

			error = true;
			return true;
		}

	return false;
}


#if defined(_WIN32) || defined(__APPLE__)
static int D_OpenWADLauncher( void )
{
	int             iwadfound = -1;

	char    *file = wad;
	dboolean test1;
	dboolean test2;
	dboolean test3;

	if( M_FileExists( file ) )
	{
		logd( "File : '%s' exists\n", file );
	}

	// check if it's a valid and supported IWAD
	test1 = D_IsDOOMIWAD( file );
	test2 = ( W_WadType(file) == IWAD );
	test3 = D_IsUnsupportedIWAD( file );

	// check if it's a valid and supported IWAD
	//if( D_IsDOOMIWAD( myargv[ 1 ] ) || ( W_WadType( myargv[ 1 ] ) == IWAD && !D_IsUnsupportedIWAD( myargv[ 1 ] ) ) )
	if( test1 || test2 && !test3 )
	{
		D_IdentifyIWADByName( file );

		if( W_AddFile( file, false ) )
		{
			iwadfound = 1;
		}
	}

	return iwadfound;
}
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
	int     choseniwad = 0;
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

	modifiedgame = false;

	for( int i = 0; i < MAXALIASES; i++ )
	{
		aliases[ i ].name[ 0 ] = '\0';
		aliases[ i ].string[ 0 ] = '\0';
	}

	D_ProcessDehCommandLine();

	// Load configuration files before initializing other subsystems.
	M_LoadCVARs( packageconfig );

	//steveproTODO	not checking cmd line params
	//if( ( respawnmonsters = M_CheckParm( "-respawn" ) ) )
	//	C_Output( "A <b>-respawn</b> parameter was found on the command-line. Monsters will respawn." );
	//else if( ( respawnmonsters = M_CheckParm( "-respawnmonsters" ) ) )
	//	C_Output( "A <b>-respawnmonsters</b> parameter was found on the command-line. Monsters will respawn." );

	//if( ( nomonsters = M_CheckParm( "-nomonsters" ) ) )
	//{
	//	C_Output( "A <b>-nomonsters</b> parameter was found on the command-line. No monsters will be spawned." );
	//	stat_cheated = SafeAdd( stat_cheated, 1 );
	//	M_SaveCVARs();
	//}

	//if( ( pistolstart = M_CheckParm( "-pistolstart" ) ) )
	//	C_Output( "A <b>-pistolstart</b> parameter was found on the command-line. The player will start each map with only a pistol." );

	//if( ( fastparm = M_CheckParm( "-fast" ) ) )
	//	C_Output( "A <b>-fast</b> parameter was found on the command-line. Monsters will be faster." );
	//else if( ( fastparm = M_CheckParm( "-fastmonsters" ) ) )
	//	C_Output( "A <b>-fastmonsters</b> parameter was found on the command-line. Monsters will be faster." );

	//if( ( devparm = M_CheckParm( "-devparm" ) ) )
	//	C_Output( "A <b>-devparm</b> parameter was found on the command-line. %s", s_D_DEVSTR );

	// turbo option
	//if( ( p = M_CheckParm( "-turbo" ) ) )
	//{
	//	int scale = 200;

	//	if( p < myargc - 1 )
	//	{
	//		scale = atoi( myargv[ p + 1 ] );

	//		if( scale >= 10 && scale <= 400 && scale != 100 )
	//			C_Output( "A <b>-turbo</b> parameter was found on the command-line. The player will be %i%% their normal speed.", scale );
	//		else
	//			scale = 100;
	//	}
	//	else
	//		C_Output( "A <b>-turbo</b> parameter was found on the command-line. The player will be twice as fast." );

	//	if( scale != 100 )
	//		G_SetMovementSpeed( scale );

	//	if( scale > turbo_default )
	//	{
	//		stat_cheated = SafeAdd( stat_cheated, 1 );
	//		M_SaveCVARs();
	//	}
	//}
	//else
	//	G_SetMovementSpeed( turbo );

	// init subsystems
	V_Init();
	I_InitTimer();

	if( !stat_runs )
	{
		//C_Output( "This is the first time <i><b>" PACKAGE_NAME "</b></i> has been run." );
		logd( "This is the first time <i><b>" PACKAGE_NAME "</b></i> has been run.\n" );
	}
		
	else if( stat_runs == 1 )
	{
		//C_Output( "<i><b>" PACKAGE_NAME "</b></i> has now been run twice." );
		logd( "<i><b>" PACKAGE_NAME "</b></i> has now been run twice.\n" );
	}
	else
	{
		char    *temp = commify( SafeAdd( stat_runs, 1 ) );

		//C_Output( "<i><b>" PACKAGE_NAME "</b></i> has now been run %s times.", temp );
		logd( "<i><b>" PACKAGE_NAME "</b></i> has now been run %s times.\n", temp );

		free( temp );
	}

	if( !M_FileExists( packagewad ) )
	{
		//I_Error( "%s can't be found.", packagewad );
		loge( "%s can't be found.\n", packagewad );
	}
		

	if( M_CheckParm( "-nodeh" ) )
	{
		//C_Output( "A <b>-nodeh</b> parameter was found on the command-line. All <b>DEHACKED</b> lumps will be ignored." );
		logd( "A <b>-nodeh</b> parameter was found on the command-line. All <b>DEHACKED</b> lumps will be ignored.\n" );
	}
		
	else if( M_CheckParm( "-nobex" ) )
	{
		//C_Output( "A <b>-nobex</b> parameter was found on the command-line. All <b>DEHACKED</b> lumps will be ignored." );
		logd( "A <b>-nobex</b> parameter was found on the command-line. All <b>DEHACKED</b> lumps will be ignored.\n" );
	}
		

	p = M_CheckParmsWithArgs( "-file", "-pwad", "-merge", 1, 1 );

//	if( !( choseniwad = D_CheckParms() ) )
//	{
//		if( iwadfile )
//		{
//			startuptimer = I_GetTimeMS();
//
//			if( W_AddFile( iwadfile, false ) )
//				stat_runs = SafeAdd( stat_runs, 1 );
//		}
//		else if( !p )
//		{
//#if defined(_WIN32) || defined(__APPLE__)
//			do
//			{

	// default load doom1.wad
	if( ( choseniwad = D_OpenWADLauncher() ) == -1 )
	{
		I_Quit( false );
	}

		
//				if( ( choseniwad = D_OpenWADLauncher() ) == -1 )
//					I_Quit( false );
//#if defined(_WIN32)
//				else if( !choseniwad && !error && ( !*wad || M_StringEndsWith( wad, ".wad" ) ) )
//#else
//				else if( !choseniwad && !error )
//#endif
//				{
//					char    buffer[ 256 ];
//
//#if defined(_WIN32)
//					M_snprintf( buffer, sizeof( buffer ), PACKAGE_NAME " couldn't find %s.", ( *wad ? wad : "any IWADs" ) );
//
//					if( previouswad )
//						wad = M_StringDuplicate( previouswad );
//#else
//					M_snprintf( buffer, sizeof( buffer ), PACKAGE_NAME " couldn't find any IWADs." );
//#endif
//
//					SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_WARNING, PACKAGE_NAME, buffer, NULL );
//				}
//			} while( !choseniwad );
//#endif
//
			stat_runs = SafeAdd( stat_runs, 1 );
//		}
//	}
//
	M_SaveCVARs();

//#if defined(_WIN32)
//	if( keyboardscreenshot == KEY_PRINTSCREEN )
//	{
//		RegisterHotKey( NULL, 1, MOD_ALT, VK_SNAPSHOT );
//		RegisterHotKey( NULL, 2, 0, VK_SNAPSHOT );
//	}
//#endif
//
//	if( p > 0 )
//		do
//		{
//			for( p = p + 1; p < myargc && myargv[ p ][ 0 ] != '-'; p++ )
//			{
//				char    *file = D_TryFindWADByName( myargv[ p ] );
//
//				if( iwadfile )
//				{
//					D_CheckSupportedPWAD( file );
//
//					if( W_MergeFile( file, false ) )
//					{
//						modifiedgame = true;
//
//						if( IWADRequiredByPWAD( file ) != none )
//							pwadfile = M_StringDuplicate( leafname( file ) );
//					}
//				}
//				else
//				{
//					GameMission_t   iwadrequired = IWADRequiredByPWAD( file );
//					char            fullpath[ MAX_PATH ];
//					char            *folder = M_ExtractFolder( file );
//
//					if( iwadrequired == none )
//						iwadrequired = doom2;
//
//					// try the current folder first
//					M_snprintf( fullpath, sizeof( fullpath ), "%s" DIR_SEPARATOR_S "%s", folder, iwadsrequired[ iwadrequired ] );
//					D_IdentifyIWADByName( fullpath );
//
//					if( W_AddFile( fullpath, true ) )
//					{
//						iwadfile = M_StringDuplicate( fullpath );
//						iwadfolder = M_StringDuplicate( folder );
//						D_CheckSupportedPWAD( file );
//
//						if( W_MergeFile( file, false ) )
//						{
//							modifiedgame = true;
//
//							if( IWADRequiredByPWAD( file ) != none )
//								pwadfile = M_StringDuplicate( leafname( file ) );
//						}
//					}
//					else
//					{
//						// otherwise try the iwadfolder CVAR
//						M_snprintf( fullpath, sizeof( fullpath ), "%s" DIR_SEPARATOR_S "%s", iwadfolder, iwadsrequired[ iwadrequired ] );
//						D_IdentifyIWADByName( fullpath );
//
//						if( W_AddFile( fullpath, true ) )
//						{
//							iwadfile = M_StringDuplicate( fullpath );
//							D_CheckSupportedPWAD( file );
//
//							if( W_MergeFile( file, false ) )
//							{
//								modifiedgame = true;
//
//								if( IWADRequiredByPWAD( file ) != none )
//									pwadfile = M_StringDuplicate( leafname( file ) );
//							}
//						}
//						else
//						{
//							// still nothing? try some common installation folders
//							if( W_AddFile( D_FindWADByName( iwadsrequired[ iwadrequired ] ), true ) )
//							{
//								iwadfile = M_StringDuplicate( fullpath );
//								D_CheckSupportedPWAD( file );
//
//								if( W_MergeFile( file, false ) )
//								{
//									modifiedgame = true;
//
//									if( IWADRequiredByPWAD( file ) != none )
//										pwadfile = M_StringDuplicate( leafname( file ) );
//								}
//							}
//						}
//					}
//
//					free( folder );
//				}
//
//			}
//		} while( ( p = M_CheckParmsWithArgs( "-file", "-pwad", "-merge", 1, p ) ) );
//
//		if( !iwadfile && !modifiedgame && !choseniwad )
//			I_Error( PACKAGE_NAME " couldn't find any IWADs." );

	
	W_Init();
}

//
// D_DoomMain
//
void D_DoomMain(void)
{
    D_DoomMainSetup();          // CPhipps - setup out of main execution stack

    D_DoomLoop();               // never returns
}
