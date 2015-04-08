#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void){
	printf("%d\n", ~setbits(~1, 5, 3, 2));
}

int setbits(int x, int p, int n, int y) {
	return (x & ((~0 << p+1) | 
		~(~0 << p+1-n))) | ((y & ~(~0 << n)) << (p+1-n)) ;
}
