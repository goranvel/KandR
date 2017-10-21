#include <stdio.h>
#include <stdlib.h>

void itoa (int n, char *s);
void reverse(char *s);
int sizes(char *s);

int main(void) {
	char num[30];
	int a = 1 << 31;
	int b = ~a;

	itoa(a, num);
	printf("a: %d %s\n", a, num);

	itoa(b, num);
	printf("b: %d %s\n", b, num);

	return 0;
}

void itoa (int n, char *s) {
	int sign;
	char *se = s;

	if((sign = n) > 0)
		n = -n;

	do {
		*s++ = -(n % 10) + '0';
	} while ((n /= 10) < 0);

	if (sign < 0)
		*s++ = '-';

	*s = '\0';
	
	reverse(se);
}

int sizes(char *s) {
	int i = 0;
	for (i = 0; *s != '\0'; ++s,++i);

	return i;
}

void reverse (char *s) {
	char *end = s + sizes(s) - 1, temp = 0;

	for (; s < end; ++s, --end) {
		temp = *s;
		*s = *end;
		*end = temp;
	}
}	
