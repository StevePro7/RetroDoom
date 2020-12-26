#if !defined(__P_SETUP_H__)
#define __P_SETUP_H__

//extern dboolean     canmodify;
//extern dboolean     samelevel;
//extern dboolean     skipblstart;    // MaxW: Skip initial blocklist short
//extern const char   *linespecials[];
//
//extern char         mapnum[6];
//extern char         maptitle[256];
//extern char         mapnumandtitle[512];
//extern char         automaptitle[512];
//
//void P_SetupLevel(int ep, int map);
//void P_MapName(int ep, int map);
//
//// Called by startup code.
//void P_Init(void);
//
//char *P_GetMapAuthor(int map);
//char *P_GetInterBackrop(int map);
//int P_GetInterMusic(int map);
//char *P_GetInterText(int map);
//char *P_GetInterSecretText(int map);
//dboolean P_GetMapEndBunny(int map);
//dboolean P_GetMapEndCast(int map);
//dboolean P_GetMapEndGame(int map);
//int P_GetMapEndPic(int map);
//int P_GetMapEnterPic(int map);
//void P_GetMapLiquids(int map);
//int P_GetMapMusic(int map);
//char *P_GetMapMusicComposer(int map);
//char *P_GetMapMusicTitle(int map);
//char *P_GetMapName(int map);
//int P_GetMapNext(int map);
//dboolean P_GetMapNoJump(int map);
//void P_GetMapNoLiquids(int map);
//dboolean P_GetMapNoMouselook(int map);
//int P_GetMapPar(int map);
//dboolean P_GetMapPistolStart(int map);
//int P_GetMapSecretNext(int map);
int P_GetMapSky1Texture(int map);
int P_GetMapSky1ScrollDelta(int map);
//int P_GetMapTitlePatch(int map);

#endif
