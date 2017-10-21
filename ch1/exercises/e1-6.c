#include <stdio.h>

/* Verifies if getchar() is EOF */
int main() {
	int c;
	c = getchar() != EOF;
	printf("%d \n", c);
}
