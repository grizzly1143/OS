#include <float.h>
#include <stdio.h>
#include <limits.h>

int main() {
	int i = 0;
	float f = 0;
	double d = 0;
	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;
	printf("Size of integer is: %lu\n", sizeof(int));
    printf("Size of float is: %lu\n", sizeof(float));
    printf("Size of double is: %lu\n", sizeof(double));
    printf("Value of integer is: %d\n", i);
    printf("Value of float is: %f\n", f);
    printf("Value of double is: %f\n", d);
}
