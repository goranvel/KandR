#include <stdio.h>
#include <ctype.h>

int main (void) { /* lower: convert input into lower case */
	int c;
	
	while ((c = getchar()) != EOF)
		putchar (tolower(c));

	return 0;
}
