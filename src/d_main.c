#include "d_main.h"

#include <stdio.h>
//
// D_DoomMainSetup
//
// CPhipps - the old contents of D_DoomMain, but moved out of the main
//  line of execution so its stack space can be freed
static void D_DoomMainSetup( void )
{
}

//
// D_DoomMain
//
void D_DoomMain( void )
{
	printf( "doom main\n" );
	D_DoomMainSetup();          // CPhipps - setup out of main execution stack

//	D_DoomLoop();               // never returns
}
