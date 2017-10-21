#include <stdio.h>

#define IS_UPPER(c) ((c) >= 'A' && (c) <= 'Z')

int isupper (int);

int main (void) {
	int a = '0';
	for (; a < 'z'; ++a) {
		/* if (a == 'Z')
			a = 'a'; */
	
		printf("%c %d %d\n",a, isupper(a), IS_UPPER(a));
	}

	return 0;
}

int isupper (int c) {	
	return c >= 'A' && c <= 'Z';
}
