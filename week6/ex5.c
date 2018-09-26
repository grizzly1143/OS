#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void handle ()
{
    printf("I'm not alive!");
	exit(0);
}

int main()
{
    signal(SIGTERM,handle);

    pid_t pid2 = fork(); 
    if (pid2==0)
    {
        while (1){
		printf ("I'm alive\n");
		sleep(1);
            }
    }
    else {
	sleep(10);
	kill(pid2,SIGTERM);
    }

    return 0;
}
