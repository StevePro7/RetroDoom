#if !defined(__HU_STUFF_H__)
#define __HU_STUFF_H__

//#include "r_defs.h"

////
//// Globally visible constants.
////
//#define HU_FONTSTART                '!'     // the first font characters
//#define HU_FONTEND                  '_'     // the last font characters
//
//// Calculate # of glyphs in font.
//#define HU_FONTSIZE                 (HU_FONTEND - HU_FONTSTART + 1)
//
//#define HU_MSGX                     3
//#define HU_MSGY                     2
//#define HU_MSGHEIGHT                1       // in lines
//
//#define HU_MSGTIMEOUT               (4 * TICRATE)
//
//#define HUD_HEALTH_X                45
//#define HUD_HEALTH_Y                (SCREENHEIGHT - SBARHEIGHT - 28)
//#define HUD_HEALTH_MIN              10
//#define HUD_HEALTH_WAIT             250
//#define HUD_HEALTH_HIGHLIGHT_WAIT   250
//
//#define HUD_ARMOR_X                 114
//#define HUD_ARMOR_Y                 HUD_HEALTH_Y
//#define HUD_ARMOR_HIGHLIGHT_WAIT    250
//
//#define HUD_KEYS_X                  (SCREENWIDTH - 78)
//#define HUD_KEYS_Y                  (HUD_HEALTH_Y - 1)
//
//#define HUD_AMMO_X                  (SCREENWIDTH - 41)
//#define HUD_AMMO_Y                  HUD_HEALTH_Y
//#define HUD_AMMO_MIN                10
//#define HUD_AMMO_WAIT               250
//#define HUD_AMMO_HIGHLIGHT_WAIT     250
//
//#define HUD_KEY_WAIT                250
//
//#define ALTHUD_LEFT_X               56
//#define ALTHUD_RIGHT_X              (SCREENWIDTH - 179)
//#define ALTHUD_Y                    (SCREENHEIGHT - SBARHEIGHT - 37)

//
// HEADS UP TEXT
//
void HU_Init(void);
void HU_SetTranslucency(void);
//void HU_Start(void);
//
//void HU_Ticker(void);
//void HU_Drawer(void);
//void HU_Erase(void);
//
//void HU_SetPlayerMessage(char *message, dboolean counter, dboolean external);
//void HU_PlayerMessage(char *message, dboolean counter, dboolean external);
//
//void HU_ClearMessages(void);
//void HU_DrawDisk(void);

//extern patch_t  *hu_font[HU_FONTSIZE];
//
//extern int      healthhighlight;
//extern int      ammohighlight;
//extern int      armorhighlight;
//extern dboolean drawdisk;
//extern dboolean idbehold;

#endif
