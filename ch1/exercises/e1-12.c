#include <stdio.h>

main() {
	char c = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t') {
			c = '\n';
		}
		putchar(c);
	}
}
