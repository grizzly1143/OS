#include <stdio.h>

void swap (int * a, int * b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int part (int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void qSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = part(arr, low, high);
        qSort(arr, low, pi - 1);
        qSort(arr, pi + 1, high);
    }
}

int main() {
    int x[9] = {9,8,7,6,5,4,3,2,1};
    printf("Before sort:\n");
    for (int i = 0; i < 9; i++) printf("%d ", x[i]);
    qSort(x, 0, 9);
    printf("\nAfter sort:\n");
    for (int i = 0; i < 9; i++) printf("%d ", x[i]);
    return 0;
}
