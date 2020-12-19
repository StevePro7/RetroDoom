#if !defined(__C_CMDS_H__)
#define __C_CMDS_H__

#include "doomtype.h"

#define MAXALIASES      256

#define DIVIDERSTRING   "===================================================================================================="

typedef enum
{
    keyboardcontrol = 1,
    mousecontrol    = 2,
    gamepadcontrol  = 3
} controltype_t;

typedef struct
{
    char            *control;
    controltype_t   type;
    int             value;
} control_t;

typedef struct
{
    char        *action;
    dboolean    hideconsole;
    void        (*func)(void);
    void        *keyboard1;
    void        *keyboard2;
    void        *mouse1;
    void        *gamepad1;
    void        *gamepad2;
} action_t;

typedef enum
{
    CT_CCMD  = 1,
    CT_CVAR  = 2,
    CT_CHEAT = 3
} cmdtype_t;

enum
{
    CF_NONE     =   0,
    CF_BOOLEAN  =   1,
    CF_FLOAT    =   2,
    CF_INTEGER  =   4,
    CF_PERCENT  =   8,
    CF_STRING   =  16,
    CF_TIME     =  32,
    CF_OTHER    =  64,
    CF_READONLY = 128
};

typedef struct
{
    char        *name;
    char        *alternate;
    dboolean    (*func1)(char *cmd, char *parms);
    void        (*func2)(char *cmd, char *parms);
    dboolean    parameters;
    cmdtype_t   type;
    int         flags;
    void        *variable;
    int         aliases;
    int         minimumvalue;
    int         maximumvalue;
    char        *format;
    char        *description;
    float       defaultnumber;
    char        *defaultstring;
} consolecmd_t;

typedef struct
{
    char    name[128];
    char    string[128];
} alias_t;

extern action_t         actions[];
extern const control_t  controls[];
extern consolecmd_t     consolecmds[];
extern alias_t          aliases[MAXALIASES];
extern dboolean         executingalias;
extern dboolean         resettingcvar;
extern dboolean         vanilla;
extern dboolean         togglingvanilla;
extern dboolean         massacre;

void alias_cmd_func2(char *cmd, char *parms);
void bind_cmd_func2(char *cmd, char *parms);

dboolean C_ExecuteAlias(const char *alias);
void C_DumpConsoleStringToFile(int index);

#endif
