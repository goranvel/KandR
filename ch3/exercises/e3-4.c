#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);
int sizes(char s[]);

int main(void) {
	char num[32];
	int a = 1 << 31;
	int b = ~a;

	printf("%d\n", a);

	itoa(a, num);
	printf("%s\n", num);

	itoa(b, num);
	printf("%s\n", num);
	return 0;
}

void itoa(int n, char s[]) {
	int i, sign;

	if((sign = n) > 0) {
		n = -n;
	}

	i = 0;
	do {
		s[i++] = -(n % 10) + '0';
	} while ((n /= 10) < 0);

	if (sign < 0) {
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
	for(i = 0; i < size; ++i, --size){
		temp = s[i];
		s[i] = s[size - 1];
		s[size - 1] = temp;
	}
}
