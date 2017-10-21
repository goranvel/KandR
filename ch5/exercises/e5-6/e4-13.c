#include <stdio.h>

#define MAX_SIZE 1000

void reverse(char *s);
int strLen(char *s);

int main (void) {
	char s[] = "Ja sam idiot";
	reverse(s);

	printf("%s \n", s);

	return 0;
}

void reverse(char *s) {
	const int len = strLen(s) - 1;
	static int i = 0;

	if(i >= len) {
		return;
	}
	char t = *(s+len-i);
	*(s+len-i) = *s;
	*s = t;
	++i;
	reverse(++s);
}

int strLen(char *s) {
	int i = 0;
	for(; i < MAX_SIZE && *s != '\0'; ++i, ++s);

	return i;
}
