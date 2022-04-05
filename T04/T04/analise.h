/*
Caio Cesar Madeira Mattoso de Souza
1921050

*/

#define IN 1
#define OUT 0
int lastChar(char *text, int textSize);
int checkSentence(char *text, int textSize, int sentence);
int checkWord(char *text, int textSize, int word);
int calculateAverage(int value1, int value2);
int showStatistics(int totalWords, int totalSentences, int totalChars, float *wordAverage, float *charAverage);