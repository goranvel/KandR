#include <stdio.h>

#define MAXLINE 1000 /* maximum input size */

/* gets one line of input */
int getLine(char line[], int maxline);
/* copies array of characters */
void copy(char to[], char from[]);

/* print longest input line */
main() {
	int len;						/* current line */
	int max;						/* maximum lenght seedn so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while((len = getLine(line, MAXLINE)) > 0) {
		if(len > max) {
			max = len;
			copy(longest, line);
		}
	}
	
	if(max > 0) { /* there was a line */
		printf("Lenght\t| Line\n");
		printf("%i\t| %s", max, longest);
	}
}

/* getline:	read a line into s, return lenght */
int getLine(char s[], int lim) {
	int c = 0, i = 0;

	for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c !='\n'; ++i)
		s[i] = c;
	
	if(c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}

/* copy: copies character array from  'from' into 'to'; assumes 'to' is big enough */
void copy(char to[], char from[]) {
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
