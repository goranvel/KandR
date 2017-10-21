#include <stdio.h>

#define LEAP(year) (year % 4 == 0 && year % 100 != 0  || year % 400 == 0 )
 
static char dayTab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int	dayOfYear( int year, int month, int day);
void	monthDay (int year, int yearday, int *pmonth, int *pday);

int main(void) {
	int year = 2016, month, day, yDay;;
	int i = 1;
	for(; i < 13; ++i) {
//		printf("%2d %4d\n", i, dayOfYear(year, i, dayTab[LEAP(year)][i]));
		yDay = dayOfYear(year, i, dayTab[LEAP(year)][i]);
		monthDay(year, yDay, &month, &day);
		printf("%2d year of day => %3d month = %2d day = %2d\n", i, yDay, month, day); 
	}
	return 0;
}

int dayOfYear( int year, int month, int day) {
	int i, leap, temp;

//	leap = year % 4 == 0 && year % 100 != 0  || year % 400 == 0;
	for (i = 1; i < month; ++i) {
		day += *(*(dayTab + LEAP(year))+i);
	}

	return day;
}

void monthDay (int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

//	leap = year % 4 == 0 && year % 100 != 0  || year % 400 == 0;
	for (i = 1; yearday > *(*(dayTab + LEAP(year)) + i); ++i) {
		yearday -= *(*(dayTab + LEAP(year)) + i);
	}

	*pmonth = i ;
	*pday = yearday;

}
