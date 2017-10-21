#include <stdio.h>
#include <stdlib.h>

void strCat(char *, char *);

int main(void) {
	char a[15] = "Hello ";
	char *b = "world";

	strCat(a, b);

	printf("%s\n", a);

	return 0;
}

void strCat(char *s, char *t) {
	while(*++s); 
	while(*s++ = *t++);
}
