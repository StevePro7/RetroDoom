#if !defined(__V_VIDEO_H__)
#define __V_VIDEO_H__

#include "doomstruct.h"
#include "doomtype.h"
//#include "r_data.h"
//#include "w_file.h"

#if defined(_WIN32)
#include <Windows.h>
#endif

//
// VIDEO
//

// Screen 0 is the screen updated by I_Update screen.
// Screen 1 is an extra buffer.
extern byte *screens[5];

extern int  lowpixelwidth;
extern int  lowpixelheight;

extern char screenshotfolder[MAX_PATH];

// Allocates buffer screens, call before R_Init.
void V_Init(void);

void V_FillRect(int scrn, int x, int y, int width, int height, int color, dboolean right);
void V_FillTransRect(int scrn, int x, int y, int width, int height, int color, dboolean right);
void V_FillSoftTransRect(int scrn, int x, int y, int width, int height, int color, dboolean right);
//
//void V_DrawPatch(int x, int y, int scrn, patch_t *patch);
//void V_DrawWidePatch(int x, int y, int scrn, patch_t *patch);
//void V_DrawBigPatch(int x, int y, patch_t *patch);
//void V_DrawConsolePatch(int x, int y, patch_t *patch, int color);
//void V_DrawConsoleBrandingPatch(int x, int y, patch_t *patch, int color);
//void V_DrawConsoleInputTextPatch(int x, int y, patch_t *patch, int width, int color,
//    int backgroundcolor, dboolean italics, byte *translucency);
void V_DrawConsoleOutputTextPatch(int x, int y, patch_t *patch, int width, int color,
    int backgroundcolor, dboolean italics, byte *translucency);
//void V_DrawShadowPatch(int x, int y, patch_t *patch);
//void V_DrawSolidShadowPatch(int x, int y, patch_t *patch);
//void V_DrawSpectreShadowPatch(int x, int y, patch_t *patch);
//void V_DrawSolidSpectreShadowPatch(int x, int y, patch_t *patch);
//dboolean V_IsEmptyPatch(patch_t *patch);
//void V_DrawPatchWithShadow(int x, int y, patch_t *patch, dboolean flag);
//void V_DrawFlippedPatch(int x, int y, patch_t *patch);
//void V_DrawFlippedShadowPatch(int x, int y, patch_t *patch);
//void V_DrawFlippedSolidShadowPatch(int x, int y, patch_t *patch);
//void V_DrawFlippedSpectreShadowPatch(int x, int y, patch_t *patch);
//void V_DrawFlippedSolidSpectreShadowPatch(int x, int y, patch_t *patch);
//void V_DrawFuzzPatch(int x, int y, patch_t *patch);
//void V_DrawFlippedFuzzPatch(int x, int y, patch_t *patch);
//void V_DrawNoGreenPatchWithShadow(int x, int y, patch_t *patch);
void V_DrawHUDPatch(int x, int y, patch_t *patch, byte *translucency);
//void V_DrawHighlightedHUDNumberPatch(int x, int y, patch_t *patch, byte *translucency);
void V_DrawTranslucentHUDPatch(int x, int y, patch_t *patch, byte *translucency);
void V_DrawTranslucentHUDNumberPatch(int x, int y, patch_t *patch, byte *translucency);
void V_DrawAltHUDPatch(int x, int y, patch_t *patch, int from, int to);
void V_DrawTranslucentAltHUDPatch(int x, int y, patch_t *patch, int from, int to);
//void V_DrawTranslucentNoGreenPatch(int x, int y, patch_t *patch);
//void V_DrawTranslucentRedPatch(int x, int y, patch_t *patch);
//void V_DrawFlippedTranslucentRedPatch(int x, int y, patch_t *patch);
//void V_DrawPatchToTempScreen(int x, int y, patch_t *patch);
//void V_DrawBigPatchToTempScreen(int x, int y, patch_t *patch);
void V_DrawAltHUDText(int x, int y, byte *screen, patch_t *patch, int color);
void V_DrawTranslucentAltHUDText(int x, int y, byte *screen, patch_t *patch, int color);
//void V_DrawPagePatch(patch_t *patch);
//
//void V_DrawPixel(int x, int y, byte color, dboolean drawshadow);
//
void GetPixelSize(dboolean reset);
//void V_LowGraphicDetail(int left, int top, int width, int height, int pixelwidth, int pixelheight);
//void V_InvertScreen(void);
//
//dboolean V_ScreenShot(void);

#endif
