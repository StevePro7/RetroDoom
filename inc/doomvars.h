#if !defined(__DOOMVARS_H__)
#define __DOOMVARS_H__

#include "doomdef.h"
#include "doomenum.h"
#include "doomtype.h"
#include "doomstruct.h"

// d_main.h
extern char     *packageconfig;
extern dboolean advancetitle;

// w_wad.c
extern char *packagewad;


// doomstat.h
extern int              gametime;


// m_menu.c
dboolean        menuactive;


// m_config.h
extern int          vid_capfps;


// doomstat.h
// Set if homebrew PWAD stuff has been added.
extern dboolean         modifiedgame;

// c_cmds.h
extern alias_t          aliases[ MAXALIASES ];
extern dboolean         vanilla;
extern dboolean         togglingvanilla;

// i_video.h
extern dboolean     returntowidescreen;
//extern dboolean     vid_widescreen;

// d_main.h
#if defined(_WIN32)
extern char *previouswad;
#endif
//#if defined(_WIN32)
//extern char         *wad;
//#endif


// m_config.h
extern dboolean     alwaysrun;
extern int          am_allmapcdwallcolor;
extern int          am_allmapfdwallcolor;
extern int          am_allmapwallcolor;
extern int          am_backcolor;
extern int          am_cdwallcolor;
extern int          am_crosshaircolor;
extern dboolean     am_external;
extern int          am_fdwallcolor;
extern dboolean     am_followmode;
extern dboolean     am_grid;
extern int          am_gridcolor;
extern char         *am_gridsize;
extern int          am_markcolor;
extern dboolean     am_path;
extern int          am_pathcolor;
extern int          am_playercolor;
extern dboolean     am_rotatemode;
extern int          am_teleportercolor;
extern int          am_thingcolor;
extern int          am_tswallcolor;
extern int          am_wallcolor;
extern dboolean     autoaim;
extern dboolean     autoload;
extern dboolean     autosave;
extern dboolean     autotilt;
extern dboolean     autouse;
extern dboolean     centerweapon;
extern int          con_backcolor;
extern int          con_edgecolor;
extern dboolean     con_obituaries;
extern int          crosshair;
extern int          crosshaircolor;
extern int          episode;
extern int          expansion;
extern int          facebackcolor;
extern dboolean     fade;
extern dboolean     gp_analog;
extern float        gp_deadzone_left;
extern float        gp_deadzone_right;
extern dboolean     gp_invertyaxis;
extern int          gp_sensitivity_horizontal;
extern int          gp_sensitivity_vertical;
extern dboolean     gp_swapthumbsticks;
extern int          gp_thumbsticks;
extern int          gp_vibrate_barrels;
extern int          gp_vibrate_damage;
extern int          gp_vibrate_weapons;
extern dboolean     infighting;
extern dboolean     infiniteheight;
extern char         *iwadfolder;
extern dboolean     m_acceleration;
extern dboolean     m_doubleclick_use;
extern dboolean     m_invertyaxis;
extern dboolean     m_novertical;
extern int          m_sensitivity;
extern dboolean     melt;
extern dboolean     messages;
extern dboolean     mouselook;
extern int          movebob;
extern char         *playername;
extern dboolean     r_althud;
extern int          r_berserkintensity;
extern int          r_blood;
extern int          r_bloodsplats_max;
extern int          r_bloodsplats_total;
extern dboolean     r_bloodsplats_translucency;
extern dboolean     r_brightmaps;
extern int          r_color;
extern dboolean     r_corpses_color;
extern dboolean     r_corpses_gib;
extern dboolean     r_corpses_mirrored;
extern dboolean     r_corpses_moreblood;
extern dboolean     r_corpses_nudge;
extern dboolean     r_corpses_slide;
extern dboolean     r_corpses_smearblood;
extern int          r_detail;
extern dboolean     r_diskicon;
extern dboolean     r_dither;
extern dboolean     r_fixmaperrors;
extern dboolean     r_fixspriteoffsets;
extern dboolean     r_floatbob;
extern int          r_fov;
extern float        r_gamma;
extern dboolean     r_graduallighting;
extern dboolean     r_homindicator;
extern dboolean     r_hud;
extern dboolean     r_hud_translucency;
extern dboolean     r_liquid_bob;
extern dboolean     r_liquid_clipsprites;
extern dboolean     r_liquid_current;
extern dboolean     r_liquid_lowerview;
extern dboolean     r_liquid_swirl;
extern char         *r_lowpixelsize;
extern dboolean     r_mirroredweapons;
extern dboolean     r_playersprites;
extern dboolean     r_rockettrails;
extern int          r_screensize;
extern dboolean     r_shadows;
extern dboolean     r_shadows_translucency;
extern dboolean     r_shake_barrels;
extern int          r_shake_damage;
extern int          r_skycolor;
extern dboolean     r_supersampling;
extern dboolean     r_textures;
extern dboolean     r_translucency;
extern int          s_channels;
extern int          s_musicvolume;
extern dboolean     s_randommusic;
extern dboolean     s_randompitch;
extern int          s_sfxvolume;
extern dboolean     s_stereo;
extern int          savegame;
extern int          skilllevel;
extern uint64_t     stat_barrelsexploded;
extern uint64_t     stat_cheated;
extern uint64_t     stat_damageinflicted;
extern uint64_t     stat_damagereceived;
extern uint64_t     stat_deaths;
extern uint64_t     stat_distancetraveled;
extern uint64_t     stat_gamessaved;
extern uint64_t     stat_itemspickedup;
extern uint64_t     stat_itemspickedup_ammo_bullets;
extern uint64_t     stat_itemspickedup_ammo_cells;
extern uint64_t     stat_itemspickedup_ammo_rockets;
extern uint64_t     stat_itemspickedup_ammo_shells;
extern uint64_t     stat_itemspickedup_armor;
extern uint64_t     stat_itemspickedup_health;
extern uint64_t     stat_mapscompleted;
extern uint64_t     stat_mapsstarted;
extern uint64_t     stat_monsterskilled;
extern uint64_t     stat_monsterskilled_arachnotrons;
extern uint64_t     stat_monsterskilled_archviles;
extern uint64_t     stat_monsterskilled_baronsofhell;
extern uint64_t     stat_monsterskilled_cacodemons;
extern uint64_t     stat_monsterskilled_cyberdemons;
extern uint64_t     stat_monsterskilled_demons;
extern uint64_t     stat_monsterskilled_heavyweapondudes;
extern uint64_t     stat_monsterskilled_hellknights;
extern uint64_t     stat_monsterskilled_imps;
extern uint64_t     stat_monsterskilled_lostsouls;
extern uint64_t     stat_monsterskilled_mancubi;
extern uint64_t     stat_monsterskilled_painelementals;
extern uint64_t     stat_monsterskilled_revenants;
extern uint64_t     stat_monsterskilled_shotgunguys;
extern uint64_t     stat_monsterskilled_spectres;
extern uint64_t     stat_monsterskilled_spidermasterminds;
extern uint64_t     stat_monsterskilled_zombiemen;
extern uint64_t     stat_runs;
extern uint64_t     stat_secretsfound;
extern uint64_t     stat_shotsfired_pistol;
extern uint64_t     stat_shotsfired_shotgun;
extern uint64_t     stat_shotsfired_supershotgun;
extern uint64_t     stat_shotsfired_chaingun;
extern uint64_t     stat_shotsfired_rocketlauncher;
extern uint64_t     stat_shotsfired_plasmarifle;
extern uint64_t     stat_shotsfired_bfg9000;
extern uint64_t     stat_shotssuccessful_pistol;
extern uint64_t     stat_shotssuccessful_shotgun;
extern uint64_t     stat_shotssuccessful_supershotgun;
extern uint64_t     stat_shotssuccessful_chaingun;
extern uint64_t     stat_shotssuccessful_rocketlauncher;
extern uint64_t     stat_shotssuccessful_plasmarifle;
extern uint64_t     stat_shotssuccessful_bfg9000;
extern uint64_t     stat_skilllevel_imtooyoungtodie;
extern uint64_t     stat_skilllevel_heynottoorough;
extern uint64_t     stat_skilllevel_hurtmeplenty;
extern uint64_t     stat_skilllevel_ultraviolence;
extern uint64_t     stat_skilllevel_nightmare;
extern uint64_t     stat_suicides;
extern uint64_t     stat_time;
extern int          stillbob;
extern dboolean     tossdrop;
extern int          turbo;
extern int          units;
extern char         *version;
extern dboolean     vid_borderlesswindow;
extern int          vid_capfps;
extern int          vid_display;
#if !defined(_WIN32)
extern char         *vid_driver;
#endif
extern dboolean     vid_fullscreen;
extern int          vid_motionblur;
extern dboolean     vid_pillarboxes;
extern char         *vid_scaleapi;
extern char         *vid_scalefilter;
extern char         *vid_screenresolution;
extern dboolean     vid_showfps;
extern int          vid_vsync;
extern dboolean     vid_widescreen;
extern char         *vid_windowpos;
extern char         *vid_windowsize;
#if defined(_WIN32)
extern char         *wad;
#endif
extern int          warninglevel;
extern int          weaponbob;
extern dboolean     weaponbounce;
extern dboolean     weaponrecoil;


// doomstat
// -------------------------
// Internal parameters for sound rendering.
// These have been taken from the DOS version,
//  but are not (yet) supported with Linux
//  (e.g. no sound volume adjustment with menu.

// From m_menu.c:
//  Sound FX volume has default, 0 - 31
//  Music volume has default, 0 - 31
// These are multiplied by 4.
extern int              sfxVolume;
extern int              musicVolume;

#endif
