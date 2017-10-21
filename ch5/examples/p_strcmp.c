#include <stdio.h>

int strCmp(char *s, char *t);

int main(void) {
	printf("%d\n", strCmp("Hellp", "Hello"));
	printf("%d\n", strCmp("Hello", "Hello"));
	printf("%d\n", strCmp("Hello", "Hellp"));

	return 0;
}

int strCmp(char *s, char *t) {
	for(; *s == *t; ++s, ++t)
		if(!*s)
			return 0;

	return *s - *t;
}
