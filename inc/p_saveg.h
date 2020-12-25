#if !defined(__P_SAVEG_H__)
#define __P_SAVEG_H__

// maximum size of a savegame description
//#define SAVESTRINGSIZE          256
//#define SAVESTRINGPIXELWIDTH    186
//#define VERSIONSIZE             24

#include "doomdef.h"
#include "doomvars.h"

enum
{
    tc_end,
    tc_mobj,
    tc_bloodsplat
};

enum
{
    tc_ceiling,
    tc_door,
    tc_floor,
    tc_plat,
    tc_flash,
    tc_strobe,
    tc_glow,
    tc_elevator,        // jff 02/22/98 new elevator type thinker
    tc_scroll,          // killough 03/07/98: new scroll effect thinker
    tc_pusher,          // phares 03/22/98: new push/pull effect thinker
    tc_fireflicker,     // killough 10/04/98
    tc_button,
    tc_endspecials
};

// temporary filename to use while saving.
//char *P_TempSaveGameFile(void);

// filename to use for a savegame slot
char *P_SaveGameFile(int slot);

//// Savegame file header read/write functions
//dboolean P_ReadSaveGameHeader(char *description);
//void P_WriteSaveGameHeader(char *description);
//
//// Savegame end-of-file read/write functions
//dboolean P_ReadSaveGameEOF(void);
//void P_WriteSaveGameEOF(void);
//
//// Persistent storage/archiving.
//// These are the load/save game routines.
//void P_ArchivePlayer(void);
//void P_UnArchivePlayer(void);
//void P_ArchiveWorld(void);
//void P_UnArchiveWorld(void);
//void P_ArchiveThinkers(void);
//void P_UnArchiveThinkers(void);
//void P_ArchiveSpecials(void);
//void P_UnArchiveSpecials(void);
//void P_ArchiveMap(void);
//void P_UnArchiveMap(void);
//
//void P_RestoreTargets(void);

//extern FILE *save_stream;

#endif
