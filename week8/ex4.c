#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

int main() {
	struct rusage usage;
	for (int i = 0; i < 10; i++) {
		char * mem = (char *) malloc(1024*1024*10);
		memset(mem, 0, 1024*1024*10);
		getrusage(RUSAGE_SELF, &usage);
		printf("Usage is: %ld\n", usage.ru_maxrss);
		sleep(1);
	}
}
