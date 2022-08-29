#include<stdlib.h>
#include<stdio.h>

int buscaBinariaRecursiva(int *vet, int chave, int inicio, int fim)
{
    int meio;
    if (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (chave == vet[meio])
            return meio;
        else {
            // chamadas recursivas
            if(chave < vet[meio]) // o eleemnto q procura ta entre o indice 0 o elemento meio -1
                return buscaBinariaRecursiva(vet, chave, inicio, meio - 1);
            else   {
                return buscaBinariaRecursiva(vet, chave, meio + 1, fim);
            }
        }
    }
    return -1; // elemento nao encontrado
}

int main(void)
{

    int vet[10] = { 13, 14, 19, 43, 47, 52, 65, 82, 89, 91 };
    int valor;
    printf("Digite o valor:\n");
    scanf("%d", &valor);
    printf("%d\n", buscaBinariaRecursiva(vet, valor, 0, 9));


    return 0;
}