#include <stdio.h>


int main2() 
{
	testFunc_getch();
}


int testFunc_getch() 
{
	int c = getch();
	printf("char: %c", c);
}