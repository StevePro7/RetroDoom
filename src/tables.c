//stevepro
#include "tables.h"

// r_main.h
fixed_t             finesine[ 5 * FINEANGLES / 4 ];
fixed_t             *finecosine = &finesine[ FINEANGLES / 4 ];
fixed_t             finetangent[ FINEANGLES / 2 ];
angle_t             tantoangle[ SLOPERANGE + 1 ];