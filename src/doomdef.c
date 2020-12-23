//stevepro
#include "doomdef.h"


// i_video.c
//#define I_SDLError(func)        I_Error("The call to " stringize(func) "() failed in %s() on line %i of %s with this error:\n" \
//                                    "    \"%s\".", __FUNCTION__, __LINE__ - 1, leafname(__FILE__), SDL_GetError())

#define MAXDISPLAYS             8

#define MAXUPSCALEWIDTH         (1600 / VANILLAWIDTH)
#define MAXUPSCALEHEIGHT        (1200 / VANILLAHEIGHT)

//#define SHAKEANGLE              ((double)M_BigRandomInt(-1000, 1000) * r_shake_damage / 100000.0)



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


// c_cmds.c
#define ALIASCMDFORMAT              "<i>alias</i> [[<b>\"</b>]<i>command</i>[<b>;</b> <i>command</i> ...<b>\"</b>]]"
#define BINDCMDFORMAT               "<i>control</i> [<b>+</b><i>action</i>|[<b>\"</b>]<i>command</i>[<b>;</b> <i>command</i> ...<b>\"</b>]]"
#define EXECCMDFORMAT               "<i>filename</i><b>.cfg</b>"
#define GIVECMDFORMAT               "<b>ammo</b>|<b>armor</b>|<b>health</b>|<b>keys</b>|<b>weapons</b>|<b>all</b>|<i>item</i>"
#define IFCMDFORMAT                 "<i>CVAR</i> <i>value</i> <b>then</b> [<b>\"</b>]<i>command</i>[<b>;</b> <i>command</i> ...<b>\"</b>]"
#define KILLCMDFORMAT               "<b>player</b>|<b>all</b>|<i>monster</i>|<b>barrels</b>|<b>missiles</b>"
#define LOADCMDFORMAT               "<i>filename</i><b>.save</b>"
#define MAPCMDFORMAT1               "<b>E</b><i>x</i><b>M</b><i>y</i>[<b>B</b>]|<i>title</i>|<b>first</b>|<b>previous</b>|<b>next</b>|<b>last</b>|<b>random</b>"
#define MAPCMDFORMAT2               "<b>MAP</b><i>xy</i>|<i>title</i>|<b>first</b>|<b>previous</b>|<b>next</b>|<b>last</b>|<b>random</b>"
#define PLAYCMDFORMAT               "<i>soundeffect</i>|<i>music</i>"
#define NAMECMDFORMAT               "[<b>friendly</b> ]<i>monster</i> <i>name</i>"
#define PRINTCMDFORMAT              "<b>\"</b><i>message</i><b>\"</b>"
#define RESETCMDFORMAT              "<i>CVAR</i>"
#define RESURRECTCMDFORMAT          "<b>player</b>|<b>all</b>|<i>monster</i>"
#define SAVECMDFORMAT               "<i>filename</i><b>.save</b>"
#define SPAWNCMDFORMAT              "<i>item</i>|[<b>friendly</b> ]<i>monster</i>"
#define TAKECMDFORMAT               "<b>ammo</b>|<b>armor</b>|<b>health</b>|<b>keys</b>|<b>weapons</b>|<b>all</b>|<i>item</i>"
#define TELEPORTCMDFORMAT           "<i>x</i> <i>y</i>[ <i>z</i>]"
#define TIMERCMDFORMAT              "<i>minutes</i>"
#define UNBINDCMDFORMAT             "<i>control</i>|<b>+</b><i>action</i>"

#define PENDINGCHANGE               "This change won't be effective until the next map."

#define INTEGERCVARWITHDEFAULT      "It is <b>%s</b> and is <b>%s</b> by default."
#define INTEGERCVARWITHNODEFAULT    "It is <b>%s</b>."
#define INTEGERCVARISDEFAULT        "It is its default of <b>%s</b>."
#define INTEGERCVARISREADONLY       "It is <b>%s</b> and is read-only."
#define PERCENTCVARWITHDEFAULT      "It is <b>%s%%</b> and is <b>%s%%</b> by default."
#define PERCENTCVARWITHNODEFAULT    "It is <b>%s%%</b>."
#define PERCENTCVARISDEFAULT        "It is its default of <b>%s%%</b>."
#define PERCENTCVARISREADONLY       "It is <b>%s%%</b> and is read-only."
#define STRINGCVARWITHDEFAULT       "It is <b>\"%s\"</b> and is <b>\"%s\"</b> by default."
#define STRINGCVARISDEFAULT         "It is its default of <b>\"%s\"</b>."
#define STRINGCVARISREADONLY        "It is <b>%s%s%s</b> and is read-only."
#define TIMECVARISREADONLY          "It is <b>%02i:%02i:%02i</b> and is read-only."

#define UNITSPERFOOT                16
#define FEETPERMETER                3.28084f
#define METERSPERKILOMETER          1000.0f
#define FEETPERMILE                 5280