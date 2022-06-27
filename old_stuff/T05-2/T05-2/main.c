/*
Caio César Madeira
33A
matricula: 1921050
*/

#include <stdio.h>
#include <stdlib.h> // malloc, sizeof, free inclusas

float * InvertedOrder(float * v, int n)
{
	int i;
	// novo vetor alocado dinamicamente
	float * newV = (float *)malloc(n * sizeof(float));

	// tratamento
	if (newV == NULL)
	{
		return NULL;
	}

	// invertendo a ordem do vetor com a ajuda de um auxiliar, no caso, newV
	for (i = 0; i < n; i++)
	{
		newV[n - 1 - i] = v[i];
	}

	for (i = 0; i < n; i++) {
		v[i] = newV[i];
	}

	return v;
}

int printV(int n, float *v) {

	printf("\nVetor Invertido:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%.1f ", v[i]);
	}

	return 0;
}

int main(void)
{
	float v[] = { 5.0, 10.0, 15.0, 20.0, 30.0 };
	int n = sizeof(v) / sizeof(v[0]);
	float * p;
	printV(n, v);

	p = InvertedOrder(v, n);
	if (p == NULL)
	{
		printf("\nMemoria insuficiente\n");
		exit(1);
	}

	printV(n, v);

	return 0;
}