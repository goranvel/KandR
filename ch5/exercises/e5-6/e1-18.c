#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int getLine(char *line);
int removeTrailingBlanks (char *line, int len);

int main(void) {
	char *line = malloc(MAXLEN*sizeof(char));
	int len = 0;

	while((len = getLine(line)) > 0) {
		printf("%d %s|\n",len, line);

		len = removeTrailingBlanks(line, len);
		printf("%d %s|\n",len, line);
	}

	return 0;
}

int getLine(char *s) {
	int i = 0;
	for(;(*s = getchar()) != EOF && *s != '\n' && i < MAXLEN - 1; ++i, ++s);

	*s = '\0';
	return i;
}

int removeTrailingBlanks(char *line, int len) {
	for(line+=len-1; *line == ' ' || *line == '\t'; --len, --line)printf("return \n");

	*++line = '\0';
	
	return len;
}
