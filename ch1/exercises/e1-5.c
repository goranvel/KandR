#include <stdio.h>

/* prints Fehrenheit-Celsius table 
		for fahr = 300, 280, 260, ... 20, 0) */
int main() {
	int fahr;
	for(fahr=3000; fahr >= 0; fahr = fahr - 20){
		printf("%3d %6.2f\n", 
				fahr, 5.0*(fahr-32)/9.0);
	}
}
