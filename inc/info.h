#if !defined(__INFO_H__)
#define __INFO_H__

#include "doomenum.h"
#include "doomtype.h"
//#include "d_think.h"

typedef struct
{
	int         doomednum;
	int         spawnstate;
	int         spawnhealth;
	int         gibhealth;
	int         seestate;
	int         seesound;
	int         reactiontime;
	int         attacksound;
	int         painstate;
	int         painchance;
	int         painsound;
	int         meleestate;
	int         missilestate;
	int         deathstate;
	int         xdeathstate;
	int         deathsound;
	mobjtype_t  droppeditem;
	int         meleethreshold;
	int         maxattackrange;
	int         minmissilechance;
	int         speed;
	int         radius;
	int         pickupradius;
	int         height;
	int         projectilepassheight;
	int         mass;
	int         damage;
	int         activesound;
	int         flags;
	int         flags2;
	int         raisestate;
	int         frames;
	dboolean    fullbright;
	int         blood;
	int         shadowoffset;
	char        name1[ 64 ];
	char        plural1[ 64 ];
	char        name2[ 64 ];
	char        plural2[ 64 ];
	char        name3[ 64 ];
	char        plural3[ 64 ];
	void( *colfunc )( void );
	void( *altcolfunc )( void );
} mobjinfo_t;

extern mobjinfo_t   mobjinfo[];

#endif
