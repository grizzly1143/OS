#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
   	char command[20];
	printf("Type a command: ");
	fgets(command, sizeof(command), stdin);
    while (strcmp(command, "exit\n") != 0) {
		system(command);
		printf("Type a command: ");
		fgets(command, sizeof(command), stdin);
		printf("\n");
    }
    return 0;
}
