#if !defined(__DOOMDEF_H__)
#define __DOOMDEF_H__

#include "doomenum.h"
#include "version.h"

//
// The packed attribute forces structures to be packed into the minimum
// space necessary. If this is not done, the compiler may align structure
// fields differently to optimize memory access, inflating the overall
// structure size. It is important to use the packed attribute on certain
// structures where alignment is important, particularly data read/written
// to disk.
//
#if defined(__GNUC__)

#if defined(_WIN32) && !defined(__clang__)
#define PACKEDATTR  __attribute__((packed,gcc_struct))
#else
#define PACKEDATTR  __attribute__((packed))
#endif

#else
#define PACKEDATTR
#endif

//
// Global parameters/defines.
//
#define DOOM1AND2   0
#define DOOM1ONLY   1
#define DOOM2ONLY   2


// Screen width and height.
#define VANILLAWIDTH        320
#define VANILLAHEIGHT       200

#define UNITYWIDTH          426

#define VANILLASBARHEIGHT   32

#define SCREENSCALE         2

#define SCREENWIDTH         (VANILLAWIDTH * SCREENSCALE)
#define SCREENHEIGHT        (VANILLAHEIGHT * SCREENSCALE)
#define SCREENAREA          (SCREENWIDTH * SCREENHEIGHT)

#define SBARHEIGHT          (VANILLASBARHEIGHT * SCREENSCALE)

// State updates, number of tics/second.
//#define TICRATE             35

#define CARETBLINKTIME      350



//
// Difficulty/skill settings/filters.
//

// Skill flags.
#define MTF_EASY        1
#define MTF_NORMAL      2
#define MTF_HARD        4

// Deaf monsters/do not react to sound.
#define MTF_AMBUSH      8

// killough 11/98
#define MTF_NOTSINGLE   16
#define MTF_NOTDM       32
#define MTF_NOTCOOP     64
#define MTF_FRIEND      128
#define MTF_RESERVED    256



#define STARTFLASHING           127

// Index of the special effects (INVUL inverse) map.
#define INVERSECOLORMAP         32

// phares 03/20/98:
//
// Player friction is variable, based on controlling
// linedefs. More friction can create mud, sludge,
// magnetized floors, etc. Less friction can create ice.
#define MORE_FRICTION_MOMENTUM  15000   // mud factor based on momentum
#define ORIG_FRICTION           0xE800  // original value
#define ORIG_FRICTION_FACTOR    2048    // original value


// NEW
// i_video.h
#define MAX_MOUSE_BUTTONS   8
#define GAMMALEVELS         31


// m_fixed.h
//
// Fixed point, 32bit as 16.16.
//
#define FRACBITS        16
#define FRACUNIT        65536
#define FIXED2DOUBLE(a) ((a) / (double)FRACUNIT)
#define FIXED_MIN       INT32_MIN
#define FIXED_MAX       INT32_MAX
#define SWAP(a, b)      (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))



// m_config.h
#define alwaysrun_default                       false

#define am_allmapcdwallcolor_min                0
#define am_allmapcdwallcolor_default            106
#define am_allmapcdwallcolor_max                255

#define am_allmapfdwallcolor_min                0
#define am_allmapfdwallcolor_default            110
#define am_allmapfdwallcolor_max                255

#define am_allmapwallcolor_min                  0
#define am_allmapwallcolor_default              108
#define am_allmapwallcolor_max                  255

#define am_backcolor_min                        0
#define am_backcolor_default                    0
#define am_backcolor_max                        255

#define am_cdwallcolor_min                      0
#define am_cdwallcolor_default                  160
#define am_cdwallcolor_max                      255

#define am_crosshaircolor_min                   0
#define am_crosshaircolor_default               4
#define am_crosshaircolor_max                   255

#define am_external_default                     false

#define am_fdwallcolor_min                      0
#define am_fdwallcolor_default                  64
#define am_fdwallcolor_max                      255

#define am_followmode_default                   true

#define am_grid_default                         false

#define am_gridcolor_min                        0
#define am_gridcolor_default                    111
#define am_gridcolor_max                        255

#define am_gridsize_default                     "128x128"

#define am_markcolor_min                        0
#define am_markcolor_default                    95
#define am_markcolor_max                        255

#define am_path_default                         false

#define am_pathcolor_min                        0
#define am_pathcolor_default                    95
#define am_pathcolor_max                        255

#define am_playercolor_min                      0
#define am_playercolor_default                  4
#define am_playercolor_max                      255

#define am_rotatemode_default                   true

#define am_teleportercolor_min                  0
#define am_teleportercolor_default              184
#define am_teleportercolor_max                  255

#define am_thingcolor_min                       0
#define am_thingcolor_default                   112
#define am_thingcolor_max                       255

#define am_tswallcolor_min                      0
#define am_tswallcolor_default                  104
#define am_tswallcolor_max                      255

#define am_wallcolor_min                        0
#define am_wallcolor_default                    176
#define am_wallcolor_max                        255

#define ammo_min                                0
#define ammo_default                            50
#define ammo_max                                INT_MAX

#define armor_min                               0
#define armor_default                           0
#define armor_max                               INT_MAX

#define armortype_min                           armortype_none
#define armortype_default                       armortype_none
#define armortype_max                           armortype_blue

#define autoaim_default                         true

#define autoload_default                        true

#define autosave_default                        true

#define autotilt_default                        false

#define autouse_default                         false

#define centerweapon_default                    true

#define con_backcolor_min                       0
#define con_backcolor_default                   12
#define con_backcolor_max                       255

#define con_edgecolor_min                       0
#define con_edgecolor_default                   180
#define con_edgecolor_max                       255

#define con_obituaries_default                  true

#define crosshair_min                           crosshair_none
#define crosshair_default                       crosshair_none
#define crosshair_max                           crosshair_dot

#define crosshaircolor_min                      0
#define crosshaircolor_default                  4
#define crosshaircolor_max                      255

#define episode_min                             1
#define episode_default                         1
#define episode_max                             5

#define expansion_min                           1
#define expansion_default                       1
#define expansion_max                           2

#define facebackcolor_min                       0
#define facebackcolor_default                   5
#define facebackcolor_max                       255

#define fade_default                            true

#define gp_analog_default                       true

#define gp_deadzone_left_min                    0.0f
#define gp_deadzone_left_default                24.0f
#define gp_deadzone_left_max                    100.0f

#define gp_deadzone_right_min                   0.0f
#define gp_deadzone_right_default               26.5f
#define gp_deadzone_right_max                   100.0f

#define gp_invertyaxis_default                  false

#define gp_sensitivity_horizontal_min           0
#define gp_sensitivity_horizontal_default       64
#define gp_sensitivity_horizontal_max           128

#define gp_sensitivity_vertical_min             0
#define gp_sensitivity_vertical_default         64
#define gp_sensitivity_vertical_max             128

#define gp_swapthumbsticks_default              false

#define gp_thumbsticks_min                      1
#define gp_thumbsticks_default                  2
#define gp_thumbsticks_max                      2

#define gp_vibrate_barrels_min                  0
#define gp_vibrate_barrels_default              100
#define gp_vibrate_barrels_max                  200

#define gp_vibrate_damage_min                   0
#define gp_vibrate_damage_default               100
#define gp_vibrate_damage_max                   200

#define gp_vibrate_weapons_min                  0
#define gp_vibrate_weapons_default              100
#define gp_vibrate_weapons_max                  200

#define health_min                              -100
#define health_default                          100
#define health_max                              INT_MAX

#define infighting_default                      true

#define infiniteheight_default                  false

#if defined(_WIN32)
#define iwadfolder_default                      "C:\\"
#else
#define iwadfolder_default                      "/"
#endif

#define m_acceleration_default                  true

#define m_doubleclick_use_default               false

#define m_invertyaxis_default                   false

#define m_novertical_default                    true

#define m_sensitivity_min                       0
#define m_sensitivity_default                   16
#define m_sensitivity_max                       128

#define melt_default                            true

#define messages_default                        false

#define mouselook_default                       false

#define movebob_min                             0
#define movebob_default                         75
#define movebob_max                             100

#define playername_default                      "you"

#define r_althud_default                        false

#define r_berserkintensity_min                  0
#define r_berserkintensity_default              2
#define r_berserkintensity_max                  8

#define r_blood_min                             r_blood_none
#define r_blood_default                         r_blood_all
#define r_blood_max                             r_blood_nofuzz

#define r_bloodsplats_max_min                   0
#define r_bloodsplats_max_default               65536
#define r_bloodsplats_max_max                   1048576

#define r_bloodsplats_total_min                 0
#define r_bloodsplats_total_default             0
#define r_bloodsplats_total_max                 0

#define r_bloodsplats_translucency_default      true

#define r_brightmaps_default                    true

#define r_color_min                             0
#define r_color_default                         100
#define r_color_max                             100

#define r_corpses_color_default                 true

#define r_corpses_gib_default                   true

#define r_corpses_mirrored_default              true

#define r_corpses_moreblood_default             true

#define r_corpses_nudge_default                 true

#define r_corpses_slide_default                 true

#define r_corpses_smearblood_default            true

#define r_detail_default                        r_detail_high

#define r_diskicon_default                      false

#define r_dither_default                        false

#define r_fixmaperrors_default                  true

#define r_fixspriteoffsets_default              true

#define r_floatbob_default                      true

#define r_fov_min                               45
#define r_fov_default                           90
#define r_fov_max                               135

////#define r_gamma_min                             gammalevels[0]
#define r_gamma_default                         0.90f
////#define r_gamma_max                             gammalevels[GAMMALEVELS - 1]

#define r_graduallighting_default               true

#define r_homindicator_default                  false

#define r_hud_default                           true

#define r_hud_translucency_default              true

#define r_liquid_bob_default                    true

#define r_liquid_clipsprites_default            true

#define r_liquid_current_default                true

#define r_liquid_lowerview_default              true

#define r_liquid_swirl_default                  true

#define r_lowpixelsize_default                  "2x2"

#define r_mirroredweapons_default               false

#define r_playersprites_default                 true

#define r_rockettrails_default                  true

#define r_screensize_min                        0
#define r_screensize_default                    7
#define r_screensize_max                        7

#define r_shadows_default                       true

#define r_shadows_translucency_default          true

#define r_shake_barrels_default                 true

#define r_shake_damage_min                      0
#define r_shake_damage_default                  50
#define r_shake_damage_max                      100

#define r_skycolor_none                         -1
#define r_skycolor_min                          0
#define r_skycolor_default                      r_skycolor_none
#define r_skycolor_max                          255

#define r_supersampling_default                 true

#define r_textures_default                      true

#define r_translucency_default                  true

#define s_channels_min                          8
#define s_channels_default                      32
#define s_channels_max                          64

#define s_musicvolume_min                       0
#define s_musicvolume_default                   100
#define s_musicvolume_max                       100

#define s_randommusic_default                   false

#define s_randompitch_default                   false

#define s_sfxvolume_min                         0
#define s_sfxvolume_default                     100
#define s_sfxvolume_max                         100

#define s_stereo_default                        true

#define savegame_min                            1
#define savegame_default                        1
#define savegame_max                            6

#define skilllevel_min                          1
#define skilllevel_default                      3
#define skilllevel_max                          5

#define stillbob_min                            0
#define stillbob_default                        0
#define stillbob_max                            100

#define tossdrop_default                        true

#define turbo_min                               10
#define turbo_default                           100
#define turbo_max                               400

#define units_default                           units_imperial

#define version_default                         PACKAGE_VERSIONSTRING

#define vid_borderlesswindow_default            true

#define vid_capfps_min                          0
#define vid_capfps_default                      200
#define vid_capfps_max                          1000

#define vid_display_min                         1
#define vid_display_default                     1
#define vid_display_max                         INT_MAX

#if !defined(_WIN32)
#define vid_driver_default                      ""
#endif

#define vid_fullscreen_default                  true

#define vid_motionblur_min                      0
#define vid_motionblur_default                  0
#define vid_motionblur_max                      100

#define vid_pillarboxes_default                 false

#if defined(_WIN32)
#define vid_scaleapi_direct3d                   "direct3d"
#elif defined(__APPLE__)
#define vid_scaleapi_metal                      "metal"
#endif
#define vid_scaleapi_opengl                     "opengl"
#if !defined(_WIN32)
#define vid_scaleapi_opengles                   "opengles"
#define vid_scaleapi_opengles2                  "opengles2"
#endif
#define vid_scaleapi_software                   "software"
#define vid_scaleapi_default                    vid_scaleapi_opengl

#define vid_scalefilter_linear                  "linear"
#define vid_scalefilter_nearest                 "nearest"
#define vid_scalefilter_nearest_linear          "nearest_linear"
#define vid_scalefilter_default                 vid_scalefilter_nearest_linear

#define vid_screenresolution_desktop            "desktop"
#define vid_screenresolution_default            vid_screenresolution_desktop

#define vid_showfps_default                     false

#define vid_vsync_min                           vid_vsync_adaptive
#define vid_vsync_default                       vid_vsync_on
#define vid_vsync_max                           vid_vsync_on

#define vid_widescreen_default                  false

#define vid_windowpos_centered                  "centered"
#define vid_windowpos_centred                   "centred"
#define vid_windowpos_default                   vid_windowpos_centered

#define vid_windowsize_default                  "768x480"

#if defined(_WIN32)
#define wad_default                             ""
#endif

#define warninglevel_min                        0
#define warninglevel_default                    1
#define warninglevel_max                        2

#define weaponbob_min                           0
#define weaponbob_default                       75
#define weaponbob_max                           100

#define weaponbounce_default                    true

#define weaponrecoil_default                    false

//#define GAMEPADALWAYSRUN_DEFAULT                0
//#define GAMEPADAUTOMAP_DEFAULT                  GAMEPAD_BACK
//#define GAMEPADAUTOMAPCLEARMARK_DEFAULT         0
//#define GAMEPADAUTOMAPFOLLOWMODE_DEFAULT        0
//#define GAMEPADAUTOMAPGRID_DEFAULT              0
//#define GAMEPADAUTOMAPMARK_DEFAULT              0
//#define GAMEPADAUTOMAPMAXZOOM_DEFAULT           0
//#define GAMEPADAUTOMAPROTATEMODE_DEFAULT        0
//#define GAMEPADAUTOMAPZOOMIN_DEFAULT            GAMEPAD_RIGHT_SHOULDER
//#define GAMEPADAUTOMAPZOOMOUT_DEFAULT           GAMEPAD_LEFT_SHOULDER
//#define GAMEPADBACK_DEFAULT                     0
//#define GAMEPADFIRE_DEFAULT                     GAMEPAD_RIGHT_TRIGGER
//#define GAMEPADFORWARD_DEFAULT                  0
//#define GAMEPADJUMP_DEFAULT                     0
//#define GAMEPADLEFT_DEFAULT                     0
//#define GAMEPADMENU_DEFAULT                     GAMEPAD_START
//#define GAMEPADMOUSELOOK_DEFAULT                0
//#define GAMEPADNEXTWEAPON_DEFAULT               GAMEPAD_B
//#define GAMEPADPREVWEAPON_DEFAULT               GAMEPAD_Y
//#define GAMEPADRIGHT_DEFAULT                    0
//#define GAMEPADRUN_DEFAULT                      GAMEPAD_LEFT_TRIGGER
//#define GAMEPADSTRAFE_DEFAULT                   0
//#define GAMEPADSTRAFELEFT_DEFAULT               0
//#define GAMEPADSTRAFERIGHT_DEFAULT              0
//#define GAMEPADUSE_DEFAULT                      GAMEPAD_A
//#define GAMEPADUSE2_DEFAULT                     GAMEPAD_RIGHT_THUMB
//#define GAMEPADWEAPON_DEFAULT                   0

//#define KEYALWAYSRUN_DEFAULT                    KEY_CAPSLOCK
//#define KEYAUTOMAP_DEFAULT                      KEY_TAB
//#define KEYAUTOMAPCLEARMARK_DEFAULT             'c'
//#define KEYAUTOMAPFOLLOWMODE_DEFAULT            'f'
//#define KEYAUTOMAPGRID_DEFAULT                  'g'
//#define KEYAUTOMAPMARK_DEFAULT                  'm'
//#define KEYAUTOMAPMAXZOOM_DEFAULT               '0'
//#define KEYAUTOMAPROTATEMODE_DEFAULT            'r'
//#define KEYAUTOMAPZOOMIN_DEFAULT                KEY_EQUALS
//#define KEYAUTOMAPZOOMOUT_DEFAULT               KEY_MINUS
//#define KEYCONSOLE_DEFAULT                      '`'
//#define KEYDOWN_DEFAULT                         KEY_DOWNARROW
//#define KEYDOWN2_DEFAULT                        's'
//#define KEYFIRE_DEFAULT                         KEY_CTRL
//#define KEYJUMP_DEFAULT                         0
//#define KEYLEFT_DEFAULT                         KEY_LEFTARROW
//#define KEYMOUSELOOK_DEFAULT                    0
//#define KEYNEXTWEAPON_DEFAULT                   0
//#define KEYPREVWEAPON_DEFAULT                   0
//#define KEYRIGHT_DEFAULT                        KEY_RIGHTARROW
//#define KEYRUN_DEFAULT                          KEY_SHIFT
//#if defined(_WIN32)
//#define KEYSCREENSHOT_DEFAULT                   KEY_PRINTSCREEN
//#else
//#define KEYSCREENSHOT_DEFAULT                   0
//#endif
//#define KEYSTRAFE_DEFAULT                       KEY_ALT
//#define KEYSTRAFELEFT_DEFAULT                   ','
//#define KEYSTRAFELEFT2_DEFAULT                  'a'
//#define KEYSTRAFERIGHT_DEFAULT                  '.'
//#define KEYSTRAFERIGHT2_DEFAULT                 'd'
//#define KEYUP_DEFAULT                           KEY_UPARROW
//#define KEYUP2_DEFAULT                          'w'
//#define KEYUSE_DEFAULT                          ' '
//#define KEYUSE2_DEFAULT                         'e'
//#define KEYWEAPON1_DEFAULT                      '1'
//#define KEYWEAPON2_DEFAULT                      '2'
//#define KEYWEAPON3_DEFAULT                      '3'
//#define KEYWEAPON4_DEFAULT                      '4'
//#define KEYWEAPON5_DEFAULT                      '5'
//#define KEYWEAPON6_DEFAULT                      '6'
//#define KEYWEAPON7_DEFAULT                      '7'
//
//#define MOUSEFIRE_DEFAULT                       0
//#define MOUSEFORWARD_DEFAULT                    -1
//#define MOUSEJUMP_DEFAULT                       -1
//#define MOUSEMOUSELOOK_DEFAULT                  -1
//#define MOUSENEXTWEAPON_DEFAULT                 MOUSE_WHEELDOWN
//#define MOUSEPREVWEAPON_DEFAULT                 MOUSE_WHEELUP
//#define MOUSERUN_DEFAULT                        -1
//#define MOUSESCREENSHOT_DEFAULT                 -1
//#define MOUSESTRAFE_DEFAULT                     -1
//#define MOUSEUSE_DEFAULT                        -1

// stevepro
//#define MAX_MOUSE_BUTTONS   8
//#define MOUSE_WHEELUP       MAX_MOUSE_BUTTONS
//#define MOUSE_WHEELDOWN     (MAX_MOUSE_BUTTONS + 1)
// stevepro


// p_mobj.h
#define REDBLOOD            184
#define GREENBLOOD          123
#define BLUEBLOOD           204
#define FUZZYBLOOD          -1

// For torque simulation:
#define OVERDRIVE           6
#define MAXGEAR             (OVERDRIVE + 16)

// Whether an object is "sentient" or not. Used for environmental influences.
#define sentient(mobj)      (mobj->health > 0 && mobj->info->seestate)

#define CORPSEBLOODSPLATS   512

// Apply additive translucency
#define MF2_TRANSLUCENT                 0x00000001

// Apply additive translucency on red only
#define MF2_TRANSLUCENT_REDONLY         0x00000002

// Apply additive translucency on green only
#define MF2_TRANSLUCENT_GREENONLY       0x00000004

// Apply additive translucency on blue only
#define MF2_TRANSLUCENT_BLUEONLY        0x00000008

// Apply 33% alpha translucency
#define MF2_TRANSLUCENT_33              0x00000010

// Apply 50% alpha translucency
#define MF2_TRANSLUCENT_50              0x00000020

// Apply additive translucency on all red to white
#define MF2_TRANSLUCENT_REDWHITEONLY    0x00000040

// Convert all red to green, then apply 33% alpha translucency
#define MF2_TRANSLUCENT_REDTOGREEN_33   0x00000080

// Convert all red to blue, then apply 33% alpha translucency
#define MF2_TRANSLUCENT_REDTOBLUE_33    0x00000100

// Apply 33% alpha translucency on all blue
#define MF2_TRANSLUCENT_BLUE_25         0x00000200

// Convert all red to green
#define MF2_REDTOGREEN                  0x00000400
// Convert all green to red
#define MF2_GREENTORED                  0x00000800
// Convert all red to blue
#define MF2_REDTOBLUE                   0x00001000

// Object bobs up and down
#define MF2_FLOATBOB                    0x00002000

// Mirrored horizontally
#define MF2_MIRRORED                    0x00004000

#define MF2_FALLING                     0x00008000

// Object is resting on top of another object
#define MF2_ONMOBJ                      0x00010000

// Object is allowed to pass over/under other objects
#define MF2_PASSMOBJ                    0x00020000

// Object is a corpse and being resurrected
#define MF2_RESURRECTING                0x00040000

// Object's feet will be clipped in liquid
#define MF2_FOOTCLIP                    0x00080000

// Object won't bob in liquid
#define MF2_NOLIQUIDBOB                 0x00100000

// Object's feet are now being clipped
#define MF2_FEETARECLIPPED              0x00200000

// Object casts a shadow
#define MF2_CASTSHADOW                  0x00400000

// Object is blood
#define MF2_BLOOD                       0x00800000

// Object's thing triangle is not displayed in automap
#define MF2_DONTMAP                     0x01000000

// Object has smoke trail
#define MF2_SMOKETRAIL                  0x02000000

// Object can be crushed into blood splats by moving sectors
#define MF2_CRUSHABLE                   0x04000000

// All objects are being killed
#define MF2_MASSACRE                    0x08000000

// Object is a map decoration
#define MF2_DECORATION                  0x10000000

// Object is a missile from a monster
#define MF2_MONSTERMISSILE              0x40000000

// Object is a boss monster
#define MF2_BOSS                        0x80000000

// Object is armed (for MF_TOUCHY objects)
#define MF3_ARMED                       0x00000001

// Object was spawned by played using spawn CCMD
#define MF3_SPAWNEDBYPLAYER             0x00000002

// Object has higher attack probability
#define MF3_MISSILEMORE                 0x00000004


// r_defs.h
// Silhouette, needed for clipping Segs (mainly)
// and sprites representing things.
#define SIL_NONE    0
#define SIL_BOTTOM  1
#define SIL_TOP     2
#define SIL_BOTH    3

#define MAXDRAWSEGS 1280
#define MAXOPENINGS 16384


// p_local.h
#define FOOTCLIPSIZE        (10 * FRACUNIT)

#define FLOATSPEED          (4 * FRACUNIT)

#define VIEWHEIGHT          (41 * FRACUNIT)
#define DEADVIEWHEIGHT      (6 * FRACUNIT)
#define JUMPHEIGHT          (9 * FRACUNIT)

#define DEADLOOKDIR         128

// mapblocks are used to check movement
// against lines and things
#define MAPBLOCKUNITS       128
#define MAPBLOCKSIZE        (MAPBLOCKUNITS * FRACUNIT)
#define MAPBLOCKSHIFT       (FRACBITS + 7)
#define MAPBTOFRAC          (MAPBLOCKSHIFT - FRACBITS)

// MAXRADIUS is for precalculated sector block boxes
// the spider demon is larger,
// but we do not have any moving sectors nearby
#define MAXRADIUS           (32 * FRACUNIT)

#define GRAVITY             FRACUNIT
#define MAXMOVE             (30 * FRACUNIT)
#define MAXMOVE_STEP        (8 * FRACUNIT)

#define USERANGE            (64 * FRACUNIT)
#define MELEERANGE          (64 * FRACUNIT)
#define MISSILERANGE        (32 * 64 * FRACUNIT)

// follow a player exclusively for 3 seconds
#define BASETHRESHOLD       100

#define BONUSADD            6

#define MOUSE_LEFTBUTTON    1
#define MOUSE_RIGHTBUTTON   2

#define MOUSE_WHEELUP       MAX_MOUSE_BUTTONS
#define MOUSE_WHEELDOWN     (MAX_MOUSE_BUTTONS + 1)

#define NEEDEDCARDFLASH     8

#define WEAPONBOTTOM        (128 * FRACUNIT)
#define WEAPONTOP           (32 * FRACUNIT)

//
// P_USER.C
//
// 16 pixels of bob
#define MAXBOB              0x100000
#define MLOOKUNIT           8
#define PLAYERSLOPE(a)      ((((a)->lookdir / MLOOKUNIT) << FRACBITS) / 153)

//
// P_MOBJ.C
//
#define ONFLOORZ            FIXED_MIN
#define ONCEILINGZ          FIXED_MAX

// Time interval for item respawning.
#define ITEMQUEUESIZE       512

#define CARDNOTFOUNDYET    -1
#define CARDNOTINMAP        0

//
// P_ENEMY.C
//
#define BARRELMS    1500

#define PT_ADDLINES     1
#define PT_ADDTHINGS    2

//
// P_INTER.C
//
#define MAXHEALTH   100


// s_sound.h
#define CHUNKSIZE                   1024
#define SAMPLERATE                  44100

#if !defined(__HAIKU__)
#define DEFAULT_DEVICE              NULL
#else
// Triggers a segfault if no name is provided even though the default device is empty
#define DEFAULT_DEVICE              ""
#endif

#define LOWER_MUSIC_VOLUME_FACTOR   3


// c_console.h
#define CONSOLETOP              0

#define EMPTYVALUE              "\"\""

#define stringize(x)            #x

#if defined(_WIN32)
#define SDL_FILENAME            "SDL2.dll"
#define SDL_MIXER_FILENAME      "SDL2_mixer.dll"
#define SDL_IMAGE_FILENAME      "SDL2_image.dll"
#else
#define SDL_FILENAME            "SDL2"
#define SDL_MIXER_FILENAME      "SDL2_mixer"
#define SDL_IMAGE_FILENAME      "SDL2_image"
#endif



// d_loop.h
// Tic handling related.
#define BACKUPTICS  8


// c_cmds.h
#define MAXALIASES      256
#define DIVIDERSTRING   "===================================================================================================="


#endif
