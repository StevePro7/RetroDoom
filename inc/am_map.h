#if !defined(__AM_MAP_H__)
#define __AM_MAP_H__

//// Called by main loop.
//dboolean AM_Responder(const event_t *ev);
//
//// Called by main loop.
//void AM_Ticker(void);
//
//// Called by main loop, called instead of view drawer if automap active.
//void AM_Drawer(void);
void AM_ClearFB(void);

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

void AM_Init(void);
void AM_SetColors( void );
void AM_GetGridSize( void );
void AM_AddToPath( void );


#endif
