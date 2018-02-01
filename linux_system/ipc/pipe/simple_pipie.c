#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUF_SIZE 100

int main() {

	int fields[2];
	ssize_t  len = 0;
	char buf[10];
	char content[30] = "iopasdfghjklzxcvbnm,;p[-0987";

	if (pipe(fields) == -1) {
		printf("pipe() error!\n");
		return -1;
	}

	len = write(fields[1], content, sizeof(content));
	printf("write to pipe %d, content : %s\n", len, content);

	len = read(fields[0], buf, sizeof(buf));
	printf("read from pipe, len : %d, content : %s\n", len, buf);

	len = read(fields[0], buf, sizeof(buf));
	printf("read from pipe, len : %d, content : %s\n", len, buf);


	return 0;
}
