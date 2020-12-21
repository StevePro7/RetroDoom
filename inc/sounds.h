#if !defined(__SOUNDS_H__)
#define __SOUNDS_H__

//#include "doomenum.h"
#include "doomtype.h"

// so that the individual game logic and sound driver code agree
#define NORM_PITCH  127

//
// SFX struct.
//
typedef struct sfxinfo_s sfxinfo_t;

struct sfxinfo_s
{
    // up to 6-character name
    char            name1[9];
    char            name2[9];

    // SFX singularity (only one at a time)
    int             singularity;

    // SFX priority
    int             priority;

    // SFX lumpnum
    int             lumpnum;
};

//
// music struct
//
typedef struct
{
    // up to 6-character name
    char            name1[9];
    char            name2[9];

    char            title1[32];
    char            title2[32];

    // lump number of music
    int             lumpnum;

    // music data
    void            *data;

    // music handle once registered
    void            *handle;
} musicinfo_t;

// the complete set of sound effects
extern sfxinfo_t    S_sfx[];

// the complete set of music
extern musicinfo_t  S_music[];

//extern musicinfo_t  *mus_playing;

extern dboolean     midimusictype;
extern dboolean     musmusictype;

#endif
