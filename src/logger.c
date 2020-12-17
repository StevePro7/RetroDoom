#include "logger.h"


#include <string.h>
#include <stdio.h>
#include <stdarg.h> 
#include <sys/timeb.h> 
#include <time.h>
#include <assert.h>


#ifdef __linux__ 
#define SEPARATOR ('/')
#elif _WIN32  /* includes windows 64 bit */
#define SEPARATOR ('\\')
#else     
#error Platform not supported
#endif

#define MAX_PATH_LENGTH 512
#define MAX_FILENAME 256
#define MAX_FILE_EXTN 20
#define LOG_FILENAME "program"

static log_level loglevel = LOG_ERRORS;
static char logpath[ MAX_PATH_LENGTH ] = { 0 };
static char filename[ MAX_FILENAME ] = LOG_FILENAME;
static char file_extn[ MAX_FILE_EXTN ] = "log";
static FILE* fp = NULL;

static const char* get_log_filename() {
	return filename;
}

static void set_log_filename( const char* name ) {
	if( name && *name )
		strncpy( filename, name, MAX_FILENAME );
}

static void set_path( const char* path ) {
	int len;
	if( path && *path != '\0' ) {
		strncpy( logpath, path, MAX_PATH_LENGTH );
		len = strlen( logpath );
		if( len > 0 && logpath[ len - 1 ] != SEPARATOR )
			logpath[ len ] = SEPARATOR;
	}
}

static const char* get_path() {
	if( !logpath ) {
		sprintf( logpath, ".%c", SEPARATOR );
	}
	return logpath;
}

static char* get_append_name( char* buf ) {
	time_t now;
	time( &now );
	strftime( buf, 20, "%y%m%d", localtime( &now ) );
	return buf;
}

static const char* get_log_filename_extension() {
	return file_extn ? file_extn : "";
}

static void set_log_filename_extension( const char* name ) {
	if( name && *name != '\0' )
		strncpy( file_extn, name, MAX_FILE_EXTN );
}

static char* construct_full_path( char* path ) {
	char append[ 20 ] = { 0 };
	sprintf( path, "%s%s%s.%s", get_path(), get_log_filename(), get_append_name( append ), get_log_filename_extension() );
	return path;
}

void log_init( const char* path, const char* filename, const char* file_extension ) {
	char fullpath[ MAX_PATH_LENGTH ];
	//if( path && *path != '\0' && filename && *filename != '\0' ) {
	if( filename && *filename != '\0' ) {
		//set_path( path );
		set_log_filename( filename );
		set_log_filename_extension( file_extension );
		fp = fopen( construct_full_path( fullpath ), "a" );
		assert( fp != NULL );
		/* just in case fopen fails, revert to stdout */
		if( fp == NULL ) {
			fp = stdout;
			fprintf( fp, "Failed to change logging target\n" );
		}
	}
	else {
		if( fp != NULL && fp != stdout )
			fclose( fp );

		fp = stdout;
	}
}

static char* get_timestamp( char* buf ) {
	int bytes;
	struct timeb start;
	ftime( &start );
	bytes = strftime( buf, 20, "%H:%M:%S", localtime( &start.time ) );
	sprintf( &buf[ bytes ], ".%03u", start.millitm );
	return buf;
}

void set_log_level( log_level level ) {
	loglevel = level;
}

log_level get_log_level() {
	return loglevel;
}

void logd( const char* format, ... ) {
	char tmp[ 50 ] = { 0 };
	if( loglevel > 0 ) {
		va_list args;
		va_start( args, format );
		fprintf( fp, "%s ", get_timestamp( tmp ) );
		vfprintf( fp, format, args );
		va_end( args );
	}
}

void loge( const char* format, ... ) {
	char tmp[ 50 ] = { 0 };
	va_list args;
	va_start( args, format );
	fprintf( fp, "%s ", get_timestamp( tmp ) );
	vfprintf( fp, format, args );
	va_end( args );
	fflush( fp );
}

void flush_log() {
	fflush( fp );
}

void close_log() {
	if( fp != stdout )
		fclose( fp );
	fp = NULL;
}