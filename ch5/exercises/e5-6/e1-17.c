#include <stdio.h>
#include <stdlib.h>

#define MAXLEN		1000
#define PRINTABLE	10

int getLine(char *);
void printLongs(char *);
int getSize(char *);

int main(void) {
	char *line = malloc(MAXLEN * sizeof(char));

	while(getLine(line) != 0)
		printLongs(line);

	return 0;
}

int getLine(char *s) {
	int i = 0;
	for(;(*s = getchar()) != EOF && *s != '\n' && i < MAXLEN; ++i, ++s);

	*s = '\0';
	return i;
}

void printLongs(char *s) {
	if(getSize(s) < PRINTABLE)
		return;

	printf("%s\n", s);
}

int getSize(char *s) {
	int i = 0;
	for(i = 0; *s != '\0' && i < MAXLEN; ++s, ++i);

	return i;
}
