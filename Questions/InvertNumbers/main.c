/* 
1. Faça um programa que lê três palavras do teclado e imprime as três palavras na ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char palavra1;
    for (int i = 0; i < 10; i++)
    {
        scanf("%c", &palavra1);
        printf("Palavra 1 normal: %c\n", palavra1);
    }

    return 0;
}