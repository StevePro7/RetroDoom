#if !defined(__I_MUSIC_H__)
#define __I_MUSIC_H__

#include "sounds.h"

extern musicinfo_t  *mus_playing;

void I_ShutdownMusic( void );
void I_UnRegisterSong( void *handle );

#endif
