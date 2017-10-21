#include <stdio.h>
#include <stdlib.h>

void itob (int n, char *s, int b);
int size(char *s);
void reverse (char *s);
int abs();

int main(void) {
	char s[1000];
	int i = 0xf83fa833;

	printf("%d\n0x%x\n", i, i);
	itob(i, s, 16);
	
	printf("0x%s\n", s);

	return 0;
}

void itob (int n, char *s, int b) {
	unsigned un = 0 | n;
	char *start = s;
	do {
		*s++ = (un % b) < 10 ? (un % b + '0') : (un % b) - 10 + 'A';
	} while ((un /= b) != 0);

	*s = '\0';

	reverse(start);
}

int size(char *s) {
	int i = 0;
	for(; *s != '\0'; ++i, ++s);
	return i;
}

int abs (int a) {
	return (a < 0) ? -a : a;
}

void reverse (char *s) {
	char *end = s + size(s) - 1, temp = 0;
	for (; s < end; ++s, --end) {
		temp = *s;
		*s = *end;
		*end = temp;
	}
}
