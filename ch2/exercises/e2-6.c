#include <stdio.h>

/* setbits() : sets n bits at position p in x to be the same as last n
		bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
	printf("0x%x \n", setbits(0x00, 4, 3, 0xd));

	return 0;
}

/* setbits() : sets n bits at position p in x to be the same as last n
		bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return (x & ((~0 << p) | ~(~0 << (p - n)))) | ((y & ~(~0 << n)) << (p-n));
}
