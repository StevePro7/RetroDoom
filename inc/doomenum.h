#if !defined(__DOOMENUM_H__)
#define __DOOMENUM_H__

#include "doomdef.h"

// doomdef.h
// Game mode handling - identify IWAD version
//  to handle IWAD dependent animations etc.
typedef enum
{
	shareware,          // DOOM 1 shareware, E1, M9
	registered,         // DOOM 1 registered, E3, M27
	commercial,         // DOOM 2 retail, E1 M34
	retail,             // DOOM 1 retail, E4, M36
	indetermined        // Well, no IWAD found.
} GameMode_t;

// Mission packs - might be useful for TC stuff?
typedef enum
{
	doom,               // DOOM 1
	doom2,              // DOOM 2
	pack_tnt,           // TNT mission pack
	pack_plut,          // Plutonia pack
	pack_nerve,         // No Rest for the Living

	none
} GameMission_t;

// The current state of the game: whether we are
// playing, gazing at the intermission screen,
// the game final animation, or title screen.
typedef enum
{
	GS_NONE = -1,
	GS_LEVEL,
	GS_INTERMISSION,
	GS_FINALE,
	GS_TITLESCREEN
} gamestate_t;

typedef enum
{
	sk_none = -1,
	sk_baby,
	sk_easy,
	sk_medium,
	sk_hard,
	sk_nightmare
} skill_t;

//
// Key cards.
//
typedef enum
{
	it_bluecard,
	it_yellowcard,
	it_redcard,
	it_blueskull,
	it_yellowskull,
	it_redskull,
	NUMCARDS,
	it_allkeys
} card_t;

// The defined weapons,
//  including a marker indicating
//  user has not changed weapon.
typedef enum
{
	wp_fist,
	wp_pistol,
	wp_shotgun,
	wp_chaingun,
	wp_missile,
	wp_plasma,
	wp_bfg,
	wp_chainsaw,
	wp_supershotgun,
	NUMWEAPONS,

	// No pending weapon change.
	wp_nochange
} weapontype_t;

// Ammunition types defined.
typedef enum
{
	am_clip,    // Pistol/chaingun ammo.
	am_shell,   // Shotgun/double-barreled shotgun.
	am_cell,    // Plasma rifle, BFG.
	am_misl,    // Missile launcher.
	NUMAMMO,

	am_noammo
} ammotype_t;

// Power up artifacts.
enum
{
	pw_none,
	pw_invulnerability,
	pw_strength,
	pw_invisibility,
	pw_ironfeet,
	pw_allmap,
	pw_infrared,
	NUMPOWERS
};

//
// Power up durations,
//  how many seconds until expiration,
//  assuming TICRATE is 35 tics/second.
//
enum
{
	INVULNTICS = 30 * TICRATE,
	INVISTICS = 60 * TICRATE,
	INFRATICS = 120 * TICRATE,
	IRONTICS = 60 * TICRATE
};


// d_deh.h
enum
{
	p_QUITMSG = 5, p_GOTARMOR = 33, p_GOTMEGA, p_GOTHTHBONUS, p_GOTARMBONUS, p_GOTSTIM, p_GOTMEDINEED,
	p_GOTMEDIKIT, p_GOTSUPER, p_GOTBLUECARD, p_GOTYELWCARD, p_GOTREDCARD, p_GOTBLUESKUL, p_GOTYELWSKUL,
	p_GOTREDSKUL, p_GOTREDSKULL, p_GOTINVUL, p_GOTBERSERK, p_GOTINVIS, p_GOTSUIT, p_GOTMAP, p_GOTVISOR,
	p_GOTCLIP, p_GOTCLIPBOX, p_GOTROCKET, p_GOTROCKETX2, p_GOTROCKBOX, p_GOTCELL, p_GOTCELLX2, p_GOTCELLBOX,
	p_GOTSHELLS, p_GOTSHELLSX2, p_GOTSHELLBOX, p_GOTBACKPACK, p_GOTBFG9000, p_GOTCHAINGUN, p_GOTCHAINSAW,
	p_GOTLAUNCHER, p_GOTMSPHERE, p_GOTPLASMA, p_GOTSHOTGUN, p_GOTSHOTGUN2, p_PD_BLUEO, p_PD_REDO, p_PD_YELLOWO,
	p_PD_BLUEK, p_PD_REDK, p_PD_YELLOWK
};


// d_player.h
typedef enum
{
	armortype_none,
	armortype_green,
	armortype_blue
} armortype_t;

//
// Player states.
//
typedef enum
{
	// Playing or camping.
	PST_LIVE,

	// Dead on the ground, view follows killer.
	PST_DEAD,

	// Ready to restart/respawn???
	PST_REBORN
} playerstate_t;

//
// Player internal flags, for cheats and debug.
//
enum
{
	// No clipping, walk through barriers.
	CF_NOCLIP = 1,

	// No damage, no health loss.
	CF_GODMODE = 2,

	CF_NOTARGET = 4,

	CF_MYPOS = 8,

	CF_ALLMAP = 16,

	CF_ALLMAP_THINGS = 32,

	CF_CHOPPERS = 64,

	CF_BUDDHA = 128
};


// doomdata.h
// Lump order in a map WAD: each map needs a couple of lumps
// to provide a complete scene geometry description.
enum
{
	ML_LABEL,       // A separator, name, ExMx or MAPxx
	ML_THINGS,      // Monsters, items...
	ML_LINEDEFS,    // LineDefs, from editing
	ML_SIDEDEFS,    // SideDefs, from editing
	ML_VERTEXES,    // Vertexes, edited and BSP splits generated
	ML_SEGS,        // LineSegs, from LineDefs split by BSP
	ML_SSECTORS,    // SubSectors, list of LineSegs
	ML_NODES,       // BSP nodes
	ML_SECTORS,     // Sectors, from editing
	ML_REJECT,      // LUT, sector-sector visibility
	ML_BLOCKMAP     // LUT, motion clipping, walls/grid element
};


// info.h
typedef enum
{
	MT_NULL = -1,
	MT_PLAYER,
	MT_POSSESSED,
	MT_SHOTGUY,
	MT_VILE,
	MT_FIRE,
	MT_UNDEAD,
	MT_TRACER,
	MT_SMOKE,
	MT_FATSO,
	MT_FATSHOT,
	MT_CHAINGUY,
	MT_TROOP,
	MT_SERGEANT,
	MT_SHADOWS,
	MT_HEAD,
	MT_BRUISER,
	MT_BRUISERSHOT,
	MT_KNIGHT,
	MT_SKULL,
	MT_SPIDER,
	MT_BABY,
	MT_CYBORG,
	MT_PAIN,
	MT_WOLFSS,
	MT_KEEN,
	MT_BOSSBRAIN,
	MT_BOSSSPIT,
	MT_BOSSTARGET,
	MT_SPAWNSHOT,
	MT_SPAWNFIRE,
	MT_BARREL,
	MT_TROOPSHOT,
	MT_HEADSHOT,
	MT_ROCKET,
	MT_PLASMA,
	MT_BFG,
	MT_ARACHPLAZ,
	MT_PUFF,
	MT_BLOOD,
	MT_TFOG,
	MT_IFOG,
	MT_TELEPORTMAN,
	MT_EXTRABFG,
	MT_MISC0,
	MT_MISC1,
	MT_MISC2,
	MT_MISC3,
	MT_MISC4,
	MT_MISC5,
	MT_MISC6,
	MT_MISC7,
	MT_MISC8,
	MT_MISC9,
	MT_MISC10,
	MT_MISC11,
	MT_MISC12,
	MT_INV,
	MT_MISC13,
	MT_INS,
	MT_MISC14,
	MT_MISC15,
	MT_MISC16,
	MT_MEGA,
	MT_CLIP,
	MT_MISC17,
	MT_MISC18,
	MT_MISC19,
	MT_MISC20,
	MT_MISC21,
	MT_MISC22,
	MT_MISC23,
	MT_MISC24,
	MT_MISC25,
	MT_CHAINGUN,
	MT_MISC26,
	MT_MISC27,
	MT_MISC28,
	MT_SHOTGUN,
	MT_SUPERSHOTGUN,
	MT_MISC29,
	MT_MISC30,
	MT_MISC31,
	MT_MISC32,
	MT_MISC33,
	MT_MISC34,
	MT_MISC35,
	MT_MISC36,
	MT_MISC37,
	MT_MISC38,
	MT_MISC39,
	MT_MISC40,
	MT_MISC41,
	MT_MISC42,
	MT_MISC43,
	MT_MISC44,
	MT_MISC45,
	MT_MISC46,
	MT_MISC47,
	MT_MISC48,
	MT_MISC49,
	MT_MISC50,
	MT_MISC51,
	MT_MISC52,
	MT_MISC53,
	MT_MISC54,
	MT_MISC55,
	MT_MISC56,
	MT_MISC57,
	MT_MISC58,
	MT_MISC59,
	MT_MISC60,
	MT_MISC61,
	MT_MISC62,
	MT_MISC63,
	MT_MISC64,
	MT_MISC65,
	MT_MISC66,
	MT_MISC67,
	MT_MISC68,
	MT_MISC69,
	MT_MISC70,
	MT_MISC71,
	MT_MISC72,
	MT_MISC73,
	MT_MISC74,
	MT_MISC75,
	MT_MISC76,
	MT_MISC77,
	MT_MISC78,
	MT_MISC79,
	MT_MISC80,
	MT_MISC81,
	MT_MISC82,
	MT_MISC83,
	MT_MISC84,
	MT_MISC85,
	MT_MISC86,

	MT_PUSH,    // controls push source                     // phares
	MT_PULL,    // controls pull source                     // phares 03/20/98

	MT_DOGS,    // killough 07/19/98: Marine's best friend

	MT_PLASMA1, // killough 07/11/98: first of alternating beta plasma fireballs
	MT_PLASMA2, // killough 07/11/98: second of alternating beta plasma fireballs
	MT_SCEPTRE, // killough 07/11/98: evil sceptre in beta version
	MT_BIBLE,   // killough 07/11/98: unholy bible in beta version

	MT_MUSICSOURCE,
	MT_GIBDTH,

	// [BH] DOOM Retro mobjs
	MT_BLUEBLOOD,
	MT_GREENBLOOD,
	MT_FUZZYBLOOD,
	MT_TRAIL,

	// [BH] Mobjs 150 to 249 (100 extra mobjs to use in DeHackEd patches)
	MT_EXTRA00, MT_EXTRA01, MT_EXTRA02, MT_EXTRA03, MT_EXTRA04,
	MT_EXTRA05, MT_EXTRA06, MT_EXTRA07, MT_EXTRA08, MT_EXTRA09,
	MT_EXTRA10, MT_EXTRA11, MT_EXTRA12, MT_EXTRA13, MT_EXTRA14,
	MT_EXTRA15, MT_EXTRA16, MT_EXTRA17, MT_EXTRA18, MT_EXTRA19,
	MT_EXTRA20, MT_EXTRA21, MT_EXTRA22, MT_EXTRA23, MT_EXTRA24,
	MT_EXTRA25, MT_EXTRA26, MT_EXTRA27, MT_EXTRA28, MT_EXTRA29,
	MT_EXTRA30, MT_EXTRA31, MT_EXTRA32, MT_EXTRA33, MT_EXTRA34,
	MT_EXTRA35, MT_EXTRA36, MT_EXTRA37, MT_EXTRA38, MT_EXTRA39,
	MT_EXTRA40, MT_EXTRA41, MT_EXTRA42, MT_EXTRA43, MT_EXTRA44,
	MT_EXTRA45, MT_EXTRA46, MT_EXTRA47, MT_EXTRA48, MT_EXTRA49,
	MT_EXTRA50, MT_EXTRA51, MT_EXTRA52, MT_EXTRA53, MT_EXTRA54,
	MT_EXTRA55, MT_EXTRA56, MT_EXTRA57, MT_EXTRA58, MT_EXTRA59,
	MT_EXTRA60, MT_EXTRA61, MT_EXTRA62, MT_EXTRA63, MT_EXTRA64,
	MT_EXTRA65, MT_EXTRA66, MT_EXTRA67, MT_EXTRA68, MT_EXTRA69,
	MT_EXTRA70, MT_EXTRA71, MT_EXTRA72, MT_EXTRA73, MT_EXTRA74,
	MT_EXTRA75, MT_EXTRA76, MT_EXTRA77, MT_EXTRA78, MT_EXTRA79,
	MT_EXTRA80, MT_EXTRA81, MT_EXTRA82, MT_EXTRA83, MT_EXTRA84,
	MT_EXTRA85, MT_EXTRA86, MT_EXTRA87, MT_EXTRA88, MT_EXTRA89,
	MT_EXTRA90, MT_EXTRA91, MT_EXTRA92, MT_EXTRA93, MT_EXTRA94,
	MT_EXTRA95, MT_EXTRA96, MT_EXTRA97, MT_EXTRA98, MT_EXTRA99,

	NUMMOBJTYPES
} mobjtype_t;


// m_config.h
enum
{
	crosshair_none,
	crosshair_cross,
	crosshair_dot
};

enum
{
	r_blood_none,
	r_blood_red,
	r_blood_all,
	r_blood_green,
	r_blood_nofuzz
};

enum
{
	r_detail_low,
	r_detail_high
};

enum
{
	units_imperial,
	units_metric
};

enum
{
	vid_vsync_adaptive = -1,
	vid_vsync_off,
	vid_vsync_on
};

typedef enum
{
	DEFAULT_INT32,
	DEFAULT_UINT64,
	DEFAULT_INT32_PERCENT,
	DEFAULT_STRING,
	DEFAULT_FLOAT,
	DEFAULT_FLOAT_PERCENT,
	DEFAULT_OTHER
} default_type_t;

typedef enum
{
	NOVALUEALIAS,
	BOOLVALUEALIAS,
	DETAILVALUEALIAS,
	GAMMAVALUEALIAS,
	BLOODVALUEALIAS,
	UNITSVALUEALIAS,
	CAPVALUEALIAS,
	SKYVALUEALIAS,
	SCALEVALUEALIAS,
	FACEBACKVALUEALIAS,
	ARMORTYPEVALUEALIAS,
	CROSSHAIRVALUEALIAS,
	VSYNCVALUEALIAS
} valuealias_type_t;


// p_mobj.h
//
// Misc. mobj flags
//
enum
{
	// Call P_SpecialThing when touched.
	MF_SPECIAL = 0x00000001,
	// Blocks.
	MF_SOLID = 0x00000002,
	// Can be hit.
	MF_SHOOTABLE = 0x00000004,
	// Don't use the sector links (invisible but touchable).
	MF_NOSECTOR = 0x00000008,
	// Don't use the blocklinks (inert but displayable)
	MF_NOBLOCKMAP = 0x00000010,

	// Not to be activated by sound, deaf monster.
	MF_AMBUSH = 0x00000020,
	// Will try to attack right back.
	MF_JUSTHIT = 0x00000040,
	// Will take at least one step before attacking.
	MF_JUSTATTACKED = 0x00000080,
	// On level spawning (initial position),
	//  hang from ceiling instead of stand on floor.
	MF_SPAWNCEILING = 0x00000100,
	// Don't apply gravity (every tic),
	//  that is, object will float, keeping current height
	//  or changing it actively.
	MF_NOGRAVITY = 0x00000200,

	// Movement flags.
	// This allows jumps from high places.
	MF_DROPOFF = 0x00000400,
	// For players, will pick up items.
	MF_PICKUP = 0x00000800,
	// Player cheat. ???
	MF_NOCLIP = 0x00001000,
	// Player: keep info about sliding along walls.
	MF_SLIDE = 0x00002000,
	// Allow moves to any height, no gravity.
	// For active floaters, e.g. cacodemons, pain elementals.
	MF_FLOAT = 0x00004000,
	// Don't cross lines
	//   ??? or look at heights on teleport.
	MF_TELEPORT = 0x00008000,
	// Don't hit same species, explode on block.
	// Player missiles as well as fireballs of various kinds.
	MF_MISSILE = 0x00010000,
	// Dropped by a demon, not level spawned.
	// E.g. ammo clips dropped by dying former humans.
	MF_DROPPED = 0x00020000,
	// Use fuzzy draw (spectres),
	//  temporary player invisibility powerup.
	MF_FUZZ = 0x00040000,
	// Flag: don't bleed when shot (use puff),
	//  barrels and shootable furniture shall not bleed.
	MF_NOBLOOD = 0x00080000,
	// Don't stop moving halfway off a step,
	//  that is, have dead bodies slide down all the way.
	MF_CORPSE = 0x00100000,
	// Floating to a height for a move, ???
	//  don't auto float to target's height.
	MF_INFLOAT = 0x00200000,

	// On kill, count this enemy object
	//  towards intermission kill total.
	// Happy gathering.
	MF_COUNTKILL = 0x00400000,

	// On picking up, count this item object
	//  towards intermission item total.
	MF_COUNTITEM = 0x00800000,

	// Special handling: skull in flight.
	// Neither a cacodemon nor a missile.
	MF_SKULLFLY = 0x01000000,

	// Don't spawn this object
	//  in death match mode (e.g. key cards).
	MF_NOTDMATCH = 0x02000000,

	// Player sprites in multiplayer modes are modified
	//  using an internal color lookup table for re-indexing.
	// If 0x04 0x08 or 0x0C,
	//  use a translation table for player colormaps
	MF_TRANSLATION = 0x0C000000,

	// Hmm ???.
	MF_TRANSLATIONSHIFT = 0x0000001A,

	MF_TOUCHY = 0x10000000,   // killough 11/98: dies when solids touch it
	MF_BOUNCES = 0x20000000,   // killough 07/11/98: for beta BFG fireballs
	MF_FRIEND = 0x40000000,   // killough 07/18/98: friendly monsters

							  // Translucent sprite?              // phares
							  MF_TRANSLUCENT = 0x80000000    // phares
};

typedef enum
{
	DI_EAST,
	DI_NORTHEAST,
	DI_NORTH,
	DI_NORTHWEST,
	DI_WEST,
	DI_SOUTHWEST,
	DI_SOUTH,
	DI_SOUTHEAST,
	DI_NODIR,
	NUMDIRS
} dirtype_t;


// p_pspr.h
enum
{
	ps_weapon,
	ps_flash,
	NUMPSPRITES
};


// sounds.h
enum
{
	sg_none,
	sg_itemup,
	sg_wpnup,
	sg_oof,
	sg_getpow,
	sg_stnmov,
	sg_saw
};

//
// Identifiers for all music in game.
//
enum
{
	mus_none,
	mus_e1m1,
	mus_e1m2,
	mus_e1m3,
	mus_e1m4,
	mus_e1m5,
	mus_e1m6,
	mus_e1m7,
	mus_e1m8,
	mus_e1m9,
	mus_e2m1,
	mus_e2m2,
	mus_e2m3,
	mus_e2m4,
	mus_e2m5,
	mus_e2m6,
	mus_e2m7,
	mus_e2m8,
	mus_e2m9,
	mus_e3m1,
	mus_e3m2,
	mus_e3m3,
	mus_e3m4,
	mus_e3m5,
	mus_e3m6,
	mus_e3m7,
	mus_e3m8,
	mus_e3m9,
	mus_e5m1,
	mus_e5m2,
	mus_e5m3,
	mus_e5m4,
	mus_e5m5,
	mus_e5m6,
	mus_e5m7,
	mus_e5m8,
	mus_e5m9,
	mus_inter,
	mus_intro,
	mus_bunny,
	mus_victor,
	mus_introa,
	mus_runnin,
	mus_stalks,
	mus_countd,
	mus_betwee,
	mus_doom,
	mus_the_da,
	mus_shawn,
	mus_ddtblu,
	mus_in_cit,
	mus_dead,
	mus_stlks2,
	mus_theda2,
	mus_doom2,
	mus_ddtbl2,
	mus_runni2,
	mus_dead2,
	mus_stlks3,
	mus_romero,
	mus_shawn2,
	mus_messag,
	mus_count2,
	mus_ddtbl3,
	mus_ampie,
	mus_theda3,
	mus_adrian,
	mus_messg2,
	mus_romer2,
	mus_tense,
	mus_shawn3,
	mus_openin,
	mus_evil,
	mus_ultima,
	mus_read_m,
	mus_dm2ttl,
	mus_dm2int,
	NUMMUSIC,
	mus_musinfo
};

//
// Identifiers for all sfx in game.
//
enum
{
	sfx_none,
	sfx_pistol,
	sfx_shotgn,
	sfx_sgcock,
	sfx_dshtgn,
	sfx_dbopn,
	sfx_dbcls,
	sfx_dbload,
	sfx_plasma,
	sfx_bfg,
	sfx_sawup,
	sfx_sawidl,
	sfx_sawful,
	sfx_sawhit,
	sfx_rlaunc,
	sfx_rxplod,
	sfx_firsht,
	sfx_firxpl,
	sfx_pstart,
	sfx_pstop,
	sfx_doropn,
	sfx_dorcls,
	sfx_stnmov,
	sfx_swtchn,
	sfx_swtchx,
	sfx_plpain,
	sfx_dmpain,
	sfx_popain,
	sfx_vipain,
	sfx_mnpain,
	sfx_pepain,
	sfx_slop,
	sfx_itemup,
	sfx_wpnup,
	sfx_oof,
	sfx_telept,
	sfx_posit1,
	sfx_posit2,
	sfx_posit3,
	sfx_bgsit1,
	sfx_bgsit2,
	sfx_sgtsit,
	sfx_cacsit,
	sfx_brssit,
	sfx_cybsit,
	sfx_spisit,
	sfx_bspsit,
	sfx_kntsit,
	sfx_vilsit,
	sfx_mansit,
	sfx_pesit,
	sfx_sklatk,
	sfx_sgtatk,
	sfx_skepch,
	sfx_vilatk,
	sfx_claw,
	sfx_skeswg,
	sfx_pldeth,
	sfx_pdiehi,
	sfx_podth1,
	sfx_podth2,
	sfx_podth3,
	sfx_bgdth1,
	sfx_bgdth2,
	sfx_sgtdth,
	sfx_cacdth,
	sfx_skldth,
	sfx_brsdth,
	sfx_cybdth,
	sfx_spidth,
	sfx_bspdth,
	sfx_vildth,
	sfx_kntdth,
	sfx_pedth,
	sfx_skedth,
	sfx_posact,
	sfx_bgact,
	sfx_dmact,
	sfx_bspact,
	sfx_bspwlk,
	sfx_vilact,
	sfx_noway,
	sfx_barexp,
	sfx_punch,
	sfx_hoof,
	sfx_metal,
	sfx_chgun,
	sfx_tink,
	sfx_bdopn,
	sfx_bdcls,
	sfx_itmbk,
	sfx_flame,
	sfx_flamst,
	sfx_getpow,
	sfx_bospit,
	sfx_boscub,
	sfx_bossit,
	sfx_bospn,
	sfx_bosdth,
	sfx_manatk,
	sfx_mandth,
	sfx_sssit,
	sfx_ssdth,
	sfx_keenpn,
	sfx_keendt,
	sfx_skeact,
	sfx_skesit,
	sfx_skeatk,
	sfx_radio,

	// killough 11/98: dog sounds
	sfx_dgsit,
	sfx_dgatk,
	sfx_dgact,
	sfx_dgdth,
	sfx_dgpain,

	// e6y
	sfx_secret,
	sfx_gibdth,

	sfx_scrsht,

	NUMSFX
};


#endif