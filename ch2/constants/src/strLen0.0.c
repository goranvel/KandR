#include <stdio.h>
#include <string.h>

int strLen(char s[]);
int main(void){
	char c[6] = "hello";

	printf("%d", strLen(c));
	printf("%d", strlen(c));

	return 0;
}

int strLen(char s[]){
	int i = 0;

//	for(;s[i] != '\0'; ++i);

	while(s[i] != '\0')
		++i;

	return i;
}
