#include <stdio.h>

#define SPACE		' '
#define TAB			'\t'
#define TAB_SPACE	5
#define MAXLINE	1000

/* gets line of input */
int	getLine(char line[]);
/* replaces TAB_SPACE ammount of spaces with TAB \t */
void	entab(char line[]);

/* Demonstrates replacing spaces with tab
	This uses Microsoft Word style of tab removal
		EXAMPLE: 'abc    d' would become 'abc\t  d' */
main() {
	char input[MAXLINE];
	int len;

	while((len = getLine(input)) != 0) {
		entab(input);
		printf("\nFINAL:%s\n", input);
	}

	return 0;
}

/* gets a single line of input */
int getLine(char line[]) {
	int i = 0;
	for(; i < MAXLINE && (line[i] = getchar()) != EOF && line[i] != '\n'; ++i);

	line[i] = '\0';
	return i;
}

/* replacews TAB_SPACE ammount of spaces with TAB \t character */
void entab(char line[]){
	int i = 0, j = 0, k = 0;
	for (; line[i] != '\0'; ++i, ++j) {	// traverses the line
		if(line[i] == SPACE) {	// checks if current position is space
			for(k = i; (k == i || i % TAB_SPACE) && line[i] == SPACE; ++i); //

			if (!(i % TAB_SPACE)){ // checks if cursor position has no remainder 
				line[j] = TAB;	// replaces the space with TAB
				--i;
			} else {
				i = k;
				line[j] = line[i];
			}
		} else {
			line[j] = line[i];
		}
	}
	line[j] = '\0';
}
