#include <stdio.h>

int strLen(char *p);

int main(void) {
	char *p = "Hello World!!!";
	printf("%d \n", strLen(p));

	return 0;
}

int strLen(char *s) {
	char *p = s;
	for(; *p != '\0'; ++p);

	return p - s;
}
