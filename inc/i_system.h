#if !defined(__I_SYSTEM_H__)
#define __I_SYSTEM_H__

//#include "d_event.h"

#if defined(_WIN32)
#define WINDOWS     "Windows"
#define EXECUTABLE  "executable"
#elif defined(__APPLE__)
#define WINDOWS     "macOS"
#define EXECUTABLE  "app"
#else
#define WINDOWS     "Linux"
#define EXECUTABLE  "binary"
#endif


//
//// Called by D_DoomLoop,
//// called before processing each tic in a frame.
//// Quick synchronous operations are performed here.
//// Can call D_PostEvent.
//void I_StartTic(void);
//
//// Called by M_Responder when quit is selected.
//// Clean exit, displays sell blurb.
//void I_Quit(dboolean shutdown);
//
//void I_Error(const char *error, ...);
//
//void I_PrintWindowsVersion(void);
//void I_PrintSystemInfo(void);
//
//void *I_Realloc(void *ptr, size_t size);
//
#endif
