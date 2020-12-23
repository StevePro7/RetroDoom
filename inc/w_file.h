#if !defined(__W_FILE_H__)
#define __W_FILE_H__

#include "doomstruct.h"
#include "doomtype.h"
#include <stdio.h>

#if defined(__OpenBSD__)
#include <stdio.h>
#endif

#if !defined(MAX_PATH)
#define MAX_PATH    260
#endif

//typedef struct wadfile_s wadfile_t;
//
//struct wadfile_s
//{
//    FILE        *fstream;
//    dboolean    freedoom;
//    char        path[MAX_PATH];
//    int         type;
//};

// Open the specified file. Returns a pointer to a new wadfile_t
// handle for the WAD file, or NULL if it could not be opened.
wadfile_t *W_OpenFile(char *path);

// Close the specified WAD file.
void W_CloseFile(wadfile_t *wad);

// Read data from the specified file into the provided buffer. The
// data is read from the specified offset from the start of the file.
// Returns the number of bytes read.
size_t W_Read(wadfile_t *wad, unsigned int offset, void *buffer, size_t buffer_len);

dboolean W_WriteFile(char const *name, const void *source, size_t length);

#endif
