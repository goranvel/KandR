#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[]);
void removeTrailingBlanks(char line[], int len);

main() {
	char line[MAXLINE];
	int len = 0;	
	while((len = getLine(line)) != -1){
		removeTrailingBlanks(line, len);
		printf("%s|\n", line);
	}
}

int getLine(char s[]) {
	int i = 0;
	for(;(s[i] = getchar()) != EOF && s[i] != '\n' && i < MAXLINE - 1; ++i);

	s[i] = '\0';

	return i;
}

void removeTrailingBlanks(char line[], int len) {
	for(;(line[--len] == ' ' || line[len] == '\t'););

	line[++len] = '\0';
}
