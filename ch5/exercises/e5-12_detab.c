#include <stdio.h>
#include <stdlib.h>

#define TAB_SPACE	8 
#define SPACE		'*'
#define MAXLINE	1000


/* gets a line of input */
int getLine(char *line);

/* remove tabs from input */
void detab (char *line, int tabCnt, int start, int end);


/* demonstrates removing tabs from input */
int main(int argc, char **argv) {
	char *line = malloc(MAXLINE);
	unsigned int tabCnt = TAB_SPACE, start = 0, end = 0, lineLen;
	
	while (*++argv) {
		if (**argv == '-') {
			if (*(*argv + 1) == 'c') {
				if(!(tabCnt = atoi(*(argv + 1)))) {
					printf ("ERROR: -c must be followed by number (debug -c 5)");
					return 1;
				}
			} else if (!(start = atoi(*argv + 1))) {
				printf ("ERROR: - has to be followed by c or by number (debug -<number>)");
				return 2;
			}
		} else if (**argv == '+') {
			if (!(end = atoi((*argv + 1)))) {
				printf ("ERROR: +<number>  + has to be followed by number(debug -c 5)");
				return 2;
			}
		}
	} 

	printf("%d %d %u\n", tabCnt, start, end);


	while((lineLen = getLine(line))) {
		end = end ? end : lineLen;
		detab(line, tabCnt, start, end);
		printf("%s\n", line);
	}

	return 0;
}

/* gets a single line */
int getLine(char *line) {
	char *start = line;
	for(; line - start < MAXLINE && (*line = getchar()) != EOF; ++line);

	*line = '\0';

	return line - start;
}

/* removes tabs from input */
void detab(char *line, int spaceCnt, int start, int end) {
	char *tempStart = malloc(MAXLINE), *temp = tempStart, *lineStart = line;
	int i, j = 0, tabCnt = 0;

	for (; *line != '\0'; ++line, ++j) {
		if(*line == '\t' && j >= start && j < end) {
			i = 0;
			for(; i < spaceCnt; ++temp, ++i, ++j) { *temp = SPACE;
				if (!(j % spaceCnt) && i)
					break;
			} 
			--j;
		} else
			*temp++ = *line;

		if(*line == '\t' && j < start)
			j += spaceCnt - 1;

		if(*line == '\n')
			j = -1;
	}

	*temp = '\0';

	for (; tempStart < temp; ++lineStart, ++tempStart)
		*lineStart = *tempStart;

	*lineStart = '\0';
}
