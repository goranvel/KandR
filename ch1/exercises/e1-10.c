#include <stdio.h>

/* replaces tab with \t
				backspace with \b
				backslahs with \\
*/
main() {
	char c;

	/* goes throuhg input and replaces \t \b and \\ with it's symbosls */
	while((c = getchar()) != EOF) {
		if(c == '\t') {			/* replaces TAB with \t */
			putchar('\\');
			putchar('t');
		} else if(c == '\b') {	/* replaces BACKSPACE with \b */
			putchar('\\');
			putchar('b');
		} else if(c == '\\') {A /* replaces BACKSHASH with \ */
			putchar('\\');
			putchar('\\');
		} else {						/* outputs other characters */
			putchar(c);
		}
	}
}
