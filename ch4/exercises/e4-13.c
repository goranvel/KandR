#include <stdio.h>

#define MAX_SIZE 1000
void reverse(char s[]);
int strLen(char s[]);

int main(void) {
	char s[] = "Ja sam idiot";
	reverse(s);

	printf("%s \n", s);

	return 0;
}

void reverse(char s[]) {
	static int i = 0;
	int len = strLen(s) - 1;
	if(len - i <= i) {
		return;
	}
	char temp = s[i];
	s[i] = s[len - i];
	s[len - i] = temp;
	++i;
	reverse(s);
}

int strLen(char s[]) {
	int i = 0;
	for(; i < MAX_SIZE && s[i] != '\0'; ++i);

	return i;
}
