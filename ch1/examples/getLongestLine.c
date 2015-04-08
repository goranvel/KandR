#include <stdio.h>

#define MAXLINE 1000 /* MAXIMUM INPUT LINE SIZE */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

main() {
	int len;						/* current line lenght */
	int max;						/* maximum lenght seen so far */
	char line[MAXLINE];		/* current line saved here */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while((len = getLine(line,	MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if(max > 0) { /* there was a line */
		printf("%s\n", longest);
	}

	return 0;
}

/* getLine: read a line into s, retunr lenght */
int getLine(char s[], int lim) {
	int c, i = -1;
	
	for (i = 0; i < lim - 1 && (c = getchar())  != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
