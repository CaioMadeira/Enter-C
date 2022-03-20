#include <stdio.h>

int main(void) {

	int x, y;
	int * p;
	x = 5;
	p = &x;
	printf("address x:  %08X(%d)\n", &x, (long long)&x);
	p = &y;
	printf("address y:  %08X(%d)\n", &y, (long long)&y);
	printf("address p: %08X(%d)\n\n\n", p, (long long)p);

	printf("content of x: (%d)\ncontent of y: (%d)\ncontent of p: (%p)", x, y, p);

	printf("\n\ncontent of y int *p: %d", *p);

	p = p + 1;

	printf("\n\naddress subsequent of p: %p(%11d)", p, (long long)p);
	printf("\n\nnew adress of p: %08X", p);
	printf("\nnew *p: %d",*p);

}