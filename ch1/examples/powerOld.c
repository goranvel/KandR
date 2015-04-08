#include <stdio.h>

int power();

/* test power function */
void main() {
	int i;
	
	for(i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	
}

/* power : raise base to n-th power; n>0 
		old-style version */
int power(base, n)
	int base, n; {
	int i, p = 1;

	for(i = 1; i <= n; ++i)
		p = p * base;
	
	return p;
}
