#include <stdio.h>

/* replaces tab with \t
				backspace with \b
				backslahs with \\
*/
main() {
	char c;

	while((c = getchar()) != EOF) {
		if(c == '\t') {
			putchar('\\');
			putchar('t');
		} else if(c == '\b') {
			putchar('\\');
			putchar('b');
		} else if(c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}
}
