#include "ideal_fifo_common.h"

int main() {

	int serverFd, dummyFd, clientFd;
	char client_fifo[IDEAL_FIFO_CLIENT_NAME_LEN];

	idealFifoRequest request;
	idealFifoResponse response;

	int seqNum = 0;

	umask(0);

	if (mkfifo(IDEAL_FIFO_SERVER, S_IRUSR | S_IWUSR | S_IWGRP) == -1 
					&& errno != EEXIST) {
		printf("mkfifo server failed!\n");
		return -1;
	}

	serverFd = open(IDEAL_FIFO_SERVER, O_WRONLY);
	if (serverFd == -1) {
		printf("open ideal server failed!\n");
		return -1;
	} else {
		printf("open ideal server success!\n");
	}
		
	printf("already open the IDEAL_FIFO_SERVER\n");

	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		return -1;

	if (write(serverFd, &request, sizeof(idealFifoRequest)) 
					!= sizeof(idealFifoRequest)) {
		printf("write to serverFd failed!\n");
	}

	printf("Have already write to serverFd!\n");

/*	for (;;) {
		if (read(serverFd, &request, sizeof(idealFifoRequest)
					!= sizeof(idealFifoRequest))) {
			printf("read serverFd failed! continue!\n");
			continue;
		}

		sprintf(client_fifo, IDEAL_FIFO_CLIENT, 
						IDEAL_FIFO_CLIENT_NAME_LEN, (long) request.pid);

		clientFd = open(client_fifo, O_WRONLY);
		if (clientFd == -1) {
			printf("open client fifo failed! continue!\n");
			continue;
		}
	
		response.seqNum = seqNum++;
		if (write(clientFd, &response, sizeof(idealFifoResponse)) 
						!= sizeof(idealFifoResponse)) {
			printf("write clientFd failed! continue\n");
			continue;
		}

		if (close(clientFd) == -1) 
			printf("close clientFd failed!\n");
	}*/

	close(serverFd);
	return 0;
}
