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
	// 2. declaracao de duas variaveis do tipo ponteiro para inteiro
	int *pa, *pb;
	//3. fa�a com que as vari�veis do tipo ponteiro apontem para as vari�veis do tipo inteiro.
	*pa = a;
	*pb = b;
}