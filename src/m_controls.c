#include "m_controls.h"
#include "doomdef.h"
#include "m_config.h"
#include "doomkeys.h"
#include "version.h"
//#include "i_gamepad.h"
//#include "p_local.h"

int keyboardalwaysrun = KEYALWAYSRUN_DEFAULT;
int keyboardautomap = KEYAUTOMAP_DEFAULT;
int keyboardautomapclearmark = KEYAUTOMAPCLEARMARK_DEFAULT;
int keyboardautomapfollowmode = KEYAUTOMAPFOLLOWMODE_DEFAULT;
int keyboardautomapgrid = KEYAUTOMAPGRID_DEFAULT;
int keyboardautomapmark = KEYAUTOMAPMARK_DEFAULT;
int keyboardautomapmaxzoom = KEYAUTOMAPMAXZOOM_DEFAULT;
int keyboardautomaprotatemode = KEYAUTOMAPROTATEMODE_DEFAULT;
int keyboardautomapzoomin = KEYAUTOMAPZOOMIN_DEFAULT;
int keyboardautomapzoomout = KEYAUTOMAPZOOMOUT_DEFAULT;
int keyboardback = KEYDOWN_DEFAULT;
int keyboardback2 = KEYDOWN2_DEFAULT;
int keyboardconsole = KEYCONSOLE_DEFAULT;
int keyboardfire = KEYFIRE_DEFAULT;
int keyboardjump = KEYJUMP_DEFAULT;
int keyboardleft = KEYLEFT_DEFAULT;
int keyboardmenu = KEY_ESCAPE;
int keyboardmouselook = KEYMOUSELOOK_DEFAULT;
int keyboardnextweapon = KEYNEXTWEAPON_DEFAULT;
int keyboardprevweapon = KEYPREVWEAPON_DEFAULT;
int keyboardright = KEYRIGHT_DEFAULT;
int keyboardrun = KEYRUN_DEFAULT;
int keyboardscreenshot = KEYSCREENSHOT_DEFAULT;
int keyboardstrafe = KEYSTRAFE_DEFAULT;
int keyboardstrafeleft = KEYSTRAFELEFT_DEFAULT;
int keyboardstrafeleft2 = KEYSTRAFELEFT2_DEFAULT;
int keyboardstraferight = KEYSTRAFERIGHT_DEFAULT;
int keyboardstraferight2 = KEYSTRAFERIGHT2_DEFAULT;
int keyboardforward = KEYUP_DEFAULT;
int keyboardforward2 = KEYUP2_DEFAULT;
int keyboarduse = KEYUSE_DEFAULT;
int keyboarduse2 = KEYUSE2_DEFAULT;
int keyboardweapon1 = KEYWEAPON1_DEFAULT;
int keyboardweapon2 = KEYWEAPON2_DEFAULT;
int keyboardweapon3 = KEYWEAPON3_DEFAULT;
int keyboardweapon4 = KEYWEAPON4_DEFAULT;
int keyboardweapon5 = KEYWEAPON5_DEFAULT;
int keyboardweapon6 = KEYWEAPON6_DEFAULT;
int keyboardweapon7 = KEYWEAPON7_DEFAULT;

int mousefire = MOUSEFIRE_DEFAULT;
int mouseforward = MOUSEFORWARD_DEFAULT;
int mousejump = MOUSEJUMP_DEFAULT;
int mousemouselook = MOUSEMOUSELOOK_DEFAULT;
int mousenextweapon = MOUSENEXTWEAPON_DEFAULT;
int mouseprevweapon = MOUSEPREVWEAPON_DEFAULT;
int mouserun = MOUSERUN_DEFAULT;
int mousescreenshot = MOUSESCREENSHOT_DEFAULT;
int mousestrafe = MOUSESTRAFE_DEFAULT;
int mouseuse = MOUSEUSE_DEFAULT;

//int gamepadalwaysrun = GAMEPADALWAYSRUN_DEFAULT;
//int gamepadautomap = GAMEPADAUTOMAP_DEFAULT;
//int gamepadautomapclearmark = GAMEPADAUTOMAPCLEARMARK_DEFAULT;
//int gamepadautomapfollowmode = GAMEPADAUTOMAPFOLLOWMODE_DEFAULT;
//int gamepadautomapgrid = GAMEPADAUTOMAPGRID_DEFAULT;
//int gamepadautomapmark = GAMEPADAUTOMAPMARK_DEFAULT;
//int gamepadautomapmaxzoom = GAMEPADAUTOMAPMAXZOOM_DEFAULT;
//int gamepadautomaprotatemode = GAMEPADAUTOMAPROTATEMODE_DEFAULT;
//int gamepadautomapzoomin = GAMEPADAUTOMAPZOOMIN_DEFAULT;
//int gamepadautomapzoomout = GAMEPADAUTOMAPZOOMOUT_DEFAULT;
//int gamepadback = GAMEPADBACK_DEFAULT;
//int gamepadfire = GAMEPADFIRE_DEFAULT;
//int gamepadforward = GAMEPADFORWARD_DEFAULT;
//int gamepadjump = GAMEPADJUMP_DEFAULT;
//int gamepadleft = GAMEPADLEFT_DEFAULT;
//int gamepadmenu = GAMEPADMENU_DEFAULT;
//int gamepadmouselook = GAMEPADMOUSELOOK_DEFAULT;
//int gamepadnextweapon = GAMEPADNEXTWEAPON_DEFAULT;
//int gamepadprevweapon = GAMEPADPREVWEAPON_DEFAULT;
//int gamepadright = GAMEPADRIGHT_DEFAULT;
//int gamepadrun = GAMEPADRUN_DEFAULT;
//int gamepadstrafe = GAMEPADSTRAFE_DEFAULT;
//int gamepadstrafeleft = GAMEPADSTRAFELEFT_DEFAULT;
//int gamepadstraferight = GAMEPADSTRAFERIGHT_DEFAULT;
//int gamepaduse = GAMEPADUSE_DEFAULT;
//int gamepaduse2 = GAMEPADUSE2_DEFAULT;
//int gamepadweapon1 = GAMEPADWEAPON_DEFAULT;
//int gamepadweapon2 = GAMEPADWEAPON_DEFAULT;
//int gamepadweapon3 = GAMEPADWEAPON_DEFAULT;
//int gamepadweapon4 = GAMEPADWEAPON_DEFAULT;
//int gamepadweapon5 = GAMEPADWEAPON_DEFAULT;
//int gamepadweapon6 = GAMEPADWEAPON_DEFAULT;
//int gamepadweapon7 = GAMEPADWEAPON_DEFAULT;
