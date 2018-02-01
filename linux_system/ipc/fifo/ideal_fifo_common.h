#ifndef _IDEAL_FIFO_COMMON_H_
#define _IDEAL_FIFO_COMMON_H_

#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

/* fifo server */
#define IDEAL_FIFO_SERVER "/tmp/fifo_server"

/* fifo client. maybe several, ending with client's pid */
#define IDEAL_FIFO_CLIENT "/tmp/fifo_client.ld%"

#define IDEAL_FIFO_CLIENT_NAME_LEN (sizeof(IDEAL_FIFO_CLIENT) + 20)

typedef struct request {
	pid_t pid;
	int seqLen;
} idealFifoRequest;

typedef struct {
	int seqNum;
} idealFifoResponse;

#endif // _IDEAL_FIFO_COMMON_H_
