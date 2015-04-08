#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
	printf("CHAR range:\t %25d - %25d\n", CHAR_MIN, CHAR_MAX);
	printf("UCHAR range:\t %25d - %25d\n", 0, UCHAR_MAX);
	printf("SCHAR range:\t %25d - %25d\n\n", SCHAR_MIN, SCHAR_MAX);

	printf("SHORT range:\t %25d - %25d\n", SHRT_MIN, SHRT_MAX);
	printf("USHORT range:\t %25d - %25d\n", 0, USHRT_MAX);
	printf("SSHORT range:\t %25d - %25d\n\n", SHRT_MIN, SHRT_MAX);

	printf("INT range:\t %25d - %25d\n", INT_MIN, INT_MAX);
	printf("UINT range:\t %25u - %25u\n", 0, UINT_MAX);
	printf("SINT range:\t %25d - %25d\n\n", INT_MIN, INT_MAX);

	printf("LONG range:\t %25ld - %25ld\n", LONG_MIN, LONG_MAX);
	printf("ULONG range:\t %25Lu - %25lu\n", 0, ULONG_MAX);
	printf("LONG range:\t %25lu - %25lu\n\n", LONG_MIN, LONG_MAX);

	printf("FLOAT range:\t %1.25f - %20.5f\n", FLT_MIN, FLT_MAX);
	printf("DECIMAl range:\t %1.25f - %20.5f\n\n", DBL_MIN, DBL_MAX);
	return 0;
}


