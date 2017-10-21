#include <stdio.h>

#define MAXLINE 1000

/* gets a line of input */
int getLine(char line[]);
/* reverses given string */
void reverseString(char from[], char to[], int len);

/* Revrsing string program */
main() {
	char line[MAXLINE];
	char reverse[MAXLINE];
	
	int len = getLine(line);
	reverseString(line, reverse, len);

	printf("%s <> %s\n", line, reverse);	
}

/* gets a line of input */
int getLine(char s[]) {
	int i = 0;
	for(;(s[i] = getchar()) != EOF && s[i] != '\n' && i < MAXLINE - 1; ++i);

	s[i] = '\0';

	return i;
}

/* reverses a string */
void reverseString(char from[], char to[], int len) {
	int i = 0; 
	while(len > 0) {
		to[i++] = from[--len];
	}
}
