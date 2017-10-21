#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

/* converts fahrenheight to celsius */
float fahrToCel(float far);
/* converts celsius to fahrenheight */
float celToFahr(float cel);

/* Prints conversions */
int main() {
	int i = 0;
	for(i = 0; i < UPPER; i += STEP) { 
		printf("%3d F = %6.2f C, %5d C = %6.2f F \n", 
					i, fahrToCel(i), i, celToFahr(i));
	}
}

/* Fahrenheight to Celsius conversion */
float fahrToCel(float fahr) {
	return 5 * (fahr - 32)/9;
}

/* Celsius to Fahrenheight conversion */
float celToFahr(float cel) {
		return 9 * cel/5 + 32;
}
