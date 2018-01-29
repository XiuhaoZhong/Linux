#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static void* threadFunc(void *arg) {
	char *s = (char*) arg;

	printf("%s", s);

	return (void*) strlen(s);
}

int main(int argc, char *argv[]) {
	pthread_t t1;
	void* res;
	int s;

	s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
	if (s != 0) {
		printf("pthread_create error!\n");
	}

	printf("Message from main()\n");
	s = pthread_join(t1, &res);
	if (s != 0)
		printf("pthread_join error!\n");

	printf("Thread returnd %ld\n", (long) res);

	exit(EXIT_SUCCESS);
}
