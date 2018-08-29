#include <stdio.h>

int main(int argc, char* argv[]) {
    int n = 0;
    if (argc > 2) {
        printf("There must be only one argument!\n");
        return 0;
    }
    n = atoi(argv[1]);
    for (int i = 1;  i < n; i++) {
        printf("%*c", (n-i), ' ');
        for (int j = 0;  j < 2*i -1; j++) printf("%c", '*');
        printf("%*c\n", (n-i), ' ');
    }
    for (int j = 0;  j < 2*n -1; j++) printf("%c", '*');
}


