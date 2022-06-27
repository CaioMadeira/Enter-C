/*
Caio C�sar Madeira Mattoso de Souza
1921050
*/

/*
Fa�a um programa que:
	1. declare duas vari�veis do tipo inteiro (a,b)
	2. declare duas vari�veis do tipo  ponteiro para inteiro (pa, pb).
	3. fa�a com que as vari�veis do tipo ponteiro apontem para as vari�veis do tipo inteiro.
	4. leia os valores de a e de b atrav�s de pa e pb
	5. imprima os valores de a e de b usando a e b.
*/

#include <stdio.h>

int main(void)
{
	// 1. declare duas vari�veis do tipo inteiro (a,b)
	int a, b;
	a = 34;
	b = 23;
	// 2. declaracao de duas variaveis do tipo ponteiro para inteiro
	int *pa;
	int *pb;
	//3. fa�a com que as vari�veis do tipo ponteiro apontem para as vari�veis do tipo inteiro.
	//atribuindo o endere�o da vari�vel a e b aos ponteiros pa, pb
	pa = &a;
	pb = &b;
	// Desreferenciar: pode-se ler conte�do (valor) da posi��o de mem�ria indicada ("apontada") pelo ponteiro.
	//Leitura: pode-se ler o valor armazenado no ponteiro
	printf("Desreferenciar: Valor de A atraves de PA: %p\n", *pa);
	printf("Leitura: Valor de A atraves de PA: %p\n", pa);

	//5. imprima os valores de a e de b usando a e b.
	printf("Valor de A: %d\n", a);
	printf("Valor de B: %d\n", b);
}