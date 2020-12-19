#if !defined(__I_COLORS_H__)
#define __I_COLORS_H__

#include "doomtype.h"
#include "r_defs.h"

extern byte *tinttab20;
extern byte *tinttab25;
extern byte *tinttab30;
extern byte *tinttab33;
extern byte *tinttab40;
extern byte *tinttab50;
extern byte *tinttab60;
extern byte *tinttab66;
extern byte *tinttab75;

extern byte *alttinttab20;
extern byte *alttinttab40;
extern byte *alttinttab60;

extern byte *tranmap;
extern byte *tinttabadditive;
extern byte *tinttabred;
extern byte *tinttabredwhite1;
extern byte *tinttabredwhite2;
extern byte *tinttabgreen;
extern byte *tinttabblue;
extern byte *tinttabred33;
extern byte *tinttabredwhite50;
extern byte *tinttabgreen33;
extern byte *tinttabblue25;

extern byte nearestcolors[256];
extern byte nearestblack;
extern byte nearestred;
extern byte nearestwhite;

extern byte *black25;
extern byte *black40;
extern byte *yellow15;
extern byte *white25;

void I_InitTintTables(byte *palette);
int FindNearestColor(byte *palette, const int red, const int green, const int blue);
void FindNearestColors(byte *palette);

int FindDominantColor(patch_t *patch, byte *palette);

#endif
