#if !defined(__DOOMSTRUCT_H__)
#define __DOOMSTRUCT_H__

#include "doomdef.h"
#include "doomdata.h"
#include "doomenum.h"
#include "doomtype.h"
#include "d_think.h"
#include "info.h"
#include "m_fixed.h"
#include "tables.h"
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


// p_mobj.h
// Map Object definition.
typedef struct mobj_s
{
	// List: thinker links.
	thinker_t           thinker;

	// Info for drawing: position.
	fixed_t             x, y, z;

	// More list: links in sector (if needed)
	struct mobj_s       *snext;
	struct mobj_s       **sprev;                // killough 08/10/98: change to ptr-to-ptr

												// More drawing info: to determine current sprite.
	angle_t             angle;                  // orientation
	spritenum_t         sprite;                 // used to find patch_t and flip value
	int                 frame;                  // might be ORed with FF_FULLBRIGHT

												// Interaction info, by BLOCKMAP.
												// Links in blocks (if needed).
	struct mobj_s       *bnext;
	struct mobj_s       **bprev;                // killough 08/11/98: change to ptr-to-ptr

	struct subsector_s  *subsector;

	// The closest interval over all contacted Sectors.
	fixed_t             floorz;
	fixed_t             ceilingz;

	// killough 11/98: the lowest floor over all contacted Sectors.
	fixed_t             dropoffz;

	// For movement checking.
	fixed_t             radius;
	fixed_t             height;

	// Momentums, used to update position.
	fixed_t             momx, momy, momz;

	mobjtype_t          type;
	mobjinfo_t          *info;                  // &mobjinfo[mobj->type]

	int                 tics;                   // state tic counter
	state_t             *state;
	int                 flags;
	int                 flags2;
	int                 flags3;

	int                 health;

	// Movement direction, movement generation (zig-zagging).
	dirtype_t           movedir;                // 0-7
	int                 movecount;              // when 0, select a new dir

												// Thing being chased/attacked (or NULL),
												// also the originator for missiles.
	struct mobj_s       *target;

	// Reaction time: if non 0, don't attack yet.
	// Used by player to freeze a bit after teleporting.
	int                 reactiontime;

	// If >0, the target will be chased
	// no matter what (even if shot)
	int                 threshold;

	// Additional info record for player avatars only.
	// Only valid if type == MT_PLAYER
	struct player_s     *player;

	// For nightmare respawn.
	mapthing_t          spawnpoint;

	// Thing being chased/attacked for tracers.
	struct mobj_s       *tracer;

	// new field: last known enemy -- killough 02/15/98
	struct mobj_s       *lastenemy;

	// For bobbing up and down.
	int                 floatbob;

	void( *colfunc )( void );
	void( *altcolfunc )( void );
	void( *shadowcolfunc )( void );

	int                 shadowoffset;

	// a linked list of sectors where this object appears
	struct msecnode_s   *touching_sectorlist;   // phares 03/14/98

	short               gear;                   // killough 11/98: used in torque simulation

	short               pursuecount;
	short               strafecount;

	int                 bloodsplats;

	int                 blood;

	// [AM] If 1, interpolate this tic. If -1, interpolate next tic.
	int                 interpolate;

	// [AM] Previous position of mobj before think.
	//      Used to interpolate between positions.
	fixed_t             oldx, oldy, oldz;
	angle_t             oldangle;

	fixed_t             nudge;

	int                 pitch;

	int                 id;
	int                 musicid;

	char                name[ 33 ];

	dboolean            madesound;
	mobjtype_t          inflicter;
} mobj_t;

typedef struct bloodsplat_s
{
	fixed_t             x, y;
	struct bloodsplat_s *snext;
	struct bloodsplat_s **sprev;
	int                 patch;
	fixed_t             width;
	struct sector_s     *sector;
	dboolean            flip;
	int                 blood;
	void( *colfunc )( void );
} bloodsplat_t;


// p_pspr.h
typedef struct
{
	state_t *state; // a NULL state means not active
	int     tics;
	fixed_t sx, sy;
} pspdef_t;



#endif