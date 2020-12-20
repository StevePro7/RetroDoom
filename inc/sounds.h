#if !defined(__SOUNDS_H__)
#define __SOUNDS_H__

#include "doomenum.h"
#include "doomtype.h"

// so that the individual game logic and sound driver code agree
#define NORM_PITCH  127

//
// SFX struct.
//
typedef struct sfxinfo_s sfxinfo_t;

//enum
//{
//    sg_none,
//    sg_itemup,
//    sg_wpnup,
//    sg_oof,
//    sg_getpow,
//    sg_stnmov,
//    sg_saw
//};

struct sfxinfo_s
{
    // up to 6-character name
    char            name1[9];
    char            name2[9];

    // SFX singularity (only one at a time)
    int             singularity;

    // SFX priority
    int             priority;

    // SFX lumpnum
    int             lumpnum;
};

//
// music struct
//
typedef struct
{
    // up to 6-character name
    char            name1[9];
    char            name2[9];

    char            title1[32];
    char            title2[32];

    // lump number of music
    int             lumpnum;

    // music data
    void            *data;

    // music handle once registered
    void            *handle;
} musicinfo_t;

// the complete set of sound effects
extern sfxinfo_t    S_sfx[];

// the complete set of music
extern musicinfo_t  S_music[];

extern musicinfo_t  *mus_playing;

extern dboolean     midimusictype;
extern dboolean     musmusictype;

////
//// Identifiers for all music in game.
////
//enum
//{
//    mus_none,
//    mus_e1m1,
//    mus_e1m2,
//    mus_e1m3,
//    mus_e1m4,
//    mus_e1m5,
//    mus_e1m6,
//    mus_e1m7,
//    mus_e1m8,
//    mus_e1m9,
//    mus_e2m1,
//    mus_e2m2,
//    mus_e2m3,
//    mus_e2m4,
//    mus_e2m5,
//    mus_e2m6,
//    mus_e2m7,
//    mus_e2m8,
//    mus_e2m9,
//    mus_e3m1,
//    mus_e3m2,
//    mus_e3m3,
//    mus_e3m4,
//    mus_e3m5,
//    mus_e3m6,
//    mus_e3m7,
//    mus_e3m8,
//    mus_e3m9,
//    mus_e5m1,
//    mus_e5m2,
//    mus_e5m3,
//    mus_e5m4,
//    mus_e5m5,
//    mus_e5m6,
//    mus_e5m7,
//    mus_e5m8,
//    mus_e5m9,
//    mus_inter,
//    mus_intro,
//    mus_bunny,
//    mus_victor,
//    mus_introa,
//    mus_runnin,
//    mus_stalks,
//    mus_countd,
//    mus_betwee,
//    mus_doom,
//    mus_the_da,
//    mus_shawn,
//    mus_ddtblu,
//    mus_in_cit,
//    mus_dead,
//    mus_stlks2,
//    mus_theda2,
//    mus_doom2,
//    mus_ddtbl2,
//    mus_runni2,
//    mus_dead2,
//    mus_stlks3,
//    mus_romero,
//    mus_shawn2,
//    mus_messag,
//    mus_count2,
//    mus_ddtbl3,
//    mus_ampie,
//    mus_theda3,
//    mus_adrian,
//    mus_messg2,
//    mus_romer2,
//    mus_tense,
//    mus_shawn3,
//    mus_openin,
//    mus_evil,
//    mus_ultima,
//    mus_read_m,
//    mus_dm2ttl,
//    mus_dm2int,
//    NUMMUSIC,
//    mus_musinfo
//};
//
////
//// Identifiers for all sfx in game.
////
//enum
//{
//    sfx_none,
//    sfx_pistol,
//    sfx_shotgn,
//    sfx_sgcock,
//    sfx_dshtgn,
//    sfx_dbopn,
//    sfx_dbcls,
//    sfx_dbload,
//    sfx_plasma,
//    sfx_bfg,
//    sfx_sawup,
//    sfx_sawidl,
//    sfx_sawful,
//    sfx_sawhit,
//    sfx_rlaunc,
//    sfx_rxplod,
//    sfx_firsht,
//    sfx_firxpl,
//    sfx_pstart,
//    sfx_pstop,
//    sfx_doropn,
//    sfx_dorcls,
//    sfx_stnmov,
//    sfx_swtchn,
//    sfx_swtchx,
//    sfx_plpain,
//    sfx_dmpain,
//    sfx_popain,
//    sfx_vipain,
//    sfx_mnpain,
//    sfx_pepain,
//    sfx_slop,
//    sfx_itemup,
//    sfx_wpnup,
//    sfx_oof,
//    sfx_telept,
//    sfx_posit1,
//    sfx_posit2,
//    sfx_posit3,
//    sfx_bgsit1,
//    sfx_bgsit2,
//    sfx_sgtsit,
//    sfx_cacsit,
//    sfx_brssit,
//    sfx_cybsit,
//    sfx_spisit,
//    sfx_bspsit,
//    sfx_kntsit,
//    sfx_vilsit,
//    sfx_mansit,
//    sfx_pesit,
//    sfx_sklatk,
//    sfx_sgtatk,
//    sfx_skepch,
//    sfx_vilatk,
//    sfx_claw,
//    sfx_skeswg,
//    sfx_pldeth,
//    sfx_pdiehi,
//    sfx_podth1,
//    sfx_podth2,
//    sfx_podth3,
//    sfx_bgdth1,
//    sfx_bgdth2,
//    sfx_sgtdth,
//    sfx_cacdth,
//    sfx_skldth,
//    sfx_brsdth,
//    sfx_cybdth,
//    sfx_spidth,
//    sfx_bspdth,
//    sfx_vildth,
//    sfx_kntdth,
//    sfx_pedth,
//    sfx_skedth,
//    sfx_posact,
//    sfx_bgact,
//    sfx_dmact,
//    sfx_bspact,
//    sfx_bspwlk,
//    sfx_vilact,
//    sfx_noway,
//    sfx_barexp,
//    sfx_punch,
//    sfx_hoof,
//    sfx_metal,
//    sfx_chgun,
//    sfx_tink,
//    sfx_bdopn,
//    sfx_bdcls,
//    sfx_itmbk,
//    sfx_flame,
//    sfx_flamst,
//    sfx_getpow,
//    sfx_bospit,
//    sfx_boscub,
//    sfx_bossit,
//    sfx_bospn,
//    sfx_bosdth,
//    sfx_manatk,
//    sfx_mandth,
//    sfx_sssit,
//    sfx_ssdth,
//    sfx_keenpn,
//    sfx_keendt,
//    sfx_skeact,
//    sfx_skesit,
//    sfx_skeatk,
//    sfx_radio,
//
//    // killough 11/98: dog sounds
//    sfx_dgsit,
//    sfx_dgatk,
//    sfx_dgact,
//    sfx_dgdth,
//    sfx_dgpain,
//
//    // e6y
//    sfx_secret,
//    sfx_gibdth,
//
//    sfx_scrsht,
//
//    NUMSFX
//};

#endif
