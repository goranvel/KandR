#include <stdio.h>

#define MAXLEN 1000
// get line without using && and || operands in for loop
int getLine(char s[], int lim);

int main(void) {
	char line[MAXLEN];
	getLine(line, MAXLEN);
	printf("%s \n", line);
	return 0;
}

// get line program without using && or ||
int getLine(char s[], int lim){
	int i;
	char c;
/*	for (i = 0; i < lim - 1 && ( c = getchar()) != '\n'; ++i);
		s[i] = c;
*/
	for (i = 0; i < lim - 1; ++i){
		s[i] = getchar();
		if(s[i] == '\n') {
			return i;
		} else if(s[i] == EOF) {
			return i;
		}
	}
	return i;
}
