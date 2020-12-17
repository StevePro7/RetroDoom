
#if !defined(__DSTRINGS_H__)
#define __DSTRINGS_H__

// All important printed strings.
#include "d_englsh.h"

// Misc. other strings.
#define SAVEGAMENAME        "doomsav"

// QuitDOOM messages
// 8 per each game type
#define NUM_QUITMESSAGES    8

// DOOM1
#define DOOM_ENDMSG1        "please don't leave, there's more\ndemons to toast!"
#define DOOM_ENDMSG2        "let's beat it -- this is turning\ninto a bloodbath!"
#define DOOM_ENDMSG3        "i wouldn't leave if i were you.\ndos is much worse."
#define DOOM_ENDMSG4        "you're trying to say you like dos\nbetter than me, right?"
#define DOOM_ENDMSG5        "don't leave yet -- there's a\ndemon around that corner!"
#define DOOM_ENDMSG6        "ya know, next time you come in here\ni'm gonna toast ya."
#define DOOM_ENDMSG7        "go ahead and leave. see if i care."

// QuitDOOM II messages
#define DOOM2_ENDMSG1       "you want to quit?\nthen, thou hast lost an eighth!"
#define DOOM2_ENDMSG2       "don't go now, there's a \ndimensional shambler waiting\nat the dos prompt!"
#define DOOM2_ENDMSG3       "get outta here and go back\nto your boring programs."
#define DOOM2_ENDMSG4       "if i were your boss, i'd \n deathmatch ya in a minute!"
#define DOOM2_ENDMSG5       "look, bud. you leave now\nand you forfeit your body count!"
#define DOOM2_ENDMSG6       "just leave. when you come\nback, i'll be waiting with a bat."
#define DOOM2_ENDMSG7       "you're lucky i don't smack\nyou for thinking about leaving."

extern char **endmsg[];

#endif
