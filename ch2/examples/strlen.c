#include <stdio.h>

int strLen(char s[]);

int main(void) {
	printf("%d \n", strLen("Hello World!!!"));
}

/* returns lenght of s */
int strLen(char s[]) {
	int i;
	for(i = 0; s[i] != '\0'; ++i);

	return i;
}
