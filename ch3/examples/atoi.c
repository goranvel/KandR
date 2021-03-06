#include <stdio.h>
#include <ctyp.h>

/* atoi(): converts s to integer;
		Version 2
*/
int aToI(char s[]) {
	int i, n, sign;

   for(i = 0; isspace(s[i]); ++i) { // skip white spaces

   sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-') { // skip sign
		++i;
	}

	for(n = 0; isdigit(s[i]); ++i) {
		n = 10 * n + (s[i] - '0');
	}

	return sign;
}
