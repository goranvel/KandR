#include <stdio.h>

/* count character in input;
1st version */

void main() {
	long nc = 0;

	while(getchar() != EOF) {
		++nc;
	}
	
	printf("%ld\n", nc);
}
