#include <unistd.h>
#include <stdio.h>

int main () {
  setvbuf(stdout, 0, _IOLBF, 6);
  printf("H");
  sleep(1);
  printf("e");
  sleep(1);
  printf("l");
  sleep(1);
  printf("l");
  sleep(1);
  printf("o");
}
