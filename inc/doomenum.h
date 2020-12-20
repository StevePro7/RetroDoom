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



#endif