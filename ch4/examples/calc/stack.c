#include <stdio.h>
#include "calc.h"

#define MAXVAL	100	/* maximum depth of val stak */

int sp = 0;
double val[MAXVAL];

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
