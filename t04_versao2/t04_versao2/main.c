#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	int c, nw, nl, state;
	state = OUT;
	nw = nl = 0;
	while ((c = getc(stdin)) != EOF)
	{
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	size = strlen(c)
	printf("lines: %d, words: %d\n", nl, nw);
	return 0;
}