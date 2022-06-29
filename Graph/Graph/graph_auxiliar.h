/*

Caio Madeira
1921050
-------
Anotações:
Edge - Aresta


*/
// constantes
#define MAX 10 // recebe o valor de vertices do vetor
typedef struct graph Graph;
typedef struct edge Edge;
typedef struct node Node;

/* 
Função para criar e inicializar o grafo com um vetor de ponteiros para NULL. Essa função recebe o número de vértices
e retorna um grafo (i.e., retorna um ponteiro para Graph). Não use a mesma quantidade de vértices do exemplo.
*/
Graph * criaGrafo(int numeroNodes);
/* Função para montar o grafo (como na Fig. 2, mas com valores e com quantidades diferentes). Essa função recebe um
ponteiro para Graph, o vetor de arestas(edges1) e o tamanho desse vetor.
*/
void montaGrafo(Graph *grafo, int *vetorArestas, int tamVetorArestas);

// Função que imprime o grafo, dados um ponteiro para Graph e o número total de vértices
void imprimeGrafo(Graph *grafo);

/*
Função que testa se dois vértices dados são uma aresta do grafo dirigido. Essa função recebe o grafo (um ponteiro para
Graph e o número total de vértices) e os dois vértices e retorna verdadeiro ou falso. Por exemplo, na Fig. 1, 2 → 0
formam uma aresta, mas 2 → 4 não.
*/
int ehAresta(Graph *grafo, int fromNode, int toNode);

// demais funções auxiliares (não fazem parte do escopo pedido)
void destroiGrafo(Graph *grafo);
int adicionaAresta(Graph *grafo, int fromNode, int toNode);
