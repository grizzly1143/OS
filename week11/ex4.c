#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int source, out;
    char *src, *dest;
    size_t size;
    source = open("ex1.txt", O_RDONLY);
    size = lseek(source, 0, SEEK_END);
    src = mmap(NULL, size, PROT_READ, MAP_PRIVATE, source, 0);
    out = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(out, size);
    dest = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, out, 0);
    memcpy(dest, src, size);
    munmap(src, size);
    munmap(dest, size);
    close(source);
    close(out);
    return 0;
}
