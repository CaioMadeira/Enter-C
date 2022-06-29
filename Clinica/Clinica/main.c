#include <stdio.h>
#include <stdlib.h>
#include "clinica_auxiliar.h"

struct medico
{
	char nomeDoMed[51];     /* nome do medico */
	float valorDaConsulta;  /* valor da consulta com esse medico */
	Medico  *prox;          /* ponteiro para o pr�ximo m�dico da lista */
};

struct especialidade
{
	char   nomeEsp[21];   /*nome da especialidade */
	Medico *lstMedicos;  /* ponteiro para o primeiro n� de uma lista
							simplesmente encadeada de m�dicos dessa especialidade */
};

int main(void)
{

	Medico * medico_inicio;
	Medico * medico_prox;

	medico_inicio = (Medico *)malloc(sizeof(Medico));
	if (medico_inicio == NULL)
	{
		exit(1);
	}

	medico_prox = medico_inicio;

	

	return 0;
}
