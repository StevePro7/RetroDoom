#if !defined(__DOOMSTRUCT_H__)
#define __DOOMSTRUCT_H__

#include "doomtype.h"

// d_player.h
//
// INTERMISSION
// Structure passed e.g. to WI_Start(wb)
//
typedef struct
{
	int             epsd;           // episode # (0-2)

									// if true, splash the secret level
	dboolean        didsecret;

	// previous and next levels, origin 0
	int             last;
	int             next;

	int             maxkills;
	int             maxitems;
	int             maxsecret;

	// the par time
	int             partime;

	int             skills;
	int             sitems;
	int             ssecret;
	int             stime;
} wbstartstruct_t;

#endif