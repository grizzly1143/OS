#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_KILL () {
	printf("I always feel like SIGKILL!");
	exit(0);
}

void handler_STOP () {
	printf("I always feel like SIGSTOP!");
	exit(0);
}

void handler_USR1 () {
	printf("I always feel like SIGUSR1!");
	exit(0);
}

int main() {
	   printf("%d\n", getpid());
	signal(SIGKILL, handler_KILL);
	signal(SIGSTOP, handler_STOP);
	signal(SIGUSR1, handler_USR1);
     while (1)
          pause();
     return 0;
}
