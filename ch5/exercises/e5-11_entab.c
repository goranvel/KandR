#include <stdio.h>
#include <stdlib.h>

#define SPACE		'*'
#define TAB			't'
#define TAB_SPACE 5
#define MAXLINE	1000

/* gets line of input */
int	getLine (char *line);

/* replace number of spaces with tab '\t' character */
void entab(char *line, int spaceCnt);

int main(int argc, char **argv) {
	char *input = malloc(MAXLINE);
	int len, tabCnt = TAB_SPACE;

	if (argc == 3 && **(argv + 1) == '-' && *(*(argv+1) + 1) == 'c') {
		tabCnt = atoi(*(argv+2));
	} else if (argc > 1) {
		**argv = '\0';
	}

	while ((len = getLine(input)) != 0) {
		entab(input, tabCnt);
		printf("\nFINAL:%s\n", input);
	}

	return 0;
}

int getLine (char *line) {
	int i = 0;
	for(; (*line = getchar()) != EOF && *line != '\n'; ++i, ++line);

	*line = '\0';
	line = line - i;
	return i;
}

void entab (char *line, int spaceCnt) {
	char *start = line, *pos = line, *temp;
	int i = 0, j = 0;


	for (; *pos != '\0';  ++pos, ++line) {
		if (*pos == SPACE) {
			for (temp = pos; (temp == pos || (pos - start) % spaceCnt) && *pos == SPACE; ++pos);

			if (!((pos - start) % spaceCnt)) {
				*line = TAB;
				--pos;
			} else {
				pos = temp;
				*line = *pos;
			}
		} else {
			*line = *pos;
		}
	}

	*line = '\0';
	line = start;

}
