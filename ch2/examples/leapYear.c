#include <stdio.h>

void leapYear(int year);

/* determines if year is a leap year or not */:	
void leapYear(int year) {
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		printf("%d is a leap year\n", year);
	} else {
		printf("%d is not a leap year\n", year);
	}
}
