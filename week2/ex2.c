#include <stdio.h>
#include <string.h>

int main() {
	printf ("Write an input string: ");
	char* str;
	scanf("%[^\n]s", str);
	size_t len = strlen(str);
    for (int i = len; i --; i >= 0) {
        printf("%c",str[i]);
    }
}

