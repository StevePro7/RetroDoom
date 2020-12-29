#if !defined(__G_GAME_H__)
#define __G_GAME_H__

//#include "d_event.h"
//#include "i_video.h"
//#include "w_file.h"

//#define NUMKEYS         256

//#define FORWARDMOVE0    0x19
//#define FORWARDMOVE1    0x32
//
//#define SIDEMOVE0       0x18
//#define SIDEMOVE1       0x28

//
// GAME
//
//void G_InitNew(skill_t skill, int ep, int map);
//
//// Can be called by the startup code or M_Responder.
//// A normal game starts at map 1,
//// but a warp test can start elsewhere
//void G_DeferredInitNew(skill_t skill, int ep, int map);
//
//void G_DeferredLoadLevel(skill_t skill, int ep, int map);

// Can be called by the startup code or M_Responder,
// calls P_SetupLevel.
void G_LoadGame(char *name);

//void G_DoLoadGame(void);
//void G_DoLoadLevel(void);
//
//// Called by M_Responder.
//void G_SaveGame(int slot, char *description, char *name);
//
//void G_ExitLevel(void);
//void G_SecretExitLevel(void);
//
//int G_GetParTime(void);
//
//void G_WorldDone(void);
//
//// Read current data from inputs and build a player movement command.
//void G_BuildTiccmd(ticcmd_t *cmd);
//
//void G_Ticker(void);
//dboolean G_Responder(event_t *ev);
//
//void G_ScreenShot(void);
//void I_ToggleWidescreen(dboolean toggle);
//
//void G_SetFastParms(dboolean fast_pending);
void G_SetMovementSpeed(int scale);
//void G_ToggleAlwaysRun(evtype_t type);
//
//void G_NextWeapon(void);
//void G_PrevWeapon(void);
//void G_RemoveChoppers(void);
//
//void G_LoadedGameMessage(void);
//
//extern fixed_t  forwardmove[2];
//extern fixed_t  sidemove[2];
//extern fixed_t  angleturn[3];
//extern dboolean gamekeydown[NUMKEYS];
//extern dboolean *mousebuttons;
//extern dboolean gamepadpress;
//extern char     lbmname1[MAX_PATH];
//extern char     lbmpath1[MAX_PATH];
//extern char     lbmpath2[MAX_PATH];
//extern char     keyactionlist[NUMKEYS][255];
//extern char     mouseactionlist[MAX_MOUSE_BUTTONS + 2][255];
//extern int      mousewait;
//extern int      quickSaveSlot;
//extern int      st_facecount;
//extern dboolean skipaction;
//extern char     savename[MAX_PATH];
//extern dboolean usemouselook;
//extern dboolean secretexit;

#endif
