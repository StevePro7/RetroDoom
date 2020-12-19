#if !defined(__TABLES_H__)
#define __TABLES_H__

#include "m_fixed.h"

#define FINEANGLES          8192
#define FINEMASK            (FINEANGLES - 1)

#define ANGLETOFINESHIFT    19

// Effective size is 10240.
extern fixed_t  finesine[ 5 * FINEANGLES / 4 ];

// Re-use data, is just PI/2 phase shift.
extern fixed_t  *finecosine;

// Effective size is 4096.
extern fixed_t  finetangent[ FINEANGLES / 2 ];

// Binary Angle Measurement, BAM.
#define ANG1                (ANG45 / 45)
#define ANG5                (ANG90 / 18)
#define ANG45               0x20000000
#define ANG90               0x40000000
#define ANG180              0x80000000
#define ANG270              0xC0000000

#define SLOPERANGE          2048
#define SLOPEBITS           11
#define DBITS               (FRACBITS - SLOPEBITS)

typedef unsigned int    angle_t;

// Effective size is 2049;
// The +1 size is to handle the case when x == y
//  without additional checking.
extern angle_t  tantoangle[ SLOPERANGE + 1 ];

#endif
