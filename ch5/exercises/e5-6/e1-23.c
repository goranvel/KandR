#include <stdio.h>
#include <stdlib.h>

#define MAXFILE	10000

int getLine(char line[]);
void removeComments(char *line);
void removeLine(char *line);
void removeChars(char *start, char *end);

int main(void) {
	char *line = malloc(MAXFILE * sizeof(char));

	while (getLine(line) != 0) {
		printf("Got line %s\n", line);
		removeComments(line);
		printf("---------------------------------\n");
		printf(line);
	}

	return 0;
}

int getLine(char *line) {
	int i = 0;
	for(; i < MAXFILE && (*line = getchar()) != EOF; ++line, ++i);
	*line = '\0';

	return i;
}

void removeComments(char *line) {
	int i = 1;
	char isString = 0, isComment = 0;
	
	while(*line != '\0') {
		if(*line =='\"' && !isString && !isComment)
			isString = 1;
		else if (*line == '\"' && isString)
			isString = 0;

		if (*line == '/' && !isString && !isComment) {
			if (*(line + 1) == '/')
				removeLine(line);
			else if (*(line + i) == '*') {
				while (*(line + i + 1) != '*' && *(line + i + 2) != '/')
					++i;

				i += 3;
				if(*(line + i) == '\n')
					++i;

				removeChars (line, line+i);
				i = 1; 
			}
			--line;
		}
		++line;
	}
}

void removeLine (char *line) {
	char *start = line;

	while (*line++ != '\n');

	while(*line != '\0')
		*start++ = *line++;

	*start = '\0';
}

void removeChars (char *start, char *end) {
	while (*end != '\0')
		*start++ = *end++;

	*start = '\0';
}
