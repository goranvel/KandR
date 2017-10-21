#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <ctype.h>
#include <math.h>		/* for math functions */


#define MAXOP		100	/* max size of operand or operator */
#define NUMBER		'0'	/* signal that a number was found */
#define MAXVAL		100	/* maximum depth of val stak */
#define BUFSIZE	100	/* buffer for ungetch */


int	getop(char *, char *);
void	push(double);
double	pop(void);
// int getLine(void);
/* int	getch(void);
void	ungetch(int);
void	ungets(char []); */


int		sp = 0;		/* next free stack position */
double	val[MAXVAL];	/* value stack */

// char	buf[BUFSIZE];	/* buffer for input */
// int	bufp = 0;		/* next command */

/* reverse Poslish calculator */
int main(int argc, char **argv) {
	int type, modVal1, modVal2;
	double op1, op2;	/* op1 if used is 1st number in operation */
	char s[MAXOP];
	int varIsSet = 0; /* special variable for bitwise operation to check wich 
								variable is set and which is not */
	int varPos = 0;	/* tipicaly holds the variable position in vars[] array */
	int vars[('z' - 'a') << 1];

	int i = 1;
	while(--argc && (type = getop(*++argv, s)) != '\0') {
		if(isalpha(type)) {
			if ((type - 'a') >= 0) {
				varPos = type - 'A';
				if((varIsSet >> varPos) & 0x1) {	
					push(vars[varPos]);
					varIsSet &= ~(0x1 << varPos);
				} else {
					vars[varPos] = pop();
					varIsSet |= 0x1 << varPos;
				}
			} else {
				varPos = type - 'A' + 'Z';
				if((varIsSet >> varPos) & 0x1) {
					push(vars[varPos]);
					varIsSet &= ~(0x1 << varPos);
				} else {
					vars[varPos] = pop();
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
				case '~':	/* sin function */
					push(sin(pop()));
					break;
				case '^':	/* power function */
					op2 = pop();
					push(pow(pop(), op2));
					break;
				case '`':	/* for exponential function */
					push(exp(pop()));
					break;
				case '<':	/* clear the stack */
					while(sp > 0){
						pop();
					}
					break;
				case '@':	/* duplicates last element */
					op2 = pop();
					push(op2);
					push(op2);
					break;
				case '#':	/* print the stack */
					printf("%.8g ", val[sp]);
					break;
				case '|': /* swap the top two elements of stack */
					op1 = pop();
					op2 = pop();
					push(op1);
					push(op2);
					break;
				default:
						printf("ERROR: unknon comand %s\n", s);
			}
		}
	}

	printf("\t%.8g\n", pop());

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

	return 0.0;
}

/* getop(): get next operator or number */
int getop(char *arg, char *s) {
	char* i = s;

	if (!isdigit(*arg) && *arg != '.')
		return *arg; /* not a number */

	if(isdigit(*arg))	/* colect ingeter part */
		while (isdigit(*s++ = *arg++));

	if(*arg == '.')	/* collect fraction part */
		while (isdigit(*s++ = *++arg));

	*s = '\0';
	s = i;
	printf("%s\n", s);
	return NUMBER;
}
