#include <stdio.h>

void swap(int * x, int * y){
    int t = *x;
    *x = *y;
    *y = t;
}

void bubble_sort(int * arr, int size){
    for (int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
        }
    }
}

int main() {
    int x[9] = {9,8,7,6,5,4,3,2,1};
    printf("Before sort:\n");
    for (int i = 0; i < 9; i++) printf("%d ", x[i]);
    bubble_sort(x, 9);
    printf("\nAfter sort:\n");
    for (int i = 0; i < 9; i++) printf("%d ", x[i]);
    return 0;
}
