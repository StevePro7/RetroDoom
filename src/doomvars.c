//stevepro
#include "doomvars.h"
#include "d_englsh.h"
#include "doomdef.h"
#include "doomenum.h"
#include "dstrings.h"

// d_main.c
// Location where savegames are stored
char                *savegamefolder;

char                *pwadfile;// = "";

dboolean            fade;// = fade_default;
char                *iwadfolder;// = iwadfolder_default;
dboolean            melt;// = melt_default;
int                 turbo;// = turbo_default;
int                 units;// = units_default;

#if defined(_WIN32)
char                *wad;// = wad_default;
#endif

char                *packageconfig;
char                *packagewad;

//static char         dehwarning[ 256 ] = "";

#if defined( _WIN32 )
char                *previouswad;
#endif

dboolean            devparm;                // started game with -devparm
dboolean            fastparm;               // checkparm of -fast
dboolean            freeze;
dboolean            nomonsters;             // checkparm of -nomonsters
dboolean            pistolstart;            // [BH] checkparm of -pistolstart
dboolean            regenhealth;
dboolean            respawnitems;
dboolean            respawnmonsters;        // checkparm of -respawn

uint64_t            stat_runs;// = 0;

skill_t             startskill;
int                 startepisode;
//static int          startmap;
dboolean            autostart;

dboolean            advancetitle;
dboolean            dowipe;
//static dboolean     forcewipe;

//static byte         fadescreen[ SCREENWIDTH * SCREENHEIGHT ];
//static int          fadeheight;
int                 fadecount;// = 0;

dboolean            splashscreen;// = true;

//static int          startuptimer;

dboolean            realframe;
//static dboolean     error;
//static dboolean     guess;
//
//struct tm           gamestarttime;

#if defined(_WIN32)
HANDLE       CapFPSEvent;
#endif

//
//  TITLE LOOP
//
int             titlesequence;// = 0;
int             pagetic;// = 3 * TICRATE;
int             logotic;// = 3 * TICRATE;


// g_game.c
gameaction_t    loadaction; // = ga_nothing;
gamestate_t     gamestate;// = GS_TITLESCREEN;
dboolean        paused;
int             gametime;// = 0;
char            speciallumpname[ 6 ];// = "";


// m_config.c
int                 vid_capfps;// = vid_capfps_default;


// doomstat.c
// Set if homebrew PWAD stuff has been added.
int             gameepisode;
int             gamemap;
dboolean        modifiedgame;

ticcmd_t    localcmds[ BACKUPTICS ];



// c_cmds.c
alias_t             aliases[ MAXALIASES ];
dboolean            executingalias;// = false;
dboolean            healthcvar;// = false;
dboolean            quitcmd;// = false;
dboolean            resettingcvar;// = false;
dboolean            togglingvanilla;// = false;
dboolean            vanilla;// = false;

dboolean        massacre;



dboolean            devparm;                // started game with -devparm
dboolean            fastparm;               // checkparm of -fast
dboolean            freeze;
dboolean            nomonsters;             // checkparm of -nomonsters
dboolean            pistolstart;            // [BH] checkparm of -pistolstart
dboolean            regenhealth;
dboolean            respawnitems;
dboolean            respawnmonsters;        // checkparm of -respawn


// i_video.c
dboolean            returntowidescreen;
int                 framespersecond;
int                 refreshrate;
uint64_t        starttime;
int             frames;// = -1;
byte                *PLAYPAL;



// m_config.c
dboolean            alwaysrun; //=alwaysrun_default;
dboolean            m_acceleration; //=m_acceleration_default;
int                 r_color; //=r_color_default;
float               r_gamma; //=r_gamma_default;
dboolean            vid_borderlesswindow; //=vid_borderlesswindow_default;
int                 vid_capfps; //=vid_capfps_default;
int                 vid_display; //=vid_display_default;
#if !defined(_WIN32)
char                *vid_driver; //=vid_driver_default;
#endif
dboolean            vid_fullscreen; //=vid_fullscreen_default;
int                 vid_motionblur; //=vid_motionblur_default;
dboolean            vid_pillarboxes; //=vid_pillarboxes_default;
char                *vid_scaleapi; //=vid_scaleapi_default;
char                *vid_scalefilter; //=vid_scalefilter_default;
char                *vid_screenresolution; //=vid_screenresolution_default;
dboolean            vid_showfps; //=vid_showfps_default;
int                 vid_vsync; //=vid_vsync_default;
dboolean            vid_widescreen; //=vid_widescreen_default;
char                *vid_windowpos; //=vid_windowpos_default;
char                *vid_windowsize; //=vid_windowsize_default;

// am_map.c
int am_allmapcdwallcolor; //=am_allmapcdwallcolor_default;
int am_allmapfdwallcolor; //=am_allmapfdwallcolor_default;
int am_allmapwallcolor; //=am_allmapwallcolor_default;
int am_backcolor; //=am_backcolor_default;
int am_cdwallcolor; //=am_cdwallcolor_default;
int am_crosshaircolor; //=am_crosshaircolor_default;
int am_fdwallcolor; //=am_fdwallcolor_default;
int am_gridcolor; //=am_gridcolor_default;
int am_markcolor; //=am_markcolor_default;
int am_pathcolor; //=am_pathcolor_default;
int am_playercolor; //=am_playercolor_default;
int am_teleportercolor; //=am_teleportercolor_default;
int am_thingcolor; //=am_thingcolor_default;
int am_tswallcolor; //=am_tswallcolor_default;
int am_wallcolor; //=am_wallcolor_default;

// am_map.c
mpoint_t            *markpoints;    // where the points are
int                 markpointnum;   // next point to be assigned
int                 markpointnum_max;

mpoint_t            *pathpoints;
int                 pathpointnum;
int                 pathpointnum_max;

dboolean            am_external; //=am_external_default;
dboolean            am_followmode; //=am_followmode_default;
dboolean            am_grid; //=am_grid_default;
char                *am_gridsize; //=am_gridsize_default;
dboolean            am_path; //=am_path_default;
dboolean            am_rotatemode; //=am_rotatemode_default;

dboolean            automapactive;
am_frame_t          am_frame;


// p_pspr.c
dboolean        autoaim; //=autoaim_default;
dboolean        centerweapon; //=centerweapon_default;
int             weaponbob; //=weaponbob_default;
dboolean        weaponbounce; //=weaponbounce_default;
dboolean        weaponrecoil; //=weaponrecoil_default;
uint64_t        stat_shotsfired_pistol; //=0;
uint64_t        stat_shotsfired_shotgun; //=0;
uint64_t        stat_shotsfired_supershotgun; //=0;
uint64_t        stat_shotsfired_chaingun; //=0;
uint64_t        stat_shotsfired_rocketlauncher; //=0;
uint64_t        stat_shotsfired_plasmarifle; //=0;
uint64_t        stat_shotsfired_bfg9000; //=0;
uint64_t        stat_shotssuccessful_pistol; //=0;
uint64_t        stat_shotssuccessful_shotgun; //=0;
uint64_t        stat_shotssuccessful_supershotgun; //=0;
uint64_t        stat_shotssuccessful_chaingun; //=0;
uint64_t        stat_shotssuccessful_rocketlauncher; //=0;
uint64_t        stat_shotssuccessful_plasmarifle; //=0;
uint64_t        stat_shotssuccessful_bfg9000; //=0;

dboolean        successfulshot;
dboolean        skippsprinterp;

// g_game.c
dboolean        autoload; //=autoload_default;
dboolean        autosave; //=autosave_default;
uint64_t        stat_gamessaved; //=0;
uint64_t        stat_mapsstarted; //=0;
uint64_t        stat_mapscompleted; //=0;
uint64_t        stat_skilllevel_imtooyoungtodie; //=0;
uint64_t        stat_skilllevel_heynottoorough; //=0;
uint64_t        stat_skilllevel_hurtmeplenty; //=0;
uint64_t        stat_skilllevel_ultraviolence; //=0;
uint64_t        stat_skilllevel_nightmare; //=0;
dboolean        m_doubleclick_use; //=m_doubleclick_use_default;
dboolean        m_invertyaxis; //=m_invertyaxis_default;
dboolean        m_novertical; //=m_novertical_default;
dboolean        mouselook; //=mouselook_default;

// p_user.c
dboolean        autotilt; //=autotilt_default;
dboolean        autouse; //=autouse_default;
dboolean        infighting; //=infighting_default;
int             movebob; //=movebob_default;
dboolean        r_liquid_lowerview; //=r_liquid_lowerview_default;
int             r_shake_damage; //=r_shake_damage_default;
int             stillbob; //=stillbob_default;


// c_console.c
console_t               *console;
int                     consoleheight;// = 0;
int                     consoledirection;// = -1;
dboolean                consoleactive;

dboolean                forceconsoleblurredraw;

patch_t                 *consolefont[ CONSOLEFONTSIZE ];
patch_t                 *degree;
patch_t                 *unknownchar;
patch_t                 *altunderscores;
patch_t                 *brand;
patch_t                 *lsquote;
patch_t                 *ldquote;

patch_t                 *bindlist;
patch_t                 *cmdlist;
patch_t                 *cvarlist;
patch_t                 *maplist;
patch_t                 *mapstats;
patch_t                 *playerstats;
patch_t                 *thinglist;

int                     consolestrings;// = 0;
size_t                  consolestringsmax;// = 0;

char                    consolecheat[ 255 ];
char                    consolecheatparm[ 3 ];

int                     con_backcolor;// = con_backcolor_default;
int                     con_edgecolor;// = con_edgecolor_default;
int                     warninglevel;// = warninglevel_default;

dboolean                scrollbardrawn;
const kern_t altkern[];


// p_inter.c
dboolean        con_obituaries; //=con_obituaries_default;
dboolean        r_mirroredweapons; //=r_mirroredweapons_default;
dboolean        tossdrop; //=tossdrop_default;

uint64_t        stat_barrelsexploded; //=0;
uint64_t        stat_damageinflicted; //=0;
uint64_t        stat_damagereceived; //=0;
uint64_t        stat_deaths; //=0;
uint64_t        stat_itemspickedup; //=0;
uint64_t        stat_itemspickedup_ammo_bullets; //=0;
uint64_t        stat_itemspickedup_ammo_cells; //=0;
uint64_t        stat_itemspickedup_ammo_rockets; //=0;
uint64_t        stat_itemspickedup_ammo_shells; //=0;
uint64_t        stat_itemspickedup_armor; //=0;
uint64_t        stat_itemspickedup_health; //=0;
uint64_t        stat_monsterskilled; //=0;
uint64_t        stat_monsterskilled_arachnotrons; //=0;
uint64_t        stat_monsterskilled_archviles; //=0;
uint64_t        stat_monsterskilled_baronsofhell; //=0;
uint64_t        stat_monsterskilled_cacodemons; //=0;
uint64_t        stat_monsterskilled_cyberdemons; //=0;
uint64_t        stat_monsterskilled_demons; //=0;
uint64_t        stat_monsterskilled_heavyweapondudes; //=0;
uint64_t        stat_monsterskilled_hellknights; //=0;
uint64_t        stat_monsterskilled_imps; //=0;
uint64_t        stat_monsterskilled_lostsouls; //=0;
uint64_t        stat_monsterskilled_mancubi; //=0;
uint64_t        stat_monsterskilled_painelementals; //=0;
uint64_t        stat_monsterskilled_revenants; //=0;
uint64_t        stat_monsterskilled_shotgunguys; //=0;
uint64_t        stat_monsterskilled_spectres; //=0;
uint64_t        stat_monsterskilled_spidermasterminds; //=0;
uint64_t        stat_monsterskilled_zombiemen; //=0;
uint64_t        stat_suicides; //=0;

// p_tick.c
uint64_t    stat_time;// = 0;

//
// THINKERS
// All thinkers should be allocated by Z_Malloc
// so they can be operated on uniformly.
// The actual structures will vary in size,
// but the first element must be thinker_t.
//

// killough 08/29/98: we maintain several separate threads, each containing
// a special class of thinkers, to allow more efficient searches.
thinker_t       thinkers[ th_all + 1 ];


// hu_stuff.c
patch_t                 *hu_font[ HU_FONTSIZE ];

int healthhighlight; //=0;
int ammohighlight; //=0;
int armorhighlight; //=0;

dboolean                drawdisk;

dboolean                message_on;
dboolean                message_dontfuckwithme;
//static dboolean         message_external;
//static dboolean         message_nottobefuckedwith;
dboolean                idbehold;

int                     crosshair; //=crosshair_default;
int                     crosshaircolor; //=crosshaircolor_default;
char                    *playername; //=playername_default;
dboolean                r_althud; //=r_althud_default;
dboolean                r_diskicon; //=r_diskicon_default;
dboolean                r_hud; //=r_hud_default;
dboolean                r_hud_translucency; //=r_hud_translucency_default;

dboolean                s_STSTR_BEHOLD2;
byte            tempscreen[ SCREENAREA ];


// m_menu.c
int             episode;// = episode_default;
int             expansion;// = expansion_default;
int             m_sensitivity;// = m_sensitivity_default;
dboolean        messages;// = messages_default;
int             r_detail;// = r_detail_default;
int             r_screensize;// = r_screensize_default;
int             savegame;// = savegame_default;
int             skilllevel;// = skilllevel_default;

// -1 = no quicksave slot picked!
int             quickSaveSlot;

// true = message to be printed
dboolean        messagetoprint;

dboolean        inhelpscreens;
dboolean        menuactive;
dboolean        savegames;

int             spindirection;
char            savegamestrings[ 6 ][ SAVESTRINGSIZE ];
dboolean        EpiCustom;

dboolean        quitting;
dboolean    waspaused; // = false;

int             caretcolor;


// st_stuff.c
patch_t                     *grnrock;
patch_t                     *brdr_t;
patch_t                     *brdr_b;
patch_t                     *brdr_l;
patch_t                     *brdr_r;
patch_t                     *brdr_tl;
patch_t                     *brdr_tr;
patch_t                     *brdr_bl;
patch_t                     *brdr_br;

// used for evil grin
dboolean                    oldweaponsowned[ NUMWEAPONS ];

int                         facebackcolor;// = facebackcolor_default;
int                         r_berserkintensity;// = r_berserkintensity_default;
uint64_t                    stat_cheated;// = 0;
int                         st_palette;// = 0;

// 0-9, tall numbers
patch_t                     *tallnum[ 10 ];

// tall % sign
patch_t                     *tallpercent;
short                       tallpercentwidth;
dboolean                    emptytallpercent;

// face status patches
patch_t                     *faces[ ST_NUMFACES ];



// i_gamepad.c
dboolean                    gp_analog; //=gp_analog_default;
float                       gp_deadzone_left; //=gp_deadzone_left_default;
float                       gp_deadzone_right; //=gp_deadzone_right_default;
dboolean                    gp_invertyaxis; //=gp_invertyaxis_default;
int                         gp_sensitivity_horizontal; //=gp_sensitivity_horizontal_default;
int                         gp_sensitivity_vertical; //=gp_sensitivity_vertical_default;
dboolean                    gp_swapthumbsticks; //=gp_swapthumbsticks_default;
int                         gp_thumbsticks; //=gp_thumbsticks_default;
int                         gp_vibrate_barrels; //=gp_vibrate_barrels_default;
int                         gp_vibrate_damage; //=gp_vibrate_damage_default;
int                         gp_vibrate_weapons; //=gp_vibrate_weapons_default;

// p_map.c
line_t          **spechit;
int             numspechit;// = 0;

dboolean        infiniteheight; //=infiniteheight_default;
uint64_t        stat_distancetraveled; //=0;

dboolean    hitwall;




// c_cmd.c
char                *version; //= version_default;

// p_mobj.c
int         r_blood; //=r_blood_default;
int         r_bloodsplats_max; //=r_bloodsplats_max_default;
int         r_bloodsplats_total;
dboolean    r_corpses_color; //=r_corpses_color_default;
dboolean    r_corpses_gib; //=r_corpses_gib_default;
dboolean    r_corpses_mirrored; //=r_corpses_mirrored_default;
dboolean    r_corpses_moreblood; //=r_corpses_moreblood_default;
dboolean    r_corpses_nudge; //=r_corpses_nudge_default;
dboolean    r_corpses_slide; //=r_corpses_slide_default;
dboolean    r_corpses_smearblood; //=r_corpses_smearblood_default;
dboolean    r_floatbob; //=r_floatbob_default;
dboolean    r_rockettrails; //=r_rockettrails_default;
dboolean    r_shadows; //=r_shadows_default;


// r_main.c
// increment every time a check is made
int                 validcount = 1;

lighttable_t        *fixedcolormap;

dboolean            usebrightmaps;

int                 centerx;
int                 centery;

fixed_t             centerxfrac;
fixed_t             centeryfrac;
fixed_t             projection;

fixed_t             viewx;
fixed_t             viewy;
fixed_t             viewz;

angle_t             viewangle;

fixed_t             viewcos;
fixed_t             viewsin;

player_t            *viewplayer;// = NULL;

// [AM] Fractional part of the current tic, in the half-open
//      range of [0.0, 1.0). Used for interpolation.
fixed_t             fractionaltic;

//
// precalculated math tables
//
angle_t             clipangle;

// The viewangletox[viewangle + FINEANGLES/4] lookup
// maps the visible view angles to screen X coordinates,
// flattening the arc to a flat projection plane.
// There will be many angles mapped to the same X.
int                 viewangletox[ FINEANGLES / 2 ];

// The xtoviewangleangle[] table maps a screen pixel
// to the lowest viewangle that maps back to x ranges
// from clipangle to -clipangle.
angle_t             xtoviewangle[ SCREENWIDTH + 1 ];

//fixed_t             finesine[ 5 * FINEANGLES / 4 ];
//fixed_t             *finecosine = &finesine[ FINEANGLES / 4 ];
//fixed_t             finetangent[ FINEANGLES / 2 ];
//angle_t             tantoangle[ SLOPERANGE + 1 ];

int                 numcolormaps;// = 1;
lighttable_t        *( *scalelight )[ MAXLIGHTSCALE ];
lighttable_t        *( *psprscalelight )[ OLDMAXLIGHTSCALE ];
lighttable_t        *( *zlight )[ MAXLIGHTZ ];
lighttable_t        *fullcolormap;
lighttable_t        **colormaps;

// bumped light from gun blasts
int                 extralight;

dboolean            drawbloodsplats;

dboolean            r_bloodsplats_translucency; //=r_bloodsplats_translucency_default;
dboolean            r_dither; //=r_dither_default;
int                 r_fov; //=r_fov_default;
dboolean            r_homindicator; //=r_homindicator_default;
dboolean            r_shadows_translucency; //=r_shadows_translucency_default;
dboolean            r_shake_barrels; //=r_shake_barrels_default;
int                 r_skycolor; //=r_skycolor_default;
dboolean            r_textures; //=r_textures_default;
dboolean            r_translucency; //=r_translucency_default;


void( *colfunc )( void );
void( *wallcolfunc )( void );
void( *bmapwallcolfunc )( void );
void( *segcolfunc )( void );
void( *translatedcolfunc )( void );
void( *basecolfunc )( void );
void( *fuzzcolfunc )( void );
void( *tlcolfunc )( void );
void( *tl50colfunc )( void );
void( *tl50segcolfunc )( void );
void( *tl33colfunc )( void );
void( *tlgreencolfunc )( void );
void( *tlredcolfunc )( void );
void( *tlredwhitecolfunc1 )( void );
void( *tlredwhitecolfunc2 )( void );
void( *tlredwhite50colfunc )( void );
void( *tlbluecolfunc )( void );
void( *tlgreen33colfunc )( void );
void( *tlred33colfunc )( void );
void( *tlblue25colfunc )( void );
void( *redtobluecolfunc )( void );
void( *tlredtoblue33colfunc )( void );
void( *skycolfunc )( void );
void( *redtogreencolfunc )( void );
void( *tlredtogreen33colfunc )( void );
void( *psprcolfunc )( void );
void( *spanfunc )( void );
void( *bloodsplatcolfunc )( void );
void( *megaspherecolfunc )( void );
void( *supershotguncolfunc )( void );

dboolean    setsizeneeded;


// v_video.c
byte        *screens[ 5 ];
int         lowpixelwidth;
int         lowpixelheight;
char        screenshotfolder[ MAX_PATH ];

char        *r_lowpixelsize;// = r_lowpixelsize_default;
dboolean    r_supersampling;// = r_supersampling_default;


// s_sounds.c
dboolean            nomusic;
dboolean            nosfx;

musinfo_t           musinfo;


int                 s_channels; //=s_channels_default;
int                 s_musicvolume; //=s_musicvolume_default;
dboolean            s_randommusic;// = s_randommusic_default;
dboolean            s_randompitch;// = s_randompitch_default;
int                 s_sfxvolume; //=s_sfxvolume_default;
dboolean            s_stereo; //=s_stereo_default;

// p_spec.c
uint64_t            stat_secretsfound; //=0;
dboolean            r_liquid_bob; //=r_liquid_bob_default;
int timer;// = 0;
int countdown;
fixed_t             animatedliquiddiff;
fixed_t             animatedliquidxdir;
fixed_t             animatedliquidydir;
fixed_t             animatedliquidxoffs;
fixed_t             animatedliquidyoffs;


// r_things.c
//
// Sprite rotation 0 is facing the viewer, rotation 1 is one angle turn CLOCKWISE around the axis.
// This is not the same as the angle, which increases counter clockwise (protractor).
// There was a lot of stuff grabbed wrong, so I changed it...
//
fixed_t                 pspritescale;
fixed_t                 pspriteiscale;

// constant arrays used for psprite clipping and initializing clipping
int                     negonearray[ SCREENWIDTH ];
int                     viewheightarray[ SCREENWIDTH ];
//
// INITIALIZATION FUNCTIONS
//

// variables used to look up and range check thing_t sprites patches
spritedef_t             *sprites;

short                   firstbloodsplatlump;
dboolean                allowwolfensteinss;// = true;

dboolean                r_liquid_clipsprites; //=r_liquid_clipsprites_default;
dboolean                r_playersprites; //=r_playersprites_default;

int             *mfloorclip;
int             *mceilingclip;
fixed_t         spryscale;
int64_t         sprtopscreen;



// r_plane.c
visplane_t          *floorplane;
visplane_t          *ceilingplane;

int                 *openings;                  // dropoff overflow
int                 *lastopening;               // dropoff overflow

// Clip values are the solid pixel bounding the range.
//  floorclip starts out SCREENHEIGHT
//  ceilingclip starts out -1
int                 floorclip[ SCREENWIDTH ];     // dropoff overflow
int                 ceilingclip[ SCREENWIDTH ];   // dropoff overflow

fixed_t             *yslope;
fixed_t             yslopes[ LOOKDIRS ][ SCREENHEIGHT ];

dboolean            r_liquid_current; //=r_liquid_current_default;
dboolean            r_liquid_swirl; //=r_liquid_swirl_default;


// p_doors.c
dboolean    r_graduallighting; //=r_graduallighting_default;

// p_setup.c
dboolean        canmodify;
dboolean        transferredsky;
dboolean        r_fixmaperrors; //=r_fixmaperrors_default;
dboolean        samelevel;
dboolean            skipblstart;            // MaxW: Skip initial blocklist short

const char *linespecials[];

char    mapnum[ 6 ];
char    maptitle[ 256 ];
char    mapnumandtitle[ 512 ];
char    automaptitle[ 512 ];

mapformat_t     mapformat;
const char *mapformats[];

dboolean        boomcompatible;
dboolean        mbfcompatible;
dboolean        blockmaprebuilt;
dboolean        transferredsky;
dboolean        nojump;// = false;
dboolean        nomouselook;// = false;


// r_data.c
dboolean    r_fixspriteoffsets; //= r_fixspriteoffsets_default;
int         firstflat;
//static int  lastflat;
int         numflats;

//static int  missingflatnum;

int         firstspritelump;
int         lastspritelump;
int         numspritelumps;

dboolean    telefragonmap30; //= false;

int         numtextures;
texture_t   **textures;

// needed for texture pegging
fixed_t     *textureheight;
byte        **brightmap;
dboolean    *nobrightmap;


// for global animation
int         *flattranslation;
int         *texturetranslation;

// needed for prerendering
fixed_t     *spritewidth;
fixed_t     *spriteheight;
fixed_t     *spriteoffset;
fixed_t     *spritetopoffset;

fixed_t     *newspriteoffset;
fixed_t     *newspritetopoffset;

dboolean    r_fixspriteoffsets; //= r_fixspriteoffsets_default;

byte        grays[ 256 ];


// r_segs.c
lighttable_t        **walllights;
dboolean            r_brightmaps; //= r_brightmaps_default;


// s_sound.c
int                 s_channels; //= s_channels_default;
int                 s_musicvolume; //= s_musicvolume_default;
dboolean            s_randommusic; //= s_randommusic_default;
dboolean            s_randompitch; //= s_randompitch_default;
int                 s_sfxvolume; //= s_sfxvolume_default;
dboolean            s_stereo; //= s_stereo_default;


// Maximum volume of a sound effect.
// Internal default is max out of 0-31.
int                 sfxVolume;

// Maximum volume of music.
int                 musicVolume;


// d_deh.c
int             dehcount;
dboolean        dehacked;

// #include "d_deh.h" -- we don't do that here but we declare the
// variables. This externalizes everything that there is a string
// set for in the language files. See d_deh.h for detailed comments,
// original English values etc. These are set to the macro values,
// which are set by D_ENGLSH.H or D_FRENCH.H(etc). BEX files are a
// better way of changing these strings globally by language.

// ====================================================================
// Any of these can be changed using the bex extensions

char    *s_VERSION; //= "";

char    *s_D_DEVSTR; //= D_DEVSTR;
char    *s_D_CDROM; //= D_CDROM;

char    *s_PRESSKEY; //= PRESSKEY;
char    *s_PRESSYN; //= PRESSYN;
char    *s_PRESSA; //= "";
char    *s_QUITMSG; //= QUITMSG;
char    *s_LOADNET; //= LOADNET;
char    *s_QLOADNET; //= QLOADNET;
char    *s_QSAVESPOT; //= QSAVESPOT;
char    *s_SAVEDEAD; //= SAVEDEAD;
char    *s_QSPROMPT; //= QSPROMPT;
char    *s_QLPROMPT; //= QLPROMPT;
char    *s_DELPROMPT; //= "";
char    *s_NEWGAME; //= NEWGAME;
char    *s_NIGHTMARE; //= NIGHTMARE;
char    *s_SWSTRING; //= SWSTRING;
char    *s_MSGOFF; //= MSGOFF;
char    *s_MSGON; //= MSGON;
char    *s_NETEND; //= NETEND;
char    *s_ENDGAME; //= ENDGAME;
char    *s_DOSY; //= DOSY;
char    *s_DOSA; //= "";
char    *s_DETAILHI; //= DETAILHI;
char    *s_DETAILLO; //= DETAILLO;
char    *s_GAMMALVL0; //= GAMMALVL0;
char    *s_GAMMALVL1; //= GAMMALVL1;
char    *s_GAMMALVL2; //= GAMMALVL2;
char    *s_GAMMALVL3; //= GAMMALVL3;
char    *s_GAMMALVL4; //= GAMMALVL4;
char    *s_GAMMALVL; //= "";
char    *s_GAMMAOFF; //= "";
char    *s_EMPTYSTRING; //= EMPTYSTRING;

char    *s_GOTARMOR; //= GOTARMOR;
char    *s_GOTMEGA; //= GOTMEGA;
char    *s_GOTHTHBONUS; //= GOTHTHBONUS;
char    *s_GOTARMBONUS; //= GOTARMBONUS;
char    *s_GOTSTIM; //= GOTSTIM;
char    *s_GOTMEDINEED; //= GOTMEDINEED;
char    *s_GOTMEDIKIT; //= GOTMEDIKIT;
char    *s_GOTSUPER; //= GOTSUPER;

char    *s_GOTBLUECARD; //= GOTBLUECARD;
char    *s_GOTYELWCARD; //= GOTYELWCARD;
char    *s_GOTREDCARD; //= GOTREDCARD;
char    *s_GOTBLUESKUL; //= GOTBLUESKUL;
char    *s_GOTYELWSKUL; //= GOTYELWSKUL;
char    *s_GOTREDSKUL; //= GOTREDSKULL;
char    *s_GOTREDSKULL; //= GOTREDSKULL;

char    *s_GOTINVUL; //= GOTINVUL;
char    *s_GOTBERSERK; //= GOTBERSERK;
char    *s_GOTINVIS; //= GOTINVIS;
char    *s_GOTSUIT; //= GOTSUIT;
char    *s_GOTMAP; //= GOTMAP;
char    *s_GOTVISOR; //= GOTVISOR;

char    *s_GOTCLIP; //= GOTCLIP;
char    *s_GOTCLIPBOX; //= GOTCLIPBOX;
char    *s_GOTROCKET; //= GOTROCKET;
char    *s_GOTROCKETX2; //= "";
char    *s_GOTROCKBOX; //= GOTROCKBOX;
char    *s_GOTCELL; //= GOTCELL;
char    *s_GOTCELLX2; //= "";
char    *s_GOTCELLBOX; //= GOTCELLBOX;
char    *s_GOTSHELLS; //= GOTSHELLS;
char    *s_GOTSHELLSX2; //= "";
char    *s_GOTSHELLBOX; //= GOTSHELLBOX;
char    *s_GOTBACKPACK; //= GOTBACKPACK;

char    *s_GOTBFG9000; //= GOTBFG9000;
char    *s_GOTCHAINGUN; //= GOTCHAINGUN;
char    *s_GOTCHAINSAW; //= GOTCHAINSAW;
char    *s_GOTLAUNCHER; //= GOTLAUNCHER;
char    *s_GOTMSPHERE; //= GOTMSPHERE;
char    *s_GOTPLASMA; //= GOTPLASMA;
char    *s_GOTSHOTGUN; //= GOTSHOTGUN;
char    *s_GOTSHOTGUN2; //= GOTSHOTGUN2;

char    *s_PD_BLUEO; //= PD_BLUEO;
char    *s_PD_REDO; //= PD_REDO;
char    *s_PD_YELLOWO; //= PD_YELLOWO;
char    *s_PD_BLUEK; //= PD_BLUEK;
char    *s_PD_REDK; //= PD_REDK;
char    *s_PD_YELLOWK; //= PD_YELLOWK;
char    *s_PD_BLUEC; //= "";
char    *s_PD_REDC; //= "";
char    *s_PD_YELLOWC; //= "";
char    *s_PD_BLUES; //= "";
char    *s_PD_REDS; //= "";
char    *s_PD_YELLOWS; //= "";
char    *s_PD_ANY; //= "";
char    *s_PD_ALL3; //= "";
char    *s_PD_ALL6; //= "";
char    *s_KEYCARD; //= "";
char    *s_SKULLKEY; //= "";

char    *s_SECRET; //= "";

char    *s_GGSAVED; //= GGSAVED;
char    *s_GGAUTOSAVED; //= "";
char    *s_GGLOADED; //= "";
char    *s_GGAUTOLOADED; //= "";
char    *s_GGDELETED; //= "";
char    *s_GSCREENSHOT; //= GSCREENSHOT;

char    *s_ALWAYSRUNOFF; //= "";
char    *s_ALWAYSRUNON; //= "";

char    *s_HUSTR_MSGU; //= HUSTR_MSGU;

char    *s_HUSTR_E1M1; //= HUSTR_E1M1;
char    *s_HUSTR_E1M2; //= HUSTR_E1M2;
char    *s_HUSTR_E1M3; //= HUSTR_E1M3;
char    *s_HUSTR_E1M4; //= HUSTR_E1M4;
char    *s_HUSTR_E1M5; //= HUSTR_E1M5;
char    *s_HUSTR_E1M6; //= HUSTR_E1M6;
char    *s_HUSTR_E1M7; //= HUSTR_E1M7;
char    *s_HUSTR_E1M8; //= HUSTR_E1M8;
char    *s_HUSTR_E1M9; //= HUSTR_E1M9;
char    *s_HUSTR_E2M1; //= HUSTR_E2M1;
char    *s_HUSTR_E2M2; //= HUSTR_E2M2;
char    *s_HUSTR_E2M3; //= HUSTR_E2M3;
char    *s_HUSTR_E2M4; //= HUSTR_E2M4;
char    *s_HUSTR_E2M5; //= HUSTR_E2M5;
char    *s_HUSTR_E2M6; //= HUSTR_E2M6;
char    *s_HUSTR_E2M7; //= HUSTR_E2M7;
char    *s_HUSTR_E2M8; //= HUSTR_E2M8;
char    *s_HUSTR_E2M9; //= HUSTR_E2M9;
char    *s_HUSTR_E3M1; //= HUSTR_E3M1;
char    *s_HUSTR_E3M2; //= HUSTR_E3M2;
char    *s_HUSTR_E3M3; //= HUSTR_E3M3;
char    *s_HUSTR_E3M4; //= HUSTR_E3M4;
char    *s_HUSTR_E3M5; //= HUSTR_E3M5;
char    *s_HUSTR_E3M6; //= HUSTR_E3M6;
char    *s_HUSTR_E3M7; //= HUSTR_E3M7;
char    *s_HUSTR_E3M7_ALT; //= "";
char    *s_HUSTR_E3M8; //= HUSTR_E3M8;
char    *s_HUSTR_E3M9; //= HUSTR_E3M9;
char    *s_HUSTR_E4M1; //= HUSTR_E4M1;
char    *s_HUSTR_E4M2; //= HUSTR_E4M2;
char    *s_HUSTR_E4M3; //= HUSTR_E4M3;
char    *s_HUSTR_E4M4; //= HUSTR_E4M4;
char    *s_HUSTR_E4M5; //= HUSTR_E4M5;
char    *s_HUSTR_E4M6; //= HUSTR_E4M6;
char    *s_HUSTR_E4M7; //= HUSTR_E4M7;
char    *s_HUSTR_E4M8; //= HUSTR_E4M8;
char    *s_HUSTR_E4M9; //= HUSTR_E4M9;
char    *s_HUSTR_E5M1; //= "";
char    *s_HUSTR_E5M2; //= "";
char    *s_HUSTR_E5M3; //= "";
char    *s_HUSTR_E5M4; //= "";
char    *s_HUSTR_E5M5; //= "";
char    *s_HUSTR_E5M6; //= "";
char    *s_HUSTR_E5M7; //= "";
char    *s_HUSTR_E5M8; //= "";
char    *s_HUSTR_E5M9; //= "";
char    *s_HUSTR_1; //= HUSTR_1;
char    *s_HUSTR_2; //= HUSTR_2;
char    *s_HUSTR_3; //= HUSTR_3;
char    *s_HUSTR_4; //= HUSTR_4;
char    *s_HUSTR_5; //= HUSTR_5;
char    *s_HUSTR_6; //= HUSTR_6;
char    *s_HUSTR_7; //= HUSTR_7;
char    *s_HUSTR_8; //= HUSTR_8;
char    *s_HUSTR_9; //= HUSTR_9;
char    *s_HUSTR_10; //= HUSTR_10;
char    *s_HUSTR_11; //= HUSTR_11;
char    *s_HUSTR_11_ALT; //= "";
char    *s_HUSTR_12; //= HUSTR_12;
char    *s_HUSTR_13; //= HUSTR_13;
char    *s_HUSTR_14; //= HUSTR_14;
char    *s_HUSTR_15; //= HUSTR_15;
char    *s_HUSTR_16; //= HUSTR_16;
char    *s_HUSTR_17; //= HUSTR_17;
char    *s_HUSTR_18; //= HUSTR_18;
char    *s_HUSTR_19; //= HUSTR_19;
char    *s_HUSTR_20; //= HUSTR_20;
char    *s_HUSTR_21; //= HUSTR_21;
char    *s_HUSTR_22; //= HUSTR_22;
char    *s_HUSTR_23; //= HUSTR_23;
char    *s_HUSTR_24; //= HUSTR_24;
char    *s_HUSTR_25; //= HUSTR_25;
char    *s_HUSTR_26; //= HUSTR_26;
char    *s_HUSTR_27; //= HUSTR_27;
char    *s_HUSTR_28; //= HUSTR_28;
char    *s_HUSTR_29; //= HUSTR_29;
char    *s_HUSTR_30; //= HUSTR_30;
char    *s_HUSTR_31; //= HUSTR_31;
char    *s_HUSTR_31_BFG; //= "";
char    *s_HUSTR_32; //= HUSTR_32;
char    *s_HUSTR_32_BFG; //= "";
char    *s_HUSTR_33; //= "";
char    *s_PHUSTR_1; //= PHUSTR_1;
char    *s_PHUSTR_2; //= PHUSTR_2;
char    *s_PHUSTR_3; //= PHUSTR_3;
char    *s_PHUSTR_4; //= PHUSTR_4;
char    *s_PHUSTR_5; //= PHUSTR_5;
char    *s_PHUSTR_6; //= PHUSTR_6;
char    *s_PHUSTR_7; //= PHUSTR_7;
char    *s_PHUSTR_8; //= PHUSTR_8;
char    *s_PHUSTR_9; //= PHUSTR_9;
char    *s_PHUSTR_10; //= PHUSTR_10;
char    *s_PHUSTR_11; //= PHUSTR_11;
char    *s_PHUSTR_12; //= PHUSTR_12;
char    *s_PHUSTR_13; //= PHUSTR_13;
char    *s_PHUSTR_14; //= PHUSTR_14;
char    *s_PHUSTR_15; //= PHUSTR_15;
char    *s_PHUSTR_16; //= PHUSTR_16;
char    *s_PHUSTR_17; //= PHUSTR_17;
char    *s_PHUSTR_18; //= PHUSTR_18;
char    *s_PHUSTR_19; //= PHUSTR_19;
char    *s_PHUSTR_20; //= PHUSTR_20;
char    *s_PHUSTR_21; //= PHUSTR_21;
char    *s_PHUSTR_22; //= PHUSTR_22;
char    *s_PHUSTR_23; //= PHUSTR_23;
char    *s_PHUSTR_24; //= PHUSTR_24;
char    *s_PHUSTR_25; //= PHUSTR_25;
char    *s_PHUSTR_26; //= PHUSTR_26;
char    *s_PHUSTR_27; //= PHUSTR_27;
char    *s_PHUSTR_28; //= PHUSTR_28;
char    *s_PHUSTR_29; //= PHUSTR_29;
char    *s_PHUSTR_30; //= PHUSTR_30;
char    *s_PHUSTR_31; //= PHUSTR_31;
char    *s_PHUSTR_32; //= PHUSTR_32;
char    *s_THUSTR_1; //= THUSTR_1;
char    *s_THUSTR_2; //= THUSTR_2;
char    *s_THUSTR_3; //= THUSTR_3;
char    *s_THUSTR_4; //= THUSTR_4;
char    *s_THUSTR_5; //= THUSTR_5;
char    *s_THUSTR_6; //= THUSTR_6;
char    *s_THUSTR_7; //= THUSTR_7;
char    *s_THUSTR_8; //= THUSTR_8;
char    *s_THUSTR_9; //= THUSTR_9;
char    *s_THUSTR_10; //= THUSTR_10;
char    *s_THUSTR_11; //= THUSTR_11;
char    *s_THUSTR_12; //= THUSTR_12;
char    *s_THUSTR_13; //= THUSTR_13;
char    *s_THUSTR_14; //= THUSTR_14;
char    *s_THUSTR_15; //= THUSTR_15;
char    *s_THUSTR_16; //= THUSTR_16;
char    *s_THUSTR_17; //= THUSTR_17;
char    *s_THUSTR_18; //= THUSTR_18;
char    *s_THUSTR_19; //= THUSTR_19;
char    *s_THUSTR_20; //= THUSTR_20;
char    *s_THUSTR_21; //= THUSTR_21;
char    *s_THUSTR_22; //= THUSTR_22;
char    *s_THUSTR_23; //= THUSTR_23;
char    *s_THUSTR_24; //= THUSTR_24;
char    *s_THUSTR_25; //= THUSTR_25;
char    *s_THUSTR_26; //= THUSTR_26;
char    *s_THUSTR_27; //= THUSTR_27;
char    *s_THUSTR_28; //= THUSTR_28;
char    *s_THUSTR_29; //= THUSTR_29;
char    *s_THUSTR_30; //= THUSTR_30;
char    *s_THUSTR_31; //= THUSTR_31;
char    *s_THUSTR_32; //= THUSTR_32;
char    *s_NHUSTR_1; //= "";
char    *s_NHUSTR_2; //= "";
char    *s_NHUSTR_3; //= "";
char    *s_NHUSTR_4; //= "";
char    *s_NHUSTR_5; //= "";
char    *s_NHUSTR_6; //= "";
char    *s_NHUSTR_7; //= "";
char    *s_NHUSTR_8; //= "";
char    *s_NHUSTR_9; //= "";

char    *s_HUSTR_CHATMACRO1; //= HUSTR_CHATMACRO1;
char    *s_HUSTR_CHATMACRO2; //= HUSTR_CHATMACRO2;
char    *s_HUSTR_CHATMACRO3; //= HUSTR_CHATMACRO3;
char    *s_HUSTR_CHATMACRO4; //= HUSTR_CHATMACRO4;
char    *s_HUSTR_CHATMACRO5; //= HUSTR_CHATMACRO5;
char    *s_HUSTR_CHATMACRO6; //= HUSTR_CHATMACRO6;
char    *s_HUSTR_CHATMACRO7; //= HUSTR_CHATMACRO7;
char    *s_HUSTR_CHATMACRO8; //= HUSTR_CHATMACRO8;
char    *s_HUSTR_CHATMACRO9; //= HUSTR_CHATMACRO9;
char    *s_HUSTR_CHATMACRO0; //= HUSTR_CHATMACRO0;

char    *s_HUSTR_TALKTOSELF1; //= HUSTR_TALKTOSELF1;
char    *s_HUSTR_TALKTOSELF2; //= HUSTR_TALKTOSELF2;
char    *s_HUSTR_TALKTOSELF3; //= HUSTR_TALKTOSELF3;
char    *s_HUSTR_TALKTOSELF4; //= HUSTR_TALKTOSELF4;
char    *s_HUSTR_TALKTOSELF5; //= HUSTR_TALKTOSELF5;

char    *s_HUSTR_MESSAGESENT; //= HUSTR_MESSAGESENT;

char    *s_HUSTR_PLRGREEN; //= HUSTR_PLRGREEN;
char    *s_HUSTR_PLRINDIGO; //= HUSTR_PLRINDIGO;
char    *s_HUSTR_PLRBROWN; //= HUSTR_PLRBROWN;
char    *s_HUSTR_PLRRED; //= HUSTR_PLRRED;

char    *s_AMSTR_FOLLOWON; //= AMSTR_FOLLOWON;
char    *s_AMSTR_FOLLOWOFF; //= AMSTR_FOLLOWOFF;
char    *s_AMSTR_GRIDON; //= AMSTR_GRIDON;
char    *s_AMSTR_GRIDOFF; //= AMSTR_GRIDOFF;
char    *s_AMSTR_MARKEDSPOT; //= AMSTR_MARKEDSPOT;
char    *s_AMSTR_MARKCLEARED; //= "";
char    *s_AMSTR_MARKSCLEARED; //= AMSTR_MARKSCLEARED;
char    *s_AMSTR_ROTATEON; //= "";
char    *s_AMSTR_ROTATEOFF; //= "";

char    *s_STSTR_MUS; //= STSTR_MUS;
char    *s_STSTR_NOMUS; //= STSTR_NOMUS;
char    *s_STSTR_DQDON; //= STSTR_DQDON;
char    *s_STSTR_DQDOFF; //= STSTR_DQDOFF;
char    *s_STSTR_KFAADDED; //= STSTR_KFAADDED;
char    *s_STSTR_FAADDED; //= STSTR_FAADDED;
char    *s_STSTR_NCON; //= STSTR_NCON;
char    *s_STSTR_NCOFF; //= STSTR_NCOFF;
char    *s_STSTR_BEHOLD; //= STSTR_BEHOLD;
char    *s_STSTR_BEHOLDX; //= STSTR_BEHOLDX;
char    *s_STSTR_BEHOLDON; //= "";
char    *s_STSTR_BEHOLDOFF; //= "";
char    *s_STSTR_BUDDHAON; //= "";
char    *s_STSTR_BUDDHAOFF; //= "";
char    *s_STSTR_CHOPPERS; //= STSTR_CHOPPERS;
char    *s_STSTR_CLEV; //= STSTR_CLEV;
char    *s_STSTR_CLEVSAME; //= "";
char    *s_STSTR_MYPOS; //= "";
char    *s_STSTR_NTON; //= "";
char    *s_STSTR_NTOFF; //= "";
char    *s_STSTR_GODON; //= "";
char    *s_STSTR_GODOFF; //= "";
char    *s_STSTR_NMON; //= "";
char    *s_STSTR_NMOFF; //= "";
char    *s_STSTR_PSON; //= "";
char    *s_STSTR_PSOFF; //= "";
char    *s_STSTR_FMON; //= "";
char    *s_STSTR_FMOFF; //= "";
char    *s_STSTR_RION; //= "";
char    *s_STSTR_RIOFF; //= "";
char    *s_STSTR_RMON; //= "";
char    *s_STSTR_RMOFF; //= "";
char    *s_STSTR_FON; //= "";
char    *s_STSTR_FOFF; //= "";
char    *s_STSTR_RHON; //= "";
char    *s_STSTR_RHOFF; //= "";
char    *s_STSTR_VON; //= "";
char    *s_STSTR_VOFF; //= "";

char    *s_E1TEXT; //= E1TEXT;
char    *s_E2TEXT; //= E2TEXT;
char    *s_E3TEXT; //= E3TEXT;
char    *s_E4TEXT; //= E4TEXT;
char    *s_E5TEXT; //= "";
char    *s_C1TEXT; //= C1TEXT;
char    *s_C2TEXT; //= C2TEXT;
char    *s_C3TEXT; //= C3TEXT;
char    *s_C4TEXT; //= C4TEXT;
char    *s_C5TEXT; //= C5TEXT;
char    *s_C6TEXT; //= C6TEXT;
char    *s_P1TEXT; //= P1TEXT;
char    *s_P2TEXT; //= P2TEXT;
char    *s_P3TEXT; //= P3TEXT;
char    *s_P4TEXT; //= P4TEXT;
char    *s_P5TEXT; //= P5TEXT;
char    *s_P6TEXT; //= P6TEXT;
char    *s_T1TEXT; //= T1TEXT;
char    *s_T2TEXT; //= T2TEXT;
char    *s_T3TEXT; //= T3TEXT;
char    *s_T4TEXT; //= T4TEXT;
char    *s_T5TEXT; //= T5TEXT;
char    *s_T6TEXT; //= T6TEXT;
char    *s_N1TEXT; //= "";

char    *s_CC_ZOMBIE; //= CC_ZOMBIE;
char    *s_CC_SHOTGUN; //= CC_SHOTGUN;
char    *s_CC_HEAVY; //= CC_HEAVY;
char    *s_CC_IMP; //= CC_IMP;
char    *s_CC_DEMON; //= CC_DEMON;
char    *s_CC_SPECTRE; //= "";
char    *s_CC_LOST; //= CC_LOST;
char    *s_CC_CACO; //= CC_CACO;
char    *s_CC_HELL; //= CC_HELL;
char    *s_CC_BARON; //= CC_BARON;
char    *s_CC_ARACH; //= CC_ARACH;
char    *s_CC_PAIN; //= CC_PAIN;
char    *s_CC_REVEN; //= CC_REVEN;
char    *s_CC_MANCU; //= CC_MANCU;
char    *s_CC_ARCH; //= CC_ARCH;
char    *s_CC_SPIDER; //= CC_SPIDER;
char    *s_CC_CYBER; //= CC_CYBER;
char    *s_CC_HERO; //= CC_HERO;

char    *s_DOOM_ENDMSG1; //= DOOM_ENDMSG1;
char    *s_DOOM_ENDMSG2; //= DOOM_ENDMSG2;
char    *s_DOOM_ENDMSG3; //= DOOM_ENDMSG3;
char    *s_DOOM_ENDMSG4; //= DOOM_ENDMSG4;
char    *s_DOOM_ENDMSG5; //= DOOM_ENDMSG5;
char    *s_DOOM_ENDMSG6; //= DOOM_ENDMSG6;
char    *s_DOOM_ENDMSG7; //= DOOM_ENDMSG7;
char    *s_DOOM2_ENDMSG1; //= DOOM2_ENDMSG1;
char    *s_DOOM2_ENDMSG2; //= DOOM2_ENDMSG2;
char    *s_DOOM2_ENDMSG3; //= DOOM2_ENDMSG3;
char    *s_DOOM2_ENDMSG4; //= DOOM2_ENDMSG4;
char    *s_DOOM2_ENDMSG5; //= DOOM2_ENDMSG5;
char    *s_DOOM2_ENDMSG6; //= DOOM2_ENDMSG6;
char    *s_DOOM2_ENDMSG7; //= DOOM2_ENDMSG7;

char    *s_M_NEWGAME; //= "";
char    *s_M_OPTIONS; //= "";
char    *s_M_LOADGAME; //= "";
char    *s_M_SAVEGAME; //= "";
char    *s_M_QUITGAME; //= "";
char    *s_M_WHICHEPISODE; //= "";
char    *s_M_EPISODE1; //= "";
char    *s_M_EPISODE2; //= "";
char    *s_M_EPISODE3; //= "";
char    *s_M_EPISODE4; //= "";
char    *s_M_EPISODE5; //= "";
char    *s_M_EPISODE6; //= "";
char    *s_M_EPISODE7; //= "";
char    *s_M_EPISODE8; //= "";
char    *s_M_WHICHEXPANSION; //= "";
char    *s_M_EXPANSION1; //= "";
char    *s_M_EXPANSION2; //= "";
char    *s_M_CHOOSESKILLLEVEL; //= "";
char    *s_M_SKILLLEVEL1; //= "";
char    *s_M_SKILLLEVEL2; //= "";
char    *s_M_SKILLLEVEL3; //= "";
char    *s_M_SKILLLEVEL4; //= "";
char    *s_M_SKILLLEVEL5; //= "";
char    *s_M_ENDGAME; //= "";
char    *s_M_MESSAGES; //= "";
char    *s_M_ON; //= "";
char    *s_M_OFF; //= "";
char    *s_M_GRAPHICDETAIL; //= "";
char    *s_M_HIGH; //= "";
char    *s_M_LOW; //= "";
char    *s_M_SCREENSIZE; //= "";
char    *s_M_MOUSESENSITIVITY; //= "";
char    *s_M_GAMEPADSENSITIVITY; //= "";
char    *s_M_SOUNDVOLUME; //= "";
char    *s_M_SFXVOLUME; //= "";
char    *s_M_MUSICVOLUME; //= "";
char    *s_M_PAUSED; //= "";
char    *s_M_MORE; //= "";

char    *s_CAPTION_SHAREWARE; //= "";
char    *s_CAPTION_REGISTERED; //= "";
char    *s_CAPTION_ULTIMATE; //= "";
char    *s_CAPTION_DOOM2; //= "";
char    *s_CAPTION_HELLONEARTH; //= "";
char    *s_CAPTION_NERVE; //= "";
char    *s_CAPTION_BFGEDITION; //= "";
char    *s_CAPTION_PLUTONIA; //= "";
char    *s_CAPTION_TNT; //= "";
char    *s_CAPTION_CHEX; //= "";
char    *s_CAPTION_CHEX2; //= "";
char    *s_CAPTION_HACX; //= "";
char    *s_CAPTION_FREEDOOM1; //= "";
char    *s_CAPTION_FREEDOOM2; //= "";
char    *s_CAPTION_FREEDM; //= "";
char    *s_CAPTION_BTSXE1; //= "";
char    *s_CAPTION_BTSXE2; //= "";
char    *s_CAPTION_BTSXE3; //= "";
char    *s_CAPTION_E1M4B; //= "";
char    *s_CAPTION_E1M8B; //= "";

char    *s_AUTHOR_ROMERO; //= "";

char    *bgflatE1; //= "FLOOR4_8";
char    *bgflatE2; //= "SFLR6_1";
char    *bgflatE3; //= "MFLR8_4";
char    *bgflatE4; //= "MFLR8_3";
char    *bgflatE5; //= "FLOOR4_8";
char    *bgflat06; //= "SLIME16";
char    *bgflat11; //= "RROCK14";
char    *bgflat20; //= "RROCK07";
char    *bgflat30; //= "RROCK17";
char    *bgflat15; //= "RROCK13";
char    *bgflat31; //= "RROCK19";
char    *bgcastcall; //= "BOSSBACK";

char    *startup1; //= "";
char    *startup2; //= "";
char    *startup3; //= "";
char    *startup4; //= "";
char    *startup5; //= "";

char    *savegamename; //= SAVEGAMENAME;

char    *s_BANNER1; //= BANNER1;
char    *s_BANNER2; //= BANNER2;
char    *s_BANNER3; //= BANNER3;
char    *s_BANNER4; //= BANNER4;
char    *s_BANNER5; //= BANNER5;
char    *s_BANNER6; //= BANNER6;
char    *s_BANNER7; //= BANNER7;

char    *s_COPYRIGHT1; //= COPYRIGHT1;
char    *s_COPYRIGHT2; //= COPYRIGHT2;
char    *s_COPYRIGHT3; //= COPYRIGHT3;

char    *s_OB_SUICIDE; //= "";
char    *s_OB_FALLING; //= "";
char    *s_OB_CRUSH; //= "";
char    *s_OB_EXIT; //= "";
char    *s_OB_WATER; //= "";
char    *s_OB_SLIME; //= "";
char    *s_OB_LAVA; //= "";
char    *s_OB_BARREL; //= "";
char    *s_OB_SPLASH; //= "";
char    *s_OB_R_SPLASH; //= "";
char    *s_OB_ROCKET; //= "";
char    *s_OB_KILLEDSELF; //= "";
char    *s_OB_STEALTHBABY; //= "";
char    *s_OB_STEALTHVILE; //= "";
char    *s_OB_STEALTHBARON; //= "";
char    *s_OB_STEALTHCACO; //= "";
char    *s_OB_STEALTHCHAINGUY; //= "";
char    *s_OB_STEALTHDEMON; //= "";
char    *s_OB_STEALTHKNIGHT; //= "";
char    *s_OB_STEALTHIMP; //= "";
char    *s_OB_STEALTHFATSO; //= "";
char    *s_OB_STEALTHUNDEAD; //= "";
char    *s_OB_STEALTHSHOTGUY; //= "";
char    *s_OB_STEALTHZOMBIE; //= "";
char    *s_OB_UNDEADHIT; //= "";
char    *s_OB_IMPHIT; //= "";
char    *s_OB_CACOHIT; //= "";
char    *s_OB_DEMONHIT; //= "";
char    *s_OB_SPECTREHIT; //= "";
char    *s_OB_BARONHIT; //= "";
char    *s_OB_KNIGHTHIT; //= "";
char    *s_OB_ZOMBIE; //= "";
char    *s_OB_SHOTGUY; //= "";
char    *s_OB_VILE; //= "";
char    *s_OB_UNDEAD; //= "";
char    *s_OB_FATSO; //= "";
char    *s_OB_CHAINGUY; //= "";
char    *s_OB_SKULL; //= "";
char    *s_OB_IMP; //= "";
char    *s_OB_CACO; //= "";
char    *s_OB_BARON; //= "";
char    *s_OB_KNIGHT; //= "";
char    *s_OB_SPIDER; //= "";
char    *s_OB_BABY; //= "";
char    *s_OB_CYBORG; //= "";
char    *s_OB_WOLFSS; //= "";
char    *s_OB_MPFIST; //= "";
char    *s_OB_MPCHAINSAW; //= "";
char    *s_OB_MPPISTOL; //= "";
char    *s_OB_MPSHOTGUN; //= "";
char    *s_OB_MPSSHOTGUN; //= "";
char    *s_OB_MPCHAINGUN; //= "";
char    *s_OB_MPROCKET; //= "";
char    *s_OB_MPR_SPLASH; //= "";
char    *s_OB_MPPLASMARIFLE; //= "";
char    *s_OB_MPBFG_BOOM; //= "";
char    *s_OB_MPBFG_SPLASH; //= "";
char    *s_OB_MPTELEFRAG; //= "";
char    *s_OB_RAILGUN; //= "";
char    *s_OB_MPBFG_MBF; //= "";
char    *s_OB_MONTELEFRAG; //= "";
char    *s_OB_DEFAULT; //= "";
char    *s_OB_FRIENDLY1; //= "";
char    *s_OB_FRIENDLY2; //= "";
char    *s_OB_FRIENDLY3; //= "";
char    *s_OB_FRIENDLY4; //= "";

deh_strs deh_strlookup[];// =
//{
//	{ &s_VERSION,                    "VERSION" },
//
//	{ &s_D_DEVSTR,                   "D_DEVSTR" },
//	{ &s_D_CDROM,                    "D_CDROM" },
//
//	{ &s_PRESSKEY,                   "PRESSKEY" },
//	{ &s_PRESSYN,                    "PRESSYN" },
//	{ &s_PRESSA,                     "PRESSA" },
//	{ &s_QUITMSG,                    "QUITMSG" },
//	{ &s_LOADNET,                    "LOADNET" },
//	{ &s_QLOADNET,                   "QLOADNET" },
//	{ &s_QSAVESPOT,                  "QSAVESPOT" },
//	{ &s_SAVEDEAD,                   "SAVEDEAD" },
//	{ &s_QSPROMPT,                   "QSPROMPT" },
//	{ &s_QLPROMPT,                   "QLPROMPT" },
//	{ &s_DELPROMPT,                  "DELPROMPT" },
//	{ &s_NEWGAME,                    "NEWGAME" },
//	{ &s_NIGHTMARE,                  "NIGHTMARE" },
//	{ &s_SWSTRING,                   "SWSTRING" },
//	{ &s_MSGOFF,                     "MSGOFF" },
//	{ &s_MSGON,                      "MSGON" },
//	{ &s_NETEND,                     "NETEND" },
//	{ &s_ENDGAME,                    "ENDGAME" },
//	{ &s_DOSY,                       "DOSY" },
//	{ &s_DOSA,                       "DOSA" },
//	{ &s_DETAILHI,                   "DETAILHI" },
//	{ &s_DETAILLO,                   "DETAILLO" },
//	{ &s_GAMMALVL0,                  "GAMMALVL0" },
//	{ &s_GAMMALVL1,                  "GAMMALVL1" },
//	{ &s_GAMMALVL2,                  "GAMMALVL2" },
//	{ &s_GAMMALVL3,                  "GAMMALVL3" },
//	{ &s_GAMMALVL4,                  "GAMMALVL4" },
//	{ &s_GAMMALVL,                   "GAMMALVL" },
//	{ &s_GAMMAOFF,                   "GAMMAOFF" },
//	{ &s_EMPTYSTRING,                "EMPTYSTRING" },
//
//	{ &s_GOTARMOR,                   "GOTARMOR" },
//	{ &s_GOTMEGA,                    "GOTMEGA" },
//	{ &s_GOTHTHBONUS,                "GOTHTHBONUS" },
//	{ &s_GOTARMBONUS,                "GOTARMBONUS" },
//	{ &s_GOTSTIM,                    "GOTSTIM" },
//	{ &s_GOTMEDINEED,                "GOTMEDINEED" },
//	{ &s_GOTMEDIKIT,                 "GOTMEDIKIT" },
//	{ &s_GOTSUPER,                   "GOTSUPER" },
//
//	{ &s_GOTBLUECARD,                "GOTBLUECARD" },
//	{ &s_GOTYELWCARD,                "GOTYELWCARD" },
//	{ &s_GOTREDCARD,                 "GOTREDCARD" },
//	{ &s_GOTBLUESKUL,                "GOTBLUESKUL" },
//	{ &s_GOTYELWSKUL,                "GOTYELWSKUL" },
//	{ &s_GOTREDSKUL,                 "GOTREDSKUL" },
//	{ &s_GOTREDSKULL,                "GOTREDSKULL" },
//
//	{ &s_GOTINVUL,                   "GOTINVUL" },
//	{ &s_GOTBERSERK,                 "GOTBERSERK" },
//	{ &s_GOTINVIS,                   "GOTINVIS" },
//	{ &s_GOTSUIT,                    "GOTSUIT" },
//	{ &s_GOTMAP,                     "GOTMAP" },
//	{ &s_GOTVISOR,                   "GOTVISOR" },
//
//	{ &s_GOTCLIP,                    "GOTCLIP" },
//	{ &s_GOTCLIPBOX,                 "GOTCLIPBOX" },
//	{ &s_GOTROCKET,                  "GOTROCKET" },
//	{ &s_GOTROCKETX2,                "GOTROCKETX2" },
//	{ &s_GOTROCKBOX,                 "GOTROCKBOX" },
//	{ &s_GOTCELL,                    "GOTCELL" },
//	{ &s_GOTCELLX2,                  "GOTCELLX2" },
//	{ &s_GOTCELLBOX,                 "GOTCELLBOX" },
//	{ &s_GOTSHELLS,                  "GOTSHELLS" },
//	{ &s_GOTSHELLSX2,                "GOTSHELLSX2" },
//	{ &s_GOTSHELLBOX,                "GOTSHELLBOX" },
//	{ &s_GOTBACKPACK,                "GOTBACKPACK" },
//
//	{ &s_GOTBFG9000,                 "GOTBFG9000" },
//	{ &s_GOTCHAINGUN,                "GOTCHAINGUN" },
//	{ &s_GOTCHAINSAW,                "GOTCHAINSAW" },
//	{ &s_GOTLAUNCHER,                "GOTLAUNCHER" },
//	{ &s_GOTMSPHERE,                 "GOTMSPHERE" },
//	{ &s_GOTPLASMA,                  "GOTPLASMA" },
//	{ &s_GOTSHOTGUN,                 "GOTSHOTGUN" },
//	{ &s_GOTSHOTGUN2,                "GOTSHOTGUN2" },
//
//	{ &s_PD_BLUEO,                   "PD_BLUEO" },
//	{ &s_PD_REDO,                    "PD_REDO" },
//	{ &s_PD_YELLOWO,                 "PD_YELLOWO" },
//	{ &s_PD_BLUEK,                   "PD_BLUEK" },
//	{ &s_PD_REDK,                    "PD_REDK" },
//	{ &s_PD_YELLOWK,                 "PD_YELLOWK" },
//	{ &s_PD_BLUEC,                   "PD_BLUEC" },
//	{ &s_PD_REDC,                    "PD_REDC" },
//	{ &s_PD_YELLOWC,                 "PD_YELLOWC" },
//	{ &s_PD_BLUES,                   "PD_BLUES" },
//	{ &s_PD_REDS,                    "PD_REDS" },
//	{ &s_PD_YELLOWS,                 "PD_YELLOWS" },
//	{ &s_PD_ANY,                     "PD_ANY" },
//	{ &s_PD_ALL3,                    "PD_ALL3" },
//	{ &s_PD_ALL6,                    "PD_ALL6" },
//	{ &s_KEYCARD,                    "KEYCARD" },
//	{ &s_SKULLKEY,                   "SKULLKEY" },
//
//	{ &s_SECRET,                     "SECRET" },
//
//	{ &s_GGSAVED,                    "GGSAVED" },
//	{ &s_GGAUTOSAVED,                "GGAUTOSAVED" },
//	{ &s_GGLOADED,                   "GGLOADED" },
//	{ &s_GGAUTOLOADED,               "GGAUTOLOADED" },
//	{ &s_GGDELETED,                  "GGDELETED" },
//	{ &s_GSCREENSHOT,                "GSCREENSHOT" },
//
//	{ &s_ALWAYSRUNOFF,               "ALWAYSRUNOFF" },
//	{ &s_ALWAYSRUNON,                "ALWAYSRUNON" },
//
//	{ &s_HUSTR_MSGU,                 "HUSTR_MSGU" },
//
//	{ &s_HUSTR_E1M1,                 "HUSTR_E1M1" },
//	{ &s_HUSTR_E1M2,                 "HUSTR_E1M2" },
//	{ &s_HUSTR_E1M3,                 "HUSTR_E1M3" },
//	{ &s_HUSTR_E1M4,                 "HUSTR_E1M4" },
//	{ &s_HUSTR_E1M5,                 "HUSTR_E1M5" },
//	{ &s_HUSTR_E1M6,                 "HUSTR_E1M6" },
//	{ &s_HUSTR_E1M7,                 "HUSTR_E1M7" },
//	{ &s_HUSTR_E1M8,                 "HUSTR_E1M8" },
//	{ &s_HUSTR_E1M9,                 "HUSTR_E1M9" },
//	{ &s_HUSTR_E2M1,                 "HUSTR_E2M1" },
//	{ &s_HUSTR_E2M2,                 "HUSTR_E2M2" },
//	{ &s_HUSTR_E2M3,                 "HUSTR_E2M3" },
//	{ &s_HUSTR_E2M4,                 "HUSTR_E2M4" },
//	{ &s_HUSTR_E2M5,                 "HUSTR_E2M5" },
//	{ &s_HUSTR_E2M6,                 "HUSTR_E2M6" },
//	{ &s_HUSTR_E2M7,                 "HUSTR_E2M7" },
//	{ &s_HUSTR_E2M8,                 "HUSTR_E2M8" },
//	{ &s_HUSTR_E2M9,                 "HUSTR_E2M9" },
//	{ &s_HUSTR_E3M1,                 "HUSTR_E3M1" },
//	{ &s_HUSTR_E3M2,                 "HUSTR_E3M2" },
//	{ &s_HUSTR_E3M3,                 "HUSTR_E3M3" },
//	{ &s_HUSTR_E3M4,                 "HUSTR_E3M4" },
//	{ &s_HUSTR_E3M5,                 "HUSTR_E3M5" },
//	{ &s_HUSTR_E3M6,                 "HUSTR_E3M6" },
//	{ &s_HUSTR_E3M7,                 "HUSTR_E3M7" },
//	{ &s_HUSTR_E3M7_ALT,             "HUSTR_E3M7_ALT" },
//	{ &s_HUSTR_E3M8,                 "HUSTR_E3M8" },
//	{ &s_HUSTR_E3M9,                 "HUSTR_E3M9" },
//	{ &s_HUSTR_E4M1,                 "HUSTR_E4M1" },
//	{ &s_HUSTR_E4M2,                 "HUSTR_E4M2" },
//	{ &s_HUSTR_E4M3,                 "HUSTR_E4M3" },
//	{ &s_HUSTR_E4M4,                 "HUSTR_E4M4" },
//	{ &s_HUSTR_E4M5,                 "HUSTR_E4M5" },
//	{ &s_HUSTR_E4M6,                 "HUSTR_E4M6" },
//	{ &s_HUSTR_E4M7,                 "HUSTR_E4M7" },
//	{ &s_HUSTR_E4M8,                 "HUSTR_E4M8" },
//	{ &s_HUSTR_E4M9,                 "HUSTR_E4M9" },
//	{ &s_HUSTR_E5M1,                 "HUSTR_E5M1" },
//	{ &s_HUSTR_E5M2,                 "HUSTR_E5M2" },
//	{ &s_HUSTR_E5M3,                 "HUSTR_E5M3" },
//	{ &s_HUSTR_E5M4,                 "HUSTR_E5M4" },
//	{ &s_HUSTR_E5M5,                 "HUSTR_E5M5" },
//	{ &s_HUSTR_E5M6,                 "HUSTR_E5M6" },
//	{ &s_HUSTR_E5M7,                 "HUSTR_E5M7" },
//	{ &s_HUSTR_E5M8,                 "HUSTR_E5M8" },
//	{ &s_HUSTR_E5M9,                 "HUSTR_E5M9" },
//	{ &s_HUSTR_1,                    "HUSTR_1" },
//	{ &s_HUSTR_2,                    "HUSTR_2" },
//	{ &s_HUSTR_3,                    "HUSTR_3" },
//	{ &s_HUSTR_4,                    "HUSTR_4" },
//	{ &s_HUSTR_5,                    "HUSTR_5" },
//	{ &s_HUSTR_6,                    "HUSTR_6" },
//	{ &s_HUSTR_7,                    "HUSTR_7" },
//	{ &s_HUSTR_8,                    "HUSTR_8" },
//	{ &s_HUSTR_9,                    "HUSTR_9" },
//	{ &s_HUSTR_10,                   "HUSTR_10" },
//	{ &s_HUSTR_11,                   "HUSTR_11" },
//	{ &s_HUSTR_11_ALT,               "HUSTR_11_ALT" },
//	{ &s_HUSTR_12,                   "HUSTR_12" },
//	{ &s_HUSTR_13,                   "HUSTR_13" },
//	{ &s_HUSTR_14,                   "HUSTR_14" },
//	{ &s_HUSTR_15,                   "HUSTR_15" },
//	{ &s_HUSTR_16,                   "HUSTR_16" },
//	{ &s_HUSTR_17,                   "HUSTR_17" },
//	{ &s_HUSTR_18,                   "HUSTR_18" },
//	{ &s_HUSTR_19,                   "HUSTR_19" },
//	{ &s_HUSTR_20,                   "HUSTR_20" },
//	{ &s_HUSTR_21,                   "HUSTR_21" },
//	{ &s_HUSTR_22,                   "HUSTR_22" },
//	{ &s_HUSTR_23,                   "HUSTR_23" },
//	{ &s_HUSTR_24,                   "HUSTR_24" },
//	{ &s_HUSTR_25,                   "HUSTR_25" },
//	{ &s_HUSTR_26,                   "HUSTR_26" },
//	{ &s_HUSTR_27,                   "HUSTR_27" },
//	{ &s_HUSTR_28,                   "HUSTR_28" },
//	{ &s_HUSTR_29,                   "HUSTR_29" },
//	{ &s_HUSTR_30,                   "HUSTR_30" },
//	{ &s_HUSTR_31,                   "HUSTR_31" },
//	{ &s_HUSTR_31_BFG,               "HUSTR_31_BFG" },
//	{ &s_HUSTR_32,                   "HUSTR_32" },
//	{ &s_HUSTR_32_BFG,               "HUSTR_32_BFG" },
//	{ &s_HUSTR_33,                   "HUSTR_33" },
//	{ &s_PHUSTR_1,                   "PHUSTR_1" },
//	{ &s_PHUSTR_2,                   "PHUSTR_2" },
//	{ &s_PHUSTR_3,                   "PHUSTR_3" },
//	{ &s_PHUSTR_4,                   "PHUSTR_4" },
//	{ &s_PHUSTR_5,                   "PHUSTR_5" },
//	{ &s_PHUSTR_6,                   "PHUSTR_6" },
//	{ &s_PHUSTR_7,                   "PHUSTR_7" },
//	{ &s_PHUSTR_8,                   "PHUSTR_8" },
//	{ &s_PHUSTR_9,                   "PHUSTR_9" },
//	{ &s_PHUSTR_10,                  "PHUSTR_10" },
//	{ &s_PHUSTR_11,                  "PHUSTR_11" },
//	{ &s_PHUSTR_12,                  "PHUSTR_12" },
//	{ &s_PHUSTR_13,                  "PHUSTR_13" },
//	{ &s_PHUSTR_14,                  "PHUSTR_14" },
//	{ &s_PHUSTR_15,                  "PHUSTR_15" },
//	{ &s_PHUSTR_16,                  "PHUSTR_16" },
//	{ &s_PHUSTR_17,                  "PHUSTR_17" },
//	{ &s_PHUSTR_18,                  "PHUSTR_18" },
//	{ &s_PHUSTR_19,                  "PHUSTR_19" },
//	{ &s_PHUSTR_20,                  "PHUSTR_20" },
//	{ &s_PHUSTR_21,                  "PHUSTR_21" },
//	{ &s_PHUSTR_22,                  "PHUSTR_22" },
//	{ &s_PHUSTR_23,                  "PHUSTR_23" },
//	{ &s_PHUSTR_24,                  "PHUSTR_24" },
//	{ &s_PHUSTR_25,                  "PHUSTR_25" },
//	{ &s_PHUSTR_26,                  "PHUSTR_26" },
//	{ &s_PHUSTR_27,                  "PHUSTR_27" },
//	{ &s_PHUSTR_28,                  "PHUSTR_28" },
//	{ &s_PHUSTR_29,                  "PHUSTR_29" },
//	{ &s_PHUSTR_30,                  "PHUSTR_30" },
//	{ &s_PHUSTR_31,                  "PHUSTR_31" },
//	{ &s_PHUSTR_32,                  "PHUSTR_32" },
//	{ &s_THUSTR_1,                   "THUSTR_1" },
//	{ &s_THUSTR_2,                   "THUSTR_2" },
//	{ &s_THUSTR_3,                   "THUSTR_3" },
//	{ &s_THUSTR_4,                   "THUSTR_4" },
//	{ &s_THUSTR_5,                   "THUSTR_5" },
//	{ &s_THUSTR_6,                   "THUSTR_6" },
//	{ &s_THUSTR_7,                   "THUSTR_7" },
//	{ &s_THUSTR_8,                   "THUSTR_8" },
//	{ &s_THUSTR_9,                   "THUSTR_9" },
//	{ &s_THUSTR_10,                  "THUSTR_10" },
//	{ &s_THUSTR_11,                  "THUSTR_11" },
//	{ &s_THUSTR_12,                  "THUSTR_12" },
//	{ &s_THUSTR_13,                  "THUSTR_13" },
//	{ &s_THUSTR_14,                  "THUSTR_14" },
//	{ &s_THUSTR_15,                  "THUSTR_15" },
//	{ &s_THUSTR_16,                  "THUSTR_16" },
//	{ &s_THUSTR_17,                  "THUSTR_17" },
//	{ &s_THUSTR_18,                  "THUSTR_18" },
//	{ &s_THUSTR_19,                  "THUSTR_19" },
//	{ &s_THUSTR_20,                  "THUSTR_20" },
//	{ &s_THUSTR_21,                  "THUSTR_21" },
//	{ &s_THUSTR_22,                  "THUSTR_22" },
//	{ &s_THUSTR_23,                  "THUSTR_23" },
//	{ &s_THUSTR_24,                  "THUSTR_24" },
//	{ &s_THUSTR_25,                  "THUSTR_25" },
//	{ &s_THUSTR_26,                  "THUSTR_26" },
//	{ &s_THUSTR_27,                  "THUSTR_27" },
//	{ &s_THUSTR_28,                  "THUSTR_28" },
//	{ &s_THUSTR_29,                  "THUSTR_29" },
//	{ &s_THUSTR_30,                  "THUSTR_30" },
//	{ &s_THUSTR_31,                  "THUSTR_31" },
//	{ &s_THUSTR_32,                  "THUSTR_32" },
//	{ &s_NHUSTR_1,                   "NHUSTR_1" },
//	{ &s_NHUSTR_2,                   "NHUSTR_2" },
//	{ &s_NHUSTR_3,                   "NHUSTR_3" },
//	{ &s_NHUSTR_4,                   "NHUSTR_4" },
//	{ &s_NHUSTR_5,                   "NHUSTR_5" },
//	{ &s_NHUSTR_6,                   "NHUSTR_6" },
//	{ &s_NHUSTR_7,                   "NHUSTR_7" },
//	{ &s_NHUSTR_8,                   "NHUSTR_8" },
//	{ &s_NHUSTR_9,                   "NHUSTR_9" },
//
//	{ &s_HUSTR_CHATMACRO1,           "HUSTR_CHATMACRO1" },
//	{ &s_HUSTR_CHATMACRO2,           "HUSTR_CHATMACRO2" },
//	{ &s_HUSTR_CHATMACRO3,           "HUSTR_CHATMACRO3" },
//	{ &s_HUSTR_CHATMACRO4,           "HUSTR_CHATMACRO4" },
//	{ &s_HUSTR_CHATMACRO5,           "HUSTR_CHATMACRO5" },
//	{ &s_HUSTR_CHATMACRO6,           "HUSTR_CHATMACRO6" },
//	{ &s_HUSTR_CHATMACRO7,           "HUSTR_CHATMACRO7" },
//	{ &s_HUSTR_CHATMACRO8,           "HUSTR_CHATMACRO8" },
//	{ &s_HUSTR_CHATMACRO9,           "HUSTR_CHATMACRO9" },
//	{ &s_HUSTR_CHATMACRO0,           "HUSTR_CHATMACRO0" },
//	{ &s_HUSTR_TALKTOSELF1,          "HUSTR_TALKTOSELF1" },
//	{ &s_HUSTR_TALKTOSELF2,          "HUSTR_TALKTOSELF2" },
//	{ &s_HUSTR_TALKTOSELF3,          "HUSTR_TALKTOSELF3" },
//	{ &s_HUSTR_TALKTOSELF4,          "HUSTR_TALKTOSELF4" },
//	{ &s_HUSTR_TALKTOSELF5,          "HUSTR_TALKTOSELF5" },
//	{ &s_HUSTR_MESSAGESENT,          "HUSTR_MESSAGESENT" },
//	{ &s_HUSTR_PLRGREEN,             "HUSTR_PLRGREEN" },
//	{ &s_HUSTR_PLRINDIGO,            "HUSTR_PLRINDIGO" },
//	{ &s_HUSTR_PLRBROWN,             "HUSTR_PLRBROWN" },
//	{ &s_HUSTR_PLRRED,               "HUSTR_PLRRED" },
//
//	{ &s_AMSTR_FOLLOWON,             "AMSTR_FOLLOWON" },
//	{ &s_AMSTR_FOLLOWOFF,            "AMSTR_FOLLOWOFF" },
//	{ &s_AMSTR_GRIDON,               "AMSTR_GRIDON" },
//	{ &s_AMSTR_GRIDOFF,              "AMSTR_GRIDOFF" },
//	{ &s_AMSTR_MARKEDSPOT,           "AMSTR_MARKEDSPOT" },
//	{ &s_AMSTR_MARKCLEARED,          "AMSTR_MARKCLEARED" },
//	{ &s_AMSTR_MARKSCLEARED,         "AMSTR_MARKSCLEARED" },
//	{ &s_AMSTR_ROTATEON,             "AMSTR_ROTATEON" },
//	{ &s_AMSTR_ROTATEOFF,            "AMSTR_ROTATEOFF" },
//
//	{ &s_STSTR_MUS,                  "STSTR_MUS" },
//	{ &s_STSTR_NOMUS,                "STSTR_NOMUS" },
//	{ &s_STSTR_DQDON,                "STSTR_DQDON" },
//	{ &s_STSTR_DQDOFF,               "STSTR_DQDOFF" },
//	{ &s_STSTR_KFAADDED,             "STSTR_KFAADDED" },
//	{ &s_STSTR_FAADDED,              "STSTR_FAADDED" },
//	{ &s_STSTR_NCON,                 "STSTR_NCON" },
//	{ &s_STSTR_NCOFF,                "STSTR_NCOFF" },
//	{ &s_STSTR_BEHOLD,               "STSTR_BEHOLD" },
//	{ &s_STSTR_BEHOLDX,              "STSTR_BEHOLDX" },
//	{ &s_STSTR_BEHOLDON,             "STSTR_BEHOLDON" },
//	{ &s_STSTR_BEHOLDOFF,            "STSTR_BEHOLDOFF" },
//	{ &s_STSTR_BUDDHAON,             "STSTR_BUDDHAON" },
//	{ &s_STSTR_BUDDHAOFF,            "STSTR_BUDDHAOFF" },
//	{ &s_STSTR_CHOPPERS,             "STSTR_CHOPPERS" },
//	{ &s_STSTR_CLEV,                 "STSTR_CLEV" },
//	{ &s_STSTR_CLEVSAME,             "STSTR_CLEVSAME" },
//	{ &s_STSTR_MYPOS,                "STSTR_MYPOS" },
//	{ &s_STSTR_NTON,                 "STSTR_NTON" },
//	{ &s_STSTR_NTOFF,                "STSTR_NTOFF" },
//	{ &s_STSTR_GODON,                "STSTR_GODON" },
//	{ &s_STSTR_GODOFF,               "STSTR_GODOFF" },
//	{ &s_STSTR_NMON,                 "STSTR_NMON" },
//	{ &s_STSTR_NMOFF,                "STSTR_NMOFF" },
//	{ &s_STSTR_PSON,                 "STSTR_PSON" },
//	{ &s_STSTR_PSOFF,                "STSTR_PSOFF" },
//	{ &s_STSTR_FMON,                 "STSTR_FMON" },
//	{ &s_STSTR_FMOFF,                "STSTR_FMOFF" },
//	{ &s_STSTR_RION,                 "STSTR_RION" },
//	{ &s_STSTR_RIOFF,                "STSTR_RIOFF" },
//	{ &s_STSTR_RMON,                 "STSTR_RMON" },
//	{ &s_STSTR_RMOFF,                "STSTR_RMOFF" },
//	{ &s_STSTR_FON,                  "STSTR_FON" },
//	{ &s_STSTR_FOFF,                 "STSTR_FOFF" },
//	{ &s_STSTR_RHON,                 "STSTR_RHON" },
//	{ &s_STSTR_RHOFF,                "STSTR_RHOFF" },
//	{ &s_STSTR_VON,                  "STSTR_VON" },
//	{ &s_STSTR_VOFF,                 "STSTR_VOFF" },
//
//	{ &s_E1TEXT,                     "E1TEXT" },
//	{ &s_E2TEXT,                     "E2TEXT" },
//	{ &s_E3TEXT,                     "E3TEXT" },
//	{ &s_E4TEXT,                     "E4TEXT" },
//	{ &s_E5TEXT,                     "E5TEXT" },
//	{ &s_C1TEXT,                     "C1TEXT" },
//	{ &s_C2TEXT,                     "C2TEXT" },
//	{ &s_C3TEXT,                     "C3TEXT" },
//	{ &s_C4TEXT,                     "C4TEXT" },
//	{ &s_C5TEXT,                     "C5TEXT" },
//	{ &s_C6TEXT,                     "C6TEXT" },
//	{ &s_P1TEXT,                     "P1TEXT" },
//	{ &s_P2TEXT,                     "P2TEXT" },
//	{ &s_P3TEXT,                     "P3TEXT" },
//	{ &s_P4TEXT,                     "P4TEXT" },
//	{ &s_P5TEXT,                     "P5TEXT" },
//	{ &s_P6TEXT,                     "P6TEXT" },
//	{ &s_T1TEXT,                     "T1TEXT" },
//	{ &s_T2TEXT,                     "T2TEXT" },
//	{ &s_T3TEXT,                     "T3TEXT" },
//	{ &s_T4TEXT,                     "T4TEXT" },
//	{ &s_T5TEXT,                     "T5TEXT" },
//	{ &s_T6TEXT,                     "T6TEXT" },
//	{ &s_N1TEXT,                     "N1TEXT" },
//
//	{ &s_CC_ZOMBIE,                  "CC_ZOMBIE" },
//	{ &s_CC_SHOTGUN,                 "CC_SHOTGUN" },
//	{ &s_CC_HEAVY,                   "CC_HEAVY" },
//	{ &s_CC_IMP,                     "CC_IMP" },
//	{ &s_CC_DEMON,                   "CC_DEMON" },
//	{ &s_CC_SPECTRE,                 "CC_SPECTRE" },
//	{ &s_CC_LOST,                    "CC_LOST" },
//	{ &s_CC_CACO,                    "CC_CACO" },
//	{ &s_CC_HELL,                    "CC_HELL" },
//	{ &s_CC_BARON,                   "CC_BARON" },
//	{ &s_CC_ARACH,                   "CC_ARACH" },
//	{ &s_CC_PAIN,                    "CC_PAIN" },
//	{ &s_CC_REVEN,                   "CC_REVEN" },
//	{ &s_CC_MANCU,                   "CC_MANCU" },
//	{ &s_CC_ARCH,                    "CC_ARCH" },
//	{ &s_CC_SPIDER,                  "CC_SPIDER" },
//	{ &s_CC_CYBER,                   "CC_CYBER" },
//	{ &s_CC_HERO,                    "CC_HERO" },
//
//	{ &s_DOOM_ENDMSG1,               "DOOM_ENDMSG1" },
//	{ &s_DOOM_ENDMSG2,               "DOOM_ENDMSG2" },
//	{ &s_DOOM_ENDMSG3,               "DOOM_ENDMSG3" },
//	{ &s_DOOM_ENDMSG4,               "DOOM_ENDMSG4" },
//	{ &s_DOOM_ENDMSG5,               "DOOM_ENDMSG5" },
//	{ &s_DOOM_ENDMSG6,               "DOOM_ENDMSG6" },
//	{ &s_DOOM_ENDMSG7,               "DOOM_ENDMSG7" },
//	{ &s_DOOM2_ENDMSG1,              "DOOM2_ENDMSG1" },
//	{ &s_DOOM2_ENDMSG2,              "DOOM2_ENDMSG2" },
//	{ &s_DOOM2_ENDMSG3,              "DOOM2_ENDMSG3" },
//	{ &s_DOOM2_ENDMSG4,              "DOOM2_ENDMSG4" },
//	{ &s_DOOM2_ENDMSG5,              "DOOM2_ENDMSG5" },
//	{ &s_DOOM2_ENDMSG6,              "DOOM2_ENDMSG6" },
//	{ &s_DOOM2_ENDMSG7,              "DOOM2_ENDMSG7" },
//
//	{ &s_M_NEWGAME,                  "M_NEWGAME" },
//	{ &s_M_OPTIONS,                  "M_OPTIONS" },
//	{ &s_M_LOADGAME,                 "M_LOADGAME" },
//	{ &s_M_SAVEGAME,                 "M_SAVEGAME" },
//	{ &s_M_QUITGAME,                 "M_QUITGAME" },
//	{ &s_M_WHICHEPISODE,             "M_WHICHEPISODE" },
//	{ &s_M_EPISODE1,                 "M_EPISODE1" },
//	{ &s_M_EPISODE2,                 "M_EPISODE2" },
//	{ &s_M_EPISODE3,                 "M_EPISODE3" },
//	{ &s_M_EPISODE4,                 "M_EPISODE4" },
//	{ &s_M_EPISODE5,                 "M_EPISODE5" },
//	{ &s_M_WHICHEXPANSION,           "M_WHICHEXPANSION" },
//	{ &s_M_EXPANSION1,               "M_EXPANSION1" },
//	{ &s_M_EXPANSION2,               "M_EXPANSION2" },
//	{ &s_M_CHOOSESKILLLEVEL,         "M_CHOOSESKILLLEVEL" },
//	{ &s_M_SKILLLEVEL1,              "M_SKILLLEVEL1" },
//	{ &s_M_SKILLLEVEL2,              "M_SKILLLEVEL2" },
//	{ &s_M_SKILLLEVEL3,              "M_SKILLLEVEL3" },
//	{ &s_M_SKILLLEVEL4,              "M_SKILLLEVEL4" },
//	{ &s_M_SKILLLEVEL5,              "M_SKILLLEVEL5" },
//	{ &s_M_ENDGAME,                  "M_ENDGAME" },
//	{ &s_M_MESSAGES,                 "M_MESSAGES" },
//	{ &s_M_ON,                       "M_ON" },
//	{ &s_M_OFF,                      "M_OFF" },
//	{ &s_M_GRAPHICDETAIL,            "M_GRAPHICDETAIL" },
//	{ &s_M_HIGH,                     "M_HIGH" },
//	{ &s_M_LOW,                      "M_LOW" },
//	{ &s_M_SCREENSIZE,               "M_SCREENSIZE" },
//	{ &s_M_MOUSESENSITIVITY,         "M_MOUSESENSITIVITY" },
//	{ &s_M_GAMEPADSENSITIVITY,       "M_GAMEPADSENSITIVITY" },
//	{ &s_M_SOUNDVOLUME,              "M_SOUNDVOLUME" },
//	{ &s_M_SFXVOLUME,                "M_SFXVOLUME" },
//	{ &s_M_MUSICVOLUME,              "M_MUSICVOLUME" },
//	{ &s_M_PAUSED,                   "M_PAUSED" },
//	{ &s_M_MORE,                     "M_MORE" },
//
//	{ &s_CAPTION_SHAREWARE,          "CAPTION_SHAREWARE" },
//	{ &s_CAPTION_REGISTERED,         "CAPTION_REGISTERED" },
//	{ &s_CAPTION_ULTIMATE,           "CAPTION_ULTIMATE" },
//	{ &s_CAPTION_DOOM2,              "CAPTION_DOOM2" },
//	{ &s_CAPTION_HELLONEARTH,        "CAPTION_HELLONEARTH" },
//	{ &s_CAPTION_NERVE,              "CAPTION_NERVE" },
//	{ &s_CAPTION_BFGEDITION,         "CAPTION_BFGEDITION" },
//	{ &s_CAPTION_PLUTONIA,           "CAPTION_PLUTONIA" },
//	{ &s_CAPTION_TNT,                "CAPTION_TNT" },
//	{ &s_CAPTION_CHEX,               "CAPTION_CHEX" },
//	{ &s_CAPTION_CHEX2,              "CAPTION_CHEX2" },
//	{ &s_CAPTION_HACX,               "CAPTION_HACX" },
//	{ &s_CAPTION_FREEDOOM1,          "CAPTION_FREEDOOM1" },
//	{ &s_CAPTION_FREEDOOM2,          "CAPTION_FREEDOOM2" },
//	{ &s_CAPTION_FREEDM,             "CAPTION_FREEDM" },
//	{ &s_CAPTION_BTSXE1,             "CAPTION_BTSXE1" },
//	{ &s_CAPTION_BTSXE2,             "CAPTION_BTSXE2" },
//	{ &s_CAPTION_BTSXE3,             "CAPTION_BTSXE3" },
//	{ &s_CAPTION_E1M4B,              "CAPTION_E1M4B" },
//	{ &s_CAPTION_E1M8B,              "CAPTION_E1M8B" },
//	{ &s_AUTHOR_ROMERO,              "AUTHOR_ROMERO" },
//
//	{ &bgflatE1,                     "BGFLATE1" },
//	{ &bgflatE2,                     "BGFLATE2" },
//	{ &bgflatE3,                     "BGFLATE3" },
//	{ &bgflatE4,                     "BGFLATE4" },
//	{ &bgflatE5,                     "BGFLATE5" },
//	{ &bgflat06,                     "BGFLAT06" },
//	{ &bgflat11,                     "BGFLAT11" },
//	{ &bgflat15,                     "BGFLAT15" },
//	{ &bgflat20,                     "BGFLAT20" },
//	{ &bgflat30,                     "BGFLAT30" },
//	{ &bgflat31,                     "BGFLAT31" },
//	{ &bgcastcall,                   "BGCASTCALL" },
//
//	// Ty 04/08/98 - added 5 general purpose startup announcement
//	// strings for hacker use. See m_menu.c
//	{ &startup1,                     "STARTUP1" },
//	{ &startup2,                     "STARTUP2" },
//	{ &startup3,                     "STARTUP3" },
//	{ &startup4,                     "STARTUP4" },
//	{ &startup5,                     "STARTUP5" },
//
//	{ &savegamename,                 "SAVEGAMENAME" },
//
//	{ &s_BANNER1,                    "BANNER1" },
//	{ &s_BANNER2,                    "BANNER2" },
//	{ &s_BANNER3,                    "BANNER3" },
//	{ &s_BANNER4,                    "BANNER4" },
//	{ &s_BANNER5,                    "BANNER5" },
//	{ &s_BANNER6,                    "BANNER6" },
//	{ &s_BANNER7,                    "BANNER7" },
//
//	{ &s_COPYRIGHT1,                 "COPYRIGHT1" },
//	{ &s_COPYRIGHT2,                 "COPYRIGHT2" },
//	{ &s_COPYRIGHT3,                 "COPYRIGHT3" },
//
//	{ &s_OB_SUICIDE,                 "OB_SUICIDE" },
//	{ &s_OB_FALLING,                 "OB_FALLING" },
//	{ &s_OB_CRUSH,                   "OB_CRUSH" },
//	{ &s_OB_EXIT,                    "OB_EXIT" },
//	{ &s_OB_WATER,                   "OB_WATER" },
//	{ &s_OB_SLIME,                   "OB_SLIME" },
//	{ &s_OB_LAVA,                    "OB_LAVA" },
//	{ &s_OB_BARREL,                  "OB_BARREL" },
//	{ &s_OB_SPLASH,                  "OB_SPLASH" },
//	{ &s_OB_R_SPLASH,                "OB_R_SPLASH" },
//	{ &s_OB_ROCKET,                  "OB_ROCKET" },
//	{ &s_OB_KILLEDSELF,              "OB_KILLEDSELF" },
//	{ &s_OB_STEALTHBABY,             "OB_STEALTHBABY" },
//	{ &s_OB_STEALTHVILE,             "OB_STEALTHVILE" },
//	{ &s_OB_STEALTHBARON,            "OB_STEALTHBARON" },
//	{ &s_OB_STEALTHCACO,             "OB_STEALTHCACO" },
//	{ &s_OB_STEALTHCHAINGUY,         "OB_STEALTHCHAINGUY" },
//	{ &s_OB_STEALTHDEMON,            "OB_STEALTHDEMON" },
//	{ &s_OB_STEALTHKNIGHT,           "OB_STEALTHKNIGHT" },
//	{ &s_OB_STEALTHIMP,              "OB_STEALTHIMP" },
//	{ &s_OB_STEALTHFATSO,            "OB_STEALTHFATSO" },
//	{ &s_OB_STEALTHUNDEAD,           "OB_STEALTHUNDEAD" },
//	{ &s_OB_STEALTHSHOTGUY,          "OB_STEALTHSHOTGUY" },
//	{ &s_OB_STEALTHZOMBIE,           "OB_STEALTHZOMBIE" },
//	{ &s_OB_UNDEADHIT,               "OB_UNDEADHIT" },
//	{ &s_OB_IMPHIT,                  "OB_IMPHIT" },
//	{ &s_OB_CACOHIT,                 "OB_CACOHIT" },
//	{ &s_OB_DEMONHIT,                "OB_DEMONHIT" },
//	{ &s_OB_SPECTREHIT,              "OB_SPECTREHIT" },
//	{ &s_OB_BARONHIT,                "OB_BARONHIT" },
//	{ &s_OB_KNIGHTHIT,               "OB_KNIGHTHIT" },
//	{ &s_OB_ZOMBIE,                  "OB_ZOMBIE" },
//	{ &s_OB_SHOTGUY,                 "OB_SHOTGUY" },
//	{ &s_OB_VILE,                    "OB_VILE" },
//	{ &s_OB_UNDEAD,                  "OB_UNDEAD" },
//	{ &s_OB_FATSO,                   "OB_FATSO" },
//	{ &s_OB_CHAINGUY,                "OB_CHAINGUY" },
//	{ &s_OB_SKULL,                   "OB_SKULL" },
//	{ &s_OB_IMP,                     "OB_IMP" },
//	{ &s_OB_CACO,                    "OB_CACO" },
//	{ &s_OB_BARON,                   "OB_BARON" },
//	{ &s_OB_KNIGHT,                  "OB_KNIGHT" },
//	{ &s_OB_SPIDER,                  "OB_SPIDER" },
//	{ &s_OB_BABY,                    "OB_BABY" },
//	{ &s_OB_CYBORG,                  "OB_CYBORG" },
//	{ &s_OB_WOLFSS,                  "OB_WOLFSS" },
//	{ &s_OB_MPFIST,                  "OB_MPFIST" },
//	{ &s_OB_MPCHAINSAW,              "OB_MPCHAINSAW" },
//	{ &s_OB_MPPISTOL,                "OB_MPPISTOL" },
//	{ &s_OB_MPSHOTGUN,               "OB_MPSHOTGUN" },
//	{ &s_OB_MPSSHOTGUN,              "OB_MPSSHOTGUN" },
//	{ &s_OB_MPCHAINGUN,              "OB_MPCHAINGUN" },
//	{ &s_OB_MPROCKET,                "OB_MPROCKET" },
//	{ &s_OB_MPR_SPLASH,              "OB_MPR_SPLASH" },
//	{ &s_OB_MPPLASMARIFLE,           "OB_MPPLASMARIFLE" },
//	{ &s_OB_MPBFG_BOOM,              "OB_MPBFG_BOOM" },
//	{ &s_OB_MPBFG_SPLASH,            "OB_MPBFG_SPLASH" },
//	{ &s_OB_MPTELEFRAG,              "OB_MPTELEFRAG" },
//	{ &s_OB_RAILGUN,                 "OB_RAILGUN" },
//	{ &s_OB_MPBFG_MBF,               "OB_MPBFG_MBF" },
//	{ &s_OB_MONTELEFRAG,             "OB_MONTELEFRAG" },
//	{ &s_OB_DEFAULT,                 "OB_DEFAULT" },
//	{ &s_OB_FRIENDLY1,               "OB_FRIENDLY1" },
//	{ &s_OB_FRIENDLY2,               "OB_FRIENDLY2" },
//	{ &s_OB_FRIENDLY3,               "OB_FRIENDLY3" },
//	{ &s_OB_FRIENDLY4,               "OB_FRIENDLY4" }
//};

char **mapnames[] =     // DOOM shareware/registered/retail (Ultimate) names.
{
	&s_HUSTR_E1M1,
	&s_HUSTR_E1M2,
	&s_HUSTR_E1M3,
	&s_HUSTR_E1M4,
	&s_HUSTR_E1M5,
	&s_HUSTR_E1M6,
	&s_HUSTR_E1M7,
	&s_HUSTR_E1M8,
	&s_HUSTR_E1M9,
	&s_HUSTR_E2M1,
	&s_HUSTR_E2M2,
	&s_HUSTR_E2M3,
	&s_HUSTR_E2M4,
	&s_HUSTR_E2M5,
	&s_HUSTR_E2M6,
	&s_HUSTR_E2M7,
	&s_HUSTR_E2M8,
	&s_HUSTR_E2M9,
	&s_HUSTR_E3M1,
	&s_HUSTR_E3M2,
	&s_HUSTR_E3M3,
	&s_HUSTR_E3M4,
	&s_HUSTR_E3M5,
	&s_HUSTR_E3M6,
	&s_HUSTR_E3M7,
	&s_HUSTR_E3M8,
	&s_HUSTR_E3M9,
	&s_HUSTR_E4M1,
	&s_HUSTR_E4M2,
	&s_HUSTR_E4M3,
	&s_HUSTR_E4M4,
	&s_HUSTR_E4M5,
	&s_HUSTR_E4M6,
	&s_HUSTR_E4M7,
	&s_HUSTR_E4M8,
	&s_HUSTR_E4M9,
	&s_HUSTR_E5M1,
	&s_HUSTR_E5M2,
	&s_HUSTR_E5M3,
	&s_HUSTR_E5M4,
	&s_HUSTR_E5M5,
	&s_HUSTR_E5M6,
	&s_HUSTR_E5M7,
	&s_HUSTR_E5M8,
	&s_HUSTR_E5M9
};

char **mapnames2[] =    // DOOM 2 map names.
{
	&s_HUSTR_1,
	&s_HUSTR_2,
	&s_HUSTR_3,
	&s_HUSTR_4,
	&s_HUSTR_5,
	&s_HUSTR_6,
	&s_HUSTR_7,
	&s_HUSTR_8,
	&s_HUSTR_9,
	&s_HUSTR_10,
	&s_HUSTR_11,
	&s_HUSTR_12,
	&s_HUSTR_13,
	&s_HUSTR_14,
	&s_HUSTR_15,
	&s_HUSTR_16,
	&s_HUSTR_17,
	&s_HUSTR_18,
	&s_HUSTR_19,
	&s_HUSTR_20,
	&s_HUSTR_21,
	&s_HUSTR_22,
	&s_HUSTR_23,
	&s_HUSTR_24,
	&s_HUSTR_25,
	&s_HUSTR_26,
	&s_HUSTR_27,
	&s_HUSTR_28,
	&s_HUSTR_29,
	&s_HUSTR_30,
	&s_HUSTR_31,
	&s_HUSTR_32
};

char **mapnames2_bfg[] =    // DOOM 2 map names.
{
	&s_HUSTR_1,
	&s_HUSTR_2,
	&s_HUSTR_3,
	&s_HUSTR_4,
	&s_HUSTR_5,
	&s_HUSTR_6,
	&s_HUSTR_7,
	&s_HUSTR_8,
	&s_HUSTR_9,
	&s_HUSTR_10,
	&s_HUSTR_11,
	&s_HUSTR_12,
	&s_HUSTR_13,
	&s_HUSTR_14,
	&s_HUSTR_15,
	&s_HUSTR_16,
	&s_HUSTR_17,
	&s_HUSTR_18,
	&s_HUSTR_19,
	&s_HUSTR_20,
	&s_HUSTR_21,
	&s_HUSTR_22,
	&s_HUSTR_23,
	&s_HUSTR_24,
	&s_HUSTR_25,
	&s_HUSTR_26,
	&s_HUSTR_27,
	&s_HUSTR_28,
	&s_HUSTR_29,
	&s_HUSTR_30,
	&s_HUSTR_31_BFG,
	&s_HUSTR_32_BFG,
	&s_HUSTR_33
};

char **mapnamesp[] =    // Plutonia WAD map names.
{
	&s_PHUSTR_1,
	&s_PHUSTR_2,
	&s_PHUSTR_3,
	&s_PHUSTR_4,
	&s_PHUSTR_5,
	&s_PHUSTR_6,
	&s_PHUSTR_7,
	&s_PHUSTR_8,
	&s_PHUSTR_9,
	&s_PHUSTR_10,
	&s_PHUSTR_11,
	&s_PHUSTR_12,
	&s_PHUSTR_13,
	&s_PHUSTR_14,
	&s_PHUSTR_15,
	&s_PHUSTR_16,
	&s_PHUSTR_17,
	&s_PHUSTR_18,
	&s_PHUSTR_19,
	&s_PHUSTR_20,
	&s_PHUSTR_21,
	&s_PHUSTR_22,
	&s_PHUSTR_23,
	&s_PHUSTR_24,
	&s_PHUSTR_25,
	&s_PHUSTR_26,
	&s_PHUSTR_27,
	&s_PHUSTR_28,
	&s_PHUSTR_29,
	&s_PHUSTR_30,
	&s_PHUSTR_31,
	&s_PHUSTR_32
};

char **mapnamest[] =    // TNT WAD map names.
{
	&s_THUSTR_1,
	&s_THUSTR_2,
	&s_THUSTR_3,
	&s_THUSTR_4,
	&s_THUSTR_5,
	&s_THUSTR_6,
	&s_THUSTR_7,
	&s_THUSTR_8,
	&s_THUSTR_9,
	&s_THUSTR_10,
	&s_THUSTR_11,
	&s_THUSTR_12,
	&s_THUSTR_13,
	&s_THUSTR_14,
	&s_THUSTR_15,
	&s_THUSTR_16,
	&s_THUSTR_17,
	&s_THUSTR_18,
	&s_THUSTR_19,
	&s_THUSTR_20,
	&s_THUSTR_21,
	&s_THUSTR_22,
	&s_THUSTR_23,
	&s_THUSTR_24,
	&s_THUSTR_25,
	&s_THUSTR_26,
	&s_THUSTR_27,
	&s_THUSTR_28,
	&s_THUSTR_29,
	&s_THUSTR_30,
	&s_THUSTR_31,
	&s_THUSTR_32
};

char **mapnamesn[] =    // Nerve WAD map names.
{
	&s_NHUSTR_1,
	&s_NHUSTR_2,
	&s_NHUSTR_3,
	&s_NHUSTR_4,
	&s_NHUSTR_5,
	&s_NHUSTR_6,
	&s_NHUSTR_7,
	&s_NHUSTR_8,
	&s_NHUSTR_9
};

// dstrings.c
char **endmsg[] =
{
	// DOOM1
	&s_QUITMSG,
	&s_DOOM_ENDMSG1,
	&s_DOOM_ENDMSG2,
	&s_DOOM_ENDMSG3,
	&s_DOOM_ENDMSG4,
	&s_DOOM_ENDMSG5,
	&s_DOOM_ENDMSG6,
	&s_DOOM_ENDMSG7,

	// QuitDOOM II messages
	&s_QUITMSG,
	&s_DOOM2_ENDMSG1,
	&s_DOOM2_ENDMSG2,
	&s_DOOM2_ENDMSG3,
	&s_DOOM2_ENDMSG4,
	&s_DOOM2_ENDMSG5,
	&s_DOOM2_ENDMSG6,
	&s_DOOM2_ENDMSG7
};


// states.h
state_t  states[ NUMSTATES ];


// p_pspr.c
dboolean        successfulshot;
dboolean        skippsprinterp;


// w_wad.c
// Location of each lump on disk.
lumpinfo_t  **lumpinfo;
int         numlumps;


// i_colors.c
byte        *tinttab20;
byte        *tinttab25;
byte        *tinttab30;
byte        *tinttab33;
byte        *tinttab40;
byte        *tinttab50;
byte        *tinttab60;
byte        *tinttab66;
byte        *tinttab75;

byte        *alttinttab20;
byte        *alttinttab40;
byte        *alttinttab60;

byte        *tranmap;

byte        *tinttabadditive;
byte        *tinttabred;
byte        *tinttabredwhite1;
byte        *tinttabredwhite2;
byte        *tinttabgreen;
byte        *tinttabblue;

byte        *tinttabred33;
byte        *tinttabredwhite50;
byte        *tinttabgreen33;
byte        *tinttabblue25;

byte        nearestcolors[ 256 ];
byte        nearestblack;
byte        nearestred;
byte        nearestwhite;

byte        *black25;
byte        *black40;
byte        *yellow15;
byte        *white25;


// hu_lib.
const kern_t kern[];


// steveproTODO



// p_saveg.c
FILE *save_stream;


// f_finale.c
dboolean        firstevent;



// r_bsp.c
seg_t       *curline;
line_t      *linedef;
sector_t    *frontsector;
sector_t    *backsector;


// sc_main.c
char            *sc_String;
int             sc_Number;
int             sc_Line;


// r_draw.c
//
// All drawing to the view buffer is accomplished in this file.
// The other refresh files only know about coordinates,
//  not the architecture of the frame buffer.
// Conveniently, the frame buffer is a linear one,
//  and we need only the base address,
//  and the total size == width*height*depth/8.,
//

int         viewwidth;
int         scaledviewwidth;
int         viewheight;
int         viewwindowx;
int         viewwindowy;

//
// R_DrawSpan
// With DOOM style restrictions on view orientation,
//  the floors and ceilings consist of horizontal slices
//  or spans with constant z depth.
// However, rotation around the world z axis is possible,
//  thus this mapping, while simpler and faster than
//  perspective correct texture mapping, has to traverse
//  the texture at an angle in all but a few cases.
// In consequence, flats are not stored by column (like walls),
//  and the inner loop has to step in texture space u and v.
//
int             ds_y;
int             ds_x1;
int             ds_x2;

lighttable_t    *ds_colormap;

fixed_t         ds_xfrac;
fixed_t         ds_yfrac;
fixed_t         ds_xstep;
fixed_t         ds_ystep;

// start of a 64x64 tile image
byte            *ds_source;


int         fuzzpos;
const int       fuzzrange[];// = { -SCREENWIDTH, 0, SCREENWIDTH };
int         fuzztable[ SCREENAREA ];

//
// R_DrawColumn
// Source is the top of the column to scale.
//
lighttable_t    *dc_colormap[ 2 ];
int             dc_x;
int             dc_yl;
int             dc_yh;
fixed_t         dc_iscale;
fixed_t         dc_texturemid;
fixed_t         dc_texheight;
fixed_t         dc_texturefrac;
byte            dc_solidblood;
byte            *dc_blood;
byte            *dc_brightmap;
int             dc_floorclip;
int             dc_ceilingclip;
int             dc_numposts;
byte            dc_black;
byte            *dc_black25;
byte            *dc_black40;

// first pixel in a column (possibly virtual)
byte            *dc_source;

byte    *dc_translation;
byte    translationtables[ 256 * 3 ];


// r_sky.c
//
// sky mapping
//
int         skyflatnum;
int         skytexture;
int         skytexturemid;
int         skycolumnoffset;// = 0;
int         skyscrolldelta;

fixed_t     skyiscale;
dboolean    canmouselook;// = false;


// w_merge.c
dboolean                SHT2A0;


// st_lib.c
dboolean    usesmallnums;