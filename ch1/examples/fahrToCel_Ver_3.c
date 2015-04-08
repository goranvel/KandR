#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

int main() {
	int fahr;
	for(fahr=LOWER; fahr <= UPPER;
			fahr = fahr + STEP){
		printf("%3d %6.2f\n", 
				fahr, 5.0*(fahr-32)/9.0);
	}
}
