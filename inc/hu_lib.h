#if !defined(__HU_LIB_H__)
#define __HU_LIB_H__

// We are referring to patches.
#include "r_defs.h"

#define HU_TITLEX           3

// font stuff
#define HU_MAXLINES         4
#define HU_MAXLINELENGTH    512

#define HU_ALTHUDMSGX       30
#define HU_ALTHUDMSGY       12

//
// Typedefs of widgets
//

// Text Line widget
//  (parent of Scrolling Text and Input Text widgets)
typedef struct
{
    // left-justified position of scrolling text window
    int             x, y;

    patch_t         **f;                            // font
    int             sc;                             // start character
    char            l[HU_MAXLINELENGTH + 1];        // line of text
    int             len;                            // current line length

    // whether this line needs to be updated
    int             needsupdate;
} hu_textline_t;

// Scrolling Text window widget
//  (child of Text Line widget)
typedef struct
{
    hu_textline_t   l[HU_MAXLINES];                 // text lines to draw
    int             h;                              // height in lines
    int             cl;                             // current line number

    // pointer to dboolean stating whether to update window
    dboolean        *on;
    dboolean        laston;                         // last value of *->on.
} hu_stext_t;

//
// Widget creation, access, and update routines
//

//
// textline code
//

void HUlib_InitTextLine(hu_textline_t *t, int x, int y, patch_t **f, int sc);

// returns success
dboolean HUlib_AddCharToTextLine(hu_textline_t *t, char ch);

// draws text line
void HUlib_DrawTextLine(hu_textline_t *l, dboolean external);
void HUlib_DrawAltAutomapTextLine(hu_textline_t *l, dboolean external);

// erases text line
void HUlib_EraseTextLine(hu_textline_t *l);

//
// Scrolling Text window widget routines
//

void HUlib_InitSText(hu_stext_t *s, int x, int y, int h, patch_t **font, int startchar, dboolean *on);

void HUlib_AddMessageToSText(hu_stext_t *s, const char *msg);

// draws stext
void HUlib_DrawSText(hu_stext_t *s, dboolean external);

// erases all stext lines
void HUlib_EraseSText(hu_stext_t *s);

extern void (*althudtextfunc)(int, int, byte *, patch_t *, int);

extern dboolean s_STSTR_BEHOLD2;
extern byte     tempscreen[SCREENAREA];

#endif
