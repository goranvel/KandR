#include <stdio.h>
int aToI(char s[]);
int main(void) {
	printf("%d\n", aToI("12345"));
	return 0;
}
/* coverts s to integer */
int aToI(char s[]) {
	int i, n = 0;

	for(i = 0; s[i] >= '0' && s[i] <='9'; ++i) {
		n = 10 * n + s[i] - '0';
	}
  
	return n;
}
