/*

1. Faça uma função que retorna a soma, a diferença e o produto entre dois números. Os resultados devem retornar por
parâmetros passados por referência.

*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int* n1, n2;
	int op = 1;

	printf("Digite o primeiro numero: ");
	scanf("%d", &n1);
	puts("");

	printf("Digite o segundo numero: ");
	scanf("%d", &n2);
	puts("");

	basicOperations(n1, n2, op);
	return 0;
}

int* basicOperations(int op, int* n1, int* n2)
{	
	int calc;

	if (op == 1)
	{
		printf("Soma:\n");
		calc = &n1 + &n2;
	}
}