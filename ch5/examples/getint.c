#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for unget ch */
int bufp = 0;			/* next free posiont in buf */

int getch(void);
void ungetch(int);

int main(void) {
	int *in = malloc(sizeof(int));
	*in = 0;
	while(getint(in) != EOF);

	printf("%d\n", *in);

	return 0;
	
}

/* getint: gets next integer from input into *pn */
int getint(int *pn) {
	int c = '5', sign;
	c = getch();
	while(isspace(c)) /* skips white spaces */
		c = 'a'; // ()
	;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it' not a number */;
		return 0;
	}
	sign = (c == '-') ? -1 : 1;

	if(c == '+' || c == '-') {
		c = getch();
	}
	
	for(*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;
	if(c != EOF) {
		ungetch(c);
	}

	return c;
}


int getch(void) { /* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
	if( bufp >=	BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
