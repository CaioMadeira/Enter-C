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

struct aluno
{
    int matricula;
    struct aluno *proximo;
};

typedef struct aluno Aluno;

struct listacontrole
{
    Aluno *inicio;
    Aluno *fim;
    int tamanho;
};

typedef struct listacontrole ListaControle;

// funcao de inicializacao sem nenhum tipo de retorno
void criaListaAluno(ListaControle *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// funcao de insercao - inicio
// eh do tipo int para retornar um posicionamento quanto ao processo
int inserirInicio(ListaControle *lista, int matricula)
{
    // criando um novo No (Lembre-se que No=elemento)
    // sempre que vamos fazer uma insercao eh preciso criar um novo no
    // um novo elemento
    Aluno * novo; // ponteiro p um novo elemento
    // alocacao na memoria do novo elemento
    novo = (Aluno*)malloc(sizeof(Aluno));
    // verificacao de seguranca
    if (novo == NULL)
        return -1; // -1 significa que nao deu certo
    
    novo->matricula = matricula; // a variavel matricula da estrutura recebe a matricula do parametro
    
    // feito isso, voce tem um pedaco de memoria disponivel para o ponteiro e para o int
    
    // verifica se a lista esta vazia ou nao
    if(lista->inicio == NULL)
    {
        // se a lista esta vazia, tanto o inicio quanto o fim
        // estao apontando pra null (como definido anteriormente)
        novo->proximo = NULL; // o proximo do novo nao vai apontar pra nada
        lista->inicio = novo; // como o novo aluno eh o unico elemento, ele sera o inicio
        lista->fim = novo; // e o ultimo elemento
    }
    else
    {
        // caso nao esteja vazia
        novo->proximo = lista->inicio; // o proximo aluno vai pontar pro inicio da lista
        lista->inicio = novo; // e o inicio da lista vai apontar pro novo
        
    }
    lista->tamanho++; // indica que a gente fez a insercao de um elemento
    return 0;
}

// insercao no final da lista
int insercaoNoFim(ListaControle *lista, int matricula)
{
    Aluno *novo;
    
    novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo == NULL)
        return -1;
    
    novo->matricula = matricula;
    novo->proximo = NULL; // como estou inserindo no fim, o proximo sempre sera nulo
    
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
        
    } else {
        
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
    return 0;
}

// funçao de remover o primeiro no (elemento)
// o retorno pode retornar o proprio valor que inseriu no elemento ou o retorno de um ponteiro
// retornamos o ponteiro nessa funcao logo, temos que usar o free para aluno NA MAIN pois a alocacao vai ser na main. Free na funcao impossibilita o retorno do valor e a utilizacao dele pos remocao da lista

// obs: se estivessemos criando uma lib. as alocacoes e os frees devem ser feitos dentro da funcao
// pois o main nao deve se preocupar com isso
void removeInicio(ListaControle *lista)
{
    // se o inicio nao esta vazio ai sim podemos remover o inicial
    if(lista->inicio != NULL)
    {
        Aluno *rm;
        rm = (Aluno*)malloc(sizeof(Aluno));
        rm = lista->inicio;
        lista->inicio = rm->proximo;
        lista->tamanho--;
        if(lista->inicio == NULL)
            lista->fim = NULL;
        free(rm);
    }
}


// funcao de remocao padrao (geral) da lista (pode remover qlr elemento da estrutura)
// essa funcao vai buscar o valor a ser removido
/* ao inves de buscar uma funcao especifica, vou passar como
 parametro um valor que eu quero retirar, buscar na lista e se esse valor existir
 vou retirar esse valor.
 Vamos fazer uma remocao por elemento, por informacao ao inves de posicao
 */
void remover(ListaControle *lista, int matricula)
{
    Aluno *inicio = lista->inicio;
    Aluno *aRm = NULL; // recebe num pois n sabemos se vamos remover esse valor antes de passar
    
    // o elemento pode estar no inicio, no meio ou no fim.
    // se a remocao for no inicio é mais facil.
    // se a remocao for do meio para o fim é mais complicado.
    
    // valida se a nossa remocao ta no inicio
    /* se eu tiver algo dentro da lista e se a primeira
     posicao da lista tiver o valor que eu quero remover
     */
    if (inicio != NULL && lista->inicio->matricula == matricula)
    {
        aRm = lista->inicio; // eu faco com que esse auxiliar receba a primeira posicao da lista
        // como o auxiliar aRm (aRemover) tem uma copia do nó (Aluno)
        lista->inicio = aRm->proximo; // ele vai ter uma copia do ponteiro para o segundo nó
        // fazendo com que lista->inicio comece a apontar para o segundo nó (elemento)
        // dai verificamos se o segundo no existe
        if (lista->inicio == NULL)
        {
            // se ele nao existir, é porque o primeiro elemento era o unico da lista e entao
            // colocamos o fim como NULL
            lista->fim = NULL;
        }
    }
    else {
        // caso nao tenhamos a possibilidade de remover esse elemento
        // vamos ter que começar a percorrer essa lista, posicao a posicao, para que
        // a gente possa encontrar esse nosso elemento
        // para isso percorreremos com um while
        
        // inicio != NULL - verifica se ja chegamos ao final da lista
        // inicio->proximo != NULL - verifica se a proxima posicao ja nao é o final
        // inicio->proximo->matricula != matricula - verifica se o nó que contem o valor é diferente do valor passado que queremos achar
        while (inicio != NULL && inicio->proximo != NULL && inicio->proximo->matricula != matricula) {
                // variavel auxiliar para percorrer a lista
                inicio = inicio->proximo; // movimento a lista dessa forma
                // pos percorrer, temos que verificar se encontramos ou nao o valor
                // ha duas possibilidades para o fim do while:
                // 1 - ou encontramos o valor que queremos retirar
                // 2 - a lista pode ter terminado
                
            // esse eh caso encontramos o que queremos
                if (inicio != NULL && inicio->proximo != NULL)
                {
                    aRm = lista->inicio; // aRm recebe o nó que estou atualmente
                    inicio->proximo = aRm->proximo; // faço a mudan;a do processo de apontameneto
                    if (inicio->proximo == NULL) // caso seja a ultima posicao
                        lista->fim = NULL; // o fim recebe NULL
                }
                

            }
    }
    if (aRm) // se eu achei algo esse aRm vai ter algo
    {
        // agr vamos decrementar
        free(aRm); // vamos liberar a memoria do cara que removemos
        lista->tamanho--; // indica que removemos um valor
    }
}

// com isso podemos remover qualquer elemento de qualquer posicao
// numa pilha temos que sempre remover o topo
// numa fila sempre o primeiro
// nesse, é mais livre

// funcao para imprimir
void imprime(ListaControle *lista)
{
    // criar no auxiliar
    Aluno *elementoAtual = lista->inicio; // incializando na primeira posicao
    printf("Tamanho atual da lista = %d\n", lista->tamanho);
    // em quanto nosso elemento atual for diferente de NULL, significa que ainda temos elementos
    while (elementoAtual != NULL) {
        printf("Matricula: %d\n", elementoAtual->matricula);
        elementoAtual = elementoAtual->proximo; // permite que o elemento seja atualizado sempre jogando pra proxima posicao
    }
    
}


int main(void)
{
    ListaControle *lista; // uma lista
    int matricula; // um int valor
    char op; // para mostrar as opcoes
    int a;
    
    // alocaremos memoria para a lista declarada
    lista = (ListaControle*)malloc(sizeof(ListaControle));
    if (lista == NULL)
    {
        printf("Memoria insuficiente./n");
    }
    
    // inicializa/ cria lista
    criaListaAluno(lista);
    
    // menu
    while (op != 'x')
    {
        printf("A - Adicionar elementos no inicio da lista\n");
        printf("B - Adicionar elementos no fim da lista\n");
        printf("R - Remover elementos do inicio da lista\n");
        printf("S - Remover um elemento da lista\n");
        printf("L - Imprimir os elementos da lista\n");
        printf("T - Tamanho da fila\n");
        printf("X - Sair\n");
        
        scanf("%c", &op);
        if (op == 'A')
        {
            printf("Digite o numero da matricula:\n");
            scanf("%d", &matricula);
            a = inserirInicio(lista, matricula);
            if (a == 0)
            {
                printf("Sucesso.\n");
            }
            else {
                printf("Falha.\n");
            }
        }
        
        else if (op == 'B')
        {
            printf("Digite o numero da matricula:\n");
            scanf("%d", &matricula);
            a = insercaoNoFim(lista, matricula);
            if (a == 0)
            {
                printf("Sucesso.\n");
            }
            else {
                printf("Falha.\n");
            }
        }
        
        else if (op == 'R')
        {
            printf("Digite o numero da matricula:\n");
            scanf("%d", &matricula);
            removeInicio(lista);
        }
        
        else if (op == 'S')
        {
            printf("Digite o valor a ser removido:\n");
            scanf("%d", &matricula);
            remover(lista, matricula);
        }
        
        else if (op == 'L')
        {
            printf("Digite o numero da matricula:\n");
            scanf("%d", &matricula);
            imprime(lista);
        }
        else if (op == 'X')
        {
            printf("Saindo...\n");
            break;
            exit(1);
        }

    }
    
    return 0;
}
