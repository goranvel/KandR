#include <stdio.h>

int hToI(char s[]);

int main(void) {
	printf("%d 0x%x \n", hToI("11"), hToI("11"));
	return 0;
}

/* converts hexadecimal string representation to intiger value */
int hToI(char s[]) {
	int i = 0, n = 0;
	for(i = 0; s[i] != '\0'; ++i) {
		n *= 16;
		if (s[i] >= '0' && s[i] <= '9'){
			n += s[i] - '0'; 
		} else if (s[i] > 'a' && s[i] <= 'f') {
			n += s[i] - 'a' + 10;
		} else if (s[i] > 'A' && s[i] <= 'F') {
			n += s[i] - 'A' + 10;
		}
	}
	return n;
}
