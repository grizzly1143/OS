#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

void handler() {
    printf("Stopped.\n");
    exit(0);
}

int main() {
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    pid_t pid1 = 1;
    pid_t pid2 = 1;

    pid1 = fork();
    if (!pid1) {
        pid_t received;
        read(fd1[0], &received, sizeof(received));
        printf("Child 1:PID %d, going to sleep.\n", received);
        sleep(6);
        printf("Child 1: Wake up, stopping process %d\n", received);
        kill(received, SIGSTOP);
        printf("Child 1: Stopped, going to sleep\n");
        sleep(4);
        printf("Child 1: Wake up, resuming process %d\n", received);
        kill(received, SIGCONT);
        printf("Child 1: Resumed, going to sleep\n");
        sleep(4);
        printf("Child 1: Awake, asking process %d to terminate.\n", received);
        kill(received, SIGINT);
        printf("Child 1: Asked process %d to terminate.\n", received);
    } else {
        pid2 = fork();
    }

    if (!pid2) {
        signal(SIGINT, handler);
        while (1) {
            sleep(1);
        }
    }
    if (pid1 && pid2) { // Parent
        printf("Parent: Sending 2nd child PID %d to 1st child\n", pid2);
        write(fd1[1], &pid2, sizeof(pid2));
        close(fd1[1]);
        printf("Parent: Sent PID. Waiting for changes in 2nd child\n");
        waitpid(pid2, 0, 0);
        printf("Parent: 2nd child terminated.");
    }

    return 0;
}
