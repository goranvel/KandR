#include <stdio.h>
#include <stdlib.h>

#define SPACE		'*'
#define TAB			't'
#define TAB_SPACE 5
#define MAXLINE	1000

/* gets line of input */
int	getLine (char *line);

/* replace number of spaces with tab '\t' character */
void entab(char *line, unsigned int spaceCnt, unsigned int start, unsigned int end);

int main(int argc, char **argv) {
	char *input = malloc(MAXLINE);
	unsigned int len, tabCnt = TAB_SPACE, start = 0, end = ~0;

	while (*++argv) {
		if (**argv == '-') {
			if (*(*argv + 1) == 'c') {
				if(!(tabCnt = atoi(*(argv + 1)))) {
					printf ("ERROR: -c must be followed by number (debug -c 5)");
					return 1;
				}
			} else if (!(start = atoi(*argv + 1))) {
				printf ("ERROR: -<number> (debug -c 5)");
				return 2;
			}
		} else if (**argv == '+') {
			if (!(end = atoi(*argv + 1))) {
				printf ("ERROR: -<number> (debug -c 5)");
				return 2;
			}
		}
	} 

	while ((len = getLine(input)) != 0) {
		entab(input, tabCnt, start, end);
		printf("%s\n", input);
	}

	return 0;
}

int getLine (char *line) {
	int i = 0;
	for(; (*line = getchar()) != EOF; ++i, ++line);

	*line = '\0';
	line = line - i;
	return i;
}

void entab (char *line, unsigned spaceCnt, unsigned start, unsigned end) {
	char *beg = line, *colEnd = line + end + spaceCnt - end % spaceCnt - 1;
	line = line + start + spaceCnt - start % spaceCnt;
	char *pos = line, *colStart = pos, *temp;
	printf("%d \n", spaceCnt - start % spaceCnt);
	int i = start + spaceCnt - start % spaceCnt; 

	for (; *pos != '\0';  ++pos, ++line, ++i) {
		if (*pos == SPACE && i > start && i < end) { 
			for (temp = pos; (temp == pos || i % spaceCnt) && *pos == SPACE; ++pos);

			if (!(i % spaceCnt)) {
				*line = TAB;
				--pos;
				--i;
			} else {
				pos = temp;
				*line = *pos;
			}
		} else {
			*line = *pos;
		}

		if (*line == '\n') {
			colStart = pos + start + spaceCnt - (start % spaceCnt) - 1;
			colEnd	= pos + end + spaceCnt - (end % spaceCnt) - 1;	
		}
	}

	*line = '\0';
	line = beg;

}
