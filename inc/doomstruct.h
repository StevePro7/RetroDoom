#if !defined(__DOOMSTRUCT_H__)
#define __DOOMSTRUCT_H__

#include "doomenum.h"
#include "doomtype.h"

// d_player.h
//
// INTERMISSION
// Structure passed e.g. to WI_Start(wb)
//
typedef struct
{
	int             epsd;           // episode # (0-2)

									// if true, splash the secret level
	dboolean        didsecret;

	// previous and next levels, origin 0
	int             last;
	int             next;

	int             maxkills;
	int             maxitems;
	int             maxsecret;

	// the par time
	int             partime;

	int             skills;
	int             sitems;
	int             ssecret;
	int             stime;
} wbstartstruct_t;


// d_deh.h
typedef struct
{
	char    **ppstr;        // doubly indirect pointer to string
	char    *lookup;        // pointer to lookup string name
	int     assigned;       // [BH] counter indicating string has been assigned
} deh_strs;


// c_cmds.h
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
	void( *func )( void );
	void        *keyboard1;
	void        *keyboard2;
	void        *mouse1;
	void        *gamepad1;
	void        *gamepad2;
} action_t;

typedef struct
{
	char        *name;
	char        *alternate;
	dboolean( *func1 )( char *cmd, char *parms );
	void( *func2 )( char *cmd, char *parms );
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
	char    name[ 128 ];
	char    string[ 128 ];
} alias_t;


#endif