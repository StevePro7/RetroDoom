#if !defined(__DOOMVARS_H__)
#define __DOOMVARS_H__

#include "doomdef.h"
#include "doomenum.h"
#include "doomtype.h"
#include "doomstruct.h"
#include "d_event.h"
#include "d_ticcmd.h"
#include "r_defs.h"

#if defined(_WIN32)
#include <Windows.h>
#endif

// d_main.h
extern char     **episodes[];
extern char     **expansions[];
extern char     **skilllevels[];
extern char     *packageconfig;
extern char     *pwadfile;
extern dboolean advancetitle;
extern dboolean splashscreen;
extern dboolean dowipe;
extern int      titlesequence;
extern int      fadecount;

// d_main.c
#if defined(_WIN32)
extern HANDLE       CapFPSEvent;
#endif

extern dboolean     message_on;
extern gameaction_t loadaction;




// i_system.c
#if defined(_WIN32)
extern char *previouswad;
#endif




extern dboolean advancetitle;








// w_wad.c
extern char *packagewad;








// c_cmds.h
extern action_t         actions[];
extern const control_t  controls[];
extern consolecmd_t     consolecmds[];
extern alias_t          aliases[ MAXALIASES ];
extern dboolean         executingalias;
extern dboolean         resettingcvar;
extern dboolean         vanilla;
extern dboolean         togglingvanilla;
extern dboolean         massacre;


// ------------------------
// Command line parameters.
//
extern dboolean         nomonsters;             // checkparm of -nomonsters
extern dboolean         regenhealth;
extern dboolean         respawnitems;
extern dboolean         respawnmonsters;        // checkparm of -respawn
extern dboolean         pistolstart;            // [BH] checkparm of -pistolstart
extern dboolean         fastparm;               // checkparm of -fast
extern dboolean         devparm;                // DEBUG: launched with -devparm


// i_video.h
extern dboolean     returntowidescreen;
//extern dboolean     vid_widescreen;




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


// d_deh.h
extern dboolean dehacked;
extern deh_strs deh_strlookup[];

extern char     *s_VERSION;

extern char     *s_D_DEVSTR;

extern char     *s_PRESSKEY;
extern char     *s_PRESSYN;
extern char     *s_PRESSA;
extern char     *s_QUITMSG;
extern char     *s_QLPROMPT;
extern char     *s_DELPROMPT;
extern char     *s_NIGHTMARE;
extern char     *s_SWSTRING;
extern char     *s_MSGOFF;
extern char     *s_MSGON;
extern char     *s_ENDGAME;
extern char     *s_DOSY;
extern char     *s_DOSA;
extern char     *s_DETAILHI;
extern char     *s_DETAILLO;
extern char     *s_GAMMALVL;
extern char     *s_GAMMAOFF;
extern char     *s_EMPTYSTRING;

extern char     *s_GOTARMOR;
extern char     *s_GOTMEGA;
extern char     *s_GOTHTHBONUS;
extern char     *s_GOTARMBONUS;
extern char     *s_GOTSTIM;
extern char     *s_GOTMEDINEED;
extern char     *s_GOTMEDIKIT;
extern char     *s_GOTSUPER;

extern char     *s_GOTBLUECARD;
extern char     *s_GOTYELWCARD;
extern char     *s_GOTREDCARD;
extern char     *s_GOTBLUESKUL;
extern char     *s_GOTYELWSKUL;
extern char     *s_GOTREDSKUL;
extern char     *s_GOTREDSKULL;

extern char     *s_GOTINVUL;
extern char     *s_GOTBERSERK;
extern char     *s_GOTINVIS;
extern char     *s_GOTSUIT;
extern char     *s_GOTMAP;
extern char     *s_GOTVISOR;

extern char     *s_GOTCLIP;
extern char     *s_GOTCLIPBOX;
extern char     *s_GOTROCKET;
extern char     *s_GOTROCKETX2;
extern char     *s_GOTROCKBOX;
extern char     *s_GOTCELL;
extern char     *s_GOTCELLX2;
extern char     *s_GOTCELLBOX;
extern char     *s_GOTSHELLS;
extern char     *s_GOTSHELLSX2;
extern char     *s_GOTSHELLBOX;
extern char     *s_GOTBACKPACK;

extern char     *s_GOTBFG9000;
extern char     *s_GOTCHAINGUN;
extern char     *s_GOTCHAINSAW;
extern char     *s_GOTLAUNCHER;
extern char     *s_GOTMSPHERE;
extern char     *s_GOTPLASMA;
extern char     *s_GOTSHOTGUN;
extern char     *s_GOTSHOTGUN2;

extern char     *s_PD_BLUEO;
extern char     *s_PD_REDO;
extern char     *s_PD_YELLOWO;
extern char     *s_PD_BLUEK;
extern char     *s_PD_REDK;
extern char     *s_PD_YELLOWK;
extern char     *s_PD_BLUEC;
extern char     *s_PD_REDC;
extern char     *s_PD_YELLOWC;
extern char     *s_PD_BLUES;
extern char     *s_PD_REDS;
extern char     *s_PD_YELLOWS;
extern char     *s_PD_ANY;
extern char     *s_PD_ALL3;
extern char     *s_PD_ALL6;
extern char     *s_KEYCARD;
extern char     *s_SKULLKEY;

extern char     *s_SECRET;

extern char     *s_GGSAVED;
extern char     *s_GGAUTOSAVED;
extern char     *s_GGLOADED;
extern char     *s_GGAUTOLOADED;
extern char     *s_GGDELETED;
extern char     *s_GSCREENSHOT;

extern char     *s_ALWAYSRUNOFF;
extern char     *s_ALWAYSRUNON;

extern char     *s_HUSTR_E1M1;
extern char     *s_HUSTR_E1M2;
extern char     *s_HUSTR_E1M3;
extern char     *s_HUSTR_E1M4;
extern char     *s_HUSTR_E1M5;
extern char     *s_HUSTR_E1M6;
extern char     *s_HUSTR_E1M7;
extern char     *s_HUSTR_E1M8;
extern char     *s_HUSTR_E1M9;
extern char     *s_HUSTR_E2M1;
extern char     *s_HUSTR_E2M2;
extern char     *s_HUSTR_E2M3;
extern char     *s_HUSTR_E2M4;
extern char     *s_HUSTR_E2M5;
extern char     *s_HUSTR_E2M6;
extern char     *s_HUSTR_E2M7;
extern char     *s_HUSTR_E2M8;
extern char     *s_HUSTR_E2M9;
extern char     *s_HUSTR_E3M1;
extern char     *s_HUSTR_E3M2;
extern char     *s_HUSTR_E3M3;
extern char     *s_HUSTR_E3M4;
extern char     *s_HUSTR_E3M5;
extern char     *s_HUSTR_E3M6;
extern char     *s_HUSTR_E3M7;
extern char     *s_HUSTR_E3M7_ALT;
extern char     *s_HUSTR_E3M8;
extern char     *s_HUSTR_E3M9;
extern char     *s_HUSTR_E4M1;
extern char     *s_HUSTR_E4M2;
extern char     *s_HUSTR_E4M3;
extern char     *s_HUSTR_E4M4;
extern char     *s_HUSTR_E4M5;
extern char     *s_HUSTR_E4M6;
extern char     *s_HUSTR_E4M7;
extern char     *s_HUSTR_E4M8;
extern char     *s_HUSTR_E4M9;
extern char     *s_HUSTR_1;
extern char     *s_HUSTR_2;
extern char     *s_HUSTR_3;
extern char     *s_HUSTR_4;
extern char     *s_HUSTR_5;
extern char     *s_HUSTR_6;
extern char     *s_HUSTR_7;
extern char     *s_HUSTR_8;
extern char     *s_HUSTR_9;
extern char     *s_HUSTR_10;
extern char     *s_HUSTR_11;
extern char     *s_HUSTR_11_ALT;
extern char     *s_HUSTR_12;
extern char     *s_HUSTR_13;
extern char     *s_HUSTR_14;
extern char     *s_HUSTR_15;
extern char     *s_HUSTR_16;
extern char     *s_HUSTR_17;
extern char     *s_HUSTR_18;
extern char     *s_HUSTR_19;
extern char     *s_HUSTR_20;
extern char     *s_HUSTR_21;
extern char     *s_HUSTR_22;
extern char     *s_HUSTR_23;
extern char     *s_HUSTR_24;
extern char     *s_HUSTR_25;
extern char     *s_HUSTR_26;
extern char     *s_HUSTR_27;
extern char     *s_HUSTR_28;
extern char     *s_HUSTR_29;
extern char     *s_HUSTR_30;
extern char     *s_HUSTR_31;
extern char     *s_HUSTR_31_BFG;
extern char     *s_HUSTR_32;
extern char     *s_HUSTR_32_BFG;
extern char     *s_HUSTR_33;
extern char     *s_PHUSTR_1;
extern char     *s_PHUSTR_2;
extern char     *s_PHUSTR_3;
extern char     *s_PHUSTR_4;
extern char     *s_PHUSTR_5;
extern char     *s_PHUSTR_6;
extern char     *s_PHUSTR_7;
extern char     *s_PHUSTR_8;
extern char     *s_PHUSTR_9;
extern char     *s_PHUSTR_10;
extern char     *s_PHUSTR_11;
extern char     *s_PHUSTR_12;
extern char     *s_PHUSTR_13;
extern char     *s_PHUSTR_14;
extern char     *s_PHUSTR_15;
extern char     *s_PHUSTR_16;
extern char     *s_PHUSTR_17;
extern char     *s_PHUSTR_18;
extern char     *s_PHUSTR_19;
extern char     *s_PHUSTR_20;
extern char     *s_PHUSTR_21;
extern char     *s_PHUSTR_22;
extern char     *s_PHUSTR_23;
extern char     *s_PHUSTR_24;
extern char     *s_PHUSTR_25;
extern char     *s_PHUSTR_26;
extern char     *s_PHUSTR_27;
extern char     *s_PHUSTR_28;
extern char     *s_PHUSTR_29;
extern char     *s_PHUSTR_30;
extern char     *s_PHUSTR_31;
extern char     *s_PHUSTR_32;
extern char     *s_THUSTR_1;
extern char     *s_THUSTR_2;
extern char     *s_THUSTR_3;
extern char     *s_THUSTR_4;
extern char     *s_THUSTR_5;
extern char     *s_THUSTR_6;
extern char     *s_THUSTR_7;
extern char     *s_THUSTR_8;
extern char     *s_THUSTR_9;
extern char     *s_THUSTR_10;
extern char     *s_THUSTR_11;
extern char     *s_THUSTR_12;
extern char     *s_THUSTR_13;
extern char     *s_THUSTR_14;
extern char     *s_THUSTR_15;
extern char     *s_THUSTR_16;
extern char     *s_THUSTR_17;
extern char     *s_THUSTR_18;
extern char     *s_THUSTR_19;
extern char     *s_THUSTR_20;
extern char     *s_THUSTR_21;
extern char     *s_THUSTR_22;
extern char     *s_THUSTR_23;
extern char     *s_THUSTR_24;
extern char     *s_THUSTR_25;
extern char     *s_THUSTR_26;
extern char     *s_THUSTR_27;
extern char     *s_THUSTR_28;
extern char     *s_THUSTR_29;
extern char     *s_THUSTR_30;
extern char     *s_THUSTR_31;
extern char     *s_THUSTR_32;
extern char     *s_NHUSTR_1;
extern char     *s_NHUSTR_2;
extern char     *s_NHUSTR_3;
extern char     *s_NHUSTR_4;
extern char     *s_NHUSTR_5;
extern char     *s_NHUSTR_6;
extern char     *s_NHUSTR_7;
extern char     *s_NHUSTR_8;
extern char     *s_NHUSTR_9;

extern char     *s_AMSTR_FOLLOWON;
extern char     *s_AMSTR_FOLLOWOFF;
extern char     *s_AMSTR_GRIDON;
extern char     *s_AMSTR_GRIDOFF;
extern char     *s_AMSTR_MARKEDSPOT;
extern char     *s_AMSTR_MARKCLEARED;
extern char     *s_AMSTR_MARKSCLEARED;
extern char     *s_AMSTR_ROTATEON;
extern char     *s_AMSTR_ROTATEOFF;

extern char     *s_STSTR_MUS;
extern char     *s_STSTR_DQDON;
extern char     *s_STSTR_DQDOFF;
extern char     *s_STSTR_KFAADDED;
extern char     *s_STSTR_FAADDED;
extern char     *s_STSTR_NCON;
extern char     *s_STSTR_NCOFF;
extern char     *s_STSTR_BEHOLD;
extern char     *s_STSTR_BEHOLDX;
extern char     *s_STSTR_BEHOLDON;
extern char     *s_STSTR_BEHOLDOFF;
extern char     *s_STSTR_BUDDHAON;
extern char     *s_STSTR_BUDDHAOFF;
extern char     *s_STSTR_CHOPPERS;
extern char     *s_STSTR_CLEV;
extern char     *s_STSTR_CLEVSAME;
extern char     *s_STSTR_MYPOS;
extern char     *s_STSTR_NTON;
extern char     *s_STSTR_NTOFF;
extern char     *s_STSTR_GODON;
extern char     *s_STSTR_GODOFF;
extern char     *s_STSTR_NMON;
extern char     *s_STSTR_NMOFF;
extern char     *s_STSTR_PSON;
extern char     *s_STSTR_PSOFF;
extern char     *s_STSTR_FMON;
extern char     *s_STSTR_FMOFF;
extern char     *s_STSTR_RION;
extern char     *s_STSTR_RIOFF;
extern char     *s_STSTR_RMON;
extern char     *s_STSTR_RMOFF;
extern char     *s_STSTR_FON;
extern char     *s_STSTR_FOFF;
extern char     *s_STSTR_RHON;
extern char     *s_STSTR_RHOFF;
extern char     *s_STSTR_VON;
extern char     *s_STSTR_VOFF;

extern char     *s_E1TEXT;
extern char     *s_E2TEXT;
extern char     *s_E3TEXT;
extern char     *s_E4TEXT;
extern char     *s_E5TEXT;
extern char     *s_C1TEXT;
extern char     *s_C2TEXT;
extern char     *s_C3TEXT;
extern char     *s_C4TEXT;
extern char     *s_C5TEXT;
extern char     *s_C6TEXT;
extern char     *s_P1TEXT;
extern char     *s_P2TEXT;
extern char     *s_P3TEXT;
extern char     *s_P4TEXT;
extern char     *s_P5TEXT;
extern char     *s_P6TEXT;
extern char     *s_T1TEXT;
extern char     *s_T2TEXT;
extern char     *s_T3TEXT;
extern char     *s_T4TEXT;
extern char     *s_T5TEXT;
extern char     *s_T6TEXT;
extern char     *s_N1TEXT;

extern char     *s_CC_ZOMBIE;
extern char     *s_CC_SHOTGUN;
extern char     *s_CC_HEAVY;
extern char     *s_CC_IMP;
extern char     *s_CC_DEMON;
extern char     *s_CC_SPECTRE;
extern char     *s_CC_LOST;
extern char     *s_CC_CACO;
extern char     *s_CC_HELL;
extern char     *s_CC_BARON;
extern char     *s_CC_ARACH;
extern char     *s_CC_PAIN;
extern char     *s_CC_REVEN;
extern char     *s_CC_MANCU;
extern char     *s_CC_ARCH;
extern char     *s_CC_SPIDER;
extern char     *s_CC_CYBER;
extern char     *s_CC_HERO;

extern char     *s_DOOM_ENDMSG1;
extern char     *s_DOOM_ENDMSG2;
extern char     *s_DOOM_ENDMSG3;
extern char     *s_DOOM_ENDMSG4;
extern char     *s_DOOM_ENDMSG5;
extern char     *s_DOOM_ENDMSG6;
extern char     *s_DOOM_ENDMSG7;
extern char     *s_DOOM2_ENDMSG1;
extern char     *s_DOOM2_ENDMSG2;
extern char     *s_DOOM2_ENDMSG3;
extern char     *s_DOOM2_ENDMSG4;
extern char     *s_DOOM2_ENDMSG5;
extern char     *s_DOOM2_ENDMSG6;
extern char     *s_DOOM2_ENDMSG7;

extern char     *s_M_NEWGAME;
extern char     *s_M_OPTIONS;
extern char     *s_M_LOADGAME;
extern char     *s_M_SAVEGAME;
extern char     *s_M_QUITGAME;
extern char     *s_M_WHICHEPISODE;
extern char     *s_M_EPISODE1;
extern char     *s_M_EPISODE2;
extern char     *s_M_EPISODE3;
extern char     *s_M_EPISODE4;
extern char     *s_M_EPISODE5;
extern char     *s_M_EPISODE6;
extern char     *s_M_EPISODE7;
extern char     *s_M_EPISODE8;
extern char     *s_M_WHICHEXPANSION;
extern char     *s_M_EXPANSION1;
extern char     *s_M_EXPANSION2;
extern char     *s_M_CHOOSESKILLLEVEL;
extern char     *s_M_SKILLLEVEL1;
extern char     *s_M_SKILLLEVEL2;
extern char     *s_M_SKILLLEVEL3;
extern char     *s_M_SKILLLEVEL4;
extern char     *s_M_SKILLLEVEL5;
extern char     *s_M_ENDGAME;
extern char     *s_M_MESSAGES;
extern char     *s_M_ON;
extern char     *s_M_OFF;
extern char     *s_M_GRAPHICDETAIL;
extern char     *s_M_HIGH;
extern char     *s_M_LOW;
extern char     *s_M_SCREENSIZE;
extern char     *s_M_MOUSESENSITIVITY;
extern char     *s_M_GAMEPADSENSITIVITY;
extern char     *s_M_SOUNDVOLUME;
extern char     *s_M_SFXVOLUME;
extern char     *s_M_MUSICVOLUME;
extern char     *s_M_PAUSED;
extern char     *s_M_MORE;

extern char     *s_CAPTION_SHAREWARE;
extern char     *s_CAPTION_REGISTERED;
extern char     *s_CAPTION_ULTIMATE;
extern char     *s_CAPTION_DOOM2;
extern char     *s_CAPTION_HELLONEARTH;
extern char     *s_CAPTION_NERVE;
extern char     *s_CAPTION_BFGEDITION;
extern char     *s_CAPTION_PLUTONIA;
extern char     *s_CAPTION_TNT;
extern char     *s_CAPTION_CHEX;
extern char     *s_CAPTION_CHEX2;
extern char     *s_CAPTION_HACX;
extern char     *s_CAPTION_FREEDOOM1;
extern char     *s_CAPTION_FREEDOOM2;
extern char     *s_CAPTION_FREEDM;
extern char     *s_CAPTION_BTSXE1;
extern char     *s_CAPTION_BTSXE2;
extern char     *s_CAPTION_BTSXE3;
extern char     *s_CAPTION_E1M4B;
extern char     *s_CAPTION_E1M8B;

extern char     *s_AUTHOR_ROMERO;

extern char     *bgflatE1;
extern char     *bgflatE2;
extern char     *bgflatE3;
extern char     *bgflatE4;
extern char     *bgflatE5;
extern char     *bgflat06;
extern char     *bgflat11;
extern char     *bgflat20;
extern char     *bgflat30;
extern char     *bgflat15;
extern char     *bgflat31;
extern char     *bgcastcall;

extern char     *startup1;
extern char     *startup2;
extern char     *startup3;
extern char     *startup4;
extern char     *startup5;

extern char     **mapnames[];
extern char     **mapnames2[];
extern char     **mapnames2_bfg[];
extern char     **mapnamesp[];
extern char     **mapnamest[];
extern char     **mapnamesn[];

extern int      dehcount;


// doomstat.h
// ------------------------
// Command line parameters.
//
extern dboolean         nomonsters;             // checkparm of -nomonsters
extern dboolean         regenhealth;
extern dboolean         respawnitems;
extern dboolean         respawnmonsters;        // checkparm of -respawn
extern dboolean         pistolstart;            // [BH] checkparm of -pistolstart
extern dboolean         fastparm;               // checkparm of -fast

extern dboolean         devparm;                // DEBUG: launched with -devparm

// -----------------------------------------------------
// Game Mode - identify IWAD as shareware, retail etc.
//
extern GameMode_t       gamemode;
extern GameMission_t    gamemission;
extern char             gamedescription[ 255 ];

// Set if homebrew PWAD stuff has been added.
extern dboolean         modifiedgame;

// -------------------------------------------
// Selected skill type, map etc.
//

// Defaults for menu, methinks.
extern skill_t          startskill;
extern int              startepisode;

extern dboolean         autostart;

// Selected by user.
extern skill_t          gameskill;
extern int              pendinggameskill;
extern int              gameepisode;
extern int              gamemap;
extern char             speciallumpname[ 6 ];

extern dboolean         freeze;

extern dboolean         sigil;
extern dboolean         autosigil;
extern dboolean         buckethead;
extern dboolean         nerve;
extern dboolean         bfgedition;
extern dboolean         unity;

extern dboolean         chex;
extern dboolean         chex1;
extern dboolean         chex2;
extern dboolean         hacx;
extern dboolean         BTSX;
extern dboolean         BTSXE1;
extern dboolean         BTSXE1A;
extern dboolean         BTSXE1B;
extern dboolean         BTSXE2;
extern dboolean         BTSXE2A;
extern dboolean         BTSXE2B;
extern dboolean         BTSXE3;
extern dboolean         BTSXE3A;
extern dboolean         BTSXE3B;
extern dboolean         E1M4B;
extern dboolean         E1M8B;
extern dboolean         sprfix18;
extern dboolean         eviternity;
extern dboolean         doom4vanilla;
extern dboolean         remnant;

extern dboolean         DMENUPIC;
extern dboolean         DSSECRET;
extern dboolean         FREEDOOM;
extern dboolean         FREEDM;
extern dboolean         M_DOOM;
extern dboolean         M_EPISOD;
extern dboolean         M_GDHIGH;
extern dboolean         M_GDLOW;
extern dboolean         M_LOADG;
extern dboolean         M_LSCNTR;
extern dboolean         M_MSENS;
extern dboolean         M_MSGOFF;
extern dboolean         M_MSGON;
extern dboolean         M_NEWG;
extern dboolean         M_NGAME;
extern dboolean         M_NMARE;
extern dboolean         M_OPTTTL;
extern dboolean         M_PAUSE;
extern dboolean         M_SAVEG;
extern dboolean         M_SKILL;
extern dboolean         M_SKULL1;
extern dboolean         M_SVOL;
extern short            RROCK05;
extern short            RROCK08;
extern short            SLIME09;
extern short            SLIME12;
extern int              STBAR;
extern dboolean         STCFN034;
extern dboolean         STYSNUM0;
extern dboolean         TITLEPIC;
extern dboolean         WISCRT2;

// From m_menu.c:
//  Sound FX volume has default, 0 - 31
//  Music volume has default, 0 - 31
// These are multiplied by 4.
extern int              sfxVolume;
extern int              musicVolume;

// -------------------------
// Status flags for refresh.
//

extern dboolean         automapactive;  // In automap mode?
extern dboolean         menuactive;     // Menu overlaid?
extern dboolean         paused;         // Game Pause?

extern dboolean         viewactive;

// -------------------------------------
// Scores, rating.
// Statistics on a given map, for intermission.
//
extern int              totalkills;
extern int              totalitems;
extern int              totalsecret;
extern int              totalpickups;
extern int              monstercount[ NUMMOBJTYPES ];
extern int              barrelcount;

// Timer, for scores.
extern int              leveltime;      // tics in game play for par

										//?
extern gamestate_t      gamestate;

//-----------------------------
// Internal parameters, fixed.
// These are set by the engine, and not changed
//  according to user inputs. Partly load from
//  WAD, partly set at startup time.

extern int              gametime;
extern struct tm        gamestarttime;

extern dboolean         realframe;

// Intermission stats.
// Parameters for world map/intermission.
extern wbstartstruct_t  wminfo;

//-----------------------------------------
// Internal parameters, used for engine.
//

// File handling stuff.
extern char             *savegamefolder;

// wipegamestate can be set to -1
//  to force a wipe on the next draw
extern gamestate_t      wipegamestate;

// Needed to store the number of the dummy sky flat.
// Used for rendering,
//  as well as tracking projectiles etc.
extern int              skyflatnum;

extern ticcmd_t         localcmds[ BACKUPTICS ];


// states.h
extern state_t  states[ NUMSTATES ];


// p_pspr.h
extern dboolean skippsprinterp;


// w_wad.h
extern lumpinfo_t   **lumpinfo;
extern int          numlumps;


// hu_lib.c
extern patch_t  *consolefont[ CONSOLEFONTSIZE ];


// c_console.h
extern patch_t          *bindlist;
extern patch_t          *cmdlist;
extern patch_t          *cvarlist;
extern patch_t          *maplist;
extern patch_t          *mapstats;
extern patch_t          *playerstats;
extern patch_t          *thinglist;

extern console_t        *console;

extern dboolean         consoleactive;
extern int              consoleheight;
extern int              consoledirection;

extern int              consolestrings;
extern size_t           consolestringsmax;

extern char             consolecheat[ 255 ];
extern char             consolecheatparm[ 3 ];
extern char             consolecmdparm[ 255 ];

extern dboolean         forceconsoleblurredraw;
extern dboolean         scrollbardrawn;

extern const kern_t     kern[];
extern const kern_t     altkern[];

extern autocomplete_t   autocompletelist[];

// c_console.c
extern int              framespersecond;
extern int              refreshrate;
extern dboolean         quitcmd;


// i_color.h
extern byte *tinttab20;
extern byte *tinttab25;
extern byte *tinttab30;
extern byte *tinttab33;
extern byte *tinttab40;
extern byte *tinttab50;
extern byte *tinttab60;
extern byte *tinttab66;
extern byte *tinttab75;

extern byte *alttinttab20;
extern byte *alttinttab40;
extern byte *alttinttab60;

extern byte *tranmap;
extern byte *tinttabadditive;
extern byte *tinttabred;
extern byte *tinttabredwhite1;
extern byte *tinttabredwhite2;
extern byte *tinttabgreen;
extern byte *tinttabblue;
extern byte *tinttabred33;
extern byte *tinttabredwhite50;
extern byte *tinttabgreen33;
extern byte *tinttabblue25;

extern byte nearestcolors[ 256 ];
extern byte nearestblack;
extern byte nearestred;
extern byte nearestwhite;

extern byte *black25;
extern byte *black40;
extern byte *yellow15;
extern byte *white25;


// st_stuff.h
extern dboolean idclev;
extern int      idclevtics;
extern dboolean idmus;
extern int      st_palette;
extern dboolean oldweaponsowned[ NUMWEAPONS ];

extern patch_t  *grnrock;
extern patch_t  *brdr_t;
extern patch_t  *brdr_b;
extern patch_t  *brdr_l;
extern patch_t  *brdr_r;
extern patch_t  *brdr_tl;
extern patch_t  *brdr_tr;
extern patch_t  *brdr_bl;
extern patch_t  *brdr_br;


// c_cmds.c
//
// vid_showfps CVAR
//
extern uint64_t starttime;
extern int      frames;


#endif
