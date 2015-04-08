#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20
float fahrToCel(float far);
float celToFahr(float cel);

int main() {
	int i = 0;
	for(i = 0; i < UPPER; i += STEP) {
		printf("%3d F = %6.2f C, %5d C = %6.2f F \n", i, fahrToCel(i), i, celToFahr(i));
	}
}

float fahrToCel(float fahr) {
	return 5*(fahr - 32)/9;
}

float celToFahr(float cel) {
		return 9*cel/5 + 32;
}
