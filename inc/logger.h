// https://codereview.stackexchange.com/questions/120715/lightweight-logging-library-in-c
#ifndef LOG_H_
#define LOG_H_

//#ifdef __cplusplus
//extern "C" {
//#endif

	typedef enum {
		LOG_ERRORS,
		LOG_EVERYTHING
	} log_level;

	/* configuration */
	void log_init( const char* path, const char* filename, const char* file_extension );
	void set_log_level( log_level level );
	log_level get_log_level();

	/* logging functions */
	void logd( const char* format, ... ); /* debug log */
	void loge( const char* format, ... ); /* error log */

										  /* cleanup / ancillary */
	void flush_log();
	void close_log();

//#ifdef __cplusplus
//}
//#endif

#endif /* LOG_H_ */