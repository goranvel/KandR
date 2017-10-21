#include <stdio.h>

/* functions that get ranges of signed data types */
void rangeOfChar();
void rangeOfShort();
void rangeOfInt();
void rangeOfLong();

/* prints range of different types */
void printUnsignedRanges(int size);
void printSignedRanges(int size);

int main(void) {
	printf("Tyle\t\t\t|\t\tmin\t|\tmax\n");
	rangeOfChar();
	rangeOfShort();
	rangeOfInt();
	rangeOfLong();

	return 0;
}

void rangeOfChar() {
	int size = 0;
	char test = ~1;

	while(test < 0) {
		test <<= 1;
		++size;
	}

	printf("Char\t");
	printf("----------------");
	printf("+-----------------------+-----------------------+\n");

	printf("\tunsigned\t|");
	printUnsignedRanges(size);
	printf("\tsigned\t\t|");
	printSignedRanges(size);
}

void rangeOfShort() {
	int size = 0;
	short test = ~1;

	while(test < 0) {
		test <<= 1;
		++size;
	}

	printf("Short\t");
	printf("----------------");
	printf("+-----------------------+-----------------------+\n");

	printf("\tunsigned\t|");
	printUnsignedRanges(size);
	printf("\tsigned\t\t|");
	printSignedRanges(size);
}

void rangeOfInt() {
	int size = 0;
	int test = ~1;

	while(test < 0) {
		test <<= 1;
		++size;
	}
	
	printf("Int\t");
	printf("----------------");
	printf("+-----------------------+-----------------------+\n");

	printf("\tunsigned\t|");
	printUnsignedRanges(size);
	printf("\tsigned\t\t|");
	printSignedRanges(size);
}

void rangeOfLong() {
	int size = 0;
	long test = ~1;

	while(test < 0) {
		test <<= 1;
		++size;
	}

	printf("Long\t");
	printf("----------------");
	printf("+-----------------------+-----------------------+\n");

	printf("\tunsigned\t|");
	printUnsignedRanges(size);
	printf("\tsigned\t\t|");
	printSignedRanges(size);
}

void printUnsignedRanges(int size){
	long min = 0UL;
	long max = ~(~min << (size+1));
	max = (max <= 0) ? max : ~max;
	
	max = ~max;
	printf("%22lu | %22lu\n", min, max);

}

void printSignedRanges(int size) {
	long min = ~0L << size;
	long max = ~min, temp = 0;

	if(min + 1 == 0) { // if system uses sign-magnitude represenation
		min = ~0;
	} else if (min > 0) { // if system uses biased represenation
		temp	= min;
		min	= max;
		max 	= temp;
	} 
	
	printf("%22ld | %22ld\n", min, max);
}
