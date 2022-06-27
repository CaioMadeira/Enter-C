/*
Caio César Madeira Mattoso de Souza
1921050
33A
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constantes
#define ESTOQUE "estoque.txt"
#define PREFIX "data_"
#define EXTENSION ".dat"

// prototipos
FILE* openFile(const char *file, const char *mode);
char * replaceEmptySpacesWith(char *nameCompany);

int main(void)
{
	FILE *fp;
	char nameCompany[100];
	char storeData[100];
	char binaryFileName;
	fp = openFile(ESTOQUE, "r");

	fgets(nameCompany, 100, fp); // fgets le uma string ate encontrar a quebra de linha ('\n')
	replaceEmptySpacesWith(nameCompany); // pega APENAS o nome da empresa
	strcat(nameCompany, ".dat");
	printf("\n||||||||||Concatenado: %s |||||||\n", nameCompany);

	// le o arquivo completo DE TEXTO
	while (!feof(fp))
	{
		fgets(storeData, 100, fp);
		printf("%s", storeData);
	}

	fp = openFile(nameCompany, "w");
	fprintf(fp, storeData);

	fclose(fp);

	return 0;
}

FILE* openFile(const char *file, const char *mode)
{
	FILE *fp = fopen(file, mode);
	if (fp == NULL)
	{
		puts("Erro na abertura do arquivo.");
		exit(1);
	}
	
	return fp;
}

char * replaceEmptySpacesWith(char *nameCompany) {
	int i;
	printf("Nome da Empresa: %s \n", nameCompany);
	for (i = 0; i < strlen(nameCompany); ++i)
	{
		if (nameCompany[i] == ' ' && nameCompany[i] != '\0')
		{
			nameCompany[i] = '_';
		}
		if (nameCompany[i] == ':') 
		{
			nameCompany[i] = "";
		}
		if (nameCompany[i] == '\n')
		{
			nameCompany[i] = "";
		}
	}

	printf("New name company: %s \n", nameCompany);

	return *nameCompany;
}