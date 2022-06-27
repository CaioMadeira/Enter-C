#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utils.h"


int main(void)
{
	int config;
	setlocale(LC_ALL, PT);

	puts(">Deseja fazer as configurações iniciais?");
	scanf("%d", &config);
	setup("r", CONFIG_FILENAME, config);

	return 0;
}
