#include <stdio.h>

/* bitcount(): count 1 bits in x */
int bitcount(unsigned x);

int main (void) {
	printf("%d\n", bitcount(0xffff));
}

int bitcount(unsigned x) {
	int b;
	for(b = 0; x > 0; ++b, x &= (x-1));
	return b;
}
