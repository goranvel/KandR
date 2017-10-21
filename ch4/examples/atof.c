#include <stdio.h>

/* atof: convert string s to dobule */
double aToF(char s[]);
int isDigit(char a);

int main(void) {
	printf("%f\n", aToF("10.55"));

	return 0;
}

/* atof: convert string s to double */
double aToF(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; s[i] == ' '; ++i); /* skip white spaces */

	sign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '+' || s[i] == '-')
		++i;

	for(val = 0.0; isDigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.') 
		++i;

	for(power = 1.0; isDigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val/power;
}

int isDigit(char a) {
	return (a >= '0') && (a <= '9');
}
