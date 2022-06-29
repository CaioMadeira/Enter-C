/*
 MARK: - LISTAS ENCADEADAS
 Uma lista encadeada (ou lista ligada) é uma representação de uma
 sequencia de objetos;
 
    - cada elemento é armazenado em uma célula ou nó(nodes) da lista;
    - Um nó(node) é composto de duas partes:
        - A informação/ dado (float, char, int) podendo ser mais de um;
        - uma REFEFERENCIA AO NÓ POSTERIOR/ Info anterior;
        - Pode haver a informação para o nó ANTERIOR também, ou seja, lista com dois apontadores;
 
 - Dois apontadores da mais vantagem e mais caminhos de manutenção;
 
 VANTAGENS:
 - Em relação a vetores:
        Facilidade em poder inserir e remover elementos de forma ordenada/sequencial;
 - Facilidade de inserção e remoção de nós em qualquer ponto da lista;
 - Isso tudo pode ser feito sem a necessidade de realocação ou reorganização de toda a estrutura visto que nós não precisam ser armazenados em sequencia na mémoria;
 
 DESVANTAGENS:
    - Não permitem acesso direto aos dados ou qlqr forma eficiente de indexação;
    - Assim, muitas operações básicas como buscar um nó com uma informação x podem significar percorrer a maioria dos elementos da lista;
 
    MARK: - MANIPULAÇÃO
    
    - Voce pode inserir ou remover qualquer dado no início, meio ou fim da lista/Uso independente;
    - Os elementos podem ser:
        - Inseridos, duplicados, removidos, ordenados, consultados, movidos, manip. em qlqr posição.
 
    O unico adendo, é evitar buracos na lista, ou seja os elementos devem ser sequenciais.
    Não tem regra de inserção, nem de remoção
 
    MARK: -> COMO IMPLEMENTAR?
    
 
    - De forma sequencial e estática:
        Usando vetores;
    - De forma dinamica e encadeada:
        Usando ponteiros (referencia de memória);
 
 
 */

#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    
};

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
