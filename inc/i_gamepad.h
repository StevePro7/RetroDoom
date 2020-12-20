#if !defined(__I_GAMEPAD_H__)
#define __I_GAMEPAD_H__

#include "doomtype.h"

#define GAMEPAD_A                       0x00000001
#define GAMEPAD_B                       0x00000002
#define GAMEPAD_X                       0x00000004
#define GAMEPAD_Y                       0x00000008
#define GAMEPAD_BACK                    0x00000010
#define GAMEPAD_GUIDE                   0x00000020
#define GAMEPAD_START                   0x00000040
#define GAMEPAD_LEFT_THUMB              0x00000080
#define GAMEPAD_RIGHT_THUMB             0x00000100
#define GAMEPAD_LEFT_SHOULDER           0x00000200
#define GAMEPAD_RIGHT_SHOULDER          0x00000400
#define GAMEPAD_DPAD_UP                 0x00000800
#define GAMEPAD_DPAD_DOWN               0x00001000
#define GAMEPAD_DPAD_LEFT               0x00002000
#define GAMEPAD_DPAD_RIGHT              0x00004000
#define GAMEPAD_LEFT_TRIGGER            0x00010000
#define GAMEPAD_RIGHT_TRIGGER           0x00020000

#define GAMEPAD_TRIGGER_THRESHOLD       3855

#define MAXVIBRATIONSTRENGTH            65535
#define CHAINSAWIDLEVIBRATIONSTRENGTH   15000

#define gamepadthumbLXleft              ((float)(-gamepadthumbLX - gamepadleftdeadzone) / SHRT_MAX)
#define gamepadthumbLXright             ((float)(gamepadthumbLX - gamepadleftdeadzone) / SHRT_MAX)
#define gamepadthumbLYup                ((float)(-gamepadthumbLY - gamepadleftdeadzone) / SHRT_MAX)
#define gamepadthumbLYdown              ((float)(gamepadthumbLY - gamepadleftdeadzone) / SHRT_MAX)
#define gamepadthumbRXleft              ((float)(-gamepadthumbRX - gamepadrightdeadzone) / SHRT_MAX)
#define gamepadthumbRXright             ((float)(gamepadthumbRX - gamepadrightdeadzone) / SHRT_MAX)
#define gamepadthumbRYup                (-(float)(-gamepadthumbRY - gamepadrightdeadzone) / SHRT_MAX)
#define gamepadthumbRYdown              ((float)(gamepadthumbRY - gamepadrightdeadzone) / SHRT_MAX)

extern int      barrelvibrationtics;
extern int      damagevibrationtics;
extern int      weaponvibrationtics;

extern int      gamepadbuttons;
extern short    gamepadthumbLX;
extern short    gamepadthumbLY;
extern short    gamepadthumbRX;
extern short    gamepadthumbRY;
extern int      idlevibrationstrength;
extern int      restorevibrationstrength;
extern float    gamepadhorizontalsensitivity;
extern float    gamepadverticalsensitivity;
extern short    gamepadleftdeadzone;
extern short    gamepadrightdeadzone;

//void I_InitGamepad(void);
//void I_ShutdownGamepad(void);
//void I_GamepadVibration(int strength);
//void I_UpdateGamepadVibration(void);
//void I_StopGamepadVibration(void);
//void I_SetGamepadHorizontalSensitivity(void);
//void I_SetGamepadVerticalSensitivity(void);
//void I_SetGamepadLeftDeadZone(void);
//void I_SetGamepadRightDeadZone(void);

#endif
