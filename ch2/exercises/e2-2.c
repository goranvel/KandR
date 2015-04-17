#include <stdio.h>\

#define MAXLEN 1000;

int main(void) {
	int i, lim = MAXLEN;
	char c;
	for(i = 0; i < lim - 1; ++i) {
		c = getchar();
		if(c == '\n') {
			putchar(c);
			break;
		} else if (c == EOF) {
			break;
		}
		putchar(c);
	}

	return 0;
}
