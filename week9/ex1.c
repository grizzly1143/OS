#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Page {
    int name;
    int number;
};

struct Page * init_page(int name) {
    struct Page * page = malloc(sizeof(struct Page));
    page->name = name;
    page->number = 0 >> 1;
    page->number = (page->number & ~(1 << 1)) | ((1 << 0) & (1 << 1));
    return page;
}

void aging (int * arr, int n, int frames) {
    struct Page pages[frames];
    int count = 0;
    int hit = 0;
    int miss = 0;

    for (int i = 0; i < n; i++) {
        if (count < frames) {
            bool R = false;
            for (int j = 0; j <= count; j++) {
                if (pages[j].name == arr[i]) {
                    hit ++;
                    R = true;
                    pages[j].number = pages[j].number >> 1;
                    pages[j].number = (pages[j].number & ~(1 << 1)) | ((1 << 0) & (1 << 1));
                }
            }
            if (!R) {
                pages[count] = *init_page(arr[i]);
                miss ++;
                count ++;
            }
        } else {
            int min = INT_MAX;
            int ind = 0;
            bool R = false;
            for (int j = 0; j < frames; j++) {
                if (pages[j].name == arr[i]) {
                    hit ++;
                    R = true;
                    pages[j].number = pages[j].number >> 1;
                    pages[j].number = (pages[j].number & ~(1 << 1)) | ((1 << 0) & (1 << 1));
                } else {
                    pages[j].number = pages[j].number >> 1;
                    if (pages[j].number < min) {
                        min = pages[j].number;
                        ind = j;
                    }
                }
            }
            if (!R) {
                miss ++;
                pages[ind] = *init_page(arr[i]);
            }
        }
    }
    printf ("Hit/Miss: %d/%d\n", hit, miss);
}

int main() {
    FILE* file = fopen ("input.txt", "r");
    int i = 0;
    int n = 0;

    int * arr = malloc(sizeof(int));

    while (!feof (file))
    {
        fscanf (file, "%d", &i);
        n ++;
        arr = realloc(arr, sizeof(int) * n);
        arr[n-1] = i;

    }

    printf("Stats for 10: \n");
    aging(arr, n , 10);
    printf("Stats for 50: \n");
    aging(arr, n, 50);
    printf("Stats for 100: \n");
    aging(arr, n, 100);
    return 0;
}
