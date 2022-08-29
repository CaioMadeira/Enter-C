#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;


// inserir no inicio

void inserirInicio(No **lista, int valor)
{
    No *auxiliar, *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = valor; 
        novo->proximo = *lista; //precisa apontar p o primeiro elemento do inicio da lista
        *lista = novo; // atualiza o inicio da lista
    }
    else {
        printf("Erro na alocacao.");
        return NULL;
    }
}

// inserir no final
void inserirFim(No *lista, int valor)
{
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->proximo = NULL;

        // esse no eh o primero da lista?
        if (*lista == NULL)
        {
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;

            }
            aux->proximo = novo;
        }
        
    } else {

    }
}

int main(void)
{
    return 0;
}