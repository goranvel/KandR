#include <stdio.h>

unsigned int getbits(unsigned int x, int p, int n);

int main(void){
	printf("%x", getbits(40, 5, 3));

	return 0;
}

unsigned int getbits(unsigned int x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}
