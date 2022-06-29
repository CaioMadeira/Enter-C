/*

Caio Madeira
1921050
-------
Anotações:
Edge - Aresta


*/

#include <stdio.h>
#include <stdlib.h>
#include "graph_auxiliar.h"

struct graph 
{
	int num_vertices;
	float **pesos; // para graficos ponderados
	int* vectorGrau[MAX]; //para cada vertice quantas arestas ele possui
	int **arestas; // matriz de arestas, sendo um ponteiro para i e um outro para j
};

struct edge
{
	int *edges1[];
};


Graph * criaGrafo(int num_vertices)
{
	Graph * grafo = (Graph*)malloc(sizeof(struct graph));
	if (grafo == NULL)
	{
		return NULL;
	}
	else
	{
		grafo->num_vertices = num_vertices;
		grafo->arestas = (int**)malloc(num_vertices * sizeof(int));
		if (grafo->arestas == NULL)
		{
			return NULL;
		}
		else
		{
			for (int i = 0; i < num_vertices; i++)
			{
				for (int j = 0; i < num_vertices; j++)
				{
					grafo->arestas[i] = grafo->vectorGrau[j];

				}
			}
			return grafo;
		}
	}
}

void montaGrafo(Graph *grafo, int *vetorArestas, int tamVetorArestas)
{

}

void imprimeGrafo(Graph *grafo)
{

}


int ehAresta(Graph *grafo, int fromNode, int toNode) 
{

}

void destroiGrafo(Graph *grafo) 
{

}

int adicionaAresta(Graph *grafo, int fromNode, int toNode)
{

}