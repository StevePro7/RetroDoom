// Eternity Engine's Client Interface to RPC Midi Server by James Haley

#if defined(_WIN32)
#include <Windows.h>

#include "../midiproc/midiproc.h"

#include "c_console.h"
#include "i_timer.h"
#include "m_misc.h"

//
// Data
//
static STARTUPINFO          si;
static PROCESS_INFORMATION  pi;
static unsigned char        *szStringBinding;       // RPC client binding string
static dboolean             serverInit;             // if true, server was started
static dboolean             clientInit;             // if true, client was bound
static char                 module[MAX_PATH + 1];

//
// RPC Memory Management
//
void __RPC_FAR * __RPC_USER midl_user_allocate(size_t size)
{
    return malloc(size);
}

void __RPC_USER midl_user_free(void __RPC_FAR *p)
{
    free(p);
}

//
// RPC Wrappers
//

// This number * 20 is the amount of time you can try to wait for.
#define MIDIRPC_MAXTRIES    100

static dboolean I_MidiRPCWaitForServer(void)
{
    int tries = 0;

    //while (RpcMgmtIsServerListening(hMidiRPCBinding) != RPC_S_OK)
    //{
    //    I_Sleep(20);

    //    if (++tries >= MIDIRPC_MAXTRIES)
    //        return false;
    //}

    return true;
}

//
// I_MidiRPCRegisterSong
// Prepare the RPC MIDI engine to receive new song data, and transmit the song data to the server process.
//
dboolean I_MidiRPCRegisterSong(void *data, int size)
{
    if (!serverInit || !clientInit)
        return false;

    RpcTryExcept
        //MidiRPC_PrepareNewSong();
        //MidiRPC_AddChunk((unsigned int)size, (byte *)data);
    RpcExcept(1)
        return false;
    RpcEndExcept

    return true;
}

//
// I_MidiRPCPlaySong
// Tell the RPC server to start playing a song.
//
dboolean I_MidiRPCPlaySong(dboolean looping)
{
    if (!serverInit || !clientInit)
        return false;

    RpcTryExcept
        //MidiRPC_PlaySong(looping);
    RpcExcept(1)
        return false;
    RpcEndExcept

    return true;
}

//
// I_MidiRPCStopSong
// Tell the RPC server to stop any currently playing song.
//
dboolean I_MidiRPCStopSong(void)
{
    if (!serverInit || !clientInit)
        return false;

    RpcTryExcept
        //MidiRPC_StopSong();
    RpcExcept(1)
        return false;
    RpcEndExcept

    return true;
}

//
// I_MidiRPCSetVolume
// Change the volume level of music played by the RPC midi server.
//
dboolean I_MidiRPCSetVolume(int volume)
{
    if (!serverInit || !clientInit)
        return false;

    RpcTryExcept
        //MidiRPC_ChangeVolume(volume);
    RpcExcept(1)
        return false;
    RpcEndExcept

    return true;
}

//
// I_MidiRPCPauseSong
// Pause the music being played by the server.
// In actuality, due to SDL_mixer limitations, this just temporarily sets the volume to zero.
//
dboolean I_MidiRPCPauseSong(void)
{
    if (!serverInit || !clientInit)
        return false;

    RpcTryExcept
        //MidiRPC_PauseSong();
    RpcExcept(1)
        return false;
    RpcEndExcept

    return true;
}

//
// I_MidiRPCResumeSong
// Resume a song after having paused it.
//
dboolean I_MidiRPCResumeSong(void)
{
    if (!serverInit || !clientInit)
        return false;

    RpcTryExcept
        //MidiRPC_ResumeSong();
    RpcExcept(1)
        return false;
    RpcEndExcept

    return true;
}

//
// Public Interface
//

//
// I_MidiRPCInitServer
// Start up the RPC MIDI server.
//
dboolean I_MidiRPCInitServer(void)
{
    dboolean    result;
    char        *temp = M_GetExecutableFolder();

    M_snprintf(module, sizeof(module), "%s" DIR_SEPARATOR_S "midiproc.exe", temp);
    free(temp);

    // Look for executable file
    if (!M_FileExists(module))
    {
        C_Warning(1, "<b>%s</b> couldn't be found.", module);
        return false;
    }

    si.cb = sizeof(si);
    result = CreateProcess(module, NULL, NULL, NULL, false, 0, NULL, NULL, &si, &pi);

    if (result)
    {
        C_Output("Using <b>%s</b> to play MUS and MIDI music lumps.", module);
        serverInit = true;
    }
    else
        C_Warning(1, "<b>%s</b> couldn't be initialized.", module);

    return result;
}

//
// I_MidiRPCInitClient
// Initialize client RPC bindings and bind to the server.
//
dboolean I_MidiRPCInitClient(void)
{
    dboolean    result;

    // If server didn't start, client cannot be bound.
    if (!serverInit)
        return false;

    // Compose binding string
    if (RpcStringBindingCompose(NULL, (RPC_CSTR)"ncalrpc", NULL,
        (RPC_CSTR)"2d4dc2f9-ce90-4080-8a00-1cb819086970", NULL, &szStringBinding))
        return false;

    // Create binding handle
    //if (RpcBindingFromStringBinding(szStringBinding, &hMidiRPCBinding))
    //    return false;

    clientInit = true;

    result = I_MidiRPCWaitForServer();

    if (!result)
        C_Warning(1, "<b>%s</b> couldn't be initialized.", module);

    return result;
}

//
// I_MidiRPCClientShutDown
// Shutdown the RPC Client
//
void I_MidiRPCClientShutDown(void)
{
    // stop the server
    if (serverInit)
    {
        RpcTryExcept
            //MidiRPC_StopServer();
        RpcExcept(1)
        RpcEndExcept

        serverInit = false;

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    if (szStringBinding)
    {
        RpcStringFree(&szStringBinding);
        szStringBinding = NULL;
    }

    //if (hMidiRPCBinding)
    //{
    //    RpcBindingFree(&hMidiRPCBinding);
    //    hMidiRPCBinding = NULL;
    //}

    clientInit = false;
}
#endif
