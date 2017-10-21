#include <stdio.h>

#define BUFSIZE	100	/* buffer for ungetch */

char buf[BUFSIZE];

int bufp = 0;

/* get a posibly pushed back) character */
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characcters\n");
	else
		buf[bufp++] = c;
}
