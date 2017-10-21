#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getlin(char *);
void reverseString(char *, int);

int main(void) {
	char *line = malloc(MAXLINE*sizeof(char));

	int len = getLine(line);
	reverseString(line, len);

	printf("%s \n", line);

	return 0;
}

int getLine(char *s) {
	int i = 0;
	for(;(*s = getchar()) != EOF && *s != '\n' && i < MAXLINE; ++i, ++s);

	*s = '\0';

	return i;
}

void reverseString(char *str, int len) {
	char *end  = len + str - 1;
	char temp = 0;
	printf("<< %s >>\n", str);
	for(;str < end; --end, ++str) {
		temp = *str;
		*str = *end;
		*end = temp;
	}
}
