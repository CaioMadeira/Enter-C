#include <stdio.h>

int main(void) {

	unsigned int a;
	unsigned int * p;
	a = 0xFFFFFFF9;
	p = &a;

	printf("a (decimal unsigned): %u\n", a);
	printf("a (decimal signed): %d\n", (short int)a);
	printf("a (variable address in memory): %p(%u)\n", p, (long long)p);
}