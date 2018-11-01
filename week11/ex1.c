#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
		struct stat fileStat;
    int fptr = open("ex1.txt", O_RDWR);
		stat("ex1.txt", &fileStat);
		off_t myfsz = fileStat.st_size;
		char * day = "This is a nice day";
		char * ad = mmap(NULL, myfsz, PROT_READ|PROT_WRITE, MAP_SHARED, fptr, 0);
		memcpy(ad, day, strlen(day) + 1);
    return 0;
}
