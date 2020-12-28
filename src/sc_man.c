#include "sc_man.h"
#include "doomvars.h"

#include "logger.h"
#include "i_system.h"
#include "m_misc.h"
#include "w_wad.h"
#include "z_zone.h"

#define MAX_STRING_SIZE 1024
#define ASCII_COMMENT1  ';'
#define ASCII_COMMENT2  '/'
#define ASCII_QUOTE     '"'
#define ASCII_ESCAPE    '\\'

//char            *sc_String;
//int             sc_Number;
//int             sc_Line;

static char     *ScriptBuffer;
static char     *ScriptPtr;
static char     *ScriptEndPtr;
static int      ScriptLumpNum;
static dboolean sc_End;
static dboolean ScriptOpen;
static dboolean AlreadyGot;

void SC_Open( char *name )
{
	static char StringBuffer[ MAX_STRING_SIZE ];

	SC_Close();
	ScriptLumpNum = W_GetNumForName( name );
	ScriptBuffer = W_CacheLumpNum( ScriptLumpNum );
	ScriptPtr = ScriptBuffer;
	ScriptEndPtr = ScriptPtr + W_LumpLength( ScriptLumpNum );
	sc_Line = 1;
	sc_End = false;
	ScriptOpen = true;
	sc_String = StringBuffer;
	AlreadyGot = false;
}

void SC_Close( void )
{
	if( ScriptOpen )
	{
		if( ScriptLumpNum >= 0 )
			W_ReleaseLumpNum( ScriptLumpNum );
		else
			Z_Free( ScriptBuffer );

		ScriptOpen = false;
	}
}

dboolean SC_GetString(void)
{
    char        *text;
    dboolean    foundToken = false;

    if (AlreadyGot)
    {
        AlreadyGot = false;
        return true;
    }

    if (ScriptPtr >= ScriptEndPtr)
    {
        sc_End = true;
        return false;
    }

    while (!foundToken)
    {
        while (ScriptPtr < ScriptEndPtr && (*ScriptPtr <= 32 || *ScriptPtr == '=' || *ScriptPtr == ','))
            if (*ScriptPtr++ == '\n')
                sc_Line++;

        if (ScriptPtr >= ScriptEndPtr)
        {
            sc_End = true;
            return false;
        }

        if (*ScriptPtr != ASCII_COMMENT1 && *ScriptPtr != ASCII_COMMENT2 && *(ScriptPtr + 1) != ASCII_COMMENT2)
            foundToken = true;
        else
        {
            while (*ScriptPtr++ != '\n')
                if (ScriptPtr >= ScriptEndPtr)
                {
                    sc_End = true;
                    return false;
                }

            sc_Line++;
        }
    }

    text = sc_String;

    if (*ScriptPtr == ASCII_QUOTE)
    {
        ScriptPtr++;

        while (*ScriptPtr != ASCII_QUOTE || *(ScriptPtr - 1) == ASCII_ESCAPE)
        {
            if (*ScriptPtr != ASCII_ESCAPE)
                *text++ = *ScriptPtr++;
            else
                ScriptPtr++;

            if (ScriptPtr == ScriptEndPtr || text == &sc_String[MAX_STRING_SIZE - 1])
                break;
        }

        ScriptPtr++;
    }
    else
        while (*ScriptPtr > 32 && *ScriptPtr != ASCII_COMMENT1 && *ScriptPtr != ASCII_COMMENT2 && *(ScriptPtr + 1) != ASCII_COMMENT2)
        {
            if (*ScriptPtr == '{' || *ScriptPtr == '}')
                ScriptPtr++;

            *text++ = *ScriptPtr++;

            if (*ScriptPtr == '=' || *ScriptPtr == ',')
            {
                ScriptPtr++;
                break;
            }

            if (ScriptPtr == ScriptEndPtr || text == &sc_String[MAX_STRING_SIZE - 1])
                break;
        }

    *text = '\0';
    return true;
}

void SC_MustGetString( void )
{
	if( !SC_GetString() )
		SC_ScriptError();
}

dboolean SC_GetNumber(void)
{
    if (SC_GetString())
    {
        sc_Number = strtol(sc_String, NULL, 0);
        return true;
    }
    else
        return false;
}

void SC_MustGetNumber(void)
{
    if (!SC_GetNumber())
        SC_ScriptError();
}

void SC_UnGet( void )
{
	AlreadyGot = true;
}

int SC_MatchString( char **strings )
{
	for( int i = 0; *strings; i++ )
		if( SC_Compare( *strings++ ) )
			return i;

	return -1;
}

dboolean SC_Compare( char *text )
{
	return M_StringCompare( text, sc_String );
}

static void SC_ScriptError( void )
{
	char    *temp = commify( sc_Line );

	//C_Warning( 1, "Line %s in the <b>MAPINFO</b> lump is invalid.", temp );
	loge( "Line %s in the <b>MAPINFO</b> lump is invalid.\n", temp );
	free( temp );
}
