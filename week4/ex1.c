#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    int n = 9;
    if (fork() == 0)
        printf("Hello from child [PID - %d, n - %d]\n", getpid(), n);
    else
        printf("Hello from parent [PID - %d, n - %d]\n", getpid(), n);
    return 0;
}
