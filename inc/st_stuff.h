#if !defined(__ST_STUFF_H__)
#define __ST_STUFF_H__

// Palette indices.
// For damage/bonus red-/gold-shifts
#define STARTREDPALS            1
#define STARTBONUSPALS          9
#define NUMREDPALS              8
#define NUMBONUSPALS            4

// Size of status bar.
// Now sensitive for scaling.
#define ST_WIDTH                SCREENWIDTH

// Number of status faces.
#define ST_NUMPAINFACES         5
#define ST_NUMSTRAIGHTFACES     3
#define ST_NUMTURNFACES         2
#define ST_NUMSPECIALFACES      3

#define ST_FACESTRIDE           (ST_NUMSTRAIGHTFACES + ST_NUMTURNFACES + ST_NUMSPECIALFACES)

#define ST_NUMEXTRAFACES        2

#define ST_NUMFACES             (ST_FACESTRIDE * ST_NUMPAINFACES + ST_NUMEXTRAFACES)

#define ST_STRAIGHTFACECOUNT    (TICRATE / 2)

#define MAPCHANGETICS           TICRATE

//
// STATUS BAR
//

// Called by main loop.
dboolean ST_Responder(event_t *ev);

// Called by main loop.
void ST_Ticker(void);

// Called by main loop.
void ST_Drawer(dboolean fullscreen, dboolean refresh);

// Called when the console player is spawned on each level.
void ST_Start(void);

// Called by startup code.
void ST_Init(void);

extern dboolean idclev;
extern int      idclevtics;
extern dboolean idmus;
extern int      st_palette;
extern dboolean oldweaponsowned[NUMWEAPONS];

extern patch_t  *grnrock;
extern patch_t  *brdr_t;
extern patch_t  *brdr_b;
extern patch_t  *brdr_l;
extern patch_t  *brdr_r;
extern patch_t  *brdr_tl;
extern patch_t  *brdr_tr;
extern patch_t  *brdr_bl;
extern patch_t  *brdr_br;

#endif
