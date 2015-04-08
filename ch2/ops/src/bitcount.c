#include <stdio.h>

int bitcount(unsigned x);

int main(void){
	printf("%d > %d\n", ~0, bitcount(~0));

	return 0;
}

int bitcount(unsigned x){
	int b;

	for(b = 0; x != 0; x >>= 1){
		if(x & 01){
			b++;
		}
	}
	
	return b;
}
