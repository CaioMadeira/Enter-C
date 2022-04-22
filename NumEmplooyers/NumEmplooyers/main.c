/* 
Caio Madeira
1921050
caiomadeira@inf.puc-rio.br
*/


#include <stdio.h>
#include <stdlib.h>

int * criaVetSalAcima(int numEmpregados, int vInscricaoEmpregados, int)
{

}

int main(void)
{
	int i;
	float s;
	int numEmpregados;
	int vInscricaoEmpregados[100] = { 4555, 6888, 5777 };
	float vSalEmpregados[100] = { 3400.00, 5800.00, 2480.00 };

	printf("Entre com o número de empregados:\n");
	scanf("%d", &numEmpregados);

	printf("NUMERO DE EMPREGADOS: %d\n", numEmpregados);
	for (i = 0; i < numEmpregados; i++)
	{
		printf("INSC: %d - SAL: %.2f\n", vInscricaoEmpregados[i], vSalEmpregados[i]);
	}

	return 0;
}