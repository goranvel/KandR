#include <stdio.h>
#include <stdlib.h>


void strCpy(char *, char *);

int main(void) {
	char *a = "Hello";
	char *b = malloc(sizeof(*a));

	strCpy(a, b);
	printf("%s %s\n", a, b);

	return 0;
}

void strCpy(char* from, char* to) {
	while (*to++ = *from++);
}
