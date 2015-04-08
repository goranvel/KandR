#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
	char charMax = 0, charMin = 0;
	unsigned char uCharMin=0, uCharMax = 0;
	signed char sCharMin = 0, sCharMax = 0;
	while(++charMin>0);
	while(--charMax<0);
	printf("CHAR range:\t %25d - %25d\n", charMin, charMax);
	while(++uCharMin>0);
	while(--uCharMax<0);
	printf("UCHAR range:\t %25d - %25d\n", uCharMin, uCharMax);
	while(++sCharMin>0);
	while(--sCharMax<0);
	printf("SCHAR range:\t %25d - %25d\n\n", sCharMin, sCharMax);

	short shortMin = 0, shortMax = 0;
	unsigned short uShortMin = 0, uShortMax = 0;
	signed short sShortMin = 0, sShortMax = 0;
	while(++shortMin>0);
	while(--shortMax<0);
	printf("SHORT range:\t %25d - %25d\n", shortMin, shortMax);
	while(++uShortMax>0);
	while(--uShortMax<0);
	printf("USHORT range:\t %25d - %25d\n", uShortMin, uShortMax);
	while(++sShortMin>0);
	while(--sShortMax<0);
	printf("SSHORT range:\t %25d - %25d\n\n", sShortMin, sShortMax);

	int intMin = 0, intMax = 0;
	unsigned uIntMin = 0, uIntMax = 0;
	signed sIntMin = 0, sIntMax = 0;
	while(++intMin>0);
	while(--intMax<0);
	printf("INT range:\t %25d - %25d\n", intMin, intMax);
	while(++uIntMin>0);
	while(--uIntMax<0);
	printf("UINT range:\t %25u - %25u\n", uIntMin, uIntMax);
	while(++sIntMin>0);
	while(--sIntMax<0);
	printf("SINT range:\t %25d - %25d\n\n", sIntMin, sIntMax);

	long longMin = 1, longMax = 0;
	unsigned long uLongMin = 0, uLongMax = 0;
	signed long sLongMin = 0, sLongMax = 0;
	longMin = ~0;
	longMin = longMin << 63;
	longMax = ~longMin;
	printf("LONG range:\t %25ld - %25ld\n", longMin, longMax);
	uLongMax = 0 - 1;
	printf("ULONG range:\t %25Lu - %25lu\n", uLongMin, uLongMax);
	sLongMin = ~0;
	sLongMin <<= 63;
	sLongMax = ~sLongMin;
	printf("SLONG range:\t %25ld - %25ld\n\n", sLongMin, sLongMax);

	int i = 1;
	float floatMin = 1;
	while(floatMin > 0.0){
		floatMin = 1/i;
		i++;
	}
	printf("FLOAT range:\t 1/%d - %20.5f\n", i, FLT_MAX);
	printf("DECIMAl range:\t %1.25f - %20.5f\n\n", DBL_MIN, DBL_MAX);
	return 0; 
}
