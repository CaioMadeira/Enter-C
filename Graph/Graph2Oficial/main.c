/*

Edges - Arestas
Nodes - Nós
Vertices - Vertices

*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_VETOR_ARESTAS 50

typedef struct node
{
    struct Edge * vy;
	struct node *proximo;
}Node;

typedef struct graph 
{
	struct Node *lista;

}Graph;

typedef struct edge 
{
    int vx;
    int vy;
    
}Edge;

Graph * criaGrafo(int numVertices)
{
	Graph *g;
	g = (Graph *)malloc(sizeof(Graph)); // ver propriedades do malloc posteriormente
	if (g == NULL)
		return NULL;
    
    g->lista = NULL;
    return g;
}


void montaGrafo(Graph *g, Edge *v, int tamanho)
{
    // primeiro conta qts items tem no vetor e passa um int
   Edge *par;
   par = (Edge*)malloc(sizeof(Edge));

   if (par == NULL)
        return NULL;
    
    for (int i = 0; i < tamanho; i++)
    {
        par->vx = v[i];
    }
    
    

}

// auxiliares
void criaEdge(Graph *g)
{
}

int main(void)
{
    Edge edges1[] = { {0,1}, {1,2}, {2,0}, {2,1}, {3,1}, {4,2} };
    Graph *g;

    g = criaGrafo(10);

    totalElementosVetor(edges1);
    printf("CONSEGUI!\n");
    return 0;
}