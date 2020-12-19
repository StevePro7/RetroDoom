#if !defined(__WI_STUFF_H__)
#define __WI_STUFF_H__

// States for the intermission
typedef enum
{
    NoState = -1,
    StatCount,
    ShowNextLoc
} stateenum_t;

// Called by main loop, animate the intermission.
void WI_Ticker(void);

// Called by main loop,
// draws the intermission directly into the screen buffer.
void WI_Drawer(void);

// Setup for an intermission screen.
void WI_Start(wbstartstruct_t *wbstartstruct);

// Shut down the intermission screen
void WI_End(void);

#endif
