/*
Caio Cesar Madeira Mattoso de Souza
1921050

*/

#include <stdio.h>
#include "analise.h"

// Passei o vetor text como parametro. Quando passamos um vetor como parametro em uma função, passamos
// o endereço do primeiro(c[0]) elemento do vetor e não os valores em si.
int lastChar(char *text, int textSize) {
	char lastChar;
	// O ultimo caractere sempre sera  #
	lastChar = text[textSize - 1]; // com isso, subtraio por 2, pois queremos ignorar o @ que marca o fim do texto
	return lastChar;
}

int checkSentence(char *text, int textSize, int sentence) {
	int i;
	// Aqui o vetor de caracteres é percorrido e ao inves do seu total
	// ser 100 como definido no inicio da main, seu total passará a ser o tamanho
	// da cadeia de caracteres, por isso é passado o textSize
	for (i = 0; i < textSize; i++)
	{
		//printf("Elemento %d, String = %c\n", i, text[i]);
		// identifica sentencas
		if (text[i] == '!' || text[i] == '.' || text[i] == '?') {
			printf("Sentenca identificada: %c\n", text[i]);
			++sentence;
		}
	}

	if (sentence == 0) {
		// caso o usuario nao coloque sentenca, a variavel recebe 1, visto que não é
		//possivel dividir por 0
		sentence = 1;
	}
	return sentence;
}

int checkWord(char *text, int textSize, int word) {
	int i;
	int wordState = OUT;
	for (i = 0; i < textSize; i++)
	{
		// identifica palavras
		if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
		{
			wordState = OUT;

		}
		else if (wordState == OUT) {
			wordState = IN;
			++word;
		}

	}
	// remove os dois ultimos caracteres #
	char lastC;
	lastC = lastChar(text, textSize);

	if (lastC == '#') {
		word = word - 1; // remove o # da contagem de palavras
		return word;
	}
	return word;
}


/* Como observado no enunciado, a média é dada pela fórmula:
 1 - totalDePalavras / totalDeSentenças;
 2 - totalDeCaracteres / totalDeSentenças;
*/
int calculateAverage(int value1, int value2)
{
	float calc;
	calc = value1 / value2;
	return calc;
}

/* showStatistics - como pedido no enunciado, ela exibe todos os valores

wordAverage e charAverage são passados por referencia.
*/
int showStatistics(int totalWords, int totalSentences, int totalChars, float *wordAverage, float *charAverage)
{
	printf("\nPalavras: %d, Sentencas: %d, Caracteres: %d, Media palavras: %.1f, Media caracteres: %.1f\n", totalWords, totalSentences, totalChars, *wordAverage, *charAverage);

	return 0;
}