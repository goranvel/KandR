#include <stdio.h>

int strLen(char string[]);

int main(void) {
	char ss[10] = "abcd";

	printf("%d \n", strLen(ss));
}

int strLen(char string[]) {
	int i;
	i = 0;
	while(string[++i] != '\0');
	return i;
}
