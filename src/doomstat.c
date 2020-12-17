#include "doomstat.h"

dboolean            devparm;                // started game with -devparm
dboolean            fastparm;               // checkparm of -fast
dboolean            freeze;
dboolean            nomonsters;             // checkparm of -nomonsters
dboolean            pistolstart;            // [BH] checkparm of -pistolstart
dboolean            regenhealth;
dboolean            respawnitems;
dboolean            respawnmonsters;        // checkparm of -respawn

// Game Mode - identify IWAD as shareware, retail etc.
//GameMode_t      gamemode = indetermined;
//GameMission_t   gamemission = doom;
char            gamedescription[ 255 ];

dboolean        sigil;
dboolean        autosigil = false;
dboolean        buckethead = false;
dboolean        nerve;
dboolean        bfgedition;
dboolean        unity;

dboolean        chex;
dboolean        chex1;
dboolean        chex2;
dboolean        hacx;
dboolean        BTSX;
dboolean        BTSXE1;
dboolean        BTSXE1A;
dboolean        BTSXE1B;
dboolean        BTSXE2;
dboolean        BTSXE2A;
dboolean        BTSXE2B;
dboolean        BTSXE3;
dboolean        BTSXE3A;
dboolean        BTSXE3B;
dboolean        E1M4B;
dboolean        E1M8B;
dboolean        sprfix18;
dboolean        eviternity;
dboolean        doom4vanilla;
dboolean        remnant;

// Set if homebrew PWAD stuff has been added.
dboolean        modifiedgame;

dboolean        DMENUPIC;
dboolean        DSSECRET;
dboolean        FREEDOOM;
dboolean        FREEDM;
dboolean        M_DOOM;
dboolean        M_EPISOD;
dboolean        M_GDHIGH;
dboolean        M_GDLOW;
dboolean        M_LOADG;
dboolean        M_LSCNTR;
dboolean        M_MSENS;
dboolean        M_MSGOFF;
dboolean        M_MSGON;
dboolean        M_NEWG;
dboolean        M_NGAME;
dboolean        M_NMARE;
dboolean        M_OPTTTL;
dboolean        M_PAUSE;
dboolean        M_SAVEG;
dboolean        M_SKILL;
dboolean        M_SKULL1;
dboolean        M_SVOL;
short           RROCK05;
short           RROCK08;
short           SLIME09;
short           SLIME12;
int             STBAR;
dboolean        STCFN034;
dboolean        STYSNUM0;
dboolean        TITLEPIC;
dboolean        WISCRT2;
