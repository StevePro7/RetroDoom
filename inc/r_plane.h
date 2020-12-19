#if !defined(__R_PLANE_H__)
#define __R_PLANE_H__

// killough 10/98: special mask indicates sky flat comes from sidedef
#define PL_SKYFLAT  0x40000000

// Visplane related.
extern int      *lastopening;
extern int      floorclip[SCREENWIDTH];
extern int      ceilingclip[SCREENWIDTH];
extern fixed_t  *yslope;
extern fixed_t  yslopes[LOOKDIRS][SCREENHEIGHT];
extern int      *openings;  // dropoff overflow

void R_ClearPlanes(void);
void R_DrawPlanes(void);
visplane_t *R_FindPlane(fixed_t height, int picnum, int lightlevel, fixed_t x, fixed_t y);
visplane_t *R_CheckPlane(visplane_t *pl, int start, int stop);
visplane_t *R_DupPlane(const visplane_t *pl, int start, int stop);
void R_InitDistortedFlats(void);

#endif
