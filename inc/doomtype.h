
#if !defined(__DOOMTYPE_H__)
#define __DOOMTYPE_H__

#include <inttypes.h>
#include <limits.h>

#include <stdbool.h>		// true + false

typedef uint8_t byte;

#define dboolean bool
//typedef enum
//{
//	false,
//	test
//} dboolean;

#if defined(_WIN32)
#define DIR_SEPARATOR   '\\'
#define DIR_SEPARATOR_S "\\"
#define PATH_SEPARATOR  ';'
#else
#define DIR_SEPARATOR   '/'
#define DIR_SEPARATOR_S "/"
#define PATH_SEPARATOR  ':'
#endif

#define arrlen(array)   (sizeof(array) / sizeof(*array))

#endif