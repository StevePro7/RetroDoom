
#if !defined(__I_TIMER_H__)
#define __I_TIMER_H__

// Called by D_DoomLoop,
// returns current time in tics.
int I_GetTime( void );

// returns current time in ms
int I_GetTimeMS( void );

// Pause for a specified number of ms
void I_Sleep( int ms );

// Initialize timer
void I_InitTimer( void );

void I_ShutdownTimer( void );

#endif
