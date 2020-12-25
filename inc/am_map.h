#if !defined(__AM_MAP_H__)
#define __AM_MAP_H__

//#include "d_event.h"
//#include "m_fixed.h"
//
//#define MAPBITS         12
//#define FRACTOMAPBITS   (FRACBITS - MAPBITS)
//
//typedef struct
//{
//    fixed_t x, y;
//} mpoint_t;
//
//// Called by main loop.
//dboolean AM_Responder(const event_t *ev);
//
//// Called by main loop.
//void AM_Ticker(void);
//
//// Called by main loop, called instead of view drawer if automap active.
//void AM_Drawer(void);
//void AM_ClearFB(void);
//
//void AM_Start(const dboolean mainwindow);
//void AM_ClearMarks(void);
//void AM_ToggleFollowMode(void);
//void AM_ToggleGrid(void);
//void AM_AddMark(void);
//void AM_ToggleRotateMode(void);
//void AM_ToggleMaxZoom(void);
//
//// Called to force the automap to quit if the level is completed while it is up.
//void AM_Stop(void);

void AM_SetAutomapSize(void);

//void AM_Init(void);
//void AM_SetColors(void);
//void AM_GetGridSize(void);
//void AM_AddToPath(void);
//
//typedef struct
//{
//    mpoint_t    center;
//    fixed_t     sin;
//    fixed_t     cos;
//    fixed_t     bbox[4];
//} am_frame_t;
//
//extern dboolean     message_dontfuckwithme;
//
//extern int          gamepadwait;
//
//extern mpoint_t     *markpoints;
//extern int          markpointnum;
//extern int          markpointnum_max;
//
//extern mpoint_t     *pathpoints;
//extern int          pathpointnum;
//extern int          pathpointnum_max;
//
//extern am_frame_t   am_frame;
//extern int          direction;
//
//dboolean keystate(int key);

#endif
