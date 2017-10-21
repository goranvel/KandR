#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "calc.h"

#define MAXOP	100	/* max size of operand or operator */

/* reverse Poslish calculator */
int main(void) {
	int type;
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
