/*

5) Simule a execução de uma pilha para avaliar uma
expressão aritmética em notação pós-fixada (maneira de
escrever expressões aritméticas sem parênteses.
Ex: (3 + 4) * 5 é escrita como 3 4 + 5 * )
Dica:
1.Leia a expressão da esquerda para a direita.
2.Quando encontrar um número, empilhe-o.
3.Quando encontrar um operador, desempilhe dois números, aplique o
operador e empilhe o resultado.

*/

#include<stdio.h>
#include<stdlib.h>

void checktoken(char x)
{
    switch (x)
    {
    case '(' || ')':
        break;
    
    case '+':
        break;

    case '*':
        break;
    
    case '/':
        break;

    case '-':
        break;

    default:
        break;
    }
}


int main(void)
{
    const char * expr = "3 4 + 5 *";
    printf("Expressão em notação pós-fixada: %s\n", expr);



    return 0;
}