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

----
Referencias: Tabela ASCII
https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define TRUE 1
#define FALSE 0
#define DEBUG 0 // 1 = ativado

struct node
{
    int n;
    struct node *next;
};

typedef struct node Node;

/*
Node *push(Node *head, int n);
--------------------------------
Insere um novo item no inicio da pilha;
*/
Node *push(Node *head, int n)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->n = n;
        new->next = head;
        head = new;
        return new;
    }
    return NULL;
}

/*
Remove um nodo da pilha e retorna o valor do nodo removido.
Ao invés de retornar o head, nesse problema precisamos obter o numero removido da pilha.
Passamos um ponteiro a referencia para a função e utilizo aritmética de ponteiros.
*/

int pop(Node **head)
{
    Node *aux;
    if (*(head) == NULL) // Se o primeiro nodo for NULL, a pilha está vazia.
    {
        perror("Stack is empty.\n");
        return -1;
    }

    // O primeiro nodo (head) é o que deve ser removido. Como vamos precisar dele, guardo em uma variavel auxiliar. 
    aux = *(head);
    int n = aux->n; // Usando a variavel auxiliar (aux) obtenho o valor do inteiro do nodo e salvo ele;
    *(head) = (*head)->next; // o primeiro nodo aponta para o seu proximo. Com esse proximo virando o primeiro.
    free(aux); // Libero da memoria o ponteiro auxiliar;
    return n;
}

/*
rmspc = Remove espaços em branco
(utilizando arimetica de ponteiros)
*/
void rmspc(char *str)
{
    // Verifica se o caractere atual é o \0 (null terminator) que indica o fim da string
    if (*str == '\0')
        return; // Se for encerra a função
    if (*str == ' ') // Verifica se o char atual é um espaço em branco
    {
        // Caso seja...
        // Devemos movimentar a string toda a fim de remover esse espaço em branco
        char *p = str; // Cria-se um ponteiro auxiliar
        while (*(p + 1) != '\0') // Em quanto o proximo char for diferente de \0
        {
            *p = *(p + 1); // O char atual (espaço em branco) recebe o proximo char
            p++;
        }
        *p = '\0'; // Coloca-se o \0 ao final para indicar o fim da string
        rmspc(str);
    }
    else
        rmspc(str + 1);
}

/*

// Checa se o caractere esta entre 48(0) e 9(57).

*/
int isDigit(char c)
{
    // 48 = 0 e 57 = 9 na tabela ASCII
    if (c >= 48 && c <= 57)
        return TRUE;
    return FALSE;
}

void printstack(Node *stack)
{
    if (stack != NULL)
    {
        printf("%d\n", stack->n);
        printstack(stack->next);
    }
}

/*
 char to int - Simplemente converte um char para inteiro subtraindo seu valor pelo char '0'
*/
int ctoi(char c) { return c - '0'; }

int operation(Node **stack, char c)
{
    int op = 0;
    switch (c)
    {
    case '+':
        op = pop(stack) + pop(stack);
        DEBUG == TRUE ? printf("result of sum: %d\n", op) : printf("");
        break;

    case '*':
        op = pop(stack) * pop(stack);
        DEBUG == TRUE ? printf("result of multiplication: %d\n", op) : printf("");
        break;

    default:
        DEBUG == TRUE ? printf("caractere %c. nenhuma operação\n") : printf("");
        return -1;
    }
    return op;
}

Node *evalnotation(Node **stack, char *expr)
{
    int result = 0;
    for (int i = 0; i < strlen(expr); i++)
    {
        if (isDigit(expr[i]) == TRUE)
        {
            DEBUG == TRUE ? printf("Number: %c\n", expr[i]) : printf("");
            *(stack) = push(*(stack), ctoi(expr[i]));
        }
        else
        {
            DEBUG == TRUE ? printf("Token (op): %c\n", expr[i]) : printf("");
            result = operation(stack, expr[i]);
            if (result != -1)
                *(stack) = push(*(stack), result);
        }
    }
    return *stack;
}

// Compile com: gcc <nome_do_arquivo.c> -o <nome_do_executavel> (sem extensao)

int main(void)
{
    char expr[] = "3 4 + 5 *)";
    Node *stack = NULL; // Inicializa a pilha como vazia
    rmspc(expr);
    printf("Expressão em notação pós-fixada: %s\n", expr);

    stack = evalnotation(&stack, expr);
    printf("Resultado:\n");
    printstack(stack);

    return 0;
}