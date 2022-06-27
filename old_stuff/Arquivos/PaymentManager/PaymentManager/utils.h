/*

utils collection include:

1 - config.properties parsing

*/

// constantes
#define PT "Portuguese"
#define CONFIG_FILENAME "config.properties"


// protótipo de funções
int setup(const char *mode, const char *filename, int config);
FILE *setupConfigFile(FILE *fp, const char *mode, const char *filename);
