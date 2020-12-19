#if !defined(__R_SKY_H__)
#define __R_SKY_H__

// SKY, store the number for name.
#define SKYFLATNAME         "F_SKY1"

// The sky map is 256*128*4 maps.
#define ANGLETOSKYSHIFT     22

#define SKYSTRETCH_HEIGHT   228

extern int      skytexture;
extern int      skytexturemid;
extern int      skycolumnoffset;
extern int      skyscrolldelta;
extern fixed_t  skyiscale;
extern dboolean canmouselook;

void R_InitSkyMap(void);

#endif
