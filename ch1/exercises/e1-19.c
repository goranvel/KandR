#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[]);
void reverseString(char from[], char to[], int len);

main() {
	char line[MAXLINE];
	char reverse[MAXLINE];
	
	int len = getLine(line);
	reverseString(line, reverse, len);

	printf("%s <> %s\n", line, reverse);	
}

int getLine(char s[]) {
	int i = 0;
	for(;(s[i] = getchar()) != EOF && s[i] != '\n' && i < MAXLINE; ++i);

	s[i] = '\0';

	return i;
}

void reverseString(char from[], char to[], int len) {
	int i = 0; 
	while(len > 0) {
		to[i++] = from[--len];
	}
}
