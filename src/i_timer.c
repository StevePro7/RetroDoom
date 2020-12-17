
#include "SDL.h"

#include "doomdef.h"

//
// I_GetTime
// returns time in 1/35th second tics
//
int I_GetTime( void )
{
	return ( SDL_GetTicks() * TICRATE / 1000 );
}

//
// Same as I_GetTime(), but returns time in milliseconds
//
int I_GetTimeMS( void )
{
	return SDL_GetTicks();
}

//
// Sleep for a specified number of milliseconds
//
void I_Sleep( int ms )
{
	SDL_Delay( ms );
}

void I_InitTimer( void )
{
	// initialize timer
	SDL_InitSubSystem( SDL_INIT_TIMER );
}

void I_ShutdownTimer( void )
{
	SDL_QuitSubSystem( SDL_INIT_TIMER );
}
