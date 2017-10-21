#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getLine(char *line, int maxlen);

void copy(char *to, char *from);

int main(void) {
	int len, max = 0;
	char *line = malloc(MAXLINE*sizeof(char));
	char longest[MAXLINE];

	while	((len = getLine(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy (longest, line);
		}
	}

	if (max > 0) {
		printf("Lenght\t| line\n");
		printf("%i\t| %s", max, longest);
	}

	return 0;
}

int getLine(char *s, int lim) {
	int c, i = 0;;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i, *s++ = c);

	if(c == '\n') {
		*s++ = c;
	}

	*s = '\0';

	return i;
}

void copy(char *to, char *from) {
	while((*to++ = *from++) != '\0');
}
