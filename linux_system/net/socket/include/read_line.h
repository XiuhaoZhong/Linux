/* read_line.h
 *
 * Header file for read_line.c 
 * */

#ifndef __READ_LINE_H__
#define __READ_LINE_H__

#include <sys/types.h>

ssize_t readLine(int fd, void* buffer, size_t n);

#endif // __READ_LINE_H__
