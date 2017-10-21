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
	int varPos = 0, varIsSet = 0;
	int *vars = malloc(sizeof(int) * ('z' - 'a') << 1);

	while((type = getop(s)) != EOF) {
		if	(isalpha(type)) {
			if ((type - 'a') >= 0) {
				varPos = type - 'A';
				if((varIsSet >> varPos) & 0x1) {
					push(*(vars + varPos));
					varIsSet &= ~(0x1 << varPos);
				} else {
					*(vars + varPos) = pop();
					varIsSet |= 0x1 << varPos;
				}
			} else {
				varPos = type - 'A' + 'Z';
				if((varIsSet >> varPos) & 0x1) {
					push(*(vars + varPos));
					varIsSet &= ~(0x1 << varPos);
				} else {
					*(vars + varPos) = pop();
					varIsSet |= 0x1 << varPos;
				}
			}
			varPos = 0;
		} else {
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
				case '\n':
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
	}

	return 0;
}

void push(double f) {
	val < maxVal ? *val++ = f : printf("ERROR: Stack is full cannot push $g\n", f);
}

double pop(void) {
	return val > startVal ? *--val : 0.0;
}

int getop (char *s) {
	char *start = s;

	while ((*s = getch()) == ' ' || *s == '\t');

	*(s + 1) = '\0';
	if(!isdigit(*s) && *s != '.')
		return *s;

	s = start;
	if(isdigit(*s))
		while (isdigit(*++s = getch()));

	if(*s == '.')
		while (isdigit(*++s = getch())); 

	if(*s != EOF)
		ungetch(*s);

	return NUMBER;
}

int getch (void) {
	return buf != bufStart ? *--buf : getchar();
}

void ungetch (int c) {
	(buf - bufStart) > BUFSIZE ? printf("ungetch: too many hcaracters\n") : (*buf++ = c);
}

void ungets(char *s) {
	for(; buf > bufStart; ++buf)
		*buf++ = *--s;
}
