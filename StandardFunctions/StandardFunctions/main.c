#include <stdio.h>


int main()
{
	//testFunc_getch();
	testFunc_getc()
}

// getch - gets one character typed from terminal
int testFunc_getch()
{
	int c = getch();
	printf("char: %c", c);
	return 0;
}

// getc
int testFunc_getc()
{


	int c = getc(stdin);
	printf("char: %c", c);
	return 0;
}

