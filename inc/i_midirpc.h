#if !defined(__I_MIDIRPC_H__)
#define __I_MIDIRPC_H__

//#include "doomtype.h"
//
//dboolean I_MidiRPCInitServer(void);
//dboolean I_MidiRPCInitClient(void);
void I_MidiRPCClientShutDown(void);
//
//dboolean I_MidiRPCRegisterSong(void *data, int size);
//dboolean I_MidiRPCPlaySong(dboolean looping);
dboolean I_MidiRPCStopSong(void);
//dboolean I_MidiRPCSetVolume(int volume);
//dboolean I_MidiRPCPauseSong(void);
//dboolean I_MidiRPCResumeSong(void);
//
#endif
