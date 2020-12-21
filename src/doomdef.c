//stevepro
#include "doomdef.h"


// i_video.c
#define I_SDLError(func)        I_Error("The call to " stringize(func) "() failed in %s() on line %i of %s with this error:\n" \
                                    "    \"%s\".", __FUNCTION__, __LINE__ - 1, leafname(__FILE__), SDL_GetError())

#define MAXDISPLAYS             8

#define MAXUPSCALEWIDTH         (1600 / VANILLAWIDTH)
#define MAXUPSCALEHEIGHT        (1200 / VANILLAHEIGHT)

#define SHAKEANGLE              ((double)M_BigRandomInt(-1000, 1000) * r_shake_damage / 100000.0)



// m_config.c
//#define NUMCVARS                                                197
//
//#define CONFIG_VARIABLE_INT(name, oldname, cvar, set)           { #name, #oldname, &cvar, DEFAULT_INT32,         set          }
//#define CONFIG_VARIABLE_INT_UNSIGNED(name, oldname, cvar, set)  { #name, #oldname, &cvar, DEFAULT_UINT64,        set          }
//#define CONFIG_VARIABLE_INT_PERCENT(name, oldname, cvar, set)   { #name, #oldname, &cvar, DEFAULT_INT32_PERCENT, set          }
//#define CONFIG_VARIABLE_FLOAT(name, oldname, cvar, set)         { #name, #oldname, &cvar, DEFAULT_FLOAT,         set          }
//#define CONFIG_VARIABLE_FLOAT_PERCENT(name, oldname, cvar, set) { #name, #oldname, &cvar, DEFAULT_FLOAT_PERCENT, set          }
//#define CONFIG_VARIABLE_STRING(name, oldname, cvar, set)        { #name, #oldname, &cvar, DEFAULT_STRING,        set          }
//#define CONFIG_VARIABLE_OTHER(name, oldname, cvar, set)         { #name, #oldname, &cvar, DEFAULT_OTHER,         set          }
//#define BLANKLINE                                               { "",     "",      NULL,  DEFAULT_OTHER,         NOVALUEALIAS }
//#define COMMENT(text)                                           { text,   "",      NULL,  DEFAULT_OTHER,         NOVALUEALIAS }


// s_sound.c
// when to clip out sounds
// Does not fit the large outdoor areas.
#define S_CLIPPING_DIST 1200

// Distance to origin when sounds should be maxed out.
// This should relate to movement clipping resolution
// (see BLOCKMAP handling).
// In the source code release: (160 * FRACUNIT). Changed back to the
// Vanilla value of 200 (why was this changed?)
#define S_CLOSE_DIST    200

// The range over which sound attenuates
#define S_ATTENUATOR    (S_CLIPPING_DIST - S_CLOSE_DIST)

// Stereo separation
#define S_STEREO_SWING  96

#define NORM_SEP        128

#define TIDNUM(x)       (int)(x->musicid & 0xFFFF)  // thing identifier


