#define __STDC_WANT_LIB_EXT1__  1

#include <time.h>

#if defined(_WIN32)
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <commdlg.h>
#include <mmsystem.h>
#endif

#include "am_map.h"
#include "c_console.h"
#include "logger.h"
#include "d_deh.h"
#include "d_iwad.h"
#include "d_main.h"
#include "doomdef.h"
#include "doomtype.h"
#include "doomvars.h"
#include "g_game.h"
#include "hu_stuff.h"
#include "i_swap.h"
#include "i_system.h"
#include "i_timer.h"
#include "i_video.h"
#include "m_argv.h"
#include "m_config.h"
#include "m_fixed.h"
#include "m_misc.h"
#include "m_menu.h"
#include "p_saveg.h"
#include "p_setup.h"
#include "r_main.h"
#include "s_sound.h"
#include "st_stuff.h"
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

typedef struct
{
	char        filename[ MAX_PATH ];
	dboolean    present;
} loaddehlast_t;

// [BH] A list of DeHackEd files to load last
static loaddehlast_t loaddehlast[ 8 ] =
{
	{ "VORTEX_DoomRetro.deh" },
	{ "2_MARKV.deh" },
	{ "3_HELLST.deh" },
	{ "3_REAPER.deh" },
	{ "4_HAR.deh" },
	{ "5_GRNADE.deh" },
	{ "6_LIGHT.deh" },
	{ "7_GAUSS.deh" }
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

static char         dehwarning[ 256 ] = "";

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

//struct tm           gamestarttime;

#if defined(_WIN32)
extern HANDLE       CapFPSEvent;
#endif

//
//  TITLE LOOP
//
int             titlesequence = 0;
int             pagetic = 3 * TICRATE;
int             logotic = 3 * TICRATE;

static patch_t  *pagelump;
static patch_t  *fineprintlump;
static patch_t  *logolump[ 18 ];
static patch_t  *titlelump;
static patch_t  *creditlump;
static byte     *splashpal;

//
// D_AdvanceTitle
// Called after each title sequence finishes
//
void D_AdvanceTitle( void )
{
	advancetitle = true;
	forceconsoleblurredraw = true;
}

//
// D_StartTitle
//
void D_StartTitle( int page )
{
	gameaction = ga_nothing;
	titlesequence = page;

	if( mapwindow )
		AM_ClearFB();

	D_AdvanceTitle();
}


static void D_ProcessDehInWad( void )
{
	dboolean    process = ( !M_CheckParm( "-nodeh" ) && !M_CheckParm( "-nobex" ) );

	if( *dehwarning )
	{
		//C_Warning( 1, dehwarning );
		loge( "%s\n", dehwarning );
	}

	if( doom4vanilla )
	{
		for( int i = 0; i < numlumps; i++ )
			if( M_StringCompare( lumpinfo[ i ]->name, "DEHACKED" )
				&& process
				&& !M_StringEndsWith( lumpinfo[ i ]->wadfile->path, PACKAGE_WAD )
				&& !M_StringEndsWith( lumpinfo[ i ]->wadfile->path, "D4V.WAD" ) )
				ProcessDehFile( NULL, i, false );

		for( int i = 0; i < numlumps; i++ )
			if( M_StringCompare( lumpinfo[ i ]->name, "DEHACKED" )
				&& M_StringEndsWith( lumpinfo[ i ]->wadfile->path, "D4V.WAD" ) )
				ProcessDehFile( NULL, i, false );

		for( int i = 0; i < numlumps; i++ )
			if( M_StringCompare( lumpinfo[ i ]->name, "DEHACKED" )
				&& M_StringEndsWith( lumpinfo[ i ]->wadfile->path, PACKAGE_WAD ) )
				ProcessDehFile( NULL, i, false );
	}
	else if( hacx || FREEDOOM )
	{
		for( int i = 0; i < numlumps; i++ )
			if( M_StringCompare( lumpinfo[ i ]->name, "DEHACKED" )
				&& ( process || M_StringEndsWith( lumpinfo[ i ]->wadfile->path, PACKAGE_WAD ) ) )
				ProcessDehFile( NULL, i, false );
	}
	else
	{
		if( chex1 )
			ProcessDehFile( NULL, W_GetNumForName( "CHEXBEX" ), true );

		for( int i = numlumps - 1; i >= 0; i-- )
			if( M_StringCompare( lumpinfo[ i ]->name, "DEHACKED" )
				&& !M_StringEndsWith( lumpinfo[ i ]->wadfile->path, "SIGIL_v1_2.wad" )
				&& ( process || M_StringEndsWith( lumpinfo[ i ]->wadfile->path, PACKAGE_WAD ) ) )
				ProcessDehFile( NULL, i, false );
	}

	for( int i = 0; i < 8; i++ )
		if( loaddehlast[ i ].present )
			ProcessDehFile( loaddehlast[ i ].filename, 0, false );
}

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
	char    lumpname[ 6 ];
	char    *appdatafolder = M_GetAppDataFolder();
	char    *iwadfile;
	int     startloadgame;
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

	FREEDM = ( W_CheckNumForName( "FREEDM" ) >= 0 );

	DMENUPIC = ( W_CheckNumForName( "DMENUPIC" ) >= 0 );
	M_DOOM = ( W_CheckMultipleLumps( "M_DOOM" ) > 1 );
	M_EPISOD = ( W_CheckMultipleLumps( "M_EPISOD" ) > 1 );
	M_GDHIGH = ( W_CheckMultipleLumps( "M_GDHIGH" ) > 1 );
	M_GDLOW = ( W_CheckMultipleLumps( "M_GDLOW" ) > 1 );
	M_LOADG = ( W_CheckMultipleLumps( "M_LOADG" ) > 1 );
	M_LSCNTR = ( W_CheckMultipleLumps( "M_LSCNTR" ) > 1 );
	M_MSENS = ( W_CheckMultipleLumps( "M_MSENS" ) > 1 );
	M_MSGOFF = ( W_CheckMultipleLumps( "M_MSGOFF" ) > 1 );
	M_MSGON = ( W_CheckMultipleLumps( "M_MSGON" ) > 1 );
	M_NEWG = ( W_CheckMultipleLumps( "M_NEWG" ) > 1 );
	M_NGAME = ( W_CheckMultipleLumps( "M_NGAME" ) > 1 );
	M_NMARE = ( W_CheckMultipleLumps( "M_NMARE" ) > 1 );
	M_OPTTTL = ( W_CheckMultipleLumps( "M_OPTTTL" ) > 1 );
	M_PAUSE = ( W_CheckMultipleLumps( "M_PAUSE" ) > 1 );
	M_SAVEG = ( W_CheckMultipleLumps( "M_SAVEG" ) > 1 );
	M_SKILL = ( W_CheckMultipleLumps( "M_SKILL" ) > 1 );
	M_SKULL1 = ( W_CheckMultipleLumps( "M_SKULL1" ) > 1 );
	M_SVOL = ( W_CheckMultipleLumps( "M_SVOL" ) > 1 );
	STBAR = W_CheckMultipleLumps( "STBAR" );
	STCFN034 = ( W_CheckMultipleLumps( "STCFN034" ) > 1 );
	STYSNUM0 = ( W_CheckMultipleLumps( "STYSNUM0" ) > 1 );
	TITLEPIC = ( W_CheckNumForName( "TITLEPIC" ) >= 0 );
	WISCRT2 = ( W_CheckMultipleLumps( "WISCRT2" ) > 1 );
	DSSECRET = ( W_CheckNumForName( "DSSECRET" ) >= 0 );

	// steveproTODO	complete all the code then switch to Windows mode instead of Console
	// does this work now i.e. NOT get the linker error "unresolved external symbol _SDL_main referenced in function _main_getcmdline"
	I_InitGraphics();

	//I_InitGamepad();

	D_IdentifyVersion();
	D_ProcessDehInWad();

	if( !M_StringCompare( s_VERSION, PACKAGE_NAMEANDVERSIONSTRING ) )
		I_Error( "The wrong version of %s was found.", packagewad );

	D_SetGameDescription();

	if( nerve && expansion == 2 )
		gamemission = pack_nerve;
	else if( gamemission == doom && !sigil && episode == 5 )
	{
		episode = 1;
		M_SaveCVARs();
	}

	D_SetSaveGameFolder( true );

	//C_Output( "Screenshots will be saved in <b>%s</b>.", screenshotfolder );
	logd( "Screenshots will be saved in <b>%s</b>.\n", screenshotfolder );

	// Check for -file in shareware
	if( modifiedgame )
	{
		if( gamemode == shareware )
			I_Error( "You can't load PWADs with DOOM1.WAD." );

		// Check for fake IWAD with right name,
		// but w/o all the lumps of the registered version.
		if( gamemode == registered )
		{
			// These are the lumps that will be checked in IWAD,
			// if any one is not present, execution will be aborted.
			char name[ 23 ][ 9 ] =
			{
				"E2M1", "E2M2", "E2M3", "E2M4", "E2M5", "E2M6", "E2M7", "E2M8", "E2M9",
				"E3M1", "E3M3", "E3M3", "E3M4", "E3M5", "E3M6", "E3M7", "E3M8", "E3M9",
				"DPHOOF", "BFGGA0", "HEADA1", "CYBRA1", "SPIDA1D1"
			};

			for( int i = 0; i < 23; i++ )
				if( W_CheckNumForName( name[ i ] ) < 0 )
					I_Error( "This is not the registered version of DOOM.WAD." );
		}
	}

	// get skill/episode/map from parms
	startskill = sk_medium;
	startepisode = 1;
	startmap = 1;
	autostart = false;	// steveproTODO	hardcode autostart

	if( ( p = M_CheckParmsWithArgs( "-skill", "-skilllevel", "", 1, 1 ) ) )
	{
		int temp = myargv[ p + 1 ][ 0 ] - '1';

		if( temp >= sk_baby && temp <= sk_nightmare )
		{
			char    *string = titlecase( *skilllevels[ temp ] );

			startskill = ( skill_t ) temp;
			skilllevel = startskill + 1;
			M_SaveCVARs();

			strreplace( string, ".", "" );
			strreplace( string, "!", "" );

			//C_Output( "A <b>-%s</b> parameter was found on the command-line. The skill level is now <i><b>%s.</b></i>",
				//myargv[ p ], string );
			logd( "A <b>-%s</b> parameter was found on the command-line. The skill level is now <i><b>%s.</b></i>\n",
				myargv[ p ], string );
			free( string );
		}
	}

	if( ( p = M_CheckParmWithArgs( "-episode", 1, 1 ) ) && gamemode != commercial )
	{
		int temp = myargv[ p + 1 ][ 0 ] - '0';

		if( ( gamemode == shareware && temp == 1 ) || ( temp >= 1 && ( ( gamemode == registered && temp <= 3 )
			|| ( gamemode == retail && temp <= 4 ) || ( sigil && temp <= 5 ) ) ) )
		{
			startepisode = temp;
			episode = temp;
			M_SaveCVARs();

			if( gamemode == commercial )
				M_snprintf( lumpname, sizeof( lumpname ), "MAP%02i", startmap );
			else
				M_snprintf( lumpname, sizeof( lumpname ), "E%iM%i", startepisode, startmap );

			autostart = true;
			//C_Output( "An <b>-episode</b> parameter was found on the command-line. The episode is now <i><b>%s.</b></i>",
			//	*episodes[ episode - 1 ] );
			logd( "An <b>-episode</b> parameter was found on the command-line. The episode is now <i><b>%s.</b></i>\n",
				*episodes[ episode - 1 ] );
		}
	}

	if( ( p = M_CheckParmWithArgs( "-expansion", 1, 1 ) ) && gamemode == commercial )
	{
		int temp = myargv[ p + 1 ][ 0 ] - '0';

		if( temp <= ( nerve ? 2 : 1 ) )
		{
			gamemission = ( temp == 1 ? doom2 : pack_nerve );
			expansion = temp;
			M_SaveCVARs();
			M_snprintf( lumpname, sizeof( lumpname ), "MAP%02i", startmap );
			autostart = true;
			//C_Output( "An <b>-expansion</b> parameter was found on the command-line. The expansion is now <i><b>%s.</b></i>",
			//	*expansions[ expansion - 1 ] );
			logd( "An <b>-expansion</b> parameter was found on the command-line. The expansion is now <i><b>%s.</b></i>\n",
				*expansions[ expansion - 1 ] );
		}
	}

	if( ( p = M_CheckParmWithArgs( "-warp", 1, 1 ) ) )
	{
		//C_Output( "A <b>-warp</b> parameter was found on the command-line." );
		logd( "A <b>-warp</b> parameter was found on the command-line.\n" );
	}
	else if( ( p = M_CheckParmWithArgs( "+map", 1, 1 ) ) )
	{
		//C_Output( "A <b>+map</b> parameter was found on the command-line." );
		logd( "A <b>+map</b> parameter was found on the command-line.\n" );
	}
		
	if( p )
	{
		if( gamemode == commercial )
		{
			if( strlen( myargv[ p + 1 ] ) == 5 && toupper( myargv[ p + 1 ][ 0 ] ) == 'M' && toupper( myargv[ p + 1 ][ 1 ] ) == 'A'
				&& toupper( myargv[ p + 1 ][ 2 ] ) == 'P' && isdigit( ( int ) myargv[ p + 1 ][ 3 ] ) && isdigit( ( int ) myargv[ p + 1 ][ 4 ] ) )
				startmap = ( myargv[ p + 1 ][ 3 ] - '0' ) * 10 + myargv[ p + 1 ][ 4 ] - '0';
			else
				startmap = atoi( myargv[ p + 1 ] );

			M_snprintf( lumpname, sizeof( lumpname ), "MAP%02i", startmap );
		}
		else
		{
			if( strlen( myargv[ p + 1 ] ) == 4 && toupper( myargv[ p + 1 ][ 0 ] ) == 'E' && isdigit( ( int ) myargv[ p + 1 ][ 1 ] )
				&& toupper( myargv[ p + 1 ][ 2 ] ) == 'M' && isdigit( ( int ) myargv[ p + 1 ][ 3 ] ) )
			{
				startepisode = myargv[ p + 1 ][ 1 ] - '0';
				startmap = myargv[ p + 1 ][ 3 ] - '0';
			}
			else
			{
				startepisode = myargv[ p + 1 ][ 0 ] - '0';

				if( p + 2 < myargc )
					startmap = myargv[ p + 2 ][ 0 ] - '0';
			}

			M_snprintf( lumpname, sizeof( lumpname ), "E%iM%i", startepisode, startmap );
		}

		if( ( BTSX && W_CheckMultipleLumps( lumpname ) > 1 ) || W_CheckNumForName( lumpname ) >= 0 )
		{
			autostart = true;

			stat_cheated = SafeAdd( stat_cheated, 1 );
			M_SaveCVARs();
		}
	}

	M_Init();

	R_Init();

	P_Init();

	S_Init();

	HU_Init();

	ST_Init();

	AM_Init();

	C_Init();

	if( ( startloadgame = ( ( p = M_CheckParmWithArgs( "-loadgame", 1, 1 ) ) ? atoi( myargv[ p + 1 ] ) : -1 ) ) >= 0 && startloadgame <= 5 )
	{
		menuactive = false;
		splashscreen = false;
		I_InitKeyboard();

		if( alwaysrun )
			C_StrCVAROutput( stringize( alwaysrun ), "on" );

		G_LoadGame( P_SaveGameFile( startloadgame ) );
	}

	fineprintlump = W_CacheLumpName( "FINEPRNT" );
	splashpal = W_CacheLumpName( "SPLSHPAL" );

	for( int i = 0; i < 18; i++ )
	{
		char    buffer[ 9 ];

		M_snprintf( buffer, sizeof( buffer ), "DRLOGO%02d", i + 1 );
		logolump[ i ] = W_CacheLumpName( buffer );
	}

	if( autosigil )
	{
		titlelump = W_CacheLastLumpName( ( TITLEPIC ? "TITLEPIC" : ( DMENUPIC ? "DMENUPIC" : "INTERPIC" ) ) );
		creditlump = W_CacheLastLumpName( "CREDIT" );
	}
	else
	{
		titlelump = W_CacheLumpName( ( TITLEPIC ? "TITLEPIC" : ( DMENUPIC ? "DMENUPIC" : "INTERPIC" ) ) );
		creditlump = W_CacheLumpName( "CREDIT" );
	}

	if( ( unity = ( TITLEPIC && lumpinfo[ W_GetLastNumForName( "TITLEPIC" ) ]->wadfile->type == IWAD
		&& SHORT( titlelump->width ) == UNITYWIDTH ) ) )
	{
		//C_Warning( 1, "Certain graphics in this IWAD are cropped to fit <i><b>" PACKAGE_NAME "'s</b></i> 4:3 aspect ratio." );
		loge( "Certain graphics in this IWAD are cropped to fit <i><b>" PACKAGE_NAME "'s</b></i> 4:3 aspect ratio.\n" );
	}

	if( gameaction != ga_loadgame )
	{
		if( autostart )
		{
			menuactive = false;
			splashscreen = false;
			I_InitKeyboard();

			if( alwaysrun )
				C_StrCVAROutput( stringize( alwaysrun ), "on" );

			//C_Output( "Warping to %s...", lumpname );
			logd( "Warping to %s...\n", lumpname );
			G_DeferredInitNew( startskill, startepisode, startmap );
		}
#if SCREENSCALE == 1
		else
		{
			menuactive = false;
			splashscreen = false;
			D_StartTitle( 1 );
		}
#else
		else if( M_CheckParm( "-nosplash" ) )
		{
			menuactive = false;
			splashscreen = false;
			D_StartTitle( 1 );
		}
		else
			D_StartTitle( 0 );
#endif
	}

}

//
// D_DoomMain
//
void D_DoomMain(void)
{
    D_DoomMainSetup();          // CPhipps - setup out of main execution stack

    D_DoomLoop();               // never returns
}
