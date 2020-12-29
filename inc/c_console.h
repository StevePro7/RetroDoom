#if !defined(__C_CONSOLE_H__)
#define __C_CONSOLE_H__

#include "doomtype.h"

//void C_Input(const char *string, ...);
//void C_InputNoRepeat(const char *string, ...);
//void C_IntCVAROutput(char *cvar, int value);
//void C_PctCVAROutput(char *cvar, int value);
void C_StrCVAROutput(char *cvar, char *string);
//void C_Output(const char *string, ...);
//void C_OutputWrap(const char *string, ...);
//void C_OutputNoRepeat(const char *string, ...);
//void C_TabbedOutput(const int tabs[4], const char *string, ...);
//void C_Header(const int tabs[4], patch_t *header, const char *string);
//void C_Warning(const int minwarninglevel, const char *string, ...);
//void C_PlayerMessage(const char *string, ...);
//void C_Obituary(const char *string, ...);
void C_AddConsoleDivider(void);
//int C_TextWidth(const char *text, const dboolean formatting, const dboolean kerning);
void C_Init(void);
//void C_ShowConsole(void);
//void C_HideConsole(void);
//void C_HideConsoleFast(void);
//void C_Drawer(void);
//dboolean C_ExecuteInputString(const char *input);
//dboolean C_ValidateInput(char *input);
//dboolean C_Responder(event_t *ev);
//void C_PrintCompileDate(void);
//void C_PrintSDLVersions(void);
void C_UpdateFPS(void);
//void C_UpdateTimer(void);
char *C_CreateTimeStamp(int index);

#endif
