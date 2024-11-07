#include <stdio.h>
#include <stdlib.h>

struct node {
    char x;
    struct node* right; // Filho direito
    struct node* left;  // Filho esquerdo
};

typedef struct node Node;

// Cria um novo nó com o valor dado
Node* newNode(char x) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new != NULL) {
        new->x = x;
        new->right = NULL;
        new->left = NULL;
    }
    return new;
}

// Adiciona um nó à direita
Node* addRight(Node* root, char x) {
    if (root == NULL) {
        return newNode(x);
    } else {
        if (x > root->x) {  // Verifica se o valor é maior para ir à direita
            root->right = addRight(root->right, x);
        }
    }
    return root;
}

// Adiciona um nó à esquerda
Node* addLeft(Node* root, char x) {
    if (root == NULL) {
        return newNode(x);
    } else {
        if (x < root->x) {  // Verifica se o valor é menor para ir à esquerda
            root->left = addLeft(root->left, x);
        }
    }
    return root;
}

// Imprime a árvore em ordem central (in-order traversal)
void positionCentral(Node* root) {
    if (root != NULL) {
        positionCentral(root->left);
        printf("%c\n", root->x);
        positionCentral(root->right);
    }
}

int main(void) {
    Node* root = newNode('A'); // Cria o nó raiz

    // Adiciona os elementos na árvore
    addLeft(root, 'B');
    addRight(root, 'C');
    addLeft(root->left, 'D');
    addRight(root->left, 'E');
    addLeft(root->right, 'F');
    addRight(root->right, 'G');

    // Imprime a árvore em ordem central
    positionCentral(root);

    return 0;
}