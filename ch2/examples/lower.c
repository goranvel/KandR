#include <stdio.h>

int toLower(int c);

/* converts upper case character to lower case character */
int toLower(int c) {
	if ( c >= 'A' && c <= 'Z') {
		return c + 'a' - 'A';
	}

	return c;
}
