/*
Caio César Madeira
Matrícula: 1921050
33A
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 11
//para testes
//#define TAM 50
//#define TAM 6

int aleatorio(int, int);
void iniciar_aleatorio(void);
int maxMin(int * v);
int print(int * v);
int * randomVector(int * v);

int main(void)
{
	int v[TAM];
	int * result;

	iniciar_aleatorio();
	result = randomVector(v);
	if (result == NULL)
	{
		exit(1);
	}

	print(result);
	maxMin(result);

	//free(result);
	return 0;
}

int maxMin(int * v)
{
	for (int i = 1; i < TAM; ++i) {
		if (v[0] < v[i]) {
			v[0] = v[i];
		}
	}

	printf("\nMaior elemento: %d", v[0]);

	for (int i = 1; i < TAM; ++i) {
		if (v[0] > v[i]) {
			v[0] = v[i];
		}
	}

	printf("\nMenor elemento: %d", v[0]);

	return 0;
}

int print(int * v)
{
	printf("\nVetor aleatorio gerado:");
	for (int i = 0; i < TAM; i++)
	{
		printf("%d ", v[i]);
	}

	return 0;
}

int * randomVector(int * v) {
	int a, b, c;
	int i;
	a = 1;
	b = 60;

	int * p = (int *)malloc(TAM * sizeof(int));
	if (p == NULL)
	{
		return NULL;
	}
	p = v;

	for (i = a; i < TAM; i++) 
	{
		c = aleatorio(a, b);
		p[i] = c;
		p[i - 1] = p[i];
	}

	return p;
}

void iniciar_aleatorio(void)
{
	srand((unsigned int)time(NULL));
	rand(); rand(); rand();
}
int aleatorio(int a, int b)
{
	double r;
	r = (double)rand() / RAND_MAX;
	return (int)(a + r * (b - a));
}