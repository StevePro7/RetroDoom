#if !defined(__C_CONSOLE_H__)
#define __C_CONSOLE_H__

#include "doomdef.h"
#include "doomstruct.h"
#include "doomtype.h"
#include "doomvars.h"
#include "d_event.h"
//#include "r_defs.h"

//#define CONSOLESTRINGSMAX       256
//
//#define CONSOLEFONTSTART        ' '
//#define CONSOLEFONTEND          '~'
//#define CONSOLEFONTSIZE         (CONSOLEFONTEND - CONSOLEFONTSTART + 1)
//
//#define NOBOLDCOLOR             -1
//#define NOBACKGROUNDCOLOR       -1
//
//#define CONSOLEWIDTH            SCREENWIDTH
//#define CONSOLEHEIGHT           (gamestate != GS_TITLESCREEN ? (SCREENHEIGHT - SBARHEIGHT) / 2 : SCREENHEIGHT - 5)
//
//#define CONSOLELINES            (gamestate != GS_TITLESCREEN ? 11 : 27)
//#define CONSOLETEXTX            10
//#define CONSOLETEXTY            8
//#define CONSOLETEXTMAXLENGTH    1024
//#define CONSOLELINEHEIGHT       14
//
//// CONSOLELINES * CONSOLELINEHEIGHT
//#define CONSOLESCROLLBARWIDTH   5
//#define CONSOLESCROLLBARHEIGHT  (CONSOLELINES * CONSOLELINEHEIGHT - 9)
//#define CONSOLESCROLLBARX       (CONSOLEWIDTH - CONSOLETEXTX - CONSOLESCROLLBARWIDTH)
//
//#define CONSOLETEXTPIXELWIDTH   (CONSOLEWIDTH - CONSOLETEXTX * 2 - (scrollbardrawn ? CONSOLESCROLLBARWIDTH + CONSOLETEXTX : 0))
//
//#define CONSOLEINPUTPIXELWIDTH  (CONSOLEWIDTH - CONSOLETEXTX - brandwidth - 2)
//
//#define CONSOLETOP              0
//
//#define EMPTYVALUE              "\"\""
//
//#define stringize(x)            #x
//
//#if defined(_WIN32)
//#define SDL_FILENAME            "SDL2.dll"
//#define SDL_MIXER_FILENAME      "SDL2_mixer.dll"
//#define SDL_IMAGE_FILENAME      "SDL2_image.dll"
//#else
//#define SDL_FILENAME            "SDL2"
//#define SDL_MIXER_FILENAME      "SDL2_mixer"
//#define SDL_IMAGE_FILENAME      "SDL2_image"
//#endif

typedef enum
{
    inputstring,
    outputstring,
    dividerstring,
    warningstring,
    playermessagestring,
    obituarystring,
    headerstring,
    STRINGTYPES
} stringtype_t;

//#define BINDLISTHEADER          "\tCONTROL\t+ACTION/COMMAND(S)"
//#define CMDLISTHEADER           "\tCCMD\tDESCRIPTION"
//#define CVARLISTHEADER          "\tCVAR\tVALUE\tDESCRIPTION"
//#define MAPLISTHEADER           "\tMAP\tTITLE\tWAD"
//#define MAPSTATSHEADER          "STAT\tVALUE"
//#define PLAYERSTATSHEADER       "STAT\tCURRENT MAP\tTOTAL"
//#define THINGLISTHEADER         "\tTHING\tPOSITION"

typedef struct
{
    char                string[1024];
    unsigned int        count;
    unsigned int        line;
    unsigned int        truncate;
    stringtype_t        stringtype;
    patch_t             *header;
    int                 tabs[4];
    unsigned int        tics;
    char                timestamp[9];
} console_t;

extern patch_t          *bindlist;
extern patch_t          *cmdlist;
extern patch_t          *cvarlist;
extern patch_t          *maplist;
extern patch_t          *mapstats;
extern patch_t          *playerstats;
extern patch_t          *thinglist;

extern console_t        *console;

extern dboolean         consoleactive;
extern int              consoleheight;
extern int              consoledirection;

extern int              consolestrings;
extern size_t           consolestringsmax;

extern char             consolecheat[255];
extern char             consolecheatparm[3];
extern char             consolecmdparm[255];

extern dboolean         forceconsoleblurredraw;

extern dboolean         scrollbardrawn;

typedef struct
{
    char                *input;
    int                 caretpos;
    int                 selectstart;
    int                 selectend;
} undohistory_t;

typedef struct
{
    char                char1;
    char                char2;
    int                 adjust;
} kern_t;

extern const kern_t     kern[];
extern const kern_t     altkern[];

typedef struct
{
    char                text[255];
    int                 game;
} autocomplete_t;

extern autocomplete_t   autocompletelist[];

//void C_Input(const char *string, ...);
//void C_InputNoRepeat(const char *string, ...);
//void C_IntCVAROutput(char *cvar, int value);
//void C_PctCVAROutput(char *cvar, int value);
//void C_StrCVAROutput(char *cvar, char *string);
//void C_Output(const char *string, ...);
//void C_OutputWrap(const char *string, ...);
//void C_OutputNoRepeat(const char *string, ...);
//void C_TabbedOutput(const int tabs[4], const char *string, ...);
//void C_Header(const int tabs[4], patch_t *header, const char *string);
//void C_Warning(const int minwarninglevel, const char *string, ...);
//void C_PlayerMessage(const char *string, ...);
//void C_Obituary(const char *string, ...);
//void C_AddConsoleDivider(void);
//int C_TextWidth(const char *text, const dboolean formatting, const dboolean kerning);
//void C_Init(void);
//void C_ShowConsole(void);
//void C_HideConsole(void);
//void C_HideConsoleFast(void);
//void C_Drawer(void);
//dboolean C_ExecuteInputString(const char *input);
//dboolean C_ValidateInput(char *input);
//dboolean C_Responder(event_t *ev);
//void C_PrintCompileDate(void);
//void C_PrintSDLVersions(void);
void C_UpdateFPS(void);
//void C_UpdateTimer(void);
//char *C_CreateTimeStamp(int index);

#endif
