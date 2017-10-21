#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP		100
#define NUMBER		'0'
#define MAXVAL		100
#define BUFSIZE	100

// int	getop	(char *);
int	getop (char []);
void	push	(double);
double pop	(void);
void ungetch(int);

double	*val, *maxVal;
char		*buf, *bufStart;

int main(void) {
	val = malloc(sizeof(double) * MAXVAL);
	buf = bufStart = malloc(sizeof(char) * BUFSIZE);
	maxVal = val + MAXVAL;
	int type;
	char *s = malloc(sizeof(char) * MAXOP);
	
	while((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-': {
				double op2 = pop();
				push(pop() - op2);
				}
				break;
			case '/': {
				double op2 = pop();
				op2 != 0 ? (push(pop() / op2)) : 
					printf ("ERROR: Cannot divide by 0\n");
				}
				break;
			case '%': {
				int mod2 = pop(), mod1 = pop();
				mod2 != 0 ? push(mod1 % mod2) :
					printf ("ERROR: Cannot divide by 0");
				}
				break;
			case '\n':
				printf("\5%.8g\n", pop());
				break;
			default:
				printf("ERROR: unknown command %d\n", *s);
				break;
		}
	}

	return 0;
}

void push(double f) {
	if(val < maxVal)
		*val++ = f;
	else
		printf("ERROF: Stack is full cannot push %g\n", f);
}

double pop(void) {
	if (val > maxVal - MAXVAL)
		return *--val;
	else
		printf("ERROR: stack is empty\n");

	return 0.0;
}

int getop(char *s) {
	char *start = s;

	while((*s = getch()) == ' ' || *s == '\t');

	*(s + 1) = '\0';
	if(!isdigit(*s) && *s != '.')
		return *s;

	s = start;
	if(isdigit(*s))
		while (isdigit(*++s = getch()));

	if (*s == '.')
		while (isdigit(*++s = getch()));

	if (*s != EOF)
		ungetch(*s);
	*s = '\n';
	return NUMBER;
}

int getch (void) {
	return buf != bufStart ? *--buf : getchar();
}

void ungetch (int c) {
	(buf - bufStart) > BUFSIZE ? printf("ungetch: too many characters\n") :
		(*buf++ = c);
} 
