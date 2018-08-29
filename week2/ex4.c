#include <stdio.h>

void swap (int * num1,int * num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    int a = 0;
    int b = 0;
    printf("Write 2 integers: ");
    scanf("%d %d", &a ,&b);
    swap(&a, &b);
    printf("Swapped integers: %d %d \n", a, b);
}