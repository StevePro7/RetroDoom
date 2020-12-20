# RetroDoom
20/12/2020

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