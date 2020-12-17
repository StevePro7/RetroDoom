
#if !defined(__M_MISC_H__)
#define __M_MISC_H__

#include <stdio.h>
#include <stdlib.h>

#if defined(__OpenBSD__) || defined(__NetBSD__)
#include <stdarg.h>
#endif

#include "doomtype.h"

void M_MakeDirectory( const char *path );
dboolean M_FileExists( const char *filename );
dboolean M_FolderExists( const char *folder );
char *M_ExtractFolder( char *path );

#if !defined(_WIN32) && !defined(__APPLE__)
char *M_FileCaseExists( const char *path );
#endif

// Returns the file system location where application resource files are located.
// On Windows and Linux, this is the folder in which doomretro.exe is located;
// on macOS, this is the Contents/Resources folder within the application bundle.
char *M_GetResourceFolder( void );

// Returns the file system location where generated application
// data (configuration files, logs, savegames etc.) should be saved.
// On Windows and Linux, this is the folder in which doomretro.exe is located;
// on macOS, this is ~/Library/Application Support/DOOM Retro/.
char *M_GetAppDataFolder( void );

char *M_GetExecutableFolder( void );
dboolean M_StrToInt( const char *str, unsigned int *result );
const char *M_StrCaseStr( const char *haystack, const char *needle );
void M_StringCopy( char *dest, const char *src, const size_t dest_size );
char *M_StringReplace( char *haystack, char *needle, char *replacement );
char *M_TempFile( char *s );
char *M_StringJoin( char *s, ... );
dboolean M_StringStartsWith( const char *s, const char *prefix );
dboolean M_StringStartsWithExact( const char *s, const char *prefix );
dboolean M_StringEndsWith( const char *s, const char *suffix );
void M_vsnprintf( char *buf, int buf_len, const char *s, va_list args );
void M_snprintf( char *buf, int buf_len, const char *s, ... );
char *M_SubString( const char *str, size_t begin, size_t len );
char *M_StringDuplicate( const char *orig );
dboolean M_StringCompare( const char *str1, const char *str2 );
char *uppercase( const char *str );
char *lowercase( char *str );
char *titlecase( const char *str );
char *sentencecase( const char *str );
char *commify( int64_t value );
char *uncommify( const char *input );
dboolean wildcard( char *input, char *pattern );
int gcd( int a, int b );
int numspaces( char *str );
char *removespaces( const char *input );
char *removenonalpha( const char *input );
char *trimwhitespace( char *input );
char *makevalidfilename( const char *input );
char *leafname( char *path );
char *removeext( const char *file );
dboolean isvowel( const char ch );
dboolean ispunctuation( const char ch );
dboolean isbreak( const char ch );
char *striptrailingzero( float value, int precision );
void strreplace( char *target, char *needle, const char *replacement );
int hextodec( char *hex );
void M_StripQuotes( char *string );

#endif
