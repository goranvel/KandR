#include <stdio.h>

int aToI(char s[]);

int main(void){
	char s[15] = "Help!";

	printf("%d", aToI(s));

	return 0;
}

int aToI(char s[]){
	int i, n = 0;

	for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i){
		n = 10 * n + (s[i] - '0');
	}

	return n;
}
