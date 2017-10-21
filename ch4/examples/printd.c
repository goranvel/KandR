#include <stdio.h>

void printd (int n);
void putch (char c);

char buf[100];
int bufp = 0;

int main(void) {
	printd(1000);
	printf("%s \n", buf);
	return 0;
}

void printd (int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n / 10) {
		printd(n/10);
	}
	
	buf[bufp++] = n % 10 + '0';
}
