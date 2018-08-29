#include <stdio.h>

void right_triangle (int n) {
    for (int i = 1;  i <= n; i++) {
        for (int j = 0;  j < i ; j++) printf("%c",'*');
        printf("\n");
    }
}

void rectangle (int n) {
    for (int i = 1;  i <= n; i++) {
        for (int j = 0;  j < n ; j++) printf("%c",'*');
        printf("\n");
    }
}

void isosceles_triangle (int n) {
    int side  = (int)((n-1)/2);
    for (int i = 1;  i <= side; i++) {
        for (int j = 0;  j < i ; j++) printf("%c",'*');
        printf("\n");
    }
    for (int i = 0;  i < side + 1 ; i++) printf("%c",'*');
    printf("\n");
    for (int i = side;  i > 0; i--) {
        for (int j = 0;  j < i ; j++) printf("%c",'*');
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int n = 0;
    if (argc > 2) {
        printf("There must be only one argument!\n");
        return 0;
    }
    n = atoi(argv[1]);
    printf ("What figure do u want to draw?\n1 - Right triangle\n2 - Isosceles triangle\n3 - Rectangle\n");
    int fig = 0;
    scanf("%d", &fig);
    if (fig == 1) right_triangle(n);
    if (fig == 2) isosceles_triangle(n);
    if (fig == 3) rectangle(n);
    return 0;
}