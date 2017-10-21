#include <stdio.h>

/* prints Fehrenheit-Celsius table in reverse
		for fahr = 300, 280, 260, ... 20, 0) */
int main() {
	int fahr;
	for(fahr=3000; fahr >= 0; fahr = fahr - 20){
		printf("%4d %7.2f\n", fahr, 5.0*(fahr-32)/9.0);
		/* %4d means when printed fahr would take 4 spaces for number (ie 4 would be '   4'
			%7.2f means 7 spaces and 2 means 2 digit after '.'
		*/
	}
}
