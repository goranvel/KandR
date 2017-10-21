#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void) {
	printf("0x%0x\n", rightrot(0xffffffae, 8));

	return 0;
}

unsigned rightrot(unsigned x, int n) {
	unsigned i = 1;
	while(i > 0){
		i <<= 1;
	}
	return x >> n | x << (i - n);
}
