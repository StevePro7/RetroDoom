//
//
//#if !defined(__P_MOBJ_H__)
//#define __P_MOBJ_H__
//
////
//// Misc. mobj flags
////
//enum
//{
//	// Call P_SpecialThing when touched.
//	MF_SPECIAL = 0x00000001,
//	// Blocks.
//	MF_SOLID = 0x00000002,
//	// Can be hit.
//	MF_SHOOTABLE = 0x00000004,
//	// Don't use the sector links (invisible but touchable).
//	MF_NOSECTOR = 0x00000008,
//	// Don't use the blocklinks (inert but displayable)
//	MF_NOBLOCKMAP = 0x00000010,
//
//	// Not to be activated by sound, deaf monster.
//	MF_AMBUSH = 0x00000020,
//	// Will try to attack right back.
//	MF_JUSTHIT = 0x00000040,
//	// Will take at least one step before attacking.
//	MF_JUSTATTACKED = 0x00000080,
//	// On level spawning (initial position),
//	//  hang from ceiling instead of stand on floor.
//	MF_SPAWNCEILING = 0x00000100,
//	// Don't apply gravity (every tic),
//	//  that is, object will float, keeping current height
//	//  or changing it actively.
//	MF_NOGRAVITY = 0x00000200,
//
//	// Movement flags.
//	// This allows jumps from high places.
//	MF_DROPOFF = 0x00000400,
//	// For players, will pick up items.
//	MF_PICKUP = 0x00000800,
//	// Player cheat. ???
//	MF_NOCLIP = 0x00001000,
//	// Player: keep info about sliding along walls.
//	MF_SLIDE = 0x00002000,
//	// Allow moves to any height, no gravity.
//	// For active floaters, e.g. cacodemons, pain elementals.
//	MF_FLOAT = 0x00004000,
//	// Don't cross lines
//	//   ??? or look at heights on teleport.
//	MF_TELEPORT = 0x00008000,
//	// Don't hit same species, explode on block.
//	// Player missiles as well as fireballs of various kinds.
//	MF_MISSILE = 0x00010000,
//	// Dropped by a demon, not level spawned.
//	// E.g. ammo clips dropped by dying former humans.
//	MF_DROPPED = 0x00020000,
//	// Use fuzzy draw (spectres),
//	//  temporary player invisibility powerup.
//	MF_FUZZ = 0x00040000,
//	// Flag: don't bleed when shot (use puff),
//	//  barrels and shootable furniture shall not bleed.
//	MF_NOBLOOD = 0x00080000,
//	// Don't stop moving halfway off a step,
//	//  that is, have dead bodies slide down all the way.
//	MF_CORPSE = 0x00100000,
//	// Floating to a height for a move, ???
//	//  don't auto float to target's height.
//	MF_INFLOAT = 0x00200000,
//
//	// On kill, count this enemy object
//	//  towards intermission kill total.
//	// Happy gathering.
//	MF_COUNTKILL = 0x00400000,
//
//	// On picking up, count this item object
//	//  towards intermission item total.
//	MF_COUNTITEM = 0x00800000,
//
//	// Special handling: skull in flight.
//	// Neither a cacodemon nor a missile.
//	MF_SKULLFLY = 0x01000000,
//
//	// Don't spawn this object
//	//  in death match mode (e.g. key cards).
//	MF_NOTDMATCH = 0x02000000,
//
//	// Player sprites in multiplayer modes are modified
//	//  using an internal color lookup table for re-indexing.
//	// If 0x04 0x08 or 0x0C,
//	//  use a translation table for player colormaps
//	MF_TRANSLATION = 0x0C000000,
//
//	// Hmm ???.
//	MF_TRANSLATIONSHIFT = 0x0000001A,
//
//	MF_TOUCHY = 0x10000000,   // killough 11/98: dies when solids touch it
//	MF_BOUNCES = 0x20000000,   // killough 07/11/98: for beta BFG fireballs
//	MF_FRIEND = 0x40000000,   // killough 07/18/98: friendly monsters
//
//							  // Translucent sprite?              // phares
//							  MF_TRANSLUCENT = 0x80000000    // phares
//};
//
//// Apply additive translucency
//#define MF2_TRANSLUCENT                 0x00000001
//
//// Apply additive translucency on red only
//#define MF2_TRANSLUCENT_REDONLY         0x00000002
//
//// Apply additive translucency on green only
//#define MF2_TRANSLUCENT_GREENONLY       0x00000004
//
//// Apply additive translucency on blue only
//#define MF2_TRANSLUCENT_BLUEONLY        0x00000008
//
//// Apply 33% alpha translucency
//#define MF2_TRANSLUCENT_33              0x00000010
//
//// Apply 50% alpha translucency
//#define MF2_TRANSLUCENT_50              0x00000020
//
//// Apply additive translucency on all red to white
//#define MF2_TRANSLUCENT_REDWHITEONLY    0x00000040
//
//// Convert all red to green, then apply 33% alpha translucency
//#define MF2_TRANSLUCENT_REDTOGREEN_33   0x00000080
//
//// Convert all red to blue, then apply 33% alpha translucency
//#define MF2_TRANSLUCENT_REDTOBLUE_33    0x00000100
//
//// Apply 33% alpha translucency on all blue
//#define MF2_TRANSLUCENT_BLUE_25         0x00000200
//
//// Convert all red to green
//#define MF2_REDTOGREEN                  0x00000400
//// Convert all green to red
//#define MF2_GREENTORED                  0x00000800
//// Convert all red to blue
//#define MF2_REDTOBLUE                   0x00001000
//
//// Object bobs up and down
//#define MF2_FLOATBOB                    0x00002000
//
//// Mirrored horizontally
//#define MF2_MIRRORED                    0x00004000
//
//#define MF2_FALLING                     0x00008000
//
//// Object is resting on top of another object
//#define MF2_ONMOBJ                      0x00010000
//
//// Object is allowed to pass over/under other objects
//#define MF2_PASSMOBJ                    0x00020000
//
//// Object is a corpse and being resurrected
//#define MF2_RESURRECTING                0x00040000
//
//// Object's feet will be clipped in liquid
//#define MF2_FOOTCLIP                    0x00080000
//
//// Object won't bob in liquid
//#define MF2_NOLIQUIDBOB                 0x00100000
//
//// Object's feet are now being clipped
//#define MF2_FEETARECLIPPED              0x00200000
//
//// Object casts a shadow
//#define MF2_CASTSHADOW                  0x00400000
//
//// Object is blood
//#define MF2_BLOOD                       0x00800000
//
//// Object's thing triangle is not displayed in automap
//#define MF2_DONTMAP                     0x01000000
//
//// Object has smoke trail
//#define MF2_SMOKETRAIL                  0x02000000
//
//// Object can be crushed into blood splats by moving sectors
//#define MF2_CRUSHABLE                   0x04000000
//
//// All objects are being killed
//#define MF2_MASSACRE                    0x08000000
//
//// Object is a map decoration
//#define MF2_DECORATION                  0x10000000
//
//// Object is a missile from a monster
//#define MF2_MONSTERMISSILE              0x40000000
//
//// Object is a boss monster
//#define MF2_BOSS                        0x80000000
//
//// Object is armed (for MF_TOUCHY objects)
//#define MF3_ARMED                       0x00000001
//
//// Object was spawned by played using spawn CCMD
//#define MF3_SPAWNEDBYPLAYER             0x00000002
//
//// Object has higher attack probability
//#define MF3_MISSILEMORE                 0x00000004
//
//typedef enum
//{
//	DI_EAST,
//	DI_NORTHEAST,
//	DI_NORTH,
//	DI_NORTHWEST,
//	DI_WEST,
//	DI_SOUTHWEST,
//	DI_SOUTH,
//	DI_SOUTHEAST,
//	DI_NODIR,
//	NUMDIRS
//} dirtype_t;
//
//#endif
