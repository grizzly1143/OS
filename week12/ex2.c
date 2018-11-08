#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char c;
    int mode = 0;
    while ((c = getopt(argc, argv, "a")) != -1) {
        switch (c) {
            case 'a':
                mode = 1;
                break;
            case '?':
                if (isprint(optopt))
                    fprintf(stderr, "This is the unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr, "This is th unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                abort();
        }
    }
    int i;
    FILE *f[20];
    int n;
    char buffer[100];
    size_t l;
    char *fm;
    fm = (mode ? "a" : "w");
    n = argc - optind;
    if (n > 0) {
        for (i = optind; i < argc; i++) {
            FILE *pFile = fopen(argv[i], fm);
            f[i - optind] = pFile;
        }
    }
    FILE *not_stdin = fopen("tee.c", "r");
    while ((l = fread(&buffer[0], 1, sizeof(buffer), not_stdin)) > 0) {
        fwrite(&buffer[0], 1, l, stdout);
        for (i = 0; i < n; i++) {
            fwrite(&buffer[0], 1, l, f[i]);
        }
    }
    return 0;
}
