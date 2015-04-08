#include <stdio.h>

/* replaces multiple spaces with single space */
int main() {
	char pc = -1, c = -1;

	while((c = getchar()) != EOF) {
		if(pc != ' ' || c != ' ') {
			putchar(c);
/*			putchar(' ');
			putchar(pc);
			putchar('\n'); */
			pc = c;
		}

	}
}
