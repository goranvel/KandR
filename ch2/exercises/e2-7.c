#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
	printf("0x%x \n", invert(0xf7, 5, 3));
	return 0;
}
unsigned invert(unsigned x, int p, int n) {
	return (x & ((~0 << p) | ~(~0 << (p - n)))) | (~x & ~((~0 << p) | ~(~0 << (p - n))));
}
