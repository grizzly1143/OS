#include <stdlib.h>
#include <stdio.h>

int main() {
	int n;
	printf("Write a number: ");
	scanf("%d", &n);
	int * arr = (int *) malloc(sizeof(int));
	for (int i = 0; i < n; i++) {
		arr = (int *) realloc(arr, sizeof(int) * (i + 1));
		arr[i] = i;
		for (int j = 0; j <= i; j++) printf("%d ", arr[j]);
		printf ("\n");
	}
	free(arr);
}
