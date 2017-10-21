#include <stdio.h>

void itob(int n, char s[], int b);
int size(char s[]);
void reverse(char s[]);
int abs();

int main(void) {
	char s[1000];
	int i = 0xf83fa833;
	printf("0x%x\n", i);	
	itob(i, s, 16); 
	printf("0x%s\n", s);
	return 0;
}

void itob(int n, char s[], int b) {
	unsigned un = 0 | n;
	int i = 0, k = n;
	do {
		s[i++] = (un % b) < 10  ? 
				(un % b) + '0' : (un % b) - 10 + 'A';
	} while ((un /= b) != 0);
	
	s[i] = '\0';
	reverse(s);
}

int size(char s[]) {
	int i = 0;
	for(i = 0; s[i] != '\0'; ++i);
	return i;
}

int abs(int a) {
	return (a < 0) ? -a : a;
}

void reverse(char s[]) {
	int i = 0, len = size(s);

	char temp;

	for(i = 0, len = size(s); i < len; ++i, --len){
		temp = s[i];
		s[i] = s[len - 1];
		s[len - 1] = temp;
	}
}
