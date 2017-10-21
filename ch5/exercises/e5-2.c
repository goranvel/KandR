#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getFloat(float);

int main(void) {
	float *in = malloc(sizeof(float));

	*in = 0;

	getFloat(in);

	printf("%f \n", *in);

	return 0;
}

int getFloat (float *pn) {
	int c, sign;

	while(isspace(c = getch())); // skips white spaces

	if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* its is not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if(c == '+' || c == '-') {
		while(!isdigit(c = getch()));
	}
	
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
	}

	if(c == '.') {
		c = getch();
	}

	int power;
	for(power = 1; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		printf("%.10f <<\n", *pn);
		power *= 10;
		printf("%d \n", power);
	}
	

	*pn *= sign;
	*pn /= power;
	if(c != EOF) {
		ungetch(c);
	}

	return c;
}

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}
