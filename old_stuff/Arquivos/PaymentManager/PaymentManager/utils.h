/*

utils collection include:

1 - config.properties parsing

*/

// constantes
#define PT "Portuguese"
#define CONFIG_FILENAME "config.properties"


// prot�tipo de fun��es
int setup(const char *mode, const char *filename, int config);
FILE *setupConfigFile(FILE *fp, const char *mode, const char *filename);
