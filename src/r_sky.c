#include "r_sky.h"
#include "doomdef.h"
#include "doomvars.h"
#include "m_controls.h"
#include "p_setup.h"
#include "r_data.h"

//#include "c_console.h"
//#include "doomstat.h"
//#include "m_config.h"

//#include "r_main.h"


//
// sky mapping
//
//int         skyflatnum;
//int         skytexture;
//int         skytexturemid;
int         skycolumnoffset = 0;
//int         skyscrolldelta;

//fixed_t     skyiscale;
dboolean    canmouselook = false;

void R_InitSkyMap(void)
{
    int map = (gameepisode - 1) * 10 + gamemap;

    skyflatnum = R_FlatNumForName(SKYFLATNAME);
    skytexture = P_GetMapSky1Texture(map);
    canmouselook = ((mouselook || keyboardmouselook || mousemouselook != -1 || autotilt) && !nomouselook);

    if (!skytexture || (BTSX && !canmouselook))
    {
        if (gamemode == commercial)
        {
            if (gamemission == pack_nerve)
            {
                if (gamemap < 4 || gamemap == 9)
                    skytexture = R_TextureNumForName("SKY1");
                else
                    skytexture = R_TextureNumForName("SKY3");
            }
            else
            {
                if (gamemap < 12)
                    skytexture = R_TextureNumForName("SKY1");
                else if (gamemap < 21)
                    skytexture = R_TextureNumForName("SKY2");
                else
                    skytexture = R_TextureNumForName("SKY3");
            }
        }
        else
        {
            switch (gameepisode)
            {
                default:
                case 1:
                    skytexture = R_TextureNumForName("SKY1");
                    break;

                case 2:
                    skytexture = R_TextureNumForName("SKY2");
                    break;

                case 3:
                    skytexture = R_TextureNumForName("SKY3");
                    break;

                case 4:
                    skytexture = R_TextureNumForName("SKY4");
                    break;

                case 5:
                    skytexture = R_TextureNumForName(R_CheckTextureNumForName("SKY5_ZD") != -1 ? "SKY5_ZD" : "SKY5");
                    break;
            }
        }
    }

    skyscrolldelta = P_GetMapSky1ScrollDelta(map);

    if (canmouselook)
    {
        int skyheight = textureheight[skytexture] >> FRACBITS;

        if (skyheight >= 128 && skyheight < VANILLAHEIGHT)
            skytexturemid = -54 * FRACUNIT * skyheight / SKYSTRETCH_HEIGHT;
        else if (skyheight > VANILLAHEIGHT)
            skytexturemid = (VANILLAHEIGHT - skyheight) * FRACUNIT * skyheight / SKYSTRETCH_HEIGHT;
        else
            skytexturemid = 0;

        skyiscale = (fixed_t)(((uint64_t)SCREENWIDTH * VANILLAHEIGHT * FRACUNIT) / ((uint64_t)viewwidth * SCREENHEIGHT))
            * skyheight / SKYSTRETCH_HEIGHT;
    }
    else
    {
        skytexturemid = VANILLAHEIGHT / 2 * FRACUNIT;
        skyiscale = (fixed_t)(((uint64_t)SCREENWIDTH * VANILLAHEIGHT * FRACUNIT) / ((uint64_t)viewwidth * SCREENHEIGHT));
    }

    if (consoleactive)
        forceconsoleblurredraw = true;
}
