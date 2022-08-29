/*

Caio Madeira

Jogo inspirado no minigame de um outro videogame:
https://www.youtube.com/watch?v=EnG7jxtJn6o

Decidi criar algumas regras pra facilitar o desenvolvimento do programa

1 - precisa existir um vetor, com 4 numeros gerados randomicamente e adicionados nele;

2 - precisa existir um segundo vetor vazio, que, sera preenchido pelo usuario, ele tambem tem a mesma
qtd de espacos;

3 - a cada numero digitado, deve ser inserido de forma ordenada, ou seja, o primeiro
em primeiro, o segundo em seg, etc.

4 - uma busca binaria deve ser feita em cada vetor e comparar com os numeros para
no final, retornar ao usuario se a senha foi acertada;

detalhes:

Quando o jogador acertar um numero que existe no vetor mas errar sua posicao,
o numero aparece como AMARELO;

Quando o jogador acertar o numero e a posicao, ele aparecerá VERDE simbolizando que o jogador
acertou;

Quando o jogador errar o numero (numero inexistente no vetor), ele aparecerá em VERMELHO;

O jogador so tem 5 chances;

*/

// Constantes simbolicas para cores

#define REGULAR_TEXT_YELLOW "\e[0;33m"
#define REGULAR_TEXT_RED "\e[0;31m"
#define REGULAR_TEXT_GREEN "\e[0;32m"

#define BOLD_TEXT_YELLOW "\e[1;33m"
#define BOLD_TEXT_RED "\e[1;31m"
#define BOLD_TEXT_GREEN "\e[1;32m"

#define FOREGROUND_TEXT_YELLOW "\e[43m"
#define FOREGROUND_TEXT_RED "\e[41m"
#define FOREGROUND_TEXT_GREEN "\e[42m"

// reseta as cores printadas na tela
#define RESET

// outras constantes
#define MAX 4

// escopo das funçoes
int * geraNumerosAleatorios(int * vetorQuestion);
void imprimeNumeros(int * vetorQuestion, int isQuestion);
int* preencheResposta(int *vetorAnwser);
int buscaBinariaRecursiva(int *vetorQuestion, int valor, int inicio, int fim);
void valoresNaMesmaPos(int * vetorQuestion, int * vetorAwnser);
int buscaPosicao(int * vetorQuestion, int valor);