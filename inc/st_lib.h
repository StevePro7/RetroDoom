#if !defined(__ST_LIB_H__)
#define __ST_LIB_H__

////
//// Widget creation, access, and update routines
////
//
//// Initializes widget library.
//// More precisely, initialize STMINUS,
////  everything else is done somewhere else.
////
//// Number widget routines
//void STlib_InitNum(st_number_t *n, int x, int y, patch_t **pl, int *num, int width);
//
//void STlib_UpdateBigNum(st_number_t *n);
//void STlib_UpdateSmallNum(st_number_t *n);
//
//// Percent widget routines
//void STlib_InitPercent(st_percent_t *p, int x, int y, patch_t **pl, int *num, patch_t *percent);
//
//void STlib_UpdatePercent(st_percent_t *per, int refresh);
//
//// Multiple Icon widget routines
//void STlib_InitMultIcon(st_multicon_t *mi, int x, int y, patch_t **il, int *inum);
//
//void STlib_UpdateMultIcon(st_multicon_t *mi, dboolean refresh);
//
//void STlib_UpdateArmsIcon(st_multicon_t *mi, dboolean refresh, int i);

void STLib_Init(void);

#endif
