#if !defined(__M_MENU_H__)
#define __M_MENU_H__

//#include "p_saveg.h"
//
//typedef struct
//{
//    short           status;
//    char            name[10];
//    void            (*routine)(int choice);
//    char            **text;
//} menuitem_t;
//
//typedef struct menu_s
//{
//    short           numitems;
//    struct menu_s   *prevMenu;
//    menuitem_t      *menuitems;
//    void            (*routine)(void);
//    short           x;
//    short           y;
//    int             lastOn;
//    dboolean        change;
//} menu_t;
//
////
//// MENUS
////
//// Called by main loop,
//// saves config file and calls I_Quit when user exits.
//// Even when the menu is not displayed,
//// this can resize the view and change game parameters.
//// Does all the real work of the menu interaction.
//dboolean M_Responder(event_t *ev);
//
//// Called by main loop,
//// only used for menu (skull cursor) animation.
//void M_Ticker(void);
//
//// Called by main loop,
//// draws the menus directly into the screen buffer.
//void M_Drawer(void);
//
//// Called by D_DoomMain,
//// loads the config file.
//void M_Init(void);
//
//// Called by intro code to force menu up upon a keypress,
//// does nothing if menu is already up.
//void M_StartControlPanel(void);
//void M_ClearMenus(void);
//void M_EndingGame(void);
//void M_ChangeGamma(dboolean shift);
//
//void M_DarkBackground(void);
//void M_DrawCenteredString(int y, char *string);
//int M_StringWidth(char *string);
//
//void M_SetWindowCaption(void);
//
//void M_UpdateSaveGameName(int i);
int M_CountSaveGames(void);
//
//void M_StartMessage(char *string, void *routine, dboolean input);
//
//void M_ShowHelp(int choice);
//void M_QuitDOOM(int choice);
//
//void M_AddEpisode(int map, int ep, const char *lumpname, const char *string);
//
//extern dboolean messagetoprint;
//
//extern dboolean nomusic;
//extern dboolean nosound;
//extern dboolean nosfx;
//extern dboolean firstevent;
//extern dboolean savegames;
//extern dboolean inhelpscreens;
//extern int      spindirection;
//extern char     savegamestrings[6][SAVESTRINGSIZE];
//extern menu_t   EpiDef;
//extern menu_t   ExpDef;
//extern menu_t   LoadDef;
//extern menu_t   MainDef;
//extern menu_t   NewDef;
//extern menu_t   SaveDef;
//extern dboolean EpiCustom;

#endif
