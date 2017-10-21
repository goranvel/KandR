#include <stdio.h>

void itoa(int n, char s[]);

int main(void) {
	char num[100] = "\0";
	int a = (1 << 31) + 1; // -1234;
	int b = ~a; 

	printf("a %d \n", a); 
	itoa(a, num);
	printf("a after %s \n", num);

	printf("b before %d\n", b);	
	itoa(b, num);
	printf("b %s \n", num);

	return 0;
}

void itoa(int n, char s[]) {
	static int i = 0, k = 0;
	
	if(n < 0) {
		n = n * -1;
		s[i++] = '-';
	} 
	
	if(n / 10) {
		++k;
		itoa(n/10, s);
		--k;	
	}

	s[i++] = n % 10 + '0';
	s[i] = '\0';

	if(k == 0) {
		i = 0;
	}
}
