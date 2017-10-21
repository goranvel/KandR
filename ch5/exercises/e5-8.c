#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main(void) {
	int *d = malloc(sizeof(int));
	int *m = malloc(sizeof(int));

	void montDay(int, int, int*, int*);

	printf("%d \n", dayOfYear(2016, 3, 1));

	montDay(2016, 61, m, d);
	printf("%d %d 2016\n", *d, *m);

	return 0;
}

int dayOfYear (int year, int month, int day) {
	int i, leap;

	if (month < 1 || day < 1) {
		printf("ERROR: Month or day cannot be negative");
		return -1;
	}
		
	if (month > 12) {
		printf("ERROR: There is 12 month in a year.");
		return -1;
	}

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (day > daytab[leap][month]) {
		printf("ERROR: There is %d days in a mont you selected.");
		return -1;
	}

	for(i = 1; i < month; ++i, day += daytab[leap][i])

	return day;
}

void montDay (int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	if (yearday < 0) 
		printf("ERROR: Day of a year cannot be negative.");
		return -1;
	}

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if ((yearday > 365 && !leap) || (yearday > 366 && leap)) 
		printf("ERROR: year cannot have %d days", 365 + leap);
		return -1;
	}



	for (i = 1; yearday > daytab[leap][i]; yearday -= daytab[leap][i++]);

	*pmonth	= i;
	*pday		= yearday;
}
