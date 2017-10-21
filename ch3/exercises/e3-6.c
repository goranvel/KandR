#include <stdio.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);
int size(char s[]);

int main(void) {
	char num[32];
	int a = 1 << 31;
	int b = ~a;

	printf("%d\n", a);

	itoa(a, num, 15);
	printf(">> %s\n", num);

	return 0;
}

void itoa(int n, char s[], int w) {
	int i, sign;


	if((sign = n) > 0) {
		n = -n;
	}

	i = 0;
	do {
		s[i++] = -(n % 10) + '0';
		--w;
	} while ((n /= 10) < 0);

	if (sign < 0) {
		s[i++] = '-';
	}

	for(; w >= 0; --w) {
		s[i++] = ' ';
	}

	s[i] = '\0';

	reverse(s);

}

int size(char s[]) {
	int i = 0;
	for(i = 0; s[i] != '\0'; ++i);
	return i;
}

void reverse(char s[]) {
	int i = 0;
	int len = size(s);
	char temp;
	for(i = 0; i < len; ++i, --len){
		temp = s[i];
		s[i] = s[len - 1];
		s[len - 1] = temp;
	}
}
