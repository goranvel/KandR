#include <stdio.h>

#define TAB_SPACE 5
#define SPACE		'*'
#define MAXLINE	1000

/* gets a line of input */
int getLine(char line[]);
/* removes tabls from input */
//int detab (char line[], int start);
void detab (char line[]);

/* demonstrates removing tabs from input */
main() {
	char input[MAXLINE];
	int len;
	
	while((len=getLine(input)) != 0) {
		detab(input);
		printf("%s\n", input);
	}
}

/* gets a single line */
int getLine(char line[]){
	int i = 0;
	for(;i < MAXLINE && (line[i] = getchar()) != EOF && line[i] != '\n'; ++i);

	line[i] = '\0';

	return i;
}

/* removes tabs from input */
void detab(char line[]) {
	char temp[MAXLINE];
	int i = 0, j = 0, start;

	while (line[i] != '\0') {
		if (line[i] == '\t') {
			start = 0;	// value to represent start of the line (0 % N = 0)
			for(; start < TAB_SPACE; ++j, ++start) { // replaces TAB with spaces
				temp[j] = SPACE;
				if (!(j % TAB_SPACE) && start )	// if TAB was replaced with enough spaces breaks
					break;
			}
		} else  {
			temp[j] = line[i];
			++j;
		}
		++i;
	}

	temp[j] = '\0';
	
	for(i = 0; i <= j; ++i) {
		line[i] = temp[i];
	}
}
