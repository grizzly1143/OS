#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SIZE 10485760

int main() {
	for (int i = 0; i < 10; i++) {
	int * mem = malloc(SIZE);
	memset(mem, 0, SIZE);
	sleep(1);}
}
