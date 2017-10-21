#include <stdio.h>
#include <stdlib.h>

#define ENTAB		'*'
#define TAB_SPACE	5
#define MAXLINE	1000

int getLine(char * line);
void entab(char * line);

int main(void) {
	char *input = malloc(MAXLINE * sizeof(char));
	int len;
	while (( len = getLine(input)) > 0) {
		entab(input);
		printf("%s \n", input);
	}

	free (input);
	return 0;
}

int getLine(char *line) {
	int i = 0;
	char *input = line;
	for(i = 0; i < MAXLINE - 1 && (*line = getchar()) != EOF && *line != '\n'; ++line, ++i);

	*line = '\0';
	return  i;
}

void entab(char *line) {
	int i = 0, j = 0, k = 0;
	for(;*(line + j) != '\0'; ++i, ++line) {
		for(k = 0;k < TAB_SPACE && *(line + j) == ENTAB && ((i + j) % TAB_SPACE || i == 0); ++k, ++j);

		if (k > 0 && *(line + j - 1) == ENTAB && !((i + j) % TAB_SPACE)) {
			printf("IN 1");
			*line = 't';
			for(k = 1;k < TAB_SPACE && *(line + j + k) == ENTAB && ((i + j + k) % TAB_SPACE); ++k);
			if(*(line + j) != ENTAB || (i + j + k) % TAB_SPACE)
				--j;
		} else if (k > 0 && *(line + j - 1) == ENTAB &&*(line + j) != ENTAB && (i + j) % TAB_SPACE) {
			printf("IN 2");

			j -= k;
			*line = *(line + j); 
		} else {
			printf("IN 3");

			*line = *(line + j);
		}
	}

	*line = '\0';
}
