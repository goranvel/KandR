#include <stdio.h>

/* print Fahrenheit-Celcius table
		for fahr = 0, 20, ..., 300 */
main() {
	float fahr, celsius;
	int lower, upper, step;

	lower =	0;		/* lower limit of temperaturee tabe */
	upper =	300;	/* upper limit */
	step	=	20;	/* step size */
	printf(" Fahreneight |    Celsius\n");
	printf("-------------+-------------\n");
	for(fahr = lower; fahr <= upper; fahr+=step){
		celsius = 5.0 * (fahr-32) / 9.0;
		printf("%12.0f |%11.2f\n", fahr, celsius);
	}
}
