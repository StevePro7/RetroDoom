//#include "m_misc.h"
//
//int     myargc;
//char    **myargv;
//
////
//// M_CheckParm
//// Checks for the given parameter
//// in the program's command line arguments.
//// Returns the argument number (1 to argc-1)
//// or 0 if not present
////
//int M_CheckParmWithArgs(char *check, int num_args, int start)
//{
//    for (int i = start; i < myargc - num_args; i++)
//        if (M_StringCompare(check, myargv[i]))
//            return i;
//
//    return 0;
//}
//
//int M_CheckParmsWithArgs(char *check1, char *check2, char *check3, int num_args, int start)
//{
//    for (int i = start; i < myargc - num_args; i++)
//        if ((*check1 && M_StringCompare(check1, myargv[i]))
//            || (*check2 && M_StringCompare(check2, myargv[i]))
//            || (*check3 && M_StringCompare(check3, myargv[i])))
//            return i;
//
//    return 0;
//}
//
//int M_CheckParm(char *check)
//{
//    return M_CheckParmWithArgs(check, 0, 1);
//}
