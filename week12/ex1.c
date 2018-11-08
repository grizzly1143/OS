#include <string.h>
#include <stdio.h>

int main()
{
  FILE* fp = fopen("/dev/urandom", "r");
  int i = 0;
  while (i < 20)
  {
    char ch;
    fscanf(fp, "%c", &ch);
    if ((int)ch >= 33 && (int)ch <=127) {
    printf("%c", ch);
    i++;
  }
  }
  printf("\n");
  fclose(fp);
  return 0;
}
