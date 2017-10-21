#include <stdio.h>

#define IS_DIGIT(c) ( c >= '0' && c <= '9')

double aToF (char *s);

int main (void) {
	char a[8] = "505.005";
	char b[7] = "3.15e2";
	char c[8] = "3.15e-2";

	char d[6] = "-5.005";
	char e[7] = "-3.15e2";
	char f[9] = "-3.15e-2";

	printf("a %s -> %f\n", a, aToF(a));
	printf("b %s -> %f\n", b, aToF(b));
	printf("c %s -> %f\n", c, aToF(c));

	printf("d %s -> %f\n", d, aToF(d));
	printf("e %s -> %f\n", e, aToF(e));
	printf("f %s -> %f\n", f, aToF(f));

	return 0; }

double aToF(char *s) {
	double val, power;
	int sign; 

	for (; *s == ' '; ++s);

	sign = *s == '-' ? -1 : 1;

	if (*s == '+' || *s == '-')
		++s;

	for (val = 0.0; IS_DIGIT(*s); ++s)
		val = 10.0 * val + *s - '0';

	if (*s == '.')
		++s;
	
	for (power = 1; IS_DIGIT(*s); ++s) {
		val = 10.0 * val + *s - '0';
		power *= 10;
	}

	if (*s == 'e' || *s == 'E') {
		int e, eSign = *++s == '-' ? -1 : 1;

		if (*s == '-')
			++s;

		for (; IS_DIGIT(*s); ++s)
			e = 10 * e + *s - '0';

		e = e * eSign;
	
		for (; e > 0; --e)
			power /= 10;
		for (; e < 0; ++e)
			power *= 10;
	}
	
	return sign * val/power;
}
