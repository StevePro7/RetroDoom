#if !defined(__D_MAIN_H__)
#define __D_MAIN_H__


//
// D_DoomMain()
// Not a globally visible function, just included for source reference,
// calls all startup code, parses command line options.
// If not overridden by user input, calls D_AdvanceTitle.
//
void D_DoomMain(void);


#endif
