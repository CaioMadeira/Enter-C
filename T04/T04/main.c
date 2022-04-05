/* 
Caio Cesar Madeira Mattoso de Souza
1921050

*/
/*
Comecei o T04 implementando um vetor de caracteres e durante
a realização do exercicio percebi que vetor e ponteiros tem
uma relação especial.

*/
//stdin - standard input - entrada padrao do computador, no caso o teclado.
#include <stdio.h>
#include "analise.h"

int main(void)
{
	//vetor de characters
	char text[100];
	int i = 0;
	
	// variaveis referentes á resultados.
	float wordAverage, charAverage;

	int word, sentence;
	word = 0;
	sentence = 0;

	// variaveis que retornam valores de funcoes
	int textSize;
	int lastC;

	while ((text[i] = getc(stdin)) != '@') {
		if (text[i] != '#') {
			++i;
		}
		else
		{
			text[++i] = '\0'; // uma string sempre termina com o caractere nulo ('\0'), é preciso fazer parser da cadeia de chars

			// tamanho do caractere
			textSize = strlen(text);
			printf("Total de caracteres: %d\n", textSize);

			// ultimo caractere
			lastC = lastChar(text, textSize);
			printf("Ultimo caractere do texto: %c\n", lastC);

			// checa o texto para identificar: sentenças e palavras
			word = checkWord(text, textSize, word);
			sentence = checkSentence(text, textSize, sentence);

			//calcula a media palavras
			wordAverage = word / sentence;

			//calcula a media caracteres
			charAverage = textSize / sentence;

			// mostra as estatisticas 
			//magic number (+1) é referente a '#' como um caractere a mais
			showStatistics(word, sentence, textSize + 1, &wordAverage, &charAverage);

		}
		
	}

}


