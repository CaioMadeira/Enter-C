/*

for(initialization; condition; increment/decrement)
{
	STATEMENTS;
}

*/

#include <stdio.h>

int main(void)
{

	// increment example
	printf("Increment example: \n");
	for (int i = 1; i < 4; i++)
	{
		printf("%d\n", i);
	}

	printf("Decrement example: \n");
	// decrement example
	for (int i = 3; i > 0; i--)
	{
		printf("%d\n", i);
	}

	return 0;
}