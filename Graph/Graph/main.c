/*

Caio Madeira
1921050

*/

#include <stdio.h>
#include <stdlib.h>
#include "graph_auxiliar.h"
#include "graph.c"
#include "list_auxiliar.h"


int main(void)
{

	Graph *grafo;

	grafo = criaGrafo(10);
	if (grafo == NULL)
	{
		printf("Mem�ria insuficiente. N�o foi poss�vel alocar o grafo ou as arestas.\n");
	}
	else 
	{
		free(grafo);
		free(grafo->arestas);
	}

	return 0;
}