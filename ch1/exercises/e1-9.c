#include <stdio.h>

/* replaces multiple spaces with single space in users input */
int main() {
	char pc = 0, c = 0;

	/* loop gets input from user */
	while((c = getchar()) != EOF) {
		/* if previous character is not space or current character is not space
			print it out */
		if(pc != ' ' || c != ' ') {
			putchar(c);
			pc = c;
		}
	}
}
