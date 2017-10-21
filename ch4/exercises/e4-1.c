#include <stdio.h>

#define MAXLEN 1000 // Maximum number of characters

int strrindex(char s[], char t[]);
int getLine(char s[], int lim);
int getSize(char s[], int maxLen);

int main(void) {
	char s[MAXLEN];
	getLine(s, MAXLEN);
	printf("output %d\n", strrindex(s, "peh"));

	return 0;
}

int strrindex(char s[], char t[]) {
	int len = getSize(s, MAXLEN), j = getSize(t, MAXLEN), k = 0;
	printf("%d\n", len);	
	for(;len > 0; --len) {
		for(k = j - 1; k > 0 && s[len] == t[k]; --len, --k);

		if(k < j - 1 && t[k] == s[len]) {
			return len;
		}
	}
	return -1;
}

int getLine(char s[], int lim) {

	int c, i;

	i = 0;
	while( --lim > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int getSize(char s[], int maxLen) {
	int i = 0;
	for(;s[i] != '\0' && i < maxLen; ++i);

	return i;
}
