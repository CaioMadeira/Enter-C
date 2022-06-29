#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int rows;
	char star = '*';
	printf("Quantas linhas voce quer na sua piramide?\n");
	scanf("%d", &rows);
	puts("");

	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j <= 2 * rows - 1; j++)
		{
			if (j >= rows - (i - 1) && j <= rows + (i - 1))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}