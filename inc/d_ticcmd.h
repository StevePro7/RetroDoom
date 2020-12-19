#if !defined(__D_TICCMD_H__)
#define __D_TICCMD_H__

// The data sampled per tic..
// Mainly movements/button commands per game tic.
// [BH] forwardmove, sidemove and angleturn need to be explicitly signed
typedef struct
{
    signed char     forwardmove;    // * 2048 for move
    signed char     sidemove;       // * 2048 for move
    signed short    angleturn;      // << 16 for angle delta
    byte            buttons;
    int             lookdir;
} ticcmd_t;

#endif
