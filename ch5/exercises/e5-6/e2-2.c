#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int getLine(char *s, int lim);

int main(void) {
	char *line = malloc(MAXLEN * sizeof(char));

	getLine(line, MAXLEN);
	printf(">> %s\n", line);

	return 0;
}

int getLine(char *s, int lim) {
	int i = 0;

	for (; i < lim - 1; ++i, ++s) {
		*s = getchar();
		
		if(*s == '\n' || *s == EOF)
			return i;
	}

	return 0;
}
