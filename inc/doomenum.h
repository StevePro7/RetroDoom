#if !defined(__DOOMENUM_H__)
#define __DOOMENUM_H__

#include "doomtype.h"

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
//
// Overlay psprites are scaled shapes
// drawn directly on the view screen,
// coordinates are given for a 320*200 view screen.
//
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


// sprites.h
typedef enum
{
	// Sprites 0 to 137
	SPR_TROO, SPR_SHTG, SPR_PUNG, SPR_PISG, SPR_PISF, SPR_SHTF, SPR_SHT2, SPR_CHGG, SPR_CHGF, SPR_MISG,
	SPR_MISF, SPR_SAWG, SPR_PLSG, SPR_PLSF, SPR_BFGG, SPR_BFGF, SPR_BLUD, SPR_PUFF, SPR_BAL1, SPR_BAL2,
	SPR_PLSS, SPR_PLSE, SPR_MISL, SPR_BFS1, SPR_BFE1, SPR_BFE2, SPR_TFOG, SPR_IFOG, SPR_PLAY, SPR_POSS,
	SPR_SPOS, SPR_VILE, SPR_FIRE, SPR_FATB, SPR_FBXP, SPR_SKEL, SPR_MANF, SPR_FATT, SPR_CPOS, SPR_SARG,
	SPR_HEAD, SPR_BAL7, SPR_BOSS, SPR_BOS2, SPR_SKUL, SPR_SPID, SPR_BSPI, SPR_APLS, SPR_APBX, SPR_CYBR,
	SPR_PAIN, SPR_SSWV, SPR_KEEN, SPR_BBRN, SPR_BOSF, SPR_ARM1, SPR_ARM2, SPR_BAR1, SPR_BEXP, SPR_FCAN,
	SPR_BON1, SPR_BON2, SPR_BKEY, SPR_RKEY, SPR_YKEY, SPR_BSKU, SPR_RSKU, SPR_YSKU, SPR_STIM, SPR_MEDI,
	SPR_SOUL, SPR_PINV, SPR_PSTR, SPR_PINS, SPR_MEGA, SPR_SUIT, SPR_PMAP, SPR_PVIS, SPR_CLIP, SPR_AMMO,
	SPR_ROCK, SPR_BROK, SPR_CELL, SPR_CELP, SPR_SHEL, SPR_SBOX, SPR_BPAK, SPR_BFUG, SPR_MGUN, SPR_CSAW,
	SPR_LAUN, SPR_PLAS, SPR_SHOT, SPR_SGN2, SPR_COLU, SPR_SMT2, SPR_GOR1, SPR_POL2, SPR_POL5, SPR_POL4,
	SPR_POL3, SPR_POL1, SPR_POL6, SPR_GOR2, SPR_GOR3, SPR_GOR4, SPR_GOR5, SPR_SMIT, SPR_COL1, SPR_COL2,
	SPR_COL3, SPR_COL4, SPR_CAND, SPR_CBRA, SPR_COL6, SPR_TRE1, SPR_TRE2, SPR_ELEC, SPR_CEYE, SPR_FSKU,
	SPR_COL5, SPR_TBLU, SPR_TGRN, SPR_TRED, SPR_SMBT, SPR_SMGT, SPR_SMRT, SPR_HDB1, SPR_HDB2, SPR_HDB3,
	SPR_HDB4, SPR_HDB5, SPR_HDB6, SPR_POB1, SPR_POB2, SPR_BRS1, SPR_TLMP, SPR_TLP2,

	// Sprites 138 to 143
	SPR_TNT1,   // phares 03/08/98: add invisible sprite
	SPR_DOGS,   // killough 07/19/98: Marine's best friend :)
	SPR_PLS1,   // killough 07/19/98: first of two plasma fireballs in the beta
	SPR_PLS2,   // killough 07/19/98: second of two plasma fireballs in the beta
	SPR_BON3,   // killough 07/11/98: evil sceptre in beta version
	SPR_BON4,   // killough 07/11/98: unholy bible in beta version

	// Sprite 144
	SPR_BLD2,   // [BH] blood splats

	// [BH] Sprites 145 to 244 (100 extra sprite names to use in DeHackEd patches)
	SPR_SP00, SPR_SP01, SPR_SP02, SPR_SP03, SPR_SP04, SPR_SP05, SPR_SP06, SPR_SP07, SPR_SP08, SPR_SP09,
	SPR_SP10, SPR_SP11, SPR_SP12, SPR_SP13, SPR_SP14, SPR_SP15, SPR_SP16, SPR_SP17, SPR_SP18, SPR_SP19,
	SPR_SP20, SPR_SP21, SPR_SP22, SPR_SP23, SPR_SP24, SPR_SP25, SPR_SP26, SPR_SP27, SPR_SP28, SPR_SP29,
	SPR_SP30, SPR_SP31, SPR_SP32, SPR_SP33, SPR_SP34, SPR_SP35, SPR_SP36, SPR_SP37, SPR_SP38, SPR_SP39,
	SPR_SP40, SPR_SP41, SPR_SP42, SPR_SP43, SPR_SP44, SPR_SP45, SPR_SP46, SPR_SP47, SPR_SP48, SPR_SP49,
	SPR_SP50, SPR_SP51, SPR_SP52, SPR_SP53, SPR_SP54, SPR_SP55, SPR_SP56, SPR_SP57, SPR_SP58, SPR_SP59,
	SPR_SP60, SPR_SP61, SPR_SP62, SPR_SP63, SPR_SP64, SPR_SP65, SPR_SP66, SPR_SP67, SPR_SP68, SPR_SP69,
	SPR_SP70, SPR_SP71, SPR_SP72, SPR_SP73, SPR_SP74, SPR_SP75, SPR_SP76, SPR_SP77, SPR_SP78, SPR_SP79,
	SPR_SP80, SPR_SP81, SPR_SP82, SPR_SP83, SPR_SP84, SPR_SP85, SPR_SP86, SPR_SP87, SPR_SP88, SPR_SP89,
	SPR_SP90, SPR_SP91, SPR_SP92, SPR_SP93, SPR_SP94, SPR_SP95, SPR_SP96, SPR_SP97, SPR_SP98, SPR_SP99,

	NUMSPRITES
} spritenum_t;


// states.h
typedef enum
{
	S_NULL,
	S_LIGHTDONE,
	S_PUNCH,
	S_PUNCHDOWN,
	S_PUNCHUP,
	S_PUNCH1,
	S_PUNCH2,
	S_PUNCH3,
	S_PUNCH4,
	S_PUNCH5,
	S_PISTOL,
	S_PISTOLDOWN,
	S_PISTOLUP,
	S_PISTOL1,
	S_PISTOL2,
	S_PISTOL3,
	S_PISTOL4,
	S_PISTOLFLASH,
	S_SGUN,
	S_SGUNDOWN,
	S_SGUNUP,
	S_SGUN1,
	S_SGUN2,
	S_SGUN3,
	S_SGUN4,
	S_SGUN5,
	S_SGUN6,
	S_SGUN7,
	S_SGUN8,
	S_SGUN9,
	S_SGUNFLASH1,
	S_SGUNFLASH2,
	S_DSGUN,
	S_DSGUNDOWN,
	S_DSGUNUP,
	S_DSGUN1,
	S_DSGUN2,
	S_DSGUN3,
	S_DSGUN4,
	S_DSGUN5,
	S_DSGUN6,
	S_DSGUN7,
	S_DSGUN8,
	S_DSGUN9,
	S_DSGUN10,
	S_DSNR1,
	S_DSNR2,
	S_DSGUNFLASH1,
	S_DSGUNFLASH2,
	S_CHAIN,
	S_CHAINDOWN,
	S_CHAINUP,
	S_CHAIN1,
	S_CHAIN2,
	S_CHAIN3,
	S_CHAINFLASH1,
	S_CHAINFLASH2,
	S_MISSILE,
	S_MISSILEDOWN,
	S_MISSILEUP,
	S_MISSILE1,
	S_MISSILE2,
	S_MISSILE3,
	S_MISSILEFLASH1,
	S_MISSILEFLASH2,
	S_MISSILEFLASH3,
	S_MISSILEFLASH4,
	S_SAW,
	S_SAWB,
	S_SAWDOWN,
	S_SAWUP,
	S_SAW1,
	S_SAW2,
	S_SAW3,
	S_PLASMA,
	S_PLASMADOWN,
	S_PLASMAUP,
	S_PLASMA1,
	S_PLASMA2,
	S_PLASMAFLASH1,
	S_PLASMAFLASH2,
	S_BFG,
	S_BFGDOWN,
	S_BFGUP,
	S_BFG1,
	S_BFG2,
	S_BFG3,
	S_BFG4,
	S_BFGFLASH1,
	S_BFGFLASH2,
	S_BLOOD1,
	S_BLOOD2,
	S_BLOOD3,
	S_PUFF1,
	S_PUFF2,
	S_PUFF3,
	S_PUFF4,
	S_TBALL1,
	S_TBALL2,
	S_TBALLX1,
	S_TBALLX2,
	S_TBALLX3,
	S_RBALL1,
	S_RBALL2,
	S_RBALLX1,
	S_RBALLX2,
	S_RBALLX3,
	S_PLASBALL,
	S_PLASBALL2,
	S_PLASEXP,
	S_PLASEXP2,
	S_PLASEXP3,
	S_PLASEXP4,
	S_PLASEXP5,
	S_ROCKET,
	S_BFGSHOT,
	S_BFGSHOT2,
	S_BFGLAND,
	S_BFGLAND2,
	S_BFGLAND3,
	S_BFGLAND4,
	S_BFGLAND5,
	S_BFGLAND6,
	S_BFGEXP,
	S_BFGEXP2,
	S_BFGEXP3,
	S_BFGEXP4,
	S_EXPLODE1,
	S_EXPLODE2,
	S_EXPLODE3,
	S_TFOG,
	S_TFOG01,
	S_TFOG02,
	S_TFOG2,
	S_TFOG3,
	S_TFOG4,
	S_TFOG5,
	S_TFOG6,
	S_TFOG7,
	S_TFOG8,
	S_TFOG9,
	S_TFOG10,
	S_IFOG,
	S_IFOG01,
	S_IFOG02,
	S_IFOG2,
	S_IFOG3,
	S_IFOG4,
	S_IFOG5,
	S_PLAY,
	S_PLAY_RUN1,
	S_PLAY_RUN2,
	S_PLAY_RUN3,
	S_PLAY_RUN4,
	S_PLAY_ATK1,
	S_PLAY_ATK2,
	S_PLAY_PAIN,
	S_PLAY_PAIN2,
	S_PLAY_DIE1,
	S_PLAY_DIE2,
	S_PLAY_DIE3,
	S_PLAY_DIE4,
	S_PLAY_DIE5,
	S_PLAY_DIE6,
	S_PLAY_DIE7,
	S_PLAY_XDIE1,
	S_PLAY_XDIE2,
	S_PLAY_XDIE3,
	S_PLAY_XDIE4,
	S_PLAY_XDIE5,
	S_PLAY_XDIE6,
	S_PLAY_XDIE7,
	S_PLAY_XDIE8,
	S_PLAY_XDIE9,
	S_POSS_STND,
	S_POSS_STND2,
	S_POSS_RUN1,
	S_POSS_RUN2,
	S_POSS_RUN3,
	S_POSS_RUN4,
	S_POSS_RUN5,
	S_POSS_RUN6,
	S_POSS_RUN7,
	S_POSS_RUN8,
	S_POSS_ATK1,
	S_POSS_ATK2,
	S_POSS_ATK3,
	S_POSS_PAIN,
	S_POSS_PAIN2,
	S_POSS_DIE1,
	S_POSS_DIE2,
	S_POSS_DIE3,
	S_POSS_DIE4,
	S_POSS_DIE5,
	S_POSS_XDIE1,
	S_POSS_XDIE2,
	S_POSS_XDIE3,
	S_POSS_XDIE4,
	S_POSS_XDIE5,
	S_POSS_XDIE6,
	S_POSS_XDIE7,
	S_POSS_XDIE8,
	S_POSS_XDIE9,
	S_POSS_RAISE1,
	S_POSS_RAISE2,
	S_POSS_RAISE3,
	S_POSS_RAISE4,
	S_SPOS_STND,
	S_SPOS_STND2,
	S_SPOS_RUN1,
	S_SPOS_RUN2,
	S_SPOS_RUN3,
	S_SPOS_RUN4,
	S_SPOS_RUN5,
	S_SPOS_RUN6,
	S_SPOS_RUN7,
	S_SPOS_RUN8,
	S_SPOS_ATK1,
	S_SPOS_ATK2,
	S_SPOS_ATK3,
	S_SPOS_PAIN,
	S_SPOS_PAIN2,
	S_SPOS_DIE1,
	S_SPOS_DIE2,
	S_SPOS_DIE3,
	S_SPOS_DIE4,
	S_SPOS_DIE5,
	S_SPOS_XDIE1,
	S_SPOS_XDIE2,
	S_SPOS_XDIE3,
	S_SPOS_XDIE4,
	S_SPOS_XDIE5,
	S_SPOS_XDIE6,
	S_SPOS_XDIE7,
	S_SPOS_XDIE8,
	S_SPOS_XDIE9,
	S_SPOS_RAISE1,
	S_SPOS_RAISE2,
	S_SPOS_RAISE3,
	S_SPOS_RAISE4,
	S_SPOS_RAISE5,
	S_VILE_STND,
	S_VILE_STND2,
	S_VILE_RUN1,
	S_VILE_RUN2,
	S_VILE_RUN3,
	S_VILE_RUN4,
	S_VILE_RUN5,
	S_VILE_RUN6,
	S_VILE_RUN7,
	S_VILE_RUN8,
	S_VILE_RUN9,
	S_VILE_RUN10,
	S_VILE_RUN11,
	S_VILE_RUN12,
	S_VILE_ATK1,
	S_VILE_ATK2,
	S_VILE_ATK3,
	S_VILE_ATK4,
	S_VILE_ATK5,
	S_VILE_ATK6,
	S_VILE_ATK7,
	S_VILE_ATK8,
	S_VILE_ATK9,
	S_VILE_ATK10,
	S_VILE_ATK11,
	S_VILE_HEAL1,
	S_VILE_HEAL2,
	S_VILE_HEAL3,
	S_VILE_PAIN,
	S_VILE_PAIN2,
	S_VILE_DIE1,
	S_VILE_DIE2,
	S_VILE_DIE3,
	S_VILE_DIE4,
	S_VILE_DIE5,
	S_VILE_DIE6,
	S_VILE_DIE7,
	S_VILE_DIE8,
	S_VILE_DIE9,
	S_VILE_DIE10,
	S_FIRE1,
	S_FIRE2,
	S_FIRE3,
	S_FIRE4,
	S_FIRE5,
	S_FIRE6,
	S_FIRE7,
	S_FIRE8,
	S_FIRE9,
	S_FIRE10,
	S_FIRE11,
	S_FIRE12,
	S_FIRE13,
	S_FIRE14,
	S_FIRE15,
	S_FIRE16,
	S_FIRE17,
	S_FIRE18,
	S_FIRE19,
	S_FIRE20,
	S_FIRE21,
	S_FIRE22,
	S_FIRE23,
	S_FIRE24,
	S_FIRE25,
	S_FIRE26,
	S_FIRE27,
	S_FIRE28,
	S_FIRE29,
	S_FIRE30,
	S_SMOKE1,
	S_SMOKE2,
	S_SMOKE3,
	S_SMOKE4,
	S_SMOKE5,
	S_TRACER,
	S_TRACER2,
	S_TRACEEXP1,
	S_TRACEEXP2,
	S_TRACEEXP3,
	S_SKEL_STND,
	S_SKEL_STND2,
	S_SKEL_RUN1,
	S_SKEL_RUN2,
	S_SKEL_RUN3,
	S_SKEL_RUN4,
	S_SKEL_RUN5,
	S_SKEL_RUN6,
	S_SKEL_RUN7,
	S_SKEL_RUN8,
	S_SKEL_RUN9,
	S_SKEL_RUN10,
	S_SKEL_RUN11,
	S_SKEL_RUN12,
	S_SKEL_FIST1,
	S_SKEL_FIST2,
	S_SKEL_FIST3,
	S_SKEL_FIST4,
	S_SKEL_MISS1,
	S_SKEL_MISS2,
	S_SKEL_MISS3,
	S_SKEL_MISS4,
	S_SKEL_PAIN,
	S_SKEL_PAIN2,
	S_SKEL_DIE1,
	S_SKEL_DIE2,
	S_SKEL_DIE3,
	S_SKEL_DIE4,
	S_SKEL_DIE5,
	S_SKEL_DIE6,
	S_SKEL_RAISE1,
	S_SKEL_RAISE2,
	S_SKEL_RAISE3,
	S_SKEL_RAISE4,
	S_SKEL_RAISE5,
	S_SKEL_RAISE6,
	S_FATSHOT1,
	S_FATSHOT2,
	S_FATSHOTX1,
	S_FATSHOTX2,
	S_FATSHOTX3,
	S_FATT_STND,
	S_FATT_STND2,
	S_FATT_RUN1,
	S_FATT_RUN2,
	S_FATT_RUN3,
	S_FATT_RUN4,
	S_FATT_RUN5,
	S_FATT_RUN6,
	S_FATT_RUN7,
	S_FATT_RUN8,
	S_FATT_RUN9,
	S_FATT_RUN10,
	S_FATT_RUN11,
	S_FATT_RUN12,
	S_FATT_ATK1,
	S_FATT_ATK2,
	S_FATT_ATK3,
	S_FATT_ATK4,
	S_FATT_ATK5,
	S_FATT_ATK6,
	S_FATT_ATK7,
	S_FATT_ATK8,
	S_FATT_ATK9,
	S_FATT_ATK10,
	S_FATT_PAIN,
	S_FATT_PAIN2,
	S_FATT_DIE1,
	S_FATT_DIE2,
	S_FATT_DIE3,
	S_FATT_DIE4,
	S_FATT_DIE5,
	S_FATT_DIE6,
	S_FATT_DIE7,
	S_FATT_DIE8,
	S_FATT_DIE9,
	S_FATT_DIE10,
	S_FATT_RAISE1,
	S_FATT_RAISE2,
	S_FATT_RAISE3,
	S_FATT_RAISE4,
	S_FATT_RAISE5,
	S_FATT_RAISE6,
	S_FATT_RAISE7,
	S_FATT_RAISE8,
	S_CPOS_STND,
	S_CPOS_STND2,
	S_CPOS_RUN1,
	S_CPOS_RUN2,
	S_CPOS_RUN3,
	S_CPOS_RUN4,
	S_CPOS_RUN5,
	S_CPOS_RUN6,
	S_CPOS_RUN7,
	S_CPOS_RUN8,
	S_CPOS_ATK1,
	S_CPOS_ATK2,
	S_CPOS_ATK3,
	S_CPOS_ATK4,
	S_CPOS_PAIN,
	S_CPOS_PAIN2,
	S_CPOS_DIE1,
	S_CPOS_DIE2,
	S_CPOS_DIE3,
	S_CPOS_DIE4,
	S_CPOS_DIE5,
	S_CPOS_DIE6,
	S_CPOS_DIE7,
	S_CPOS_XDIE1,
	S_CPOS_XDIE2,
	S_CPOS_XDIE3,
	S_CPOS_XDIE4,
	S_CPOS_XDIE5,
	S_CPOS_XDIE6,
	S_CPOS_RAISE1,
	S_CPOS_RAISE2,
	S_CPOS_RAISE3,
	S_CPOS_RAISE4,
	S_CPOS_RAISE5,
	S_CPOS_RAISE6,
	S_CPOS_RAISE7,
	S_TROO_STND,
	S_TROO_STND2,
	S_TROO_RUN1,
	S_TROO_RUN2,
	S_TROO_RUN3,
	S_TROO_RUN4,
	S_TROO_RUN5,
	S_TROO_RUN6,
	S_TROO_RUN7,
	S_TROO_RUN8,
	S_TROO_ATK1,
	S_TROO_ATK2,
	S_TROO_ATK3,
	S_TROO_PAIN,
	S_TROO_PAIN2,
	S_TROO_DIE1,
	S_TROO_DIE2,
	S_TROO_DIE3,
	S_TROO_DIE4,
	S_TROO_DIE5,
	S_TROO_XDIE1,
	S_TROO_XDIE2,
	S_TROO_XDIE3,
	S_TROO_XDIE4,
	S_TROO_XDIE5,
	S_TROO_XDIE6,
	S_TROO_XDIE7,
	S_TROO_XDIE8,
	S_TROO_RAISE1,
	S_TROO_RAISE2,
	S_TROO_RAISE3,
	S_TROO_RAISE4,
	S_TROO_RAISE5,
	S_SARG_STND,
	S_SARG_STND2,
	S_SARG_RUN1,
	S_SARG_RUN2,
	S_SARG_RUN3,
	S_SARG_RUN4,
	S_SARG_RUN5,
	S_SARG_RUN6,
	S_SARG_RUN7,
	S_SARG_RUN8,
	S_SARG_ATK1,
	S_SARG_ATK2,
	S_SARG_ATK3,
	S_SARG_PAIN,
	S_SARG_PAIN2,
	S_SARG_DIE1,
	S_SARG_DIE2,
	S_SARG_DIE3,
	S_SARG_DIE4,
	S_SARG_DIE5,
	S_SARG_DIE6,
	S_SARG_RAISE1,
	S_SARG_RAISE2,
	S_SARG_RAISE3,
	S_SARG_RAISE4,
	S_SARG_RAISE5,
	S_SARG_RAISE6,
	S_HEAD_STND,
	S_HEAD_RUN1,
	S_HEAD_ATK1,
	S_HEAD_ATK2,
	S_HEAD_ATK3,
	S_HEAD_PAIN,
	S_HEAD_PAIN2,
	S_HEAD_PAIN3,
	S_HEAD_DIE1,
	S_HEAD_DIE2,
	S_HEAD_DIE3,
	S_HEAD_DIE4,
	S_HEAD_DIE5,
	S_HEAD_DIE6,
	S_HEAD_RAISE1,
	S_HEAD_RAISE2,
	S_HEAD_RAISE3,
	S_HEAD_RAISE4,
	S_HEAD_RAISE5,
	S_HEAD_RAISE6,
	S_BRBALL1,
	S_BRBALL2,
	S_BRBALLX1,
	S_BRBALLX2,
	S_BRBALLX3,
	S_BOSS_STND,
	S_BOSS_STND2,
	S_BOSS_RUN1,
	S_BOSS_RUN2,
	S_BOSS_RUN3,
	S_BOSS_RUN4,
	S_BOSS_RUN5,
	S_BOSS_RUN6,
	S_BOSS_RUN7,
	S_BOSS_RUN8,
	S_BOSS_ATK1,
	S_BOSS_ATK2,
	S_BOSS_ATK3,
	S_BOSS_PAIN,
	S_BOSS_PAIN2,
	S_BOSS_DIE1,
	S_BOSS_DIE2,
	S_BOSS_DIE3,
	S_BOSS_DIE4,
	S_BOSS_DIE5,
	S_BOSS_DIE6,
	S_BOSS_DIE7,
	S_BOSS_RAISE1,
	S_BOSS_RAISE2,
	S_BOSS_RAISE3,
	S_BOSS_RAISE4,
	S_BOSS_RAISE5,
	S_BOSS_RAISE6,
	S_BOSS_RAISE7,
	S_BOS2_STND,
	S_BOS2_STND2,
	S_BOS2_RUN1,
	S_BOS2_RUN2,
	S_BOS2_RUN3,
	S_BOS2_RUN4,
	S_BOS2_RUN5,
	S_BOS2_RUN6,
	S_BOS2_RUN7,
	S_BOS2_RUN8,
	S_BOS2_ATK1,
	S_BOS2_ATK2,
	S_BOS2_ATK3,
	S_BOS2_PAIN,
	S_BOS2_PAIN2,
	S_BOS2_DIE1,
	S_BOS2_DIE2,
	S_BOS2_DIE3,
	S_BOS2_DIE4,
	S_BOS2_DIE5,
	S_BOS2_DIE6,
	S_BOS2_DIE7,
	S_BOS2_RAISE1,
	S_BOS2_RAISE2,
	S_BOS2_RAISE3,
	S_BOS2_RAISE4,
	S_BOS2_RAISE5,
	S_BOS2_RAISE6,
	S_BOS2_RAISE7,
	S_SKULL_STND,
	S_SKULL_STND2,
	S_SKULL_RUN1,
	S_SKULL_RUN2,
	S_SKULL_ATK1,
	S_SKULL_ATK2,
	S_SKULL_ATK3,
	S_SKULL_ATK4,
	S_SKULL_PAIN,
	S_SKULL_PAIN2,
	S_SKULL_DIE1,
	S_SKULL_DIE2,
	S_SKULL_DIE3,
	S_SKULL_DIE4,
	S_SKULL_DIE5,
	S_SKULL_DIE6,
	S_SPID_STND,
	S_SPID_STND2,
	S_SPID_RUN1,
	S_SPID_RUN2,
	S_SPID_RUN3,
	S_SPID_RUN4,
	S_SPID_RUN5,
	S_SPID_RUN6,
	S_SPID_RUN7,
	S_SPID_RUN8,
	S_SPID_RUN9,
	S_SPID_RUN10,
	S_SPID_RUN11,
	S_SPID_RUN12,
	S_SPID_ATK1,
	S_SPID_ATK2,
	S_SPID_ATK3,
	S_SPID_ATK4,
	S_SPID_PAIN,
	S_SPID_PAIN2,
	S_SPID_DIE1,
	S_SPID_DIE2,
	S_SPID_DIE3,
	S_SPID_DIE4,
	S_SPID_DIE5,
	S_SPID_DIE6,
	S_SPID_DIE7,
	S_SPID_DIE8,
	S_SPID_DIE9,
	S_SPID_DIE10,
	S_SPID_DIE11,
	S_BSPI_STND,
	S_BSPI_STND2,
	S_BSPI_SIGHT,
	S_BSPI_RUN1,
	S_BSPI_RUN2,
	S_BSPI_RUN3,
	S_BSPI_RUN4,
	S_BSPI_RUN5,
	S_BSPI_RUN6,
	S_BSPI_RUN7,
	S_BSPI_RUN8,
	S_BSPI_RUN9,
	S_BSPI_RUN10,
	S_BSPI_RUN11,
	S_BSPI_RUN12,
	S_BSPI_ATK1,
	S_BSPI_ATK2,
	S_BSPI_ATK3,
	S_BSPI_ATK4,
	S_BSPI_PAIN,
	S_BSPI_PAIN2,
	S_BSPI_DIE1,
	S_BSPI_DIE2,
	S_BSPI_DIE3,
	S_BSPI_DIE4,
	S_BSPI_DIE5,
	S_BSPI_DIE6,
	S_BSPI_DIE7,
	S_BSPI_RAISE1,
	S_BSPI_RAISE2,
	S_BSPI_RAISE3,
	S_BSPI_RAISE4,
	S_BSPI_RAISE5,
	S_BSPI_RAISE6,
	S_BSPI_RAISE7,
	S_ARACH_PLAZ,
	S_ARACH_PLAZ2,
	S_ARACH_PLEX,
	S_ARACH_PLEX2,
	S_ARACH_PLEX3,
	S_ARACH_PLEX4,
	S_ARACH_PLEX5,
	S_CYBER_STND,
	S_CYBER_STND2,
	S_CYBER_RUN1,
	S_CYBER_RUN2,
	S_CYBER_RUN3,
	S_CYBER_RUN4,
	S_CYBER_RUN5,
	S_CYBER_RUN6,
	S_CYBER_RUN7,
	S_CYBER_RUN8,
	S_CYBER_ATK1,
	S_CYBER_ATK2,
	S_CYBER_ATK3,
	S_CYBER_ATK4,
	S_CYBER_ATK5,
	S_CYBER_ATK6,
	S_CYBER_PAIN,
	S_CYBER_DIE1,
	S_CYBER_DIE2,
	S_CYBER_DIE3,
	S_CYBER_DIE4,
	S_CYBER_DIE5,
	S_CYBER_DIE6,
	S_CYBER_DIE7,
	S_CYBER_DIE8,
	S_CYBER_DIE9,
	S_CYBER_DIE10,
	S_PAIN_STND,
	S_PAIN_RUN1,
	S_PAIN_RUN2,
	S_PAIN_RUN3,
	S_PAIN_RUN4,
	S_PAIN_RUN5,
	S_PAIN_RUN6,
	S_PAIN_ATK1,
	S_PAIN_ATK2,
	S_PAIN_ATK3,
	S_PAIN_ATK4,
	S_PAIN_PAIN,
	S_PAIN_PAIN2,
	S_PAIN_DIE1,
	S_PAIN_DIE2,
	S_PAIN_DIE3,
	S_PAIN_DIE4,
	S_PAIN_DIE5,
	S_PAIN_DIE6,
	S_PAIN_RAISE1,
	S_PAIN_RAISE2,
	S_PAIN_RAISE3,
	S_PAIN_RAISE4,
	S_PAIN_RAISE5,
	S_PAIN_RAISE6,
	S_SSWV_STND,
	S_SSWV_STND2,
	S_SSWV_RUN1,
	S_SSWV_RUN2,
	S_SSWV_RUN3,
	S_SSWV_RUN4,
	S_SSWV_RUN5,
	S_SSWV_RUN6,
	S_SSWV_RUN7,
	S_SSWV_RUN8,
	S_SSWV_ATK1,
	S_SSWV_ATK2,
	S_SSWV_ATK3,
	S_SSWV_ATK4,
	S_SSWV_ATK5,
	S_SSWV_ATK6,
	S_SSWV_PAIN,
	S_SSWV_PAIN2,
	S_SSWV_DIE1,
	S_SSWV_DIE2,
	S_SSWV_DIE3,
	S_SSWV_DIE4,
	S_SSWV_DIE5,
	S_SSWV_XDIE1,
	S_SSWV_XDIE2,
	S_SSWV_XDIE3,
	S_SSWV_XDIE4,
	S_SSWV_XDIE5,
	S_SSWV_XDIE6,
	S_SSWV_XDIE7,
	S_SSWV_XDIE8,
	S_SSWV_XDIE9,
	S_SSWV_RAISE1,
	S_SSWV_RAISE2,
	S_SSWV_RAISE3,
	S_SSWV_RAISE4,
	S_SSWV_RAISE5,
	S_KEENSTND,
	S_COMMKEEN,
	S_COMMKEEN2,
	S_COMMKEEN3,
	S_COMMKEEN4,
	S_COMMKEEN5,
	S_COMMKEEN6,
	S_COMMKEEN7,
	S_COMMKEEN8,
	S_COMMKEEN9,
	S_COMMKEEN10,
	S_COMMKEEN11,
	S_COMMKEEN12,
	S_KEENPAIN,
	S_KEENPAIN2,
	S_BRAIN,
	S_BRAIN_PAIN,
	S_BRAIN_DIE1,
	S_BRAIN_DIE2,
	S_BRAIN_DIE3,
	S_BRAIN_DIE4,
	S_BRAINEYE,
	S_BRAINEYESEE,
	S_BRAINEYE1,
	S_SPAWN1,
	S_SPAWN2,
	S_SPAWN3,
	S_SPAWN4,
	S_SPAWNFIRE1,
	S_SPAWNFIRE2,
	S_SPAWNFIRE3,
	S_SPAWNFIRE4,
	S_SPAWNFIRE5,
	S_SPAWNFIRE6,
	S_SPAWNFIRE7,
	S_SPAWNFIRE8,
	S_BRAINEXPLODE1,
	S_BRAINEXPLODE2,
	S_BRAINEXPLODE3,
	S_ARM1,
	S_ARM1A,
	S_ARM2,
	S_ARM2A,
	S_BAR1,
	S_BAR2,
	S_BEXP,
	S_BEXP2,
	S_BEXP3,
	S_BEXP4,
	S_BEXP5,
	S_BBAR1,
	S_BBAR2,
	S_BBAR3,
	S_BON1,
	S_BON1A,
	S_BON1B,
	S_BON1C,
	S_BON1D,
	S_BON1E,
	S_BON2,
	S_BON2A,
	S_BON2B,
	S_BON2C,
	S_BON2D,
	S_BON2E,
	S_BKEY,
	S_BKEY2,
	S_RKEY,
	S_RKEY2,
	S_YKEY,
	S_YKEY2,
	S_BSKULL,
	S_BSKULL2,
	S_RSKULL,
	S_RSKULL2,
	S_YSKULL,
	S_YSKULL2,
	S_STIM,
	S_MEDI,
	S_SOUL,
	S_SOUL2,
	S_SOUL3,
	S_SOUL4,
	S_SOUL5,
	S_SOUL6,
	S_PINV,
	S_PINV2,
	S_PINV3,
	S_PINV4,
	S_PSTR,
	S_PINS,
	S_PINS2,
	S_PINS3,
	S_PINS4,
	S_MEGA,
	S_MEGA2,
	S_MEGA3,
	S_MEGA4,
	S_SUIT,
	S_PMAP,
	S_PMAP2,
	S_PMAP3,
	S_PMAP4,
	S_PMAP5,
	S_PMAP6,
	S_PVIS,
	S_PVIS2,
	S_CLIP,
	S_AMMO,
	S_ROCK,
	S_BROK,
	S_CELL,
	S_CELP,
	S_SHEL,
	S_SBOX,
	S_BPAK,
	S_BFUG,
	S_MGUN,
	S_CSAW,
	S_LAUN,
	S_PLAS,
	S_SHOT,
	S_SHOT2,
	S_COLU,
	S_STALAG,
	S_BLOODYTWITCH,
	S_BLOODYTWITCH2,
	S_BLOODYTWITCH3,
	S_BLOODYTWITCH4,
	S_DEADTORSO,
	S_DEADBOTTOM,
	S_HEADSONSTICK,
	S_GIBS,
	S_HEADONASTICK,
	S_HEADCANDLES,
	S_HEADCANDLES2,
	S_DEADSTICK,
	S_LIVESTICK,
	S_LIVESTICK2,
	S_MEAT2,
	S_MEAT3,
	S_MEAT4,
	S_MEAT5,
	S_STALAGMITE,
	S_TALLGRNCOL,
	S_SHRTGRNCOL,
	S_TALLREDCOL,
	S_SHRTREDCOL,
	S_CANDLESTIK,
	S_CANDELABRA,
	S_SKULLCOL,
	S_TORCHTREE,
	S_BIGTREE,
	S_TECHPILLAR,
	S_EVILEYE,
	S_EVILEYE2,
	S_EVILEYE3,
	S_EVILEYE4,
	S_FLOATSKULL,
	S_FLOATSKULL2,
	S_FLOATSKULL3,
	S_HEARTCOL,
	S_HEARTCOL2,
	S_BLUETORCH,
	S_BLUETORCH2,
	S_BLUETORCH3,
	S_BLUETORCH4,
	S_GREENTORCH,
	S_GREENTORCH2,
	S_GREENTORCH3,
	S_GREENTORCH4,
	S_REDTORCH,
	S_REDTORCH2,
	S_REDTORCH3,
	S_REDTORCH4,
	S_BTORCHSHRT,
	S_BTORCHSHRT2,
	S_BTORCHSHRT3,
	S_BTORCHSHRT4,
	S_GTORCHSHRT,
	S_GTORCHSHRT2,
	S_GTORCHSHRT3,
	S_GTORCHSHRT4,
	S_RTORCHSHRT,
	S_RTORCHSHRT2,
	S_RTORCHSHRT3,
	S_RTORCHSHRT4,
	S_HANGNOGUTS,
	S_HANGBNOBRAIN,
	S_HANGTLOOKDN,
	S_HANGTSKULL,
	S_HANGTLOOKUP,
	S_HANGTNOBRAIN,
	S_COLONGIBS,
	S_SMALLPOOL,
	S_BRAINSTEM,
	S_TECHLAMP,
	S_TECHLAMP2,
	S_TECHLAMP3,
	S_TECHLAMP4,
	S_TECH2LAMP,
	S_TECH2LAMP2,
	S_TECH2LAMP3,
	S_TECH2LAMP4,

	// phares 03/08/98: add state for invisible sprite
	S_TNT1,

	// killough 08/09/98: grenade launcher
	S_GRENADE,

	// killough 08/09/98: detonation of objects
	S_DETONATE,
	S_DETONATE2,
	S_DETONATE3,

	// killough 07/19/98: Marine's best friend :)
	S_DOGS_STND,
	S_DOGS_STND2,
	S_DOGS_RUN1,
	S_DOGS_RUN2,
	S_DOGS_RUN3,
	S_DOGS_RUN4,
	S_DOGS_RUN5,
	S_DOGS_RUN6,
	S_DOGS_RUN7,
	S_DOGS_RUN8,
	S_DOGS_ATK1,
	S_DOGS_ATK2,
	S_DOGS_ATK3,
	S_DOGS_PAIN,
	S_DOGS_PAIN2,
	S_DOGS_DIE1,
	S_DOGS_DIE2,
	S_DOGS_DIE3,
	S_DOGS_DIE4,
	S_DOGS_DIE5,
	S_DOGS_DIE6,
	S_DOGS_RAISE1,
	S_DOGS_RAISE2,
	S_DOGS_RAISE3,
	S_DOGS_RAISE4,
	S_DOGS_RAISE5,
	S_DOGS_RAISE6,

	// killough 07/11/98: the old BFG's 43 firing frames
	S_OLDBFG1,
	S_OLDBFG2,
	S_OLDBFG3,
	S_OLDBFG4,
	S_OLDBFG5,
	S_OLDBFG6,
	S_OLDBFG7,
	S_OLDBFG8,
	S_OLDBFG9,
	S_OLDBFG10,
	S_OLDBFG11,
	S_OLDBFG12,
	S_OLDBFG13,
	S_OLDBFG14,
	S_OLDBFG15,
	S_OLDBFG16,
	S_OLDBFG17,
	S_OLDBFG18,
	S_OLDBFG19,
	S_OLDBFG20,
	S_OLDBFG21,
	S_OLDBFG22,
	S_OLDBFG23,
	S_OLDBFG24,
	S_OLDBFG25,
	S_OLDBFG26,
	S_OLDBFG27,
	S_OLDBFG28,
	S_OLDBFG29,
	S_OLDBFG30,
	S_OLDBFG31,
	S_OLDBFG32,
	S_OLDBFG33,
	S_OLDBFG34,
	S_OLDBFG35,
	S_OLDBFG36,
	S_OLDBFG37,
	S_OLDBFG38,
	S_OLDBFG39,
	S_OLDBFG40,
	S_OLDBFG41,
	S_OLDBFG42,
	S_OLDBFG43,

	// killough 07/19/98: first plasma fireball in the beta
	S_PLS1BALL,
	S_PLS1BALL2,
	S_PLS1EXP,
	S_PLS1EXP2,
	S_PLS1EXP3,
	S_PLS1EXP4,
	S_PLS1EXP5,

	// killough 07/19/98: second plasma fireball in the beta
	S_PLS2BALL,
	S_PLS2BALL2,
	S_PLS2BALLX1,
	S_PLS2BALLX2,
	S_PLS2BALLX3,

	// killough 07/11/98: evil sceptre in beta version
	S_BON3,

	// killough 07/11/98: unholy bible in beta version
	S_BON4,

	// killough 10/98: beta lost souls were different from their modern cousins
	S_BSKUL_STND,
	S_BSKUL_RUN1,
	S_BSKUL_RUN2,
	S_BSKUL_RUN3,
	S_BSKUL_RUN4,
	S_BSKUL_ATK1,
	S_BSKUL_ATK2,
	S_BSKUL_ATK3,
	S_BSKUL_PAIN1,
	S_BSKUL_PAIN2,
	S_BSKUL_PAIN3,
	S_BSKUL_DIE1,
	S_BSKUL_DIE2,
	S_BSKUL_DIE3,
	S_BSKUL_DIE4,
	S_BSKUL_DIE5,
	S_BSKUL_DIE6,
	S_BSKUL_DIE7,
	S_BSKUL_DIE8,

	// killough 10/98: mushroom explosion effect
	S_MUSHROOM,

	// [BH] DOOM Retro states
	S_BAR3,
	S_TRAIL,
	S_TRAIL2,
	S_TRAIL3,
	S_TRAIL4,

	// [BH] extra DeHackEd states 1081 to 3999
	EXTRASTATES = 1081,

	NUMSTATES = 4000
} statenum_t;



// c_cmds.h
typedef enum
{
	keyboardcontrol = 1,
	mousecontrol = 2,
	gamepadcontrol = 3
} controltype_t;

typedef enum
{
	CT_CCMD = 1,
	CT_CVAR = 2,
	CT_CHEAT = 3
} cmdtype_t;

enum
{
	CF_NONE = 0,
	CF_BOOLEAN = 1,
	CF_FLOAT = 2,
	CF_INTEGER = 4,
	CF_PERCENT = 8,
	CF_STRING = 16,
	CF_TIME = 32,
	CF_OTHER = 64,
	CF_READONLY = 128
};


// z_zone.h
//
// ZONE MEMORY
// PU - purge tags.
//
enum
{
	PU_FREE,       // a free block
	PU_STATIC,     // static entire execution time
	PU_LEVEL,      // static until level exited
	PU_LEVSPEC,    // a special thinker in a level
	PU_CACHE,
	PU_MAX         // Must always be last -- killough
};


// r_defs.h
typedef enum
{
	SOLID,
	LIQUID,
	NUKAGE,
	WATER,
	LAVA,
	BLOOD,
	SLIME,
	GRAYSLIME,
	GOOP,
	ICYWATER,
	TAR,
	SLUDGE
} terraintype_t;

//
// Move clipping aid for LineDefs.
//
typedef enum
{
	ST_HORIZONTAL,
	ST_VERTICAL,
	ST_POSITIVE,
	ST_NEGATIVE
} slopetype_t;


enum
{
	DR_Door_OpenWaitClose_AlsoMonsters = 1,
	W1_Door_OpenStay = 2,
	W1_Door_CloseStay = 3,
	W1_Door_OpenWaitClose = 4,
	W1_Floor_RaiseToLowestCeiling = 5,
	W1_Crusher_StartWithFastDamage = 6,
	S1_Stairs_RaiseBy8 = 7,
	W1_Stairs_RaiseBy8 = 8,
	S1_Floor_RaiseDonut_ChangesTexture = 9,
	W1_Lift_LowerWaitRaise = 10,
	S1_ExitLevel = 11,
	W1_Light_ChangeToBrightestAdjacent = 12,
	W1_Light_ChangeTo255 = 13,
	S1_Floor_RaiseBy32_ChangesTexture = 14,
	S1_Floor_RaiseBy24_ChangesTexture = 15,
	W1_Door_CloseWaitOpen = 16,
	W1_Light_StartBlinking = 17,
	S1_Floor_RaiseToNextHighestFloor = 18,
	W1_Floor_LowerToHighestFloor = 19,
	S1_Floor_RaiseToNextHighestFloor_ChangesTexture = 20,
	S1_Lift_LowerWaitRaise = 21,
	W1_Floor_RaiseToNextHighestFloor_ChangesTexture = 22,
	S1_Floor_LowerToLowestFloor = 23,
	G1_Floor_RaiseToLowestCeiling = 24,
	W1_Crusher_StartWithSlowDamage = 25,
	DR_Door_Blue_OpenWaitClose = 26,
	DR_Door_Yellow_OpenWaitClose = 27,
	DR_Door_Red_OpenWaitClose = 28,
	S1_Door_OpenWaitClose = 29,
	W1_Floor_RaiseByShortestLowerTexture = 30,
	D1_Door_OpenStay = 31,
	D1_Door_Blue_OpenStay = 32,
	D1_Door_Red_OpenStay = 33,
	D1_Door_Yellow_OpenStay = 34,
	W1_Light_ChangeTo35 = 35,
	W1_Floor_LowerTo8AboveHighestFloor = 36,
	W1_Floor_LowerToLowestFloor_ChangesTexture = 37,
	W1_Floor_LowerToLowestFloor = 38,
	W1_Teleport = 39,
	W1_Ceiling_RaiseToHighestCeiling = 40,
	S1_Ceiling_LowerToFloor = 41,
	SR_Door_CloseStay = 42,
	SR_Ceiling_LowerToFloor = 43,
	W1_Ceiling_LowerTo8AboveFloor = 44,
	SR_Floor_LowerToHighestFloor = 45,
	GR_Door_OpenStay = 46,
	G1_Floor_RaiseToNextHighestFloor_ChangesTexture = 47,
	Scroll_ScrollTextureLeft = 48,
	S1_Ceiling_LowerTo8AboveFloor_PerpetualSlowCrusherDamage = 49,
	S1_Door_CloseStay = 50,
	S1_ExitLevel_GoesToSecretLevel = 51,
	W1_ExitLevel = 52,
	W1_Floor_StartMovingUpAndDown = 53,
	W1_Floor_StopMoving = 54,
	S1_Floor_RaiseTo8BelowLowestCeiling_Crushes = 55,
	W1_Floor_RaiseTo8BelowLowestCeiling_Crushes = 56,
	W1_Crusher_Stop = 57,
	W1_Floor_RaiseBy24 = 58,
	W1_Floor_RaiseBy24_ChangesTexture = 59,
	SR_Floor_LowerToLowestFloor = 60,
	SR_Door_OpenStay = 61,
	SR_Lift_LowerWaitRaise = 62,
	SR_Door_OpenWaitClose = 63,
	SR_Floor_RaiseToLowestCeiling = 64,
	SR_Floor_RaiseTo8BelowLowestCeiling_Crushes = 65,
	SR_Floor_RaiseBy24_ChangesTexture = 66,
	SR_Floor_RaiseBy32_ChangesTexture = 67,
	SR_Floor_RaiseToNextHighestFloor_ChangesTexture = 68,
	SR_Floor_RaiseToNextHighestFloor = 69,
	SR_Floor_LowerTo8AboveHighestFloor = 70,
	S1_Floor_LowerTo8AboveHighestFloor = 71,
	WR_Ceiling_LowerTo8AboveFloor = 72,
	WR_Crusher_StartWithSlowDamage = 73,
	WR_Crusher_Stop = 74,
	WR_Door_CloseStay = 75,
	WR_Door_CloseStayOpen = 76,
	WR_Crusher_StartWithFastDamage = 77,
	SR_ChangeTextureAndEffectToNearest = 78,
	WR_Light_ChangeTo35 = 79,
	WR_Light_ChangeToBrightestAdjacent = 80,
	WR_Light_ChangeTo255 = 81,
	WR_Floor_LowerToLowestFloor = 82,
	WR_Floor_LowerToHighestFloor = 83,
	WR_Floor_LowerToLowestFloor_ChangesTexture = 84,
	Scroll_ScrollTextureRight = 85,
	WR_Door_OpenStay = 86,
	WR_Floor_StartMovingUpAndDown = 87,
	WR_Lift_LowerWaitRaise = 88,
	WR_Floor_StopMoving = 89,
	WR_Door_OpenWaitClose = 90,
	WR_Floor_RaiseToLowestCeiling = 91,
	WR_Floor_RaiseBy24 = 92,
	WR_Floor_RaiseBy24_ChangesTexture = 93,
	WR_Floor_RaiseTo8BelowLowestCeiling_Crushes = 94,
	WR_Floor_RaiseToNextHighestFloor_ChangesTexture = 95,
	WR_Floor_RaiseByShortestLowerTexture = 96,
	WR_Teleport = 97,
	WR_Floor_LowerTo8AboveHighestFloor = 98,
	SR_Door_Blue_OpenStay_Fast = 99,
	W1_Stairs_RaiseBy16_Fast = 100,
	S1_Floor_RaiseToLowestCeiling = 101,
	S1_Floor_LowerToHighestFloor = 102,
	S1_Door_OpenStay = 103,
	W1_Light_ChangeToDarkestAdjacent = 104,
	WR_Door_OpenWaitClose_Fast = 105,
	WR_Door_OpenStay_Fast = 106,
	WR_Door_CloseStay_Fast = 107,
	W1_Door_OpenWaitClose_Fast = 108,
	W1_Door_OpenStay_Fast = 109,
	W1_Door_CloseStay_Fast = 110,
	S1_Door_OpenWaitClose_Fast = 111,
	S1_Door_OpenStay_Fast = 112,
	S1_Door_CloseStay_Fast = 113,
	SR_Door_OpenWaitClose_Fast = 114,
	SR_Door_OpenStay_Fast = 115,
	SR_Door_CloseStay_Fast = 116,
	DR_Door_OpenWaitClose_Fast = 117,
	D1_Door_OpenStay_Fast = 118,
	W1_Floor_RaiseToNextHighestFloor = 119,
	WR_Lift_LowerWaitRaise_Fast = 120,
	W1_Lift_LowerWaitRaise_Fast = 121,
	S1_Lift_LowerWaitRaise_Fast = 122,
	SR_Lift_LowerWaitRaise_Fast = 123,
	W1_ExitLevel_GoesToSecretLevel = 124,
	W1_Teleport_MonstersOnly = 125,
	WR_Teleport_MonstersOnly = 126,
	S1_Stairs_RaiseBy16_Fast = 127,
	WR_Floor_RaiseToNextHighestFloor = 128,
	WR_Floor_RaiseToNextHighestFloor_Fast = 129,
	W1_Floor_RaiseToNextHighestFloor_Fast = 130,
	S1_Floor_RaiseToNextHighestFloor_Fast = 131,
	SR_Floor_RaiseToNextHighestFloor_Fast = 132,
	S1_Door_Blue_OpenStay_Fast = 133,
	SR_Door_Red_OpenStay_Fast = 134,
	S1_Door_Red_OpenStay_Fast = 135,
	SR_Door_Yellow_OpenStay_Fast = 136,
	S1_Door_Yellow_OpenStay_Fast = 137,
	SR_Light_ChangeTo255 = 138,
	SR_Light_ChangeTo35 = 139,
	S1_Floor_RaiseBy512 = 140,
	W1_Crusher_StartWithSlowDamage_Silent = 141,

	BOOMLINESPECIALS = 142,

	W1_Floor_RaiseBy512 = 142,
	W1_Lift_RaiseBy24_ChangesTexture = 143,
	W1_Lift_RaiseBy32_ChangesTexture = 144,
	W1_CeilingLowerToFloor_Fast = 145,
	W1_Floor_RaiseDonut_ChangesTexture = 146,
	WR_Floor_RaiseBy512 = 147,
	WR_Lift_RaiseBy24_ChangesTexture = 148,
	WR_Lift_RaiseBy32_ChangesTexture = 149,
	WR_Crusher_Start_Silent = 150,
	WR_Ceiling_RaiseToHighestCeiling = 151,
	WR_Ceiling_LowerToFloor_Fast = 152,
	W1_ChangeTextureAndEffect = 153,
	WR_ChangeTextureAndEffect = 154,
	WR_Floor_RaiseDonut_ChangesTexture = 155,
	WR_Light_StartBlinking = 156,
	WR_Light_ChangeToDarkestAdjacent = 157,
	S1_Floor_RaiseByShortestLowerTexture = 158,
	S1_Floor_LowerToLowestFloor_ChangesTexture = 159,
	S1_Floor_RaiseBy24_ChangesTextureAndEffect = 160,
	S1_Floor_RaiseBy24 = 161,
	S1_Lift_PerpetualLowestAndHighestFloors = 162,
	S1_Lift_Stop = 163,
	S1_Crusher_Start_Fast = 164,
	S1_Crusher_Start_Silent = 165,
	S1_Ceiling_RaiseToHighestCeiling = 166,
	S1_Ceiling_LowerTo8AboveFloor = 167,
	S1_Crusher_Stop = 168,
	S1_Light_ChangeToBrightestAdjacent = 169,
	S1_Light_ChangeTo35 = 170,
	S1_Light_ChangeTo255 = 171,
	S1_Light_StartBlinking = 172,
	S1_Light_ChangeToDarkestAdjacent = 173,
	S1_Teleport_AlsoMonsters = 174,
	S1_Door_CloseWaitOpen_30Seconds = 175,
	SR_Floor_RaiseByShortestLowerTexture = 176,
	SR_Floor_LowerToLowestFloor_ChangesTexture = 177,
	SR_Floor_RaiseBy512 = 178,
	SR_Floor_RaiseBy24_ChangesTextureAndEffect = 179,
	SR_Floor_RaiseBy24 = 180,
	SR_Lift_PerpetualLowestAndHighestFloors = 181,
	SR_Lift_Stop = 182,
	SR_Crusher_Start_Fast = 183,
	SR_Crusher_Start = 184,
	SR_Crusher_Start_Silent = 185,
	SR_Ceiling_RaiseToHighestCeiling = 186,
	SR_Ceiling_LowerTo8AboveFloor = 187,
	SR_Crusher_Stop = 188,
	S1_ChangeTextureAndEffect = 189,
	SR_ChangeTextureAndEffect = 190,
	SR_Floor_RaiseDonut_ChangesTexture = 191,
	SR_Light_ChangeToBrightestAdjacent = 192,
	SR_Light_StartBlinking = 193,
	SR_Light_ChangeToDarkestAdjacent = 194,
	SR_Teleport_AlsoMonsters = 195,
	SR_Door_CloseWaitOpen_30Seconds = 196,
	G1_ExitLevel = 197,
	G1_ExitLevel_GoesToSecretLevel = 198,
	W1_Ceiling_LowerToLowestCeiling = 199,
	W1_Ceiling_LowerToHighestFloor = 200,
	WR_Ceiling_LowerToLowestCeiling = 201,
	WR_Ceiling_LowerToHighestFloor = 202,
	S1_Ceiling_LowerToLowestCeiling = 203,
	S1_Ceiling_LowerToHighestFloor = 204,
	SR_Ceiling_LowerToLowestCeiling = 205,
	SR_Ceiling_LowerToHighestFloor = 206,
	W1_Teleport_AlsoMonsters_Silent_SameAngle = 207,
	WR_Teleport_AlsoMonsters_Silent_SameAngle = 208,
	S1_Teleport_AlsoMonsters_Silent_SameAngle = 209,
	SR_Teleport_AlsoMonsters_Silent_SameAngle = 210,
	SR_Lift_RaiseToCeiling_Instantly = 211,
	WR_Lift_RaiseToCeiling_Instantly = 212,
	Floor_ChangeBrightnessToThisBrightness = 213,
	Scroll_CeilingAcceleratesWhenSectorHeightChanges = 214,
	Scroll_FloorAcceleratesWhenSectorHeightChanges = 215,
	Scroll_ThingsAccelerateWhenSectorHeightChanges = 216,
	Scroll_FloorAndThingsAccelerateWhenSectorHeightChanges = 217,
	Scroll_WallAcceleratesWhenSectorHeightChanges = 218,
	W1_Floor_LowerToNearestFloor = 219,
	WR_Floor_LowerToNearestFloor = 220,
	S1_Floor_LowerToNearestFloor = 221,
	SR_Floor_LowerToNearestFloor = 222,
	FrictionTaggedSector = 223,
	WindAccordingToLineVector = 224,
	CurrentAccordingToLineVector = 225,
	WindCurrentByPushPullThingInSector = 226,
	W1_Lift_RaiseToNextHighestFloor_Fast = 227,
	WR_Lift_RaiseToNextHighestFloor_Fast = 228,
	S1_Lift_RaiseToNextHighestFloor_Fast = 229,
	SR_Lift_RaiseToNextHighestFloor_Fast = 230,
	W1_Lift_LowerToNextLowestFloor_Fast = 231,
	WR_Lift_LowerToNextLowestFloor_Fast = 232,
	S1_Lift_LowerToNextLowestFloor_Fast = 233,
	SR_Lift_LowerToNextLowestFloor_Fast = 234,
	W1_Lift_MoveToSameFloorHeight_Fast = 235,
	WR_Lift_MoveToSameFloorHeight_Fast = 236,
	S1_Lift_MoveToSameFloorHeight_Fast = 237,
	SR_Lift_MoveToSameFloorHeight_Fast = 238,
	W1_ChangeTextureAndEffectToNearest = 239,
	WR_ChangeTextureAndEffectToNearest = 240,
	S1_ChangeTextureAndEffectToNearest = 241,
	CreateFakeCeilingAndFloor = 242,
	W1_TeleportToLineWithSameTag_Silent_SameAngle = 243,
	WR_TeleportToLineWithSameTag_Silent_SameAngle = 244,
	Scroll_ScrollCeilingWhenSectorChangesHeight = 245,
	Scroll_ScrollFloorWhenSectorChangesHeight = 246,
	Scroll_MoveThingsWhenSectorChangesHeight = 247,
	Scroll_ScrollFloorAndMoveThingsWhenSectorChangesHeight = 248,
	Scroll_ScrollWallWhenSectorChangesHeight = 249,
	Scroll_ScrollCeilingAccordingToLineVector = 250,
	Scroll_ScrollFloorAccordingToLineVector = 251,
	Scroll_MoveThingsAccordingToLineVector = 252,
	Scroll_ScrollFloorAndMoveThings = 253,
	Scroll_ScrollWallAccordingToLineVector = 254,
	Scroll_ScrollWallUsingSidedefOffsets = 255,
	WR_Stairs_RaiseBy8 = 256,
	WR_Stairs_RaiseBy16_Fast = 257,
	SR_Stairs_RaiseBy8 = 258,
	SR_Stairs_RaiseBy16_Fast = 259,
	Translucent_MiddleTexture = 260,
	Ceiling_ChangeBrightnessToThisBrightness = 261,
	W1_TeleportToLineWithSameTag_Silent_ReversedAngle = 262,
	WR_TeleportToLineWithSameTag_Silent_ReversedAngle = 263,
	W1_TeleportToLineWithSameTag_MonstersOnly_Silent_ReversedAngle = 264,
	WR_TeleportToLineWithSameTag_MonstersOnly_Silent_ReversedAngle = 265,
	W1_TeleportToLineWithSameTag_MonstersOnly_Silent = 266,
	WR_TeleportToLineWithSameTag_MonstersOnly_Silent = 267,
	W1_Teleport_MonstersOnly_Silent = 268,
	WR_Teleport_MonstersOnly_Silent = 269,

	MBFLINESPECIALS = 271,

	TransferSkyTextureToTaggedSectors = 271,
	TransferSkyTextureToTaggedSectors_Flipped = 272,

	NUMLINESPECIALS = 272
};

enum
{
	Normal = 0,
	LightBlinks_Randomly = 1,
	LightBlinks_2Hz = 2,
	LightBlinks_1Hz = 3,
	DamageNegative10Or20PercentHealthAndLightBlinks_2Hz = 4,
	DamageNegative5Or10PercentHealth = 5,
	DamageNegative2Or5PercentHealth = 7,
	LightGlows_1PlusSec = 8,
	Secret = 9,
	Door_CloseStay_After30sec = 10,
	DamageNegative10Or20PercentHealthAndEndLevel = 11,
	LightBlinks_1HzSynchronized = 12,
	LightBlinks_2HzSynchronized = 13,
	Door_OpenClose_OpensAfter5Min = 14,
	DamageNegative10Or20PercentHealth = 16,
	LightFlickers_Randomly = 17
};

enum
{
	Nothing = 0,
	Player1Start = 1,
	Player2Start = 2,
	Player3Start = 3,
	Player4Start = 4,
	BlueKeycard = 5,
	YellowKeycard = 6,
	SpiderMastermind = 7,
	Backpack = 8,
	ShotgunGuy = 9,
	BloodyMess1 = 10,
	PlayerDeathmatchStart = 11,
	BloodyMess2 = 12,
	RedKeycard = 13,
	TeleportDestination = 14,
	DeadPlayer = 15,
	Cyberdemon = 16,
	CellPack = 17,
	DeadZombieman = 18,
	DeadShotgunGuy = 19,
	DeadImp = 20,
	DeadDemon = 21,
	DeadCacodemon = 22,
	DeadLostSoulInvisible = 23,
	PoolOfBloodAndBones = 24,
	ImpaledHuman = 25,
	TwitchingImpaledHuman = 26,
	SkullOnAPole = 27,
	FiveSkullsShishKebab = 28,
	PileOfSkullsAndCandles = 29,
	TallGreenColumn = 30,
	ShortGreenColumn = 31,
	TallRedColumn = 32,
	ShortRedColumn = 33,
	Candlestick = 34,
	Candelabra = 35,
	ShortGreenColumnWithBeatingHeart = 36,
	ShortRedColumnWithSkull = 37,
	RedSkullKey = 38,
	YellowSkullKey = 39,
	BlueSkullKey = 40,
	EvilEye = 41,
	FloatingSkullRock = 42,
	TorchedTree = 43,
	TallBlueFirestick = 44,
	TallGreenFirestick = 45,
	TallRedFirestick = 46,
	Stalagmite = 47,
	TallTechnoPillar = 48,
	HangingVictimTwitchingBlocking = 49,
	HangingVictimArmsOutBlocking = 50,
	HangingVictimOneLeggedBlocking = 51,
	HangingPairOfLegsBlocking = 52,
	HangingLegBlocking = 53,
	LargeBrownTree = 54,
	ShortBlueFirestick = 55,
	ShortGreenFirestick = 56,
	ShortRedFirestick = 57,
	Spectre = 58,
	HangingVictimArmsOut = 59,
	HangingPairOfLegs = 60,
	HangingVictimOneLegged = 61,
	HangingLeg = 62,
	HangingVictimTwitching = 63,
	ArchVile = 64,
	HeavyWeaponDude = 65,
	Revenant = 66,
	Mancubus = 67,
	Arachnotron = 68,
	HellKnight = 69,
	BurningBarrel = 70,
	PainElemental = 71,
	CommanderKeen = 72,
	HangingVictimGutsRemoved = 73,
	HangingVictimGutsAndBrainRemoved = 74,
	HangingTorsoLookingDown = 75,
	HangingTorsoOpenSkull = 76,
	HangingTorsoLookingUp = 77,
	HangingTorsoBrainRemoved = 78,
	PoolOfBloodAndGuts = 79,
	PoolOfBlood = 80,
	PoolOfBrains = 81,
	SuperShotgun = 82,
	MegaSphere = 83,
	WolfensteinSS = 84,
	TallTechnoFloorLamp = 85,
	ShortTechnoFloorLamp = 86,
	MonstersTarget = 87,
	BossBrain = 88,
	MonstersSpawner = 89,
	Shotgun = 2001,
	Chaingun = 2002,
	RocketLauncher = 2003,
	PlasmaRifle = 2004,
	Chainsaw = 2005,
	BFG9000 = 2006,
	Clip = 2007,
	ShotgunShells = 2008,
	Rocket = 2010,
	Stimpack = 2011,
	Medikit = 2012,
	SoulSphere = 2013,
	HealthBonus = 2014,
	ArmorBonus = 2015,
	GreenArmor = 2018,
	BlueArmor = 2019,
	Invulnerability = 2022,
	Berserk = 2023,
	PartialInvisibility = 2024,
	RadiationShieldingSuit = 2025,
	ComputerAreaMap = 2026,
	FloorLamp = 2028,
	Barrel = 2035,
	LightAmplificationVisor = 2045,
	BoxOfRockets = 2046,
	Cell = 2047,
	BoxOfBullets = 2048,
	BoxOfShells = 2049,
	Imp = 3001,
	Demon = 3002,
	BaronOfHell = 3003,
	Zombieman = 3004,
	Cacodemon = 3005,
	LostSoul = 3006,
	Pusher = 5001,
	Puller = 5002,
	MusicSourceMin = 14100,
	MusicSourceMax = 14164,
	VisualModeCamera = 32000
};


// c_console.h
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


// r_state.h
typedef enum
{
	DOOMBSP,
	DEEPBSP,
	ZDBSPX
} mapformat_t;


// p_tick.h
enum
{
	th_mobj,
	th_misc,
	NUMTHCLASS,
	th_all = NUMTHCLASS
};


// p_spec.h
// jff 2/23/98 identify the special classes that can share sectors
typedef enum
{
	floor_special,
	ceiling_special
} special_e;

typedef enum
{
	nowhere = -1,
	top,
	middle,
	bottom
} bwhere_e;

//
// P_PLATS.C
//
typedef enum
{
	up,
	down,
	waiting,
	in_stasis
} plat_e;

// jff 3/15/98 pure texture/type change for better generalized support
typedef enum
{
	trigChangeOnly,
	numChangeOnly
} change_e;

typedef enum
{
	perpetualRaise,
	downWaitUpStay,
	raiseAndChange,
	raiseToNearestAndChange,
	blazeDWUS,
	genLift,            // jff added to support generalized Plat types
	genPerpetual,
	toggleUpDn
} plattype_e;

//
// P_DOORS.C
//
typedef enum
{
	doorNormal,
	doorClose30ThenOpen,
	doorClose,
	doorOpen,
	doorRaiseIn5Mins,
	doorBlazeRaise,
	doorBlazeOpen,
	doorBlazeClose,

	// jff 02/05/98 add generalized door types
	genRaise,
	genBlazeRaise,
	genOpen,
	genBlazeOpen,
	genClose,
	genBlazeClose,
	genCdO,
	genBlazeCdO
} vldoor_e;

//
// P_CEILING.C
//
typedef enum
{
	lowerToFloor,
	raiseToHighest,
	lowerToLowest,
	lowerToMaxFloor,
	lowerAndCrush,
	crushAndRaise,
	fastCrushAndRaise,
	silentCrushAndRaise,

	// jff 02/04/98 add types for generalized ceiling mover
	genCeiling,
	genCeilingChg,
	genCeilingChg0,
	genCeilingChgT,

	// jff 02/05/98 add types for generalized ceiling mover
	genCrusher,
	genSilentCrusher
} ceiling_e;

//
// P_FLOOR.C
//
typedef enum
{
	// lower floor to highest surrounding floor
	lowerFloor,

	// lower floor to lowest surrounding floor
	lowerFloorToLowest,

	// lower floor to highest surrounding floor VERY FAST
	turboLower,

	// raise floor to lowest surrounding CEILING
	raiseFloor,

	// raise floor to next highest surrounding floor
	raiseFloorToNearest,

	// jff 02/03/98 lower floor to next lowest neighbor
	lowerFloorToNearest,

	// jff 02/03/98 lower floor 24 absolute
	lowerFloor24,

	// jff 02/03/98 lower floor 32 absolute
	lowerFloor32Turbo,

	// raise floor to shortest height texture around it
	raiseToTexture,

	// lower floor to lowest surrounding floor
	//  and change floorpic
	lowerAndChange,

	raiseFloor24,

	// jff 02/03/98 raise floor 32 absolute
	raiseFloor32Turbo,

	raiseFloor24AndChange,
	raiseFloorCrush,

	// raise to next highest floor, turbo-speed
	raiseFloorTurbo,
	donutRaise,
	raiseFloor512,

	// jff 02/04/98  add types for generalized floor mover
	genFloor,
	genFloorChg,
	genFloorChg0,
	genFloorChgT,

	buildStair,
	genBuildStair
} floor_e;

typedef enum
{
	elevateUp,
	elevateDown,
	elevateCurrent
} elevator_e;

enum
{
	build8,     // slowly build by 8
	turbo16     // quickly build by 16
};

typedef enum
{
	ok,
	crushed,
	pastdest
} result_e;

// define names for the TriggerType field of the general linedefs
enum
{
	WalkOnce,
	WalkMany,
	SwitchOnce,
	SwitchMany,
	GunOnce,
	GunMany,
	PushOnce,
	PushMany
};

// define names for the Speed field of the general linedefs
enum
{
	SpeedSlow,
	SpeedNormal,
	SpeedFast,
	SpeedTurbo
};

// define names for the Target field of the general floor
enum
{
	FtoHnF,
	FtoLnF,
	FtoNnF,
	FtoLnC,
	FtoC,
	FbyST,
	Fby24,
	Fby32
};

// define names for the Changer Type field of the general floor
enum
{
	FNoChg,
	FChgZero,
	FChgTxt,
	FChgTyp
};

// define names for the Change Model field of the general floor
enum
{
	FTriggerModel,
	FNumericModel
};

// define names for the Target field of the general ceiling
enum
{
	CtoHnC,
	CtoLnC,
	CtoNnC,
	CtoHnF,
	CtoF,
	CbyST,
	Cby24,
	Cby32
};

// define names for the Changer Type field of the general ceiling
enum
{
	CNoChg,
	CChgZero,
	CChgTxt,
	CChgTyp
};

// define names for the Change Model field of the general ceiling
enum
{
	CTriggerModel,
	CNumericModel
};

// define names for the Target field of the general lift
enum
{
	F2LnF,
	F2NnF,
	F2LnC,
	LnF2HnF
};

// define names for the door Kind field of the general ceiling
enum
{
	OdCDoor,
	ODoor,
	CdODoor,
	CDoor
};

// define names for the locked door Kind field of the general ceiling
enum
{
	AnyKey,
	RCard,
	BCard,
	YCard,
	RSkull,
	BSkull,
	YSkull,
	AllKeys
};


#endif