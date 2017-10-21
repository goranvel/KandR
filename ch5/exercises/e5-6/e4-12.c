#include <stdio.h>
#include <stdlib.h>

#define LEN 100

void itoa		(int n, char *s);
void reverse	(char *s);

int main(void) {
	char *num = malloc(sizeof(char) * LEN);

	int a = (1 << 31) + 1;
	int b = ~a;

	printf("a %d\n", a);
	itoa(a, num);
	printf("1 - %d \n",num);
	printf("a after %s << \n", num);
	printf("2 - %d \n",num);

	printf("b before %d\n", b);
	itoa(b, num);
	printf("3 - %d \n",num);
	printf("b after %s << \n", num);
	printf("4 - %d \n",num);

	return 0;
}

void itoa(int n, char *s) {
	char *start, *c = s;
	static int i = 0;
	if(i == 0) {
		start = s;
		*s = '\0';
	}

	if(n < 0) {
		n *= -1;
		*s++ = '-';
	} else if (n > 0 && i == 0) {
		--s;
	}

	if (n % 10) {
		++i;
		itoa(n/10, ++s);	
		--i;
	} else {
		*(s+1) = '\0';
	}

	*--s = n % 10 + '0';

	if(i == 0 || (i == 1 && *start == '-')) {
		reverse(s);
		i = 0;
	}
}

void reverse(char *s) {
	char *c, *start = c = s, temp;
	for(; *s != '\0'; ++s);
	--s;
	for(; start < s; --s, ++start) {
		temp = *start;
		*start = *s;
		*s = temp;
	}
}
