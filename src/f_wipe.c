#include <string.h>

#include "i_video.h"
#include "m_config.h"
#include "m_random.h"
#include "v_video.h"

//
// SCREEN WIPE PACKAGE
//

static short    *wipe_scr_start;
static short    *wipe_scr_end;
static short    *wipe_scr;
static int      *ypos;
static int      speed;
static short    dest[SCREENAREA];

static void wipe_shittyColMajorXform(short *array)
{
    for (int y = 0; y < SCREENHEIGHT; y++)
        for (int x = 0; x < SCREENWIDTH / 2; x++)
            dest[y + x * SCREENHEIGHT] = array[y * SCREENWIDTH / 2 + x];

    memcpy(array, dest, SCREENAREA);
}

static void wipe_initMelt(void)
{
    speed = (SCREENHEIGHT - (SBARHEIGHT * vid_widescreen)) / 16;

    // copy start screen to main screen
    memcpy(wipe_scr, wipe_scr_start, SCREENAREA);

    // makes this wipe faster (in theory) to have stuff in column-major format
    wipe_shittyColMajorXform(wipe_scr_start);
    wipe_shittyColMajorXform(wipe_scr_end);

    // setup initial column positions (ypos < 0 => not ready to scroll yet)
    ypos = malloc(SCREENWIDTH * sizeof(int));
    ypos[0] = ypos[1] = -(M_Random() % 15);

    for (int i = 2; i < SCREENWIDTH - 1; i += 2)
        ypos[i] = ypos[i + 1] = BETWEEN(-15, ypos[i - 1] + M_Random() % 3 - 1, 0);
}

static void wipe_Melt(int i, int dy)
{
    short   *s = &wipe_scr_end[i * SCREENHEIGHT + ypos[i]];
    short   *d = &wipe_scr[ypos[i] * SCREENWIDTH / 2 + i];

    for (int j = 0, k = dy; k > 0; k--, j += SCREENWIDTH / 2)
        d[j] = *s++;

    ypos[i] += dy;
    s = &wipe_scr_start[i * SCREENHEIGHT];
    d = &wipe_scr[ypos[i] * SCREENWIDTH / 2 + i];

    for (int j = 0, k = SCREENHEIGHT - ypos[i]; k > 0; k--, j += SCREENWIDTH / 2)
        d[j] = *s++;
}

static dboolean wipe_doMelt(void)
{
    dboolean    done = true;

    for (int i = 0; i < SCREENWIDTH / 2; i++)
        if (ypos[i] < 0)
        {
            ypos[i]++;
            done = false;
        }
        else if (ypos[i] < 16)
        {
            wipe_Melt(i, ypos[i] + 1);
            done = false;
        }
        else if (ypos[i] < SCREENHEIGHT)
        {
            wipe_Melt(i, MIN(speed, SCREENHEIGHT - ypos[i]));
            done = false;
        }

    return done;
}

static void wipe_exitMelt(void)
{
    free(ypos);
    free(wipe_scr_start);
    free(wipe_scr_end);
}

void wipe_StartScreen(void)
{
    wipe_scr_start = malloc(SCREENAREA);
    memcpy(wipe_scr_start, screens[0], SCREENAREA);
}

void wipe_EndScreen(void)
{
    wipe_scr_end = malloc(SCREENAREA);
    memcpy(wipe_scr_end, screens[0], SCREENAREA);
    memcpy(screens[0], wipe_scr_start, SCREENAREA);
}

dboolean wipe_ScreenWipe(void)
{
    // when false, stop the wipe
    static dboolean go;

    // initial stuff
    if (!go)
    {
        go = true;
        wipe_scr = (short *)screens[0];
        wipe_initMelt();
    }

    // do a piece of wipe-in
    if (wipe_doMelt())
    {
        // final stuff
        go = false;
        wipe_exitMelt();
    }

    return !go;
}
