#include <stdio.h>

int any(char s1[], char s2[]);

int main(void) {
	char a[6] = "Hello";
	char b[6] = "world";

	printf("%d \n", any(a, b));
}

int any(char s1[], char s2[]) {
	int i = 0, j = 0;
	for(; s1[i] != '\0'; ++i) {
		for(j = 0; s2[j] != '\0'; ++j) {
			if(s1[i] == s2[j]){
				return i + 1;
			}
		}
	}
	return -1;
}
