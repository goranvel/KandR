#include <stdio.h>

/* puts each word into new line */
main() {
	char c = 0;

	while((c = getchar()) != EOF) { /* gets input from user */
		if(c == ' ' || c == '\t') { /* replaces space and tab with new line */
			c = '\n';
		}
		putchar(c);
	}
}
