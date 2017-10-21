#include <stdio.h>

/* getbits(): get n bits from position p */
unsigned getBits(unsigned x, int p, int n);

int main(void) {
	printf("%u \n", getBits(13, 4, 3));
	return 0;
}

/* getbits(): get n bits from position p */
unsigned getBits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n))  & ~(~0 << n);
} 
