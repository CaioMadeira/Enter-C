/*
Implemente uma função que inverta uma string usando
uma pilha.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int count;
    char c;
    struct node * next;
};

typedef struct node Node;

Node * newstack(void)
{
    Node * head = (Node*)malloc(sizeof(Node));
    if (head != NULL) 
    {
        head->next = NULL;
        head->count = 0;
        return head;
    }
    else { printf("Erro ao criar o head.\n"); return NULL; }
}

Node * push(Node * head, char c)
{
    Node * new = (Node*)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->c = c;
        head->count++;
        new->next = head;
        head = new;
        return new;
    }
    return NULL;
}

char * invertstr(Node * stack)
{
    Node* p;
    char * buffer = (char*)malloc((stack->count + 1)*sizeof(char));
    int i = 0;
    if (buffer != NULL)
    {
        strcpy(buffer, ""); // Copiando uma string vazia apenas para inicializar a string
        for(p = stack; p != NULL; p = p->next)
        {
            //printf("%c", p->c);
            buffer[i] = p->c;
            i++;
        }
        buffer[i] = '\0';
        return buffer;
    }
    return NULL;
}

int main(void)
{
    const char * str1 = "Alan Turing";
    Node * stack = newstack();

    for(int i = 0; i < strlen(str1); i++)
        stack = push(stack, str1[i]);

    char * str = invertstr(stack);

    if (str != NULL)
        printf("%s\n", str);

    return 0;
}