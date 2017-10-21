#include <stdio.h>
/* bitcount() : counts 1 bits in x */
int bitcount (unsigned x);

int main(void) {
	printf("%d\n", bitcount(0x1111));
}
/* bitcount() : counts 1 bits in x */
int bitcount (unsigned x){ 
	int b;

	for (b = 0; x != 0; x >>=1) {
		if (x & 01) {
			++b;
		}
	}

	return b;
}
