#if !defined(__D_IWAD_H__)
#define __D_IWAD_H__

//#include "doomdef.h"
//
char *D_FindWADByName(char *filename);
//char *D_TryFindWADByName(char *filename);
char *D_FindIWAD(void);
//void D_SetSaveGameFolder(dboolean output);
void D_IdentifyVersion(void);
void D_SetGameDescription(void);
void D_IdentifyIWADByName(char *name);
void D_InitIWADFolder(void);

#endif
