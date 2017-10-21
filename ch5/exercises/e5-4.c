#include <stdio.h>

int strend(char *, char *);

int main(void) {
	char a[15] = "Hello world";
	printf("%d\n", strend(a, "world"));

	return 0;
}

int strend(char *s, char *t) {
	char *t2 = t;
	while(*++s);
	while(*++t);

	while(*s-- == *t--)
		if(t == t2)
			return 1;

	return 0;	
}
