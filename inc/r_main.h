#if !defined(__R_MAIN_H__)
#define __R_MAIN_H__

#include "doomstruct.h"


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

// Called by startup code.
void R_Init(void);

// Called by M_Responder.
void R_SetViewSize(int blocks);
void R_ExecuteSetViewSize(void);

void R_InitLightTables(void);
void R_InitColumnFunctions(void);

#endif
