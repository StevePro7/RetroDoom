#if !defined(__DOOMSTRUCT_H__)
#define __DOOMSTRUCT_H__

#include "doomdef.h"
#include "doomenum.h"
#include "doomtype.h"
#include "d_think.h"
#include <stdio.h>

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


// w_file.h
typedef struct wadfile_s wadfile_t;

struct wadfile_s
{
	FILE        *fstream;
	dboolean    freedoom;
	char        path[ MAX_PATH ];
	int         type;
};


// w_wad.h
typedef struct lumpinfo_s lumpinfo_t;

struct lumpinfo_s
{
	char        name[ 9 ];
	int         size;
	void        *cache;

	// killough 01/31/98: hash table fields, used for ultra-fast hash table lookup
	int         index;
	int         next;

	int         position;

	wadfile_t   *wadfile;
};


// states.h
typedef struct
{
	spritenum_t sprite;
	long        frame;
	long        tics;
	actionf_t   action;
	statenum_t  nextstate;
	long        misc1;
	long        misc2;
	dboolean    translucent;
	dboolean    dehacked;
} state_t;



#endif