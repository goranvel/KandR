#include <stdio.h>

void strcopy(char[], char[]);

int main(void) {
	char a[5] = "Hello";
	char b[5] = "";

	strcopy(a, b);
	printf("%s\n", b);
	return 0;
}
void strcopy(char from[], char to[]) {
	int i;
	for(i = 0; (to[i] = from[i]) != '\0'; ++i);
}
