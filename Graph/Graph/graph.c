/*

Caio Madeira
1921050
-------
Anota��es:
Edge - Aresta


*/

#include <stdio.h>
#include <stdlib.h>
#include "graph_auxiliar.h"
struct node
{
	struct Node *proximo;
	int verticeNoFinal;
};

struct graph 
{
	int tamanhoVetor;
	Node ** lista;
};

struct edge 
{
	int verticeInicial;
	int verticeFinal;
};

Graph * criaGrafo(int num_vertices)
{
	Graph *g;
	g->lista = (Node *)malloc(sizeof(Node));
	if (g->lista == NULL)
	{
		return NULL;
	}
	else {
		return g;
	}
}