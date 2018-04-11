#include <stdio.h>
#include <stdlib.h>

void itoa (int n, char *s, int w);
void reverse(char *s);
int size(char *s);

int main(void) {
	char *num = malloc(sizeof(char)*32);
	int a = 1 << 31;
	int b = ~a;

	printf("%d\n", a);

	itoa(a, num, 15);
	printf(">> %s\n", num);

	return 0;
}

void itoa (int n, char *s, int w) {
	int sign = n;
	n = (n > 0) ? -n : n;

	do {
		*s++ = -(n % 10) + '0';
		--w;
	} while ((n /= 10) < 0);
	
	if(sign < 0)
		*s++ = '-';

	for(; w >= 0; --w)
		*s++ = ' ';

	*s = '\0';

	reverse(s);
}

int size(char *s) {
	int i = 0;
	for(; *s++ != '\0'; ++i);
	return i;
}

void reverse(char *s) {
	char *end = s + size(s) - 1, temp = 0;

	for(; s < end; ++s, --end) {
		temp = *s;
		*s = *end;
		*end = temp;
	}
}
