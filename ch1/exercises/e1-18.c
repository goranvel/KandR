#include <stdio.h>

#define MAXLINE 1000

/* gets a single line */
int getLine(char line[]);
/* removes trailing blank spaces */
int removeTrailingBlanks(char line[], int len);

/* this program removes all trealing spaces */
main() {
	char line[MAXLINE];
	int len = 0;	
	while((len = getLine(line)) != -1){
		len = removeTrailingBlanks(line, len);
		printf("%s\n", line);
	}
}

/* gets a single line */
int getLine(char s[]) {
	int i = 0;
	for(;(s[i] = getchar()) != EOF && s[i] != '\n' && i < MAXLINE - 1; ++i);

	s[i] = '\0';

	return i;
}

/* removes trailing blanks from line */
int removeTrailingBlanks(char line[], int len) {
	for(;(line[--len] == ' ' || line[len] == '\t'););

	line[++len] = '\0';

	int len;
}
