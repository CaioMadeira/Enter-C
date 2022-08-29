#include <stdio.h>
#include <stdlib.h> // a funcao rand precisa da stdlib
#include "gpassword.h"
#include <time.h> // usamos para trabalhar com a hora

int main(void)
{
    int *vetorQuestion;
    int *vetorAnwser;
    vetorQuestion = (int *)malloc(MAX*sizeof(int));
    if (vetorQuestion == NULL)
    {
        printf("Memória Insuficiente.\n");
        exit(-1);
    }

    vetorAnwser = (int *)malloc(MAX*sizeof(int));
    if (vetorAnwser == NULL)
    {
        printf("Memória Insuficiente.\n");
        exit(-1);
    }

    // questao
    geraNumerosAleatorios(vetorQuestion);
    imprimeNumeros(vetorQuestion, 1);

    // resposta
    preencheResposta(vetorAnwser);
    imprimeNumeros(vetorAnwser, 0);

    // compara os vetores
   valoresNaMesmaPos(vetorQuestion, vetorAnwser);


    return 0;
} 

void valoresNaMesmaPos(int * vetorQuestion, int * vetorAwnser)
{
    for (int i = 0; i < MAX; i++)
    {
        if (vetorAwnser[i] == vetorQuestion[i])
        {
            printf(REGULAR_TEXT_GREEN "IGUAL!\nvetor answer: %d = %d vetor question \n" RESET, vetorAwnser[i], vetorQuestion[i]);
        } 
        // se nao o item n eh igual verificar se ele esta no vetor
        else if (vetorAwnser[i] != vetorQuestion[i])
        {
            int verificaPosicao = buscaPosicao(vetorQuestion, vetorAwnser[i]);
            if (verificaPosicao == vetorQuestion[i]) {
                printf(REGULAR_TEXT_YELLOW "IGUAL MAS EM POS DIFERENTE!\nvetor answer: %d = %d vetor question \n" RESET, verificaPosicao, vetorQuestion[i]);
            }
            else if (verificaPosicao == -1)
            {
                printf(REGULAR_TEXT_RED "NAO IGUAL!\nvetor answer: %d = %d vetor question \n" RESET, vetorAwnser[i], vetorQuestion[i]);
            }
        } 
        
    }
}

int buscaPosicao(int * vetorQuestion, int valor)
{
    for (int i = 0; i > MAX; i ++)
    {
        if (vetorQuestion[i] == valor) 
        {
            return valor; // significa que o valor existe no vetor
        } else {
            return -1;
        }

    }
}

int buscaBinariaRecursiva(int *vetorQuestion, int valor, int inicio, int fim)
{
    int meio;
    // verifica se o inicio é maior ou igual ao fim
    // se sim, ele pode entrar na busca, se nao
    // o vetor terminou
    if(inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (valor == vetorQuestion[meio]) {
            return meio;
        } else {
            if (valor < vetorQuestion[meio])
                return buscaBinariaRecursiva(vetorQuestion, valor, inicio, meio - 1);
            else 
                return buscaBinariaRecursiva(vetorQuestion, valor, meio + 1 , fim);
        }
    } 
    return -1; 
}

int* preencheResposta(int *vetorAnwser)
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        scanf("%d", &vetorAnwser[i]);
    }

    return vetorAnwser;
}

// apenas a funcao rand() nao é tao boa, pois ela pode gerar valores PSEUDO - aleatorios
// a semente precisa variar; semente = numero inicial que varie

// para fazer uma variacao de semente é pode-se usar a hora do sistema (o timestamp)
int* geraNumerosAleatorios(int* vetorQuestion)
{
    int i, j;

    srand(time(NULL)); // inicializa a semente utilizando o timestamp

    for (j = 0; j < MAX; j++) {
        for (i = 0; i < MAX; i++)
        {
            vetorQuestion[j] = rand() % 9;
        }
    }
    return vetorQuestion;
}

void imprimeNumeros(int * vetorQuestion, int isQuestion)
{
    if (isQuestion == 1)
    {
        printf("Pergunta:\n");
    }
    else {
        printf("Resposta:\n");
    }
    
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", vetorQuestion[i]);

        // identifica o fim do vetor para por espacamento
        if (vetorQuestion[i + 1] == NULL)
        {
            printf("\n");
        }
    }
}