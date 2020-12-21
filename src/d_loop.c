#include "d_loop.h"
#include "d_ticcmd.h"
#include "doomdef.h"
#include "doomenum.h"
#include "doomvars.h"
//#include "d_main.h"
//#include "doomstat.h"
//#include "g_game.h"
//#include "i_system.h"
#include "i_timer.h"
//#include "m_config.h"
//#include "m_menu.h"

ticcmd_t    localcmds[BACKUPTICS];

void TryRunTics(void)
{
    static int  maketic;
    static int  lastmadetic;
    int         newtics = I_GetTime() - lastmadetic;
    int         runtics;

    lastmadetic += newtics;

    while (newtics--)
    {
        //I_StartTic();		// steveproTODO

        if (maketic - gametime > BACKUPTICS / 2)
            break;

        //G_BuildTiccmd(&localcmds[maketic++ % BACKUPTICS]);		// steveproTODO
    }

    if (!(runtics = maketic - gametime) && vid_capfps != TICRATE)
        return;

    while (runtics--)
    {
        if (advancetitle)
            //D_DoAdvanceTitle();	// steveproTODO

        if (menuactive)
            //M_Ticker();			// steveproTODO

        //G_Ticker();				// steveproTODO
        gametime++;

        if (localcmds[0].buttons & BT_SPECIAL)
            localcmds[0].buttons = 0;
    }
}
