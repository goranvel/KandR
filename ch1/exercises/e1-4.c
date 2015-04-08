#include <stdio.h>

/* print Fahrenheit-Celcius table
		for fahr = 0, 20, ..., 300 */
main() {
	float fahr, cel;
	int lower, upper, step;

	lower =	0;		/* lower limit of temperaturee tabe */
	upper =	300;	/* upper limit */
	step	=	10;	/* step size */
	printf("     Celsius | Fahrenheit\n");
	printf("-------------+-------------\n");
	for(cel = lower; cel <= upper; cel += step){
		fahr = (9.0/5.0) * cel + 32.0;
		printf("%12.0f |%11.2f\n", cel, fahr);
	}
}
