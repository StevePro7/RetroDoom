#if !defined(__DOOMSTRUCT_H__)
#define __DOOMSTRUCT_H__

#include "doomdef.h"
#include "doomdata.h"
#include "doomenum.h"
#include "doomtype.h"
#include "d_think.h"
#include "d_ticcmd.h"
#include "info.h"
#include "m_fixed.h"
//#include "r_defs.h"
#include "tables.h"
#include <stdio.h>


// r_defs.h
#if defined(_MSC_VER) || defined(__GNUC__)
#pragma pack(push, 1)
#endif

// Patches.
// A patch holds one or more columns.
// Patches are used for sprites and all masked pictures,
// and we compose textures from the TEXTURE1/2 lists
// of patches.
typedef struct
{
	short               width;          // bounding box size
	short               height;
	short               leftoffset;     // pixels to the left of origin
	short               topoffset;      // pixels below the origin
	int                 columnofs[ 8 ];   // only [width] used
										  // the [0] is &columnofs[width]
} PACKEDATTR patch_t;

#if defined(_MSC_VER) || defined(__GNUC__)
#pragma pack(pop)
#endif


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


// d_player.h
//
// Extended player object info: player_t
//
typedef struct player_s
{
	mobj_t          *mo;
	playerstate_t   playerstate;
	ticcmd_t        cmd;

	// Determine POV,
	//  including viewpoint bobbing during movement.
	// Focal origin above r.z
	fixed_t         viewz;

	// Base height above floor for viewz.
	fixed_t         viewheight;

	// Bob/squat speed.
	fixed_t         deltaviewheight;

	// killough 10/98: used for realistic bobbing (i.e. not simply overall speed)
	// mo->momx and mo->momy represent true momenta experienced by player.
	// This only represents the thrust that the player applies himself.
	// This avoids anomalies with such things as BOOM ice and conveyors.
	fixed_t         momx, momy;     // killough 10/98

									// This is only used between levels,
									// mo->health is used during levels.
	int             health;

	int             armorpoints;

	// Armor type is 0-2.
	armortype_t     armortype;

	// Power ups. invinc and invis are tic counters.
	int             powers[ NUMPOWERS ];

	int             cards[ NUMCARDS ];
	int             neededcard;
	int             neededcardflash;
	dboolean        backpack;

	weapontype_t    readyweapon;

	// Is wp_nochange if not changing.
	weapontype_t    pendingweapon;

	int             weaponowned[ NUMWEAPONS ];
	int             ammo[ NUMAMMO ];
	int             maxammo[ NUMAMMO ];

	// True if button down last tic.
	dboolean        attackdown;
	dboolean        usedown;

	// Bit flags, for cheats and debug.
	// See cheat_t, above.
	int             cheats;

	// Refired shots are less accurate.
	int             refire;

	// For intermission stats.
	int             killcount;
	int             itemcount;
	int             secretcount;

	// Hint messages.
	char            *message;
	char            prevmessage[ 133 ];

	// For screen flashing (red or bright).
	int             damagecount;
	int             bonuscount;

	// Who did damage (NULL for floors/ceilings).
	mobj_t          *attacker;

	// So gun flashes light up areas.
	int             extralight;

	// Current PLAYPAL, ???
	//  can be set to REDCOLORMAP for pain, etc.
	int             fixedcolormap;

	// Overlay view sprites (gun, etc).
	pspdef_t        psprites[ NUMPSPRITES ];

	// True if secret level has been done.
	dboolean        didsecret;

	weapontype_t    preferredshotgun;
	weapontype_t    fistorchainsaw;
	dboolean        invulnbeforechoppers;
	dboolean        chainsawbeforechoppers;
	weapontype_t    weaponbeforechoppers;

	// [AM] Previous position of viewz before think.
	//      Used to interpolate between camera positions.
	angle_t         oldviewz;

	int             lookdir;
	int             oldlookdir;

	unsigned int    jumptics;

	fixed_t         recoil;
	fixed_t         oldrecoil;

	fixed_t         bounce;
	fixed_t         bouncemax;

	// For playerstats CCMD
	int             damageinflicted;
	int             damagereceived;
	int             cheated;
	int             shotssuccessful[ NUMWEAPONS ];
	int             shotsfired[ NUMWEAPONS ];
	int             deaths;
	int             suicides;
	int             mobjcount[ NUMMOBJTYPES ];
	int             distancetraveled;
	int             gamessaved;
	int             itemspickedup_ammo_bullets;
	int             itemspickedup_ammo_cells;
	int             itemspickedup_ammo_rockets;
	int             itemspickedup_ammo_shells;
	int             itemspickedup_armor;
	int             itemspickedup_health;
} player_t;

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


// st_lib.h
//
// Typedefs of widgets
//

// Number widget
typedef struct
{
	// upper right-hand corner
	//  of the number (right-justified)
	int         x, y;

	// max # of digits in number
	int         width;

	// pointer to current value
	int         *num;

	// list of patches for 0-9
	patch_t     **p;

	// user data
	int         data;
} st_number_t;

// Percent widget ("child" of number widget,
//  or, more precisely, contains a number widget.)
typedef struct
{
	// number information
	st_number_t n;

	// percent sign graphic
	patch_t     *p;
} st_percent_t;

// Multiple Icon widget
typedef struct
{
	// center-justified location of icons
	int         x, y;

	// last icon number
	int         oldinum;

	// pointer to current icon
	int         *inum;

	// list of icons
	patch_t     **p;
} st_multicon_t;


// m_cheat.h
typedef struct
{
	// settings for this cheat
	char        *sequence;
	int         parameter_chars;

	// state used during the game
	size_t      chars_read;
	int         param_chars_read;
	char        parameter_buf[ 5 ];

	int         timeout;

	dboolean    movekey;
} cheatseq_t;


// r_defs.h
//
// INTERNAL MAP TYPES
//  used by play and refresh
//

//
// Your plain vanilla vertex.
// Note: transformed values not buffered locally,
//  like some DOOM-alikes ("wt", "WebView") did.
//
typedef struct
{
	fixed_t             x, y;
} vertex_t;

// Each sector has a degenmobj_t in its center
//  for sound origin purposes.
// I suppose this does not handle sound from
//  moving objects (doppler), because
//  position is prolly just buffered, not
//  updated.
typedef struct
{
	thinker_t           thinker;        // not used for anything
	fixed_t             x, y, z;
} degenmobj_t;

//
// The SECTORS record, at runtime.
// Stores things/mobjs.
//
typedef struct sector_s
{
	int                 id;

	fixed_t             floorheight;
	fixed_t             ceilingheight;
	int                 nexttag;
	int                 firsttag;
	short               special;
	short               tag;

	// 0 = untraversed, 1,2 = sndlines -1
	int                 soundtraversed;

	// thing that made a sound (or null)
	mobj_t              *soundtarget;

	// mapblock bounding box for height changes
	int                 blockbox[ 4 ];

	// origin for any sounds played by the sector
	degenmobj_t         soundorg;

	// if == validcount, already checked
	int                 validcount;

	// list of mobjs in sector
	mobj_t              *thinglist;

	bloodsplat_t        *splatlist;

	// thinker_t for reversible actions
	void                *floordata;             // jff 02/22/98 make thinkers on
	void                *ceilingdata;           // floors and ceilings, independent of one another

												// list of mobjs that are at least partially in the sector
												// thinglist is a subset of touching_thinglist
	struct msecnode_s   *touching_thinglist;    // phares 03/14/98

	int                 linecount;
	struct line_s       **lines;                // [linecount] size

	int                 cachedheight;

	// [AM] Previous position of floor and ceiling before
	//      think. Used to interpolate between positions.
	fixed_t             oldfloorheight;
	fixed_t             oldceilingheight;

	// [AM] Gametic when the old positions were recorded.
	//      Has a dual purpose; it prevents movement thinkers
	//      from storing old positions twice in a tic, and
	//      prevents the renderer from attempting to interpolate
	//      if old values were not updated recently.
	int                 oldgametime;

	// [AM] Interpolated floor and ceiling height.
	//      Calculated once per tic and used inside
	//      the renderer.
	fixed_t             interpfloorheight;
	fixed_t             interpceilingheight;

	// jff 2/26/98 lockout machinery for stairbuilding
	int                 stairlock;      // -2 on first locked -1 after thinker done 0 normally
	int                 prevsec;        // -1 or number of sector for previous step
	int                 nextsec;        // -1 or number of next step sector

										// killough 03/07/98: floor and ceiling texture offsets
	fixed_t             floorxoffset, flooryoffset;
	fixed_t             ceilingxoffset, ceilingyoffset;

	// killough 04/11/98: support for lightlevels coming from another sector
	struct sector_s     *floorlightsec;
	struct sector_s     *ceilinglightsec;

	short               floorpic;
	short               ceilingpic;
	short               lightlevel;
	short               oldlightlevel;

	// killough 03/07/98: support flat heights drawn at another sector's heights
	struct sector_s     *heightsec;     // other sector, or NULL if no other sector

										// killough 04/04/98: dynamic colormaps
	int                 bottommap;
	int                 midmap;
	int                 topmap;

	// killough 08/28/98: friction is a sector property, not an mobj property.
	// these fields used to be in mobj_t, but presented performance problems
	// when processed as mobj properties. Fix is to make them sector properties.
	int                 friction;
	int                 movefactor;

	// killough 10/98: support skies coming from sidedefs. Allows scrolling
	// skies and other effects. No "level info" kind of lump is needed,
	// because you can use an arbitrary number of skies per level with this
	// method. This field only applies when skyflatnum is used for floorpic
	// or ceilingpic, because the rest of DOOM needs to know which is sky
	// and which isn't, etc.
	int                 sky;

	terraintype_t       terraintype;

	dboolean            islift;
} sector_t;

//
// The SideDef.
//
typedef struct
{
	// add this to the calculated texture column
	fixed_t             textureoffset;

	// add this to the calculated texture top
	fixed_t             rowoffset;

	// Texture indices.
	// We do not maintain names here.
	short               toptexture;
	short               bottomtexture;
	short               midtexture;

	// Sector the SideDef is facing.
	sector_t            *sector;

	// killough 04/04/98, 04/11/98: highest referencing special linedef's type,
	// or lump number of special effect. Allows texture names to be overloaded
	// for other functions.
	int                 special;

	dboolean            missingtoptexture;
	dboolean            missingmidtexture;
	dboolean            missingbottomtexture;
} side_t;

typedef struct line_s
{
	int                 id;

	// Vertexes, from v1 to v2.
	vertex_t            *v1;
	vertex_t            *v2;

	// Precalculated v2 - v1 for side checking.
	fixed_t             dx, dy;

	// Animation related.
	unsigned short      flags;

	unsigned short      special;
	short               tag;

	// Visual appearance: SideDefs.
	//  sidenum[1] will be -1 if one sided
	unsigned short      sidenum[ 2 ];

	// Neat. Another bounding box, for the extent
	//  of the LineDef.
	fixed_t             bbox[ 4 ];

	// To aid move clipping.
	slopetype_t         slopetype;

	// Front and back sector.
	// Note: redundant? Can be retrieved from SideDefs.
	sector_t            *frontsector;
	sector_t            *backsector;

	// if == validcount, already checked
	int                 validcount;

	int                 tranlump;       // killough 04/11/98: translucency filter, -1 == none

	int                 nexttag;
	int                 firsttag;

	int                 r_validcount;   // cph: if == gametime, r_flags already done

	enum
	{
		RF_NONE = 0,               // cph:
		RF_TOP_TILE = 1,               // Upper texture needs tiling
		RF_MID_TILE = 2,               // Midtexture needs tiling
		RF_BOT_TILE = 4,               // Lower texture needs tiling
		RF_IGNORE = 8,               // Renderer can skip this line
		RF_CLOSED = 16                // Line blocks view
	} r_flags;

	// sound origin for switches/buttons
	degenmobj_t         soundorg;
} line_t;

//
// A SubSector.
// References a Sector.
// Basically, this is a list of LineSegs,
//  indicating the visible walls that define
//  (all or some) sides of a convex BSP leaf.
//
typedef struct subsector_s
{
	sector_t            *sector;
	int                 numlines;
	int                 firstline;
} subsector_t;

// phares 03/14/98
//
// Sector list node showing all sectors an object appears in.
//
// There are two threads that flow through these nodes. The first thread
// starts at touching_thinglist in a sector_t and flows through the m_snext
// links to find all mobjs that are entirely or partially in the sector.
// The second thread starts at touching_sectorlist in an mobj_t and flows
// through the m_tnext links to find all sectors a thing touches. This is
// useful when applying friction or push effects to sectors. These effects
// can be done as thinkers that act upon all objects touching their sectors.
// As an mobj moves through the world, these nodes are created and
// destroyed, with the links changed appropriately.
//
// For the links, NULL means top or end of list.
//
typedef struct msecnode_s
{
	sector_t            *m_sector;      // a sector containing this object
	struct mobj_s       *m_thing;       // this object
	struct msecnode_s   *m_tprev;       // prev msecnode_t for this thing
	struct msecnode_s   *m_tnext;       // next msecnode_t for this thing
	struct msecnode_s   *m_sprev;       // prev msecnode_t for this sector
	struct msecnode_s   *m_snext;       // next msecnode_t for this sector
	dboolean            visited;        // killough 04/04/98, 4/7/98: used in search algorithms
} msecnode_t;

//
// The LineSeg.
//
typedef struct
{
	vertex_t            *v1;
	vertex_t            *v2;

	fixed_t             offset;

	angle_t             angle;

	int64_t             dx, dy;

	int64_t             length;

	side_t              *sidedef;
	line_t              *linedef;

	// Sector references.
	// Could be retrieved from linedef, too.
	// backsector is NULL for one sided lines
	sector_t            *frontsector;
	sector_t            *backsector;

	int                 fakecontrast;
} seg_t;

//
// BSP node.
//
typedef struct
{
	// Partition line.
	fixed_t             x, y;
	fixed_t             dx, dy;

	// Bounding box for each child.
	fixed_t             bbox[ 2 ][ 4 ];

	// If NF_SUBSECTOR its a subsector.
	int                 children[ 2 ];
} node_t;

#if defined(_MSC_VER) || defined(__GNUC__)
#pragma pack(push, 1)
#endif

// posts are runs of non masked source pixels
typedef struct
{
	byte               topdelta;        // -1 is the last post in a column
	byte               length;          // length data bytes follows
} PACKEDATTR post_t;

#if defined(_MSC_VER) || defined(__GNUC__)
#pragma pack(pop)
#endif

// column_t is a list of 0 or more post_t, (byte)-1 terminated
typedef post_t column_t;

//
// OTHER TYPES
//

// This could be wider for >8 bit display.
// Indeed, true color support is possible
//  precalculating 24bpp lightmap/colormap LUT.
//  from darkening PLAYPAL to all black.
// Could even use more than 32 levels.
typedef byte lighttable_t;

typedef struct
{
	seg_t               *curline;
	int                 x1;
	int                 x2;

	fixed_t             scale;
	fixed_t             scalestep;

	fixed_t             minscale;
	fixed_t             maxscale;

	// 0=none, 1=bottom, 2=top, 3=both
	int                 silhouette;

	// Pointers to lists for sprite clipping,
	//  all three adjusted so [x1] is first value.
	int                 *sprtopclip;
	int                 *sprbottomclip;
	int                 *maskedtexturecol;
} drawseg_t;



// A vissprite_t is a thing
//  that will be drawn during a refresh.
// I.e. a sprite object that is partly visible.
typedef struct
{
	int                 x1;
	int                 x2;

	// for line side calculation
	fixed_t             gx, gy;

	// global bottom/top for silhouette clipping
	fixed_t             gz;
	fixed_t             gzt;

	// horizontal position of x1
	fixed_t             startfrac;

	fixed_t             scale;

	// negative if flipped
	fixed_t             xiscale;

	fixed_t             texturemid;
	int                 patch;

	// for color translation and shadow draw,
	//  maxbright frames as well
	lighttable_t        *colormap;

	mobj_t              *mobj;

	void( *colfunc )( void );

	// foot clipping
	fixed_t             footclip;

	// killough 03/27/98: height sector for underwater/fake ceiling support
	sector_t            *heightsec;

	int                 shadowpos;
} vissprite_t;

typedef struct
{
	int                 x1;
	int                 x2;
	fixed_t             gx, gy;
	fixed_t             startfrac;
	fixed_t             scale;
	fixed_t             xiscale;
	fixed_t             texturemid;
	int                 patch;
	lighttable_t        *colormap;
	void( *colfunc )( void );
	fixed_t             blood;
} bloodsplatvissprite_t;

//
// Sprites are patches with a special naming convention
//  so they can be recognized by R_InitSprites.
// The base name is NNNNFx or NNNNFxFx, with
//  x indicating the rotation, x = 0, 1-7.
// The sprite and frame specified by a thing_t
//  is range checked at run time.
// A sprite is a patch_t that is assumed to represent
//  a three dimensional object and may have multiple
//  rotations pre-drawn.
// Horizontal flipping is used to save space,
//  thus NNNNF2F5 defines a mirrored patch.
// Some sprites will only have one picture used
// for all views: NNNNF0
//
typedef struct
{
	// If false use 0 for any position.
	// Note: as eight entries are available,
	//  we might as well insert the same name eight times.
	int                 rotate;

	// Lump to use for view angles 0-7.
	short               lump[ 16 ];

	// Flip bit (1 = flip) to use for view angles 0-15.
	unsigned short      flip;
} spriteframe_t;

//
// A sprite definition:
//  a number of animation frames.
//
typedef struct
{
	int                 numframes;
	spriteframe_t       *spriteframes;
} spritedef_t;

//
// Now what is a visplane, anyway?
//
typedef struct visplane_s
{
	// Next visplane in hash chain -- killough
	struct visplane_s   *next;

	int                 picnum;
	int                 lightlevel;
	int                 left;
	int                 right;
	fixed_t             height;

	// killough 02/28/98: Support scrolling flats
	fixed_t             xoffset, yoffset;

	// leave pads for [minx - 1]/[maxx + 1]
	unsigned int        pad1;

	unsigned int        top[ SCREENWIDTH ];

	unsigned int        pad2;
	unsigned int        pad3;

	unsigned int        bottom[ SCREENWIDTH ];

	unsigned int        pad4;

	dboolean            modified;
} visplane_t;


// c_console.h
typedef struct
{
	char                string[ 1024 ];
	unsigned int        count;
	unsigned int        line;
	unsigned int        truncate;
	stringtype_t        stringtype;
	patch_t             *header;
	int                 tabs[ 4 ];
	unsigned int        tics;
	char                timestamp[ 9 ];
} console_t;

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

typedef struct
{
	char                text[ 255 ];
	int                 game;
} autocomplete_t;


// m_menu.h
typedef struct
{
	short           status;
	char            name[ 10 ];
	void( *routine )( int choice );
	char            **text;
} menuitem_t;

typedef struct menu_s
{
	short           numitems;
	struct menu_s   *prevMenu;
	menuitem_t      *menuitems;
	void( *routine )( void );
	short           x;
	short           y;
	int             lastOn;
	dboolean        change;
} menu_t;


#endif
