#include <stdio.h>

int main() {
	char **s = malloc(1);
	char foo[] = "Hello World";
	*s = foo;
	printf("s is %s\n",*s);
	printf("s[0] is %s\n",s[0]);
	return(0);
} 
