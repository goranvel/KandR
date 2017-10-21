#include <stdio.h>
#include <stdlib.h>

#define TAB_SPACE 8
#define MAXLINE	1000

int getLine(char *line);
int detab(char *line, int start);

int main(void) {
	char *input = malloc(sizeof(char)*MAXLINE);
	int len;

	while ((len = getLine(input)) != 0) {
		printf("%s\n", input);
	}

	return 0;
}

int getLine(char *line) {
	int i = 0;

	for(; i < MAXLINE - 1 && (*line = getchar()) != EOF && *line != '\n'; ++i, ++line) {

		if(*line == '\t') {
			int j = i;
			printf("in %d \n", line);
			i = detab(line, i);
			printf("%s \n", line);
			line += (i - j);
			printf("out %d \n", line);
		}
	}

	*line = '\0';
	return i;
}

int detab(char *line, int pos) {
	int i =  pos % TAB_SPACE;
	while (i < TAB_SPACE) {
		*line++ = '*'; ++i;
	}

	return pos + i - pos % TAB_SPACE - 1;;
}
