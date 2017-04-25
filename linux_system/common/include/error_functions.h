/*************************************************************************
    > File Name: err_functions.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年07月08日 星期五 00时27分24秒
 ************************************************************************/
/* error_functions.h
 *
 *    Header file for error_functions.c.
 *    */
#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

/* Error diagnostic routines */

void errMsg(const char *format, ...);

#ifdef __GNUC__

    /* This macro stops 'gcc -Wall' complaining that "control reaches
		 *        end of non-void function" if we use the following functions to
		 *               terminate main() or some other non-void function. */

#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit(const char *format, ...) NORETURN ;

void err_exit(const char *format, ...) NORETURN ;

void errExitEN(int errnum, const char *format, ...) NORETURN ;

void fatal(const char *format, ...) NORETURN ;

void usageErr(const char *format, ...) NORETURN ;

void cmdLineErr(const char *format, ...) NORETURN ;

#endif
