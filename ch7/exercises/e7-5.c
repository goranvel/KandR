#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP		100
#define NUMBER		'0'
#define MAXVAL		100
#define BUFSIZE	100

int		getop(char*);
void		push(double);
double	pop(void);
int		getch(void);
void		ungetch(int);

double *val, *maxVal, *startVal;
char	 *buf, *bufStart;

int main(void) {
	val = malloc(sizeof(double) * MAXVAL);
	buf = bufStart = malloc(sizeof(char) * BUFSIZE);
	startVal = val;
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
				op2 != 0 ? push(pop()/op2) : printf("ERROR: cannot devide by 0");
			}
				break;
			case '%': {
				int modVal2 = pop(), modVal1 = pop();
				modVal2 ? push(modVal1 % modVal2) : printf("ERROR: cannot devide by 0");
			}
				break;
			case '=':
				printf("\t%.8g\n", pop());
				break;
			case '~':
				push(sin(pop()));
				break;
			case '`':
				push(exp(pop()));
				break;
			case '^': {
				double op2 = pop();
				push(pow(pop(), op2));
			}
				break;
			case '<':
				while (val > startVal) pop();
				break;
			case '@': {
				double op2 = pop();
				push(pop());
				push(pop());
			}
				break;
			default:
				printf("EROOR: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

int getop (char *s) {
	int val = 0;
	if ((val = scanf("%s", s)) == 0 || val == EOF) {
		return EOF;
	}

	if (isInt (s) || isFloat(s)) {
		return NUMBER;
	}

	return *s;
}

int isInt (char *s) {
	for (;*s != '\0' && isdigit(*s); ++s);

	return *s == '\0' ? 1 : 0;
}

int isFloat (char *s) {
	for (;*s != '\0' && isdigit (*s); ++s);

	if (*s != '.')
		return 0;

	return isInt (s) ? 1 : 0;
}

void push(double f) {
	val < maxVal ? *val++ = f : printf("ERROR: Stack is full cannot push $g\n", f);
}

double pop(void) {
	return val > startVal ? *--val : 0.0;
}
