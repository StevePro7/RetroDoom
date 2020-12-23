#if !defined(__W_WAD_H__)
#define __W_WAD_H__

#include "doomdef.h"
#include "doomstruct.h"
#include "w_file.h"

//
// TYPES
//

//
// WADFILE I/O related stuff.
//

#define IWAD 1
#define PWAD 2

//typedef struct lumpinfo_s lumpinfo_t;
//
//struct lumpinfo_s
//{
//    char        name[9];
//    int         size;
//    void        *cache;
//
//    // killough 01/31/98: hash table fields, used for ultra-fast hash table lookup
//    int         index;
//    int         next;
//
//    int         position;
//
//    wadfile_t   *wadfile;
//};

extern lumpinfo_t   **lumpinfo;
extern int          numlumps;

dboolean IsUltimateDOOM(const char *iwadname);

char *GetCorrectCase(char *path);

#if defined(_WIN32)
char *W_NearestFilename(char *path, char *string);
#endif

dboolean W_AddFile(char *filename, dboolean automatic);
int W_WadType(char *filename);

int W_CheckNumForName(const char *name);

int W_RangeCheckNumForName(int min, int max, const char *name);
int W_GetNumForName(const char *name);
int W_GetLastNumForName(const char *name);
int W_GetSecondNumForName(const char *name);

int W_CheckMultipleLumps(const char *name);

int W_LumpLength(int lump);

void *W_CacheLumpNum(int lumpnum);

#define W_CacheLumpName(name)       W_CacheLumpNum(W_GetNumForName(name))
#define W_CacheLastLumpName(name)   W_CacheLumpNum(W_GetLastNumForName(name))

void W_Init(void);

unsigned int W_LumpNameHash(const char *s);

void W_ReleaseLumpNum(int lumpnum);

#define W_ReleaseLumpName(name)     W_ReleaseLumpNum(W_GetNumForName(name))

GameMission_t IWADRequiredByPWAD(char *pwadname);
dboolean HasDehackedLump(const char *pwadname);

#endif
