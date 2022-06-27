#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"



int setup(const char *mode, const char *filename, int config)
{
	FILE *fp = fopen(filename, mode);

	if (config == 1) {
		fp = setupConfigFile(fp, mode, filename);
		return fp;
	}
	else if (config == 0) {
		puts(">Pulando...");
		return 0;
	}
	else {
		puts(">Comando Inválido.");
		//setup(fp, mode, filename);
		exit(-1);
	}
}


FILE *setupConfigFile(FILE *fp, const char *mode, const char *filename)
{
	char vTopics;
	fp = fopen(filename, mode);
	if (fp == NULL)
	{
		puts("Não foi possível iniciar o arquivo.");
	}

	while (feof(fp))
	{
		fscanf("%s", vTopics);
		printf("%s", vTopics);
	}

	fclose(fp);
	return fp;
}