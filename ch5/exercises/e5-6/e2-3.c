#include <stdio.h>

int hToI (char *s);

int main (void) {
	printf("%d 0x%x\n", hToI("fff"), hToI("ff"));

	return 0;
}

int hToI (char *s) {
	int n = 0;
	for(;*s != '\0'; ++s) {
		n *= 16;
		if(*s >= '0' && *s <= '9')
			n += *s - '0';
		else if (*s >= 'A' && *s <= 'F')
			n += *s - 'A' + 10;
		else if (*s >= 'a' && *s <= 'f')
			n += *s - 'a' + 10;

	}

	return n;
}
