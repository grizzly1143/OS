#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g = 0;

void *ThreadNumber() {
    printf("Thread number is: %d\n", g++);
}

int main() {
    int i;
    pthread_t tid;
    for (i = 0; i < 4; i++) {
	printf("Thread #%d is created!\n", i);
        pthread_create(&tid, NULL, ThreadNumber	, NULL);
    }
    pthread_exit(NULL);
    return 0;
}
