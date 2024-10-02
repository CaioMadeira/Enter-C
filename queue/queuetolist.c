/*

c) Apresentar o algoritmo de um método que recebe uma lista e
uma fila de inteiros por parâmetro. Este método deve copiar o
conteúdo da fila no final da lista, mas no final a fila deve estar
com o seu conteúdo original, isto é, ela não deve ser alterada.

*/

#include<stdio.h>
#include<stdlib.h>

#define VTAM 6

struct node {
    int n;
    struct node* next;
};

typedef struct node Node;

void printvector(int * v, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

Node* enqueue(Node* queue, int n)
{
    Node* aux = NULL;
    Node* p = queue;
    Node* new = (Node*)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->n = n;
        new->next = NULL;

        // Verifica se a fila não está vazia
        if (p == NULL)
            p = new; // Se a fila está vazia inserimos o novo elemento

        // Caso a fila não esteja vazia, precisamos percorrer ela até o último elemento p/ inseri-lo
        else
        {
            aux = p; // o auxiliar guarda a referencia do head da lista
            while(aux->next != NULL)
                aux = aux->next; // o ponteiro aux vai receber o proximo sucessivamente;
            aux->next = new;
        }
        queue = p;
        return queue;
    }
    return NULL;
}

void printqueue(Node* queue)
{
    if(queue != NULL)
    {
        printf("%d\n", queue->n);
        printqueue(queue->next);
    }
}

// queue size

int queuesize(Node* queue)
{
    int count = 0;
    Node* p = queue;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

// queue copy
int* qcpy(Node* queue, int* v, int n)
{
    int qsize = queuesize(queue);
    int * aux = (int*)malloc((n + qsize) * sizeof(int));
    if (aux != NULL)
    {
        for(int i = 0; i < n; i++)
            aux[i] = v[i];

        int j = n;
        for(Node* p = queue; p != NULL; p = p->next)
        {
            aux[j] = p->n;
            //printf("aux[j] = %d\n", aux[j]);
            j++;
        }
        return aux;
    }
}

int main(void)
{
    int v[VTAM] = { 90, 91, 92, 93, 94, 95 };
    printf("Lista a ser adicionada no final da fila:\n");
    printvector(v, VTAM);

    printf("\nFila: \n");
    Node* queue = NULL; // Inicializa a fila com NULL;

    queue = enqueue(queue, 3);
    queue = enqueue(queue, 10);
    queue = enqueue(queue, 5);

    printqueue(queue);
    printf("Tamanho da fila: %d\n", queuesize(queue));
    puts("");
    printf("Lista + fila:\n");
    int * v2 = qcpy(queue, v, VTAM);
    printvector(v2, VTAM + queuesize(queue));
    printf("Fila original:\n");
    printqueue(queue);

    return 0;
}