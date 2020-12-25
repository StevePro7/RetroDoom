#if !defined(__R_MAIN_H__)
#define __R_MAIN_H__

#include "doomstruct.h"

//#include "r_data.h"
//
////
//// POV related.
////
//extern fixed_t  viewcos;
//extern fixed_t  viewsin;
//
//extern int      viewwindowx;
//extern int      viewwindowy;
//
//extern int      centerx;
//extern int      centery;
//
//extern fixed_t  centerxfrac;
//extern fixed_t  centeryfrac;
//extern fixed_t  projection;
//
//extern int      validcount;
//
////
//// Lighting LUT.
//// Used for z-depth cuing per column/row,
////  and other lighting effects (sector ambient, flash).
////
//
//// Lighting constants.
//#define LIGHTLEVELS         128
//#define LIGHTSEGSHIFT       1
//#define LIGHTBRIGHT         2
//#define MAXLIGHTSCALE       384
//#define LIGHTSCALESHIFT     12
//#define MAXLIGHTZ           1024
//#define LIGHTZSHIFT         17
//
//#define OLDLIGHTLEVELS      32
//#define OLDLIGHTSEGSHIFT    3
//#define OLDMAXLIGHTSCALE    48
//
//// Number of diminishing brightness levels.
//// There a 0-31, i.e. 32 LUT in the COLORMAP lump.
//#define NUMCOLORMAPS        32
//
//// killough 03/20/98: Allow colormaps to be dynamic (e.g. underwater)
//extern lighttable_t *(*scalelight)[MAXLIGHTSCALE];
//extern lighttable_t *(*zlight)[MAXLIGHTZ];
//extern lighttable_t *(*psprscalelight)[OLDMAXLIGHTSCALE];
//extern lighttable_t *fullcolormap;
//extern int          numcolormaps;   // killough 04/04/98: dynamic number of maps
//extern lighttable_t **colormaps;
//extern int          extralight;
//extern lighttable_t *fixedcolormap;
//extern dboolean     setsizeneeded;
//
//// [AM] Fractional part of the current tic, in the half-open
////      range of [0.0, 1.0). Used for interpolation.
//extern fixed_t      fractionaltic;
//
////
//// Function pointers to switch refresh/drawing functions.
//// Used to select shadow mode etc.
////
//extern void (*colfunc)(void);
//extern void (*wallcolfunc)(void);
//extern void (*bmapwallcolfunc)(void);
//extern void (*segcolfunc)(void);
//extern void (*translatedcolfunc)(void);
//extern void (*basecolfunc)(void);
//extern void (*fuzzcolfunc)(void);
//extern void (*tlcolfunc)(void);
//extern void (*tl50colfunc)(void);
//extern void (*tl50segcolfunc)(void);
//extern void (*tl33colfunc)(void);
//extern void (*tlgreencolfunc)(void);
//extern void (*tlredcolfunc)(void);
//extern void (*tlredwhitecolfunc1)(void);
//extern void (*tlredwhitecolfunc2)(void);
//extern void (*tlredwhite50colfunc)(void);
//extern void (*tlbluecolfunc)(void);
//extern void (*tlgreen33colfunc)(void);
//extern void (*tlred33colfunc)(void);
//extern void (*tlblue25colfunc)(void);
//extern void (*redtobluecolfunc)(void);
//extern void (*tlredtoblue33colfunc)(void);
//extern void (*skycolfunc)(void);
//extern void (*redtogreencolfunc)(void);
//extern void (*tlredtogreen33colfunc)(void);
//extern void (*psprcolfunc)(void);
//extern void (*spanfunc)(void);
//extern void (*bloodsplatcolfunc)(void);
//extern void (*megaspherecolfunc)(void);
//extern void (*supershotguncolfunc)(void);

//
// Utility functions.
//int R_PointOnSide(fixed_t x, fixed_t y, const node_t *node);
//int R_PointOnSegSide(fixed_t x, fixed_t y, seg_t *line);
angle_t R_PointToAngle(fixed_t x, fixed_t y);
angle_t R_PointToAngle2(fixed_t x1, fixed_t y1, fixed_t x, fixed_t y);
//angle_t R_PointToAngleEx(fixed_t x, fixed_t y);
//angle_t R_PointToAngleEx2(fixed_t x1, fixed_t y1, fixed_t x, fixed_t y);
//subsector_t *R_PointInSubsector(fixed_t x, fixed_t y);
//
////
//// REFRESH - the actual rendering functions.
////
//
//// Called by G_Drawer.
//void R_RenderPlayerView(void);
//
//// Called by startup code.
//void R_Init(void);

// Called by M_Responder.
void R_SetViewSize(int blocks);
//void R_ExecuteSetViewSize(void);
//
//void R_InitLightTables(void);
//void R_InitColumnFunctions(void);

#endif
