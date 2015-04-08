#include <stdio.h>

/* count character in input;
1st version */

void main() {
	double nc = 0;

	for(nc = 0; getchar() != EOF; ++nc);
	
	printf("%.0f\n", nc);
}
