#include <stdio.h>
#include <stdlib.h>

static char daytab[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void) {
	int *d = malloc(sizeof(int));
	int *m = malloc(sizeof(int));
	void monthDay(int, int, int*, int*);

	printf("%d\n", dayOfYear(2016, 3, 1));
	
	monthDay(2016, 61, m, d);
	printf("%d %d 2016\n", *d, *m);
	return 0;
}

/* dayOfYear: set day of year from month  & day */
int dayOfYear(int year, int month, int day) {
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	 

	for(i = 1; i < month; ++i)
		day += daytab[leap][i];

	return day;
}

/* monthDay: set month, day from day of year */
void monthDay(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for (i = 1; yearday > daytab[leap][i]; ++i)
		yearday -= daytab[leap][i];

	*pmonth	= i;
	*pday		= yearday;
}
