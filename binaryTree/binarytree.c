/*
TE - Subarvore da esquerda
TD - SUbarvore da direita

Filhos - Nodos filhos 
    - Nodo da direita;
    - Nodo da esquerda;

Qtd de nodos variam de 0 a 2

Comeco sempre da esquerda
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    char x;
    struct node* root;
    struct node* td;
    struct node* te;
};

typedef struct node Node;

Node* newNode(Node* root, char x)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->x = x;
        new->td = NULL;
        new->te = NULL;
        new->root = root;
        return new;
    }
    return NULL;
}

Node* addRight(Node* root, char x)
{
    if (root == NULL)
        newNode(root, x);
    else 
    {
        if (x < root->x)
            root->te = newNode(root->te, x);
    }
    return root;
}

Node* addLeft(Node* root, char x)
{
    if (root == NULL) { newNode(root, x); }
    else 
    {
        if (x > root->x)
            root->td = newNode(root->td, x);
    }
    return root;
}

void printTree(Node* root)
{
    if (root != NULL)
    {
        printTree(root->te);
        printf("%c\n", root->x);
        printTree(root->td);
    }
}

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
        return true;
    case '-':
        return true;
    case '/':
        return true;    
    case '*':
        return true;
    }
    return false;
}

bool isLetter(char x)
{
    if ((x >= 'A' || x >= 'a') && (x >= 'z' || x >= 'Z'))
        return true;
    else
        return false;
}

char isMiddleOp(const char* y, char middle)
{
    if (isLetter(middle) == true)
        middle = isMiddleOp(y, y[(strlen(y) / 2) + 1]);
    return middle;
}

int main(void)
{
    const char* y = "(A+B)-(C*(D-E)+(F/G))";

    char middle = y[strlen(y) / 2];
    Node* root = addLeft(root, middle);
    
    for(int i = middle; i < strlen(y); i++)
        root = addLeft(root, y[i]);

    printTree(root);

    return 0;
}