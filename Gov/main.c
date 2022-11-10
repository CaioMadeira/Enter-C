#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FILENAME "beneficio.csv"
#define READ_MODE "r"
#define WRITE_MODE "+w"


struct benefit {

	char* data;
	char* valorTransferido;
	char* programaSocial;

};

typedef struct benefit Benefit;

FILE* openFile(const char* filename, const char* mode);


int main(void)
{
	setlocale(LC_ALL, "Portuguese");

	FILE* f;
	FILE* f_out;
	int line;

	//header
	char header[100];
	int qtdItens; //retorno do fscanf
	
	f = openFile(FILENAME, READ_MODE);
	

	
	qtdItens = fscanf(f, "%[^\n]", header);
	if (qtdItens == EOF)
	{
		printf("arquivo vazio\n");
		exit(1);
	}
	
	//printf("Linha 1: %s\n", header);
	int aux = exchangeChar(header, '"', ' ');
	aux = exchangeChar(header, ';', ' ');
	printf("\nLinha 1 modificada: %s\n", header);
	
	char data[100];
	char valorTransferido[10];
	char programaSocial[100];

	fscanf(f, "%[^;]", data);
	fscanf(f, "%[^;]", valorTransferido);
	fscanf(f, "%[^;]", programaSocial);

	printf("\nData: %s| Valor Transferido: %s| Programa Social: %s\n", data, valorTransferido, programaSocial);
	fclose(f);

	return 0;
}

FILE* openFile(const char* filename, const char* mode)
{
	FILE* f;
	f = fopen(filename, mode);
	if (f == NULL)
	{
		fprintf(stderr, "Erro ao abrir %s no modo %s", filename, mode);
		exit(1);
	}

	return f;
}

int exchangeChar(char* buffer, char c, char destiny)
{
	if (buffer == '\0')
	{
		return 0;
	}

	if (*buffer)
	{
		if (*buffer == c)
		{
			*buffer = destiny;
			return 1 + exchangeChar(buffer + 1, c, destiny);
		}
		return exchangeChar(buffer + 1, c, destiny);
	}
}