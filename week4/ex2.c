#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	printf("%d\n", getpid());
	for (int i = 0; i < 3; i++) {
		fork();
		sleep(5);
	}
}
