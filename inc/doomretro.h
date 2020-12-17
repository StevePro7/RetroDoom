#if !defined(__M_DOOMRETRO_H__)
#define __M_DOOMRETRO_H__

#if defined(_WIN32)
#include <Windows.h>
#include <ShellAPI.h>

#include <stdbool.h>		// true + false
#include "doomtype.h"
#include "logger.h"

//#include "SDL_syswm.h"
#endif

#include "d_main.h"
//#include "doomstat.h"
//#include "i_gamepad.h"
//#include "i_video.h"
#include "m_argv.h"
//#include "m_config.h"
#include "version.h"

int windowborderwidth = 0;
int windowborderheight = 0;

#if defined(_WIN32)

#if !defined(SM_CXPADDEDBORDER)
#define SM_CXPADDEDBORDER   92
#endif

#endif


#endif