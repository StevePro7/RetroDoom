#include "i_system.h"
#include "a_game.h"

#include "doomvars.h"
#include "i_music.h"
#include "i_sound.h"
#include "i_timer.h"
#include "i_video.h"
#include "m_config.h"
////#include "c_console.h"
////#include "d_main.h"

//#include "m_config.h"
//#include "m_controls.h"
#include "m_misc.h"
////#include "s_sound.h"
#include "version.h"

#include "SDL_messagebox.h"

#if defined(_WIN32)
#include <Windows.h>
#else
#include <unistd.h>
#endif

#if defined(__APPLE__)
#define PC  "Mac"
#else
#define PC  "PC"
#endif

// stevepro
static void My_S_Shutdown()
{
	I_ShutdownSound();
	I_ShutdownMusic();
}

static void I_ShutdownWindows32()
{
	DestroyIcon( icon );
	ReleaseMutex( hInstanceMutex );
	CloseHandle( hInstanceMutex );
	//I_AccessibilityShortcutKeys( true );
}

//#if defined(_WIN32)
//extern char *previouswad;
//
//typedef long    (__stdcall *PRTLGETVERSION)(PRTL_OSVERSIONINFOEXW);
//typedef BOOL    (WINAPI *PGETPRODUCTINFO)(DWORD, DWORD, DWORD, DWORD, PDWORD);
//typedef BOOL    (WINAPI *PISWOW64PROCESS)(HANDLE, PBOOL);
//
//#define PRODUCT_CORE    0x00000065
//
//void I_PrintWindowsVersion(void)
//{
//    PRTLGETVERSION  pRtlGetVersion = (PRTLGETVERSION)GetProcAddress(GetModuleHandle("ntdll.dll"), "RtlGetVersion");
//    PGETPRODUCTINFO pGetProductInfo = (PGETPRODUCTINFO)GetProcAddress(GetModuleHandle("kernel32.dll"), "GetProductInfo");
//    PISWOW64PROCESS pIsWow64Process = (PISWOW64PROCESS)GetProcAddress(GetModuleHandle("kernel32.dll"), "IsWow64Process");
//
//    if (pRtlGetVersion && pGetProductInfo)
//    {
//        int                 bits = 32;
//        char                typename[32] = "";
//        OSVERSIONINFOEXW    info;
//        DWORD               type;
//
//        if (pIsWow64Process)
//        {
//            BOOL    Wow64Process = FALSE;
//
//            pIsWow64Process(GetCurrentProcess(), &Wow64Process);
//
//            if (Wow64Process || sizeof(intptr_t) == 8)
//                bits = 64;
//        }
//
//        ZeroMemory(&info, sizeof(OSVERSIONINFOEXW));
//        info.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOEXW);
//
//        pRtlGetVersion((PRTL_OSVERSIONINFOEXW)&info);
//
//        pGetProductInfo(info.dwMajorVersion, info.dwMinorVersion, 0, 0, &type);
//
//        switch (type)
//        {
//            case PRODUCT_ULTIMATE:
//                M_StringCopy(typename, "Ultimate", sizeof(typename));
//                break;
//
//            case PRODUCT_PROFESSIONAL:
//                M_StringCopy(typename, "Professional", sizeof(typename));
//                break;
//
//            case PRODUCT_HOME_PREMIUM:
//                M_StringCopy(typename, "Home Premium", sizeof(typename));
//                break;
//
//            case PRODUCT_HOME_BASIC:
//                M_StringCopy(typename, "Home Basic", sizeof(typename));
//                break;
//
//            case PRODUCT_ENTERPRISE:
//            case PRODUCT_ENTERPRISE_SERVER:
//            case PRODUCT_ENTERPRISE_SERVER_CORE:
//            case PRODUCT_ENTERPRISE_SERVER_IA64:
//                M_StringCopy(typename, "Enterprise", sizeof(typename));
//                break;
//
//            case PRODUCT_BUSINESS:
//                M_StringCopy(typename, "Business", sizeof(typename));
//                break;
//
//            case PRODUCT_STARTER:
//                M_StringCopy(typename, "Starter", sizeof(typename));
//                break;
//
//            case PRODUCT_CLUSTER_SERVER:
//                M_StringCopy(typename, "Cluster Server", sizeof(typename));
//                break;
//
//            case PRODUCT_DATACENTER_SERVER:
//            case PRODUCT_DATACENTER_SERVER_CORE:
//                M_StringCopy(typename, "Datacenter Edition", sizeof(typename));
//                break;
//
//            case PRODUCT_SMALLBUSINESS_SERVER:
//                M_StringCopy(typename, "Small Business Server", sizeof(typename));
//                break;
//
//            case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
//                M_StringCopy(typename, "Small Business Server Premium", sizeof(typename));
//                break;
//
//            case PRODUCT_STANDARD_SERVER:
//            case PRODUCT_STANDARD_SERVER_CORE:
//                M_StringCopy(typename, "Standard", sizeof(typename));
//                break;
//
//            case PRODUCT_WEB_SERVER:
//                M_StringCopy(typename, "Web Server", sizeof(typename));
//                break;
//
//            case PRODUCT_CORE:
//                M_StringCopy(typename, "Home", sizeof(typename));
//        }
//
//        if (info.dwPlatformId == VER_PLATFORM_WIN32_NT)
//        {
//            char    infoname[32] = "NT";
//            char    *build = commify(info.dwBuildNumber);
//
//            if (info.dwMajorVersion == 5)
//            {
//                if (info.dwMinorVersion == 0)
//                    M_StringCopy(infoname, "2000", sizeof(infoname));
//                else if (info.dwMinorVersion == 1)
//                    M_StringCopy(infoname, "XP", sizeof(infoname));
//                else if (info.dwMinorVersion == 2)
//                    M_StringCopy(infoname, "Server 2003", sizeof(infoname));
//            }
//            else if (info.dwMajorVersion == 6)
//            {
//                if (info.dwMinorVersion == 0)
//                    M_StringCopy(infoname, (info.wProductType == VER_NT_WORKSTATION ? "Vista" : "Server 2008"), sizeof(infoname));
//                else if (info.dwMinorVersion == 1)
//                    M_StringCopy(infoname, (info.wProductType == VER_NT_WORKSTATION ? "7" : "Server 2008 R2"), sizeof(infoname));
//                else if (info.dwMinorVersion == 2)
//                    M_StringCopy(infoname, (info.wProductType == VER_NT_WORKSTATION ? "8" : "Server 2012"), sizeof(infoname));
//                else if (info.dwMinorVersion == 3)
//                    M_StringCopy(infoname, "8.1", sizeof(infoname));
//            }
//            else if (info.dwMajorVersion == 10)
//                M_StringCopy(infoname, (info.wProductType == VER_NT_WORKSTATION ? "10" : "Server 2016"), sizeof(infoname));
//
//            if (wcslen(info.szCSDVersion) > 0)
//                C_Output("Running on %i-bit <i><b>Microsoft Windows %s%s%s (%ws)</b></i> (Build %s).",
//                    bits, infoname, (*typename ? " " : ""), typename, info.szCSDVersion, build);
//            else
//                C_Output("Running on %i-bit <i><b>Microsoft Windows %s%s%s</b></i> (Build %s).",
//                    bits, infoname, (*typename ? " " : ""), typename, build);
//
//            free(build);
//        }
//
//        if (bits == 64 && sizeof(intptr_t) == 4)
//            C_Warning(1, "The 64-bit version of <i>" PACKAGE_NAME "</i> is recommended on this PC.");
//    }
//}
//#endif
//
//void I_PrintSystemInfo(void)
//{
//    int     cores = SDL_GetCPUCount();
//    char    *RAM = commify(SDL_GetSystemRAM() / 1000);
//
//    C_Output("There %s %i core%s and %sGB of RAM on this " PC ".", (cores > 1 ? "are" : "is"), cores, (cores > 1 ? "s" : ""), RAM);
//    free(RAM);
//}

//
// I_Quit
//
#if defined(_WIN32)
void I_ShutdownWindows32(void);
#endif

void I_Quit(dboolean shutdown)
{
    if (shutdown)
    {
		// steveproTODO
        //D_FadeScreenToBlack();

		//S_Shutdown();
		// stevepro
		My_S_Shutdown();

        if (returntowidescreen)
            vid_widescreen = true;

		// steveproTODO save CVARs
		//    M_SaveCVARs();

        I_ShutdownGraphics();
        I_ShutdownKeyboard();
        I_ShutdownGamepad();
        I_ShutdownTimer();
    }

#if defined(_WIN32)
    I_ShutdownWindows32();
#endif

    exit(0);
}

//
// I_Error
//


void I_Error(const char *error, ...)
{
    va_list         argptr;
    char            msgbuf[512];
    static dboolean already_quitting;

    if (already_quitting)
        exit(-1);
    else
        already_quitting = true;

    // Shutdown. Here might be other errors.
    //S_Shutdown();
	// stevepro
	My_S_Shutdown();


    if (returntowidescreen)
        vid_widescreen = true;

#if defined(_WIN32)
	if( previouswad )
		wad = M_StringDuplicate( previouswad );
#endif

	// steveproTODO save CVARs
//    M_SaveCVARs();

    I_ShutdownGraphics();
    I_ShutdownKeyboard();
    I_ShutdownGamepad();
    I_ShutdownTimer();
//
#if defined(_WIN32)
	I_ShutdownWindows32();
#endif

	va_start( argptr, error );
	vfprintf( stderr, error, argptr );
	fprintf( stderr, "\n\n" );
	va_end( argptr );
	fflush( stderr );

	va_start( argptr, error );
	memset( msgbuf, 0, sizeof( msgbuf ) );
	M_vsnprintf( msgbuf, sizeof( msgbuf ) - 1, error, argptr );
	va_end( argptr );

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, PACKAGE_NAME, msgbuf, NULL);

    exit(-1);
}

////
//// I_Realloc
////
//void *I_Realloc(void *ptr, size_t size)
//{
//    void    *newp = realloc(ptr, size);
//
//    if (!newp && size)
//        I_Error("I_Realloc: Failure trying to reallocate %zu bytes", size);
//
//    ptr = newp;
//
//    return ptr;
//}
