#include <stdio.h>

int strCmp(char *, char *);

int main(void) {
	printf("%d\n", strCmp("Hellp", "Hello"));

	printf("%d\n", strCmp("Hello", "Hello"));

	printf("%d\n", strCmp("Hello", "Hellp"));

	return 0;
}

int strCmp(char *s, char *t) {
	int i;

	for (i = 0; s[i] == t[i]; ++i)
		if(s[i] == '\0')
			return 0;

	return s[i] - t[i];
}
