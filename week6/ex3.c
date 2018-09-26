#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler () {
	printf("Don't kill me master!");
	exit(0);
}

int main() {
	signal(SIGINT, handler);
     while (1)
          pause();
     return 0;
}
