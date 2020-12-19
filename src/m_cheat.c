#include <ctype.h>
#include <string.h>

#include "c_console.h"
#include "doomdef.h"
#include "doomstat.h"
#include "m_cheat.h"
#include "m_misc.h"

//
// CHEAT SEQUENCE PACKAGE
//

//
// Called in st_stuff module, which handles the input.
// Returns a 1 if the cheat was successful, 0 if failed.
//
char    cheatkey = '\0';

int cht_CheckCheat(cheatseq_t *cht, unsigned char key)
{
    if (*consolecheat && M_StringCompare(consolecheat, cht->sequence))
    {
        consolecheat[0] = '\0';

        if (*consolecheatparm)
        {
            cht->parameter_buf[0] = consolecheatparm[0];
            cht->parameter_buf[1] = consolecheatparm[1];
            cht->param_chars_read = 2;
            consolecheatparm[0] = '\0';
        }

        return true;
    }

    // [BH] you have two seconds to enter all characters of a cheat sequence
    if (cht->timeout && leveltime - cht->timeout > CHEATTIMEOUT)
    {
        cht->chars_read = 0;
        cht->param_chars_read = 0;
    }

    cht->timeout = leveltime;

    if (cht->chars_read < strlen(cht->sequence))
    {
        // still reading characters from the cheat code
        // and verifying. reset back to the beginning
        // if a key is wrong
        if (toupper(key) == toupper(cht->sequence[cht->chars_read]))
            cht->chars_read++;
        else
            // [BH] recognize key as first in sequence if it matches, rather than resetting
            cht->chars_read = (toupper(key) == toupper(cht->sequence[0]));

        cht->param_chars_read = 0;

        if (cht->chars_read > 1 && !cht->movekey)
            cheatkey = key;
    }
    else if (cht->param_chars_read < cht->parameter_chars)
    {
        // we have passed the end of the cheat sequence and are
        // entering parameters now
        if (!isdigit(key))
        {
            cht->chars_read = 0;
            cht->param_chars_read = 0;
            cht->timeout = 0;
            return false;
        }
        else
        {
            cht->parameter_buf[cht->param_chars_read] = key;
            cht->param_chars_read++;
        }
    }

    if (cht->chars_read >= strlen(cht->sequence) && cht->param_chars_read >= cht->parameter_chars)
    {
        cht->chars_read = 0;
        cht->param_chars_read = 0;
        cht->timeout = 0;
        return true;
    }

    // cheat not matched yet
    return false;
}

void cht_GetParam(cheatseq_t *cht, char *buffer)
{
    memcpy(buffer, cht->parameter_buf, cht->parameter_chars);
}
