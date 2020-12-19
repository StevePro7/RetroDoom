#if !defined(__SC_MAN_H__)
#define __SC_MAN_H__

extern char *sc_String;
extern int  sc_Number;
extern int  sc_Line;

void SC_Open(char *name);
void SC_Close(void);
dboolean SC_GetString(void);
void SC_MustGetString(void);
dboolean SC_GetNumber(void);
void SC_MustGetNumber(void);
void SC_UnGet(void);
dboolean SC_Compare(char *text);
int SC_MatchString(char **strings);
static void SC_ScriptError(void);

#endif
