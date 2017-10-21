#include <stdio.h>

double aToF(char s[]);
int isDigit (char c);

int main(void) {
	char a[6] = "5.005";
	char b[7] = "3.15e2";
	char c[8] = "3.15e-2";

	printf("a %s -> %f\n", a, aToF(a));
	printf("b %s -> %f\n", b, aToF(b));
	printf("c %s -> %f\n", c, aToF(c));

	return 0;
}

double aToF(char s[]) {
	double val, power;
	int i, sign, e, eSign = 1;

	for (i = 0; s[i] == ' '; ++i);

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		++i;

	for(val = 0.0; isDigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');

	if(s[i] == '.')
		++i;

	for (power = 1; isDigit(s[i]); ++i)	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	if(s[i] == 'e' || s[i] == 'E' ) {
		eSign = (s[++i] == '-') ? -1 : 1;

		if(s[i] == '-')
			++i;

		for(; isDigit(s[i]); ++i) {
			e = 10 * e + (s[i] - '0');
		}

		e = e * eSign;
		for(; e > 0; --e)
			power /=	10;
		for(; e < 0; ++e)
			power *= 10;
	} 


	return sign * val/power;
}

int isDigit(char c) {
	return c >= '0' && c <= '9';
}
