#include<stdlib.h>
#include<stdio.h>

int main(void)
{	
	int ids[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int array_length = sizeof(ids) / sizeof(ids[0]);
	printf("Array length: %d\n", array_length);

	for (int i = 0; i < array_length; ++i)
	{
		if (ids[i] % 2 == 0)
		{
			printf("PAR ID: %d\n", ids[i]);
		}
		else 
		{
			printf("IMPAR ID: %d\n", ids[i]);
		}
	}

	return 0;
}