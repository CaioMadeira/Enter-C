#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"

struct avaliacao
{
	float valorVendidoNoMes;
	int	numeroDeFaltas;
};

struct vendedor
{
	int inscricao;
	char nome[NOME_VENDEDOR_MAX];
	float salário_base;
	Avaliacao aval;
};

float calculaExtra(Avaliacao *aval)
{
	if (aval->numeroDeFaltas < 2 && aval->valorVendidoNoMes > 2000)
	{
		return 180;
	}
	if (aval->numeroDeFaltas >= 2 && aval->numeroDeFaltas < 4 && aval->valorVendidoNoMes > 2000)
	{
		return 150;
	}
	if (aval->numeroDeFaltas >= 4 && aval->numeroDeFaltas < 6 && aval->valorVendidoNoMes > 5000)
	{
		return 120;
	}
	else
	{
		return 0;
	}
}

void calculaValorTotalDaFolha(int num_vendedores, Vendedor *v)
{
	Vendedor *v;
	int i;
	for (i = 0; i < NOME_VENDEDOR_MAX; i++)
	{
		v->nome[i] = malloc(sizeof(char)*NOME_VENDEDOR_MAX);
	}
}

