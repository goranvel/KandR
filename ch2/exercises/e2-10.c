#include <stdio.h>

char toLower(char a);

int main(void) {
	char a = 'A';
	printf("%c, %c\n", a, toLower(a));

	return 0;
}

char toLower(char a) {
	return ( a >= 'A' && a <= 'Z' ) ? a + 'a' - 'A' : a;
}
