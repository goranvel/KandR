#include <stdio.h>

unsigned long int next = 1;

/* rand: returns pseudo random intiger on 0 - 32767 */

int rand(void) {
	next = next * 1103515245 + 12345;
	return next/65536 % 32768;
}
