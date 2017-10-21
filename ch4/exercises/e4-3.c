#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP	100	/* max size of operand or operator */

#define NUMBER	'0'	/* signal that a number was found */

#define MAXVAL	100	/* maximum depth of val stak */

#define BUFSIZE	100	/* buffer for ungetch */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;	/* next free position in buf */

/* reverse Poslish calculator */
int main(void) {
	int type, modVal1, modVal2;
	double op2;
	char s[MAXOP];

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
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				if((op2 = pop()) != 0) {
					push(pop() / op2);
				} else {
					printf("ERROR: Cannot devide by 0");
				}
				break;
			case '%':
				if((modVal2 = pop()) != 0) {
					modVal1 = pop();
					push(modVal1 % modVal2);
				} else {
					printf("ERROR: Cannot devide by 0");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("ERROR: unknon comand %s\n", s);
				break;
		}
	}

	return 0;
}

/* push(): push f onto value stack */
void push(double f) {
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("ERROF: Stack is full cannot push %g\n", f);
}

/* pop() pop and return top value from stack */
double pop(void) {
	if(sp > 0)
		return val[--sp];
	else 
		printf("ERROR: stack empty\n");

	return 0.0;
}

/* getop(): get next operator or number */
int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	
	i = 0;
	if(isdigit(s[i]))	/* colect ingeter part */
		while (isdigit(s[++i] = c = getch()));

	if(s[i] == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}

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
