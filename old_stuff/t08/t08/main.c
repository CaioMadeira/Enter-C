/*
Caio César Madeira
1921050
33A
*/

// string = conjunto de caracteres
// nao usar vetor auxiliar

#include <stdio.h>
#include <string.h>

int main(void) {

	char vString[7] = "abcABC";
	int check;
	int middle_index = 7 / 2;
	check = has_substring(vString, 0, middle_index);
	printf(check);
	
	return 0;
}

// Dica: defina uma função que recebe a string e apenas chama uma outra função que recebe um ponteiro para
//	o início da string e um segundo ponteiro que aponta para o meio da string.Essa outra função de dois
//	argumentos é implementada recursivamente
int has_substring(char *string, int first_index, int middle_index) {

	if (strstr(string, string)) {
		printf("achei\n");
		if (string - string[middle_index] == string[middle_index])
		{
			printf("match!");
		}
		else {
			printf("no");
		}
	}

	return 0;
}


