#include <stdio.h>
#include <stdlib.h>


#define TAB_SPACE	8 
#define SPACE		'*'
#define MAXLINE	1000

/* gets a line of input */
int getLine(char *line);

/* remove tabs from input */
void detab (char *line, int tabCnt);

/* demonstrates removing tabs from input */
int main(int argc, char **argv) {
	char *line = malloc(MAXLINE);
	int len, tabCnt = TAB_SPACE;
	if (argc == 3 && **(argv+1) == '-' && *(*(argv + 1)+1) == 'c') {
		tabCnt = atoi(*(argv+2));
	} else if ( argc > 1) {
		argv = '\0';
	}

	while((len = getLine(line))) {
		detab(line, tabCnt);
		printf("%s\n", line);
	}

	return 0;
}

/* gets a single line */
int getLine(char *line) {
	char *start = line;
	for(; line - start < MAXLINE && (*line = getchar()) != EOF && *line != '\n'; ++line);

	*line = '\0';

	return line - start;
}

/* removes tabs from input */
void detab(char *line, int tabCnt) {
	char *tempStart = malloc(MAXLINE), *temp = tempStart, *lineStart = line;
	int i;
	
	for (; *line != '\0'; ++line)
		if(*line == '\t') {
			i = 0;
			for(; i < tabCnt; ++temp, ++i) {
				*temp = SPACE;
				if (!((temp - tempStart) % tabCnt) && i)
					break;
			}
		} else
			*temp++ = *line;

	*temp = '\0';

	for (; tempStart < temp; ++lineStart, ++tempStart)
		*lineStart = *tempStart;

	*lineStart = '\0';
}
