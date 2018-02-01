#include "ideal_fifo_common.h"

static char client_fifo[IDEAL_FIFO_CLIENT_NAME_LEN];

static void removeFifo() {
	unlink(client_fifo);
}

int main(int argc, char* argv[]) {

	int serverFd, clientFd;

	idealFifoRequest request;
	idealFifoResponse response;

	if (argc > 1 && strcmp(argv[1], "--help" == 0)) {
		printf("parameter error!\n");
		return -1;
	}

	umask(0);

	snprintf(client_fifo, IDEAL_FIFO_CLIENT_NAME_LEN, 
						IDEAL_FIFO_CLIENT, (long) getpid());

	if (mkfifo(client_fifo, S_IRUSR | S_IWUSR | S_IWGRP) == -1
					&& errno != EEXIST) {
		printf("mkfifo client failed!\n");
		return -1;
	}

	if (atexit(removeFifo) != 0) {
		printf("register exit operation failed!\n");
		return -1;
	}

	request.pid = getpid();
	request.seqLen = 99;

	serverFd = open(IDEAL_FIFO_SERVER, O_RDONLY);
	if (serverFd == -1) {
		printf("open ideal_fifo_server failed!\n");
		return -1;
	}
#if 0
	if (write(serverFd, &request, sizeof(idealFifoRequest)) 
					!= sizeof(idealFifoRequest)) {
		printf("write serverFd failed!\n");
		return -1;
	}

	clientFd = open(client_fifo, O_RDONLY);
	if (clientFd == -1) {
		printf("open client_fifo failed!\n");
		return -1;
	}

	if (read(clientFd, &response, sizeof(idealFifoResponse)) 
					!= sizeof(idealFifoResponse)) {
		printf("read clientFd failed!\n");
		return -1;
	} else 
		printf("read result, seq: %d \n", response.seqNum);

	close(clientFd);
	close(serverFd);
#endif 
	return 0;
}
