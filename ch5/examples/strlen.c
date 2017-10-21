#include <stdio.h>

int strLen(char *s);

int main(void) {
	char *s = "Help";

	printf("%d \n", strLen(s));

	return 0;
}

int strLen(char *s) {
	int n;

	for(n = 0; *s != '\0'; ++s, ++n);

	return n;
}
