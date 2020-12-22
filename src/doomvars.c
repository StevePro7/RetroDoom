//stevepro
#include "doomvars.h"
#include "doomdef.h"
#include "doomenum.h"

// d_main.c
char                *packageconfig;
char                *packagewad;
dboolean            advancetitle;

// g_game.c
int             gametime = 0;


// m_menu.h
extern dboolean         menuactive;     // Menu overlaid?

// m_config.c
int                 vid_capfps = vid_capfps_default;


// doomstat.c
// Set if homebrew PWAD stuff has been added.
dboolean        modifiedgame;

// c_cmds.c
alias_t             aliases[ MAXALIASES ];
dboolean            togglingvanilla = false;
dboolean            vanilla = false;


// i_video.c
dboolean            returntowidescreen;
//dboolean            vid_widescreen = vid_widescreen_default;



// d_main.c
#if defined(_WIN32)
char                *previouswad;
#endif

//#if defined(_WIN32)
//char                *wad = wad_default;
//#endif



// m_config.c
dboolean            alwaysrun = alwaysrun_default;
dboolean            m_acceleration = m_acceleration_default;
int                 r_color = r_color_default;
float               r_gamma = r_gamma_default;
dboolean            vid_borderlesswindow = vid_borderlesswindow_default;
//int                 vid_capfps = vid_capfps_default;
int                 vid_display = vid_display_default;
#if !defined(_WIN32)
char                *vid_driver = vid_driver_default;
#endif
dboolean            vid_fullscreen = vid_fullscreen_default;
int                 vid_motionblur = vid_motionblur_default;
dboolean            vid_pillarboxes = vid_pillarboxes_default;
char                *vid_scaleapi = vid_scaleapi_default;
char                *vid_scalefilter = vid_scalefilter_default;
char                *vid_screenresolution = vid_screenresolution_default;
dboolean            vid_showfps = vid_showfps_default;
int                 vid_vsync = vid_vsync_default;
dboolean            vid_widescreen = vid_widescreen_default;
char                *vid_windowpos = vid_windowpos_default;
char                *vid_windowsize = vid_windowsize_default;

// am_map.c
int am_allmapcdwallcolor = am_allmapcdwallcolor_default;
int am_allmapfdwallcolor = am_allmapfdwallcolor_default;
int am_allmapwallcolor = am_allmapwallcolor_default;
int am_backcolor = am_backcolor_default;
int am_cdwallcolor = am_cdwallcolor_default;
int am_crosshaircolor = am_crosshaircolor_default;
int am_fdwallcolor = am_fdwallcolor_default;
int am_gridcolor = am_gridcolor_default;
int am_markcolor = am_markcolor_default;
int am_pathcolor = am_pathcolor_default;
int am_playercolor = am_playercolor_default;
int am_teleportercolor = am_teleportercolor_default;
int am_thingcolor = am_thingcolor_default;
int am_tswallcolor = am_tswallcolor_default;
int am_wallcolor = am_wallcolor_default;

// am_map.c
dboolean            am_external = am_external_default;
dboolean            am_followmode = am_followmode_default;
dboolean            am_grid = am_grid_default;
char                *am_gridsize = am_gridsize_default;
dboolean            am_path = am_path_default;
dboolean            am_rotatemode = am_rotatemode_default;

// p_pspr.c
dboolean        autoaim = autoaim_default;
dboolean        centerweapon = centerweapon_default;
int             weaponbob = weaponbob_default;
dboolean        weaponbounce = weaponbounce_default;
dboolean        weaponrecoil = weaponrecoil_default;
uint64_t        stat_shotsfired_pistol = 0;
uint64_t        stat_shotsfired_shotgun = 0;
uint64_t        stat_shotsfired_supershotgun = 0;
uint64_t        stat_shotsfired_chaingun = 0;
uint64_t        stat_shotsfired_rocketlauncher = 0;
uint64_t        stat_shotsfired_plasmarifle = 0;
uint64_t        stat_shotsfired_bfg9000 = 0;
uint64_t        stat_shotssuccessful_pistol = 0;
uint64_t        stat_shotssuccessful_shotgun = 0;
uint64_t        stat_shotssuccessful_supershotgun = 0;
uint64_t        stat_shotssuccessful_chaingun = 0;
uint64_t        stat_shotssuccessful_rocketlauncher = 0;
uint64_t        stat_shotssuccessful_plasmarifle = 0;
uint64_t        stat_shotssuccessful_bfg9000 = 0;

// g_game.c
dboolean        autoload = autoload_default;
dboolean        autosave = autosave_default;
uint64_t        stat_gamessaved = 0;
uint64_t        stat_mapsstarted = 0;
uint64_t        stat_mapscompleted = 0;
uint64_t        stat_skilllevel_imtooyoungtodie = 0;
uint64_t        stat_skilllevel_heynottoorough = 0;
uint64_t        stat_skilllevel_hurtmeplenty = 0;
uint64_t        stat_skilllevel_ultraviolence = 0;
uint64_t        stat_skilllevel_nightmare = 0;
dboolean        m_doubleclick_use = m_doubleclick_use_default;
dboolean        m_invertyaxis = m_invertyaxis_default;
dboolean        m_novertical = m_novertical_default;
dboolean        mouselook = mouselook_default;

// p_user.c
dboolean        autotilt = autotilt_default;
dboolean        autouse = autouse_default;
dboolean        infighting = infighting_default;
int             movebob = movebob_default;
dboolean        r_liquid_lowerview = r_liquid_lowerview_default;
int             r_shake_damage = r_shake_damage_default;
int             stillbob = stillbob_default;

// c_console.c
int                     con_backcolor = con_backcolor_default;
int                     con_edgecolor = con_edgecolor_default;
int                     warninglevel = warninglevel_default;

// p_inter.c
dboolean        con_obituaries = con_obituaries_default;
dboolean        r_mirroredweapons = r_mirroredweapons_default;
dboolean        tossdrop = tossdrop_default;

uint64_t        stat_barrelsexploded = 0;
uint64_t        stat_damageinflicted = 0;
uint64_t        stat_damagereceived = 0;
uint64_t        stat_deaths = 0;
uint64_t        stat_itemspickedup = 0;
uint64_t        stat_itemspickedup_ammo_bullets = 0;
uint64_t        stat_itemspickedup_ammo_cells = 0;
uint64_t        stat_itemspickedup_ammo_rockets = 0;
uint64_t        stat_itemspickedup_ammo_shells = 0;
uint64_t        stat_itemspickedup_armor = 0;
uint64_t        stat_itemspickedup_health = 0;
uint64_t        stat_monsterskilled = 0;
uint64_t        stat_monsterskilled_arachnotrons = 0;
uint64_t        stat_monsterskilled_archviles = 0;
uint64_t        stat_monsterskilled_baronsofhell = 0;
uint64_t        stat_monsterskilled_cacodemons = 0;
uint64_t        stat_monsterskilled_cyberdemons = 0;
uint64_t        stat_monsterskilled_demons = 0;
uint64_t        stat_monsterskilled_heavyweapondudes = 0;
uint64_t        stat_monsterskilled_hellknights = 0;
uint64_t        stat_monsterskilled_imps = 0;
uint64_t        stat_monsterskilled_lostsouls = 0;
uint64_t        stat_monsterskilled_mancubi = 0;
uint64_t        stat_monsterskilled_painelementals = 0;
uint64_t        stat_monsterskilled_revenants = 0;
uint64_t        stat_monsterskilled_shotgunguys = 0;
uint64_t        stat_monsterskilled_spectres = 0;
uint64_t        stat_monsterskilled_spidermasterminds = 0;
uint64_t        stat_monsterskilled_zombiemen = 0;
uint64_t        stat_suicides = 0;

// p_tick.c
uint64_t    stat_time = 0;

// hu_stuff.c
int                     crosshair = crosshair_default;
int                     crosshaircolor = crosshaircolor_default;
char                    *playername = playername_default;
dboolean                r_althud = r_althud_default;
dboolean                r_diskicon = r_diskicon_default;
dboolean                r_hud = r_hud_default;
dboolean                r_hud_translucency = r_hud_translucency_default;

// m_menu.c
int             episode = episode_default;
int             expansion = expansion_default;
int             m_sensitivity = m_sensitivity_default;
dboolean        messages = messages_default;
int             r_detail = r_detail_default;
int             r_screensize = r_screensize_default;
int             savegame = savegame_default;
int             skilllevel = skilllevel_default;

// st_stuff.c
int                         facebackcolor = facebackcolor_default;
int                         r_berserkintensity = r_berserkintensity_default;
uint64_t                    stat_cheated = 0;

// d_main.c
dboolean            fade = fade_default;
char                *iwadfolder = iwadfolder_default;
dboolean            melt = melt_default;
int                 turbo = turbo_default;
int                 units = units_default;
uint64_t            stat_runs = 0;

#if defined(_WIN32)
char                *wad = wad_default;
#endif


// i_gamepad.c
dboolean                    gp_analog = gp_analog_default;
float                       gp_deadzone_left = gp_deadzone_left_default;
float                       gp_deadzone_right = gp_deadzone_right_default;
dboolean                    gp_invertyaxis = gp_invertyaxis_default;
int                         gp_sensitivity_horizontal = gp_sensitivity_horizontal_default;
int                         gp_sensitivity_vertical = gp_sensitivity_vertical_default;
dboolean                    gp_swapthumbsticks = gp_swapthumbsticks_default;
int                         gp_thumbsticks = gp_thumbsticks_default;
int                         gp_vibrate_barrels = gp_vibrate_barrels_default;
int                         gp_vibrate_damage = gp_vibrate_damage_default;
int                         gp_vibrate_weapons = gp_vibrate_weapons_default;

// p_map.c
dboolean        infiniteheight = infiniteheight_default;
uint64_t        stat_distancetraveled = 0;

// c_cmd.c
char                *version = version_default;

// p_mobj.c
int         r_blood = r_blood_default;
int         r_bloodsplats_max = r_bloodsplats_max_default;
int         r_bloodsplats_total;
dboolean    r_corpses_color = r_corpses_color_default;
dboolean    r_corpses_gib = r_corpses_gib_default;
dboolean    r_corpses_mirrored = r_corpses_mirrored_default;
dboolean    r_corpses_moreblood = r_corpses_moreblood_default;
dboolean    r_corpses_nudge = r_corpses_nudge_default;
dboolean    r_corpses_slide = r_corpses_slide_default;
dboolean    r_corpses_smearblood = r_corpses_smearblood_default;
dboolean    r_floatbob = r_floatbob_default;
dboolean    r_rockettrails = r_rockettrails_default;
dboolean    r_shadows = r_shadows_default;

// r_main.c
dboolean            r_bloodsplats_translucency = r_bloodsplats_translucency_default;
dboolean            r_dither = r_dither_default;
int                 r_fov = r_fov_default;
dboolean            r_homindicator = r_homindicator_default;
dboolean            r_shadows_translucency = r_shadows_translucency_default;
dboolean            r_shake_barrels = r_shake_barrels_default;
int                 r_skycolor = r_skycolor_default;
dboolean            r_textures = r_textures_default;
dboolean            r_translucency = r_translucency_default;

// v_video.c
char        *r_lowpixelsize = r_lowpixelsize_default;
dboolean    r_supersampling = r_supersampling_default;

// s_sounds.c
int                 s_channels = s_channels_default;
int                 s_musicvolume = s_musicvolume_default;
dboolean            s_randommusic = s_randommusic_default;
dboolean            s_randompitch = s_randompitch_default;
int                 s_sfxvolume = s_sfxvolume_default;
dboolean            s_stereo = s_stereo_default;

// p_spec.c
uint64_t            stat_secretsfound = 0;
dboolean            r_liquid_bob = r_liquid_bob_default;


// r_things.c
dboolean                r_liquid_clipsprites = r_liquid_clipsprites_default;
dboolean                r_playersprites = r_playersprites_default;

// r_plane.c
dboolean            r_liquid_current = r_liquid_current_default;
dboolean            r_liquid_swirl = r_liquid_swirl_default;

// p_doors.c
dboolean    r_graduallighting = r_graduallighting_default;

// p_setup.c
dboolean        r_fixmaperrors = r_fixmaperrors_default;

// r_data.c
dboolean    r_fixspriteoffsets = r_fixspriteoffsets_default;

// r_segs.c
dboolean            r_brightmaps = r_brightmaps_default;


// s_sound.c
// Maximum volume of a sound effect.
// Internal default is max out of 0-31.
int                 sfxVolume;

// Maximum volume of music.
int                 musicVolume;