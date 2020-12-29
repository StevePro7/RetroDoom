#if !defined(__R_DRAW_H__)
#define __R_DRAW_H__

#include "m_random.h"
#include "doomdef.h"

//#define FUZZ(a, b)      fuzzrange[M_BigRandomInt(a, b) + 1]
//
//// [BH] Compensate for rounding errors in DOOM's renderer by stretching wall
////  columns by 1px. This eliminates the randomly-colored pixels ("sparkles")
////  that appear at the bottom of some columns.
//#define SPARKLEFIX      64
//
//#define NOTEXTURECOLOR  80

//extern lighttable_t     *dc_colormap[2];
//extern int              dc_x;
//extern int              dc_yl;
//extern int              dc_yh;
//extern fixed_t          dc_iscale;
//extern fixed_t          dc_texturemid;
//extern fixed_t          dc_texheight;
//extern fixed_t          dc_texturefrac;
//extern byte             dc_solidblood;
//extern byte             *dc_blood;
//extern byte             *dc_brightmap;
//extern int              dc_floorclip;
//extern int              dc_ceilingclip;
//extern int              dc_numposts;
//extern byte             dc_black;
//extern byte             *dc_black25;
//extern byte             *dc_black40;
//
//// first pixel in a column
//extern byte             *dc_source;
//
//extern int              fuzzpos;
//extern const int        fuzzrange[3];
//extern int              fuzztable[SCREENAREA];

// The span blitting interface.
// Hook in assembler or system specific BLT here.
void R_DrawColumn(void);
void R_DrawColorColumn( void );
void R_DrawWallColumn( void );
void R_DrawBrightmapWallColumn( void );
void R_DrawSkyColumn( void );
void R_DrawFlippedSkyColumn( void );
void R_DrawSkyColorColumn( void );
void R_DrawTranslucentColumn( void );
void R_DrawTranslucent50Column( void );
void R_DrawTranslucentColor50Column( void );
void R_DrawDitheredColumn( void );
void R_DrawDitheredColorColumn( void );
void R_DrawTranslucent33Column( void );
void R_DrawTranslucentGreenColumn( void );
void R_DrawTranslucentRedColumn( void );
void R_DrawTranslucentRedWhiteColumn1( void );
void R_DrawTranslucentRedWhiteColumn2( void );
void R_DrawTranslucentRedWhite50Column( void );
void R_DrawTranslucentBlueColumn( void );
void R_DrawTranslucentGreen33Column( void );
void R_DrawTranslucentRed33Column( void );
void R_DrawTranslucentBlue25Column( void );
void R_DrawRedToBlueColumn( void );
void R_DrawTranslucentRedToBlue33Column( void );
void R_DrawRedToGreenColumn( void );
void R_DrawTranslucentRedToGreen33Column( void );
void R_DrawPlayerSpriteColumn( void );
void R_DrawSuperShotgunColumn( void );
void R_DrawTranslucentSuperShotgunColumn( void );
void R_DrawShadowColumn( void );
void R_DrawFuzzyShadowColumn( void );
void R_DrawSolidShadowColumn( void );
void R_DrawSolidFuzzyShadowColumn( void );
void R_DrawBloodSplatColumn( void );
void R_DrawSolidBloodSplatColumn( void );
void R_DrawMegaSphereColumn( void );
void R_DrawSolidMegaSphereColumn( void );

// The Spectre/Invisibility effect.
void R_DrawFuzzColumn(void);
void R_DrawPausedFuzzColumn(void);
void R_DrawFuzzColumns(void);
void R_DrawPausedFuzzColumns(void);

// Draw with color translation tables,
//  for player sprite rendering,
//  Green/Red/Blue/Indigo shirts.
void R_DrawTranslatedColumn(void);

void R_VideoErase(unsigned int ofs, int count);

//extern int          ds_y;
//extern int          ds_x1;
//extern int          ds_x2;
//
//extern lighttable_t *ds_colormap;
//
//extern fixed_t      ds_xfrac;
//extern fixed_t      ds_yfrac;
//extern fixed_t      ds_xstep;
//extern fixed_t      ds_ystep;
//
//// start of a 64*64 tile image
//extern byte         *ds_source;
//
//extern byte         translationtables[256 * 3];
//extern byte         *dc_translation;
//
//// Span blitting for rows, floor/ceiling.
//// No Spectre effect needed.
void R_DrawSpan(void);
void R_DrawColorSpan(void);

void R_InitBuffer( int width, int height );

//// Initialize color translation tables,
////  for player rendering etc.
void R_InitTranslationTables(void);
//
//// Rendering function.
//void R_FillBackScreen(void);
//
//// If the view size is not full screen, draws a border around it.
//void R_DrawViewBorder(void);

#endif
