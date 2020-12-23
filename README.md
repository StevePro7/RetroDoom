# RetroDoom
23/12/2020

Read the WAD file:
wadinfo_t       header;		12x bytes
04:	IWAD
04:	F0 04 00 00	000004F0	1264	numlumps
04: B4 B7 3F 00	003FB7B4	4175796	infotableofs


int	4x bytes
filelump_t		16x bytes
length			16x bytes * numlumps	20224

lumpinfo_t


003FB7B4	4175796	infotableofs
this is the start of file_lump_t
PLAYPAL
COLORMAP
ENDDOOM


22/12/2020

I *found* out why the extern is in one central header file but the implementations
are dispersed in various other header files esp. when the variable has a default value:
e.g.
r_lowpixelsize
v_video.c

There is code in v_video.c that queries r_lowpixelsize so the default value must be
set in the same file
However, I *believe* the same implementation can be actioned in multiple *.c files
so you don't have to risk having a potential cyclical dependency later...??


20/12/2020

c_console.c
KEY_ENTER


a_game.c
WndProc
for functions that are called here follow the example from VCPP
declare the function as extern in a_game.h before CALLBACK

define the function in the C file but do not #include to "avoid"
cyclical dependency
e.g.
MouseShouldBeGrabbed()



19/12/2020
remove all the code but get linker error so switch to Console app
Project properties | Linker | System | Console
will have to "eventually" switch back to Windows

Weird - sometimes when reference dboolean and #include "doomtype.h"
still get squiggle under true but when F12 and navigate they go away



Test repository remake of Retro Doom source code

Original source code can be found here:
https://github.com/bradharding/doomretro

id-software
https://github.com/id-Software/DOOM

Game Engine Black Book: DOOM
https://archive.org/details/gebbdoome/page/394/mode/2up
https://github.com/fabiensanglard/gebbdoom
https://fabiensanglard.net/gebbdoom.pdf