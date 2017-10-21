#include <stdio.h>

/* converts n to characters in s */
void itoa(int n, char s[]);
/* reverses character s */
void reverse(char s[]);
/* returns size of string s */
int sizes(char s[]);

int main(void) {
	char num[100];
	int a = 0x1 << 31;
	int b = ~a;
	printf("%d \n", a);
	
	itoa(a, num);
	printf("%s \n", num);

	itoa(b, num);
	printf("%s \n", num);
}

/* converts n to characters in s */
void itoa(int n, char s[]) {
	int i, sign;

	if((sign = n) < 0) { // record sign
		n = -n;
	}

	i = 0;
	do {		/* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0);

	/* delete it */
	if(sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s);

}

int sizes(char s[]) {
	int i = 0;
	for(i = 0; s[i] != '\0'; ++i);
	return i;
}

void reverse(char s[]) {
	int size = sizes(s), i = 0;
	char temp;
	for (i = 0; i < (size >> 1); ++i, --size) {
		temp = s[i];
		s[i] = s[size-1];
		s[size-1] = temp;
	}
}
