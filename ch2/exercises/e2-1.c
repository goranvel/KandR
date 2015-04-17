#include <stdio.h>

int main(void) {
	printf("\nVariable type\t   |size| "
				"start\t\t       | end\t\t      |\n"
				"-------------------+----+"
				"----------------------+"
				"----------------------+\n");
	
	char cmax = 0x7f;
	printf("Char\t\t   | %lu\t| %20d | %20d |\n", 
				sizeof(char), ~cmax, cmax);
	printf("Unsigned char\t   | %lu\t| %20d | %20u |\n",
				sizeof(char), 0, (unsigned char) ~0);


	short smax = 0x7fff;
	printf("Short\t\t   | %lu\t| %20d | %20d |\n",
				sizeof(short), ~smax, smax);
	printf("Unsigned short\t   | %lu\t| %20u | %20u |\n",
				sizeof(short), 0, (unsigned short) ~0);

	int imax = 0x7fffffff;
	printf("Intger\t\t   | %lu\t| %20d | %20d |\n",
				sizeof(int), ~imax, imax);
	printf("Unsigned\t   | %lu\t| %20u | %20u |\n",
				sizeof(int), 0, (unsigned) ~0);
	
	long lmax = 0x7fffffffffffffff;
	printf("Long \t\t   | %lu\t| %20ld | %20ld |\n",
				sizeof(long), ~lmax, lmax);
	printf("Unsigned long\t   | %lu\t| %20d | %20lu |\n",
				sizeof(long), 0, (unsigned long) ~0);

	long long llmax = 0x7fffffffffffffff;
	printf("Long Long\t   | %lu\t| %20lld | %20lld |\n",
				sizeof(long long), ~llmax, llmax);
	printf("Unsigned long long | %lu\t| %20d | %20llu |\n",
				sizeof(long long), 0, (unsigned long long) ~0);

	float fmax = 1.0 ;
	int fmax_int = *(int *)&var;
	printf("Float\t\t   | %lu\t|%32s\t      |\n",
				sizeof(float), "NOT RELEVANT FOR NOW");

	double dmax = -1.0 ;
	printf("Double\t\t   | %lu\t|%32s\t      |\n",
				sizeof(double), "NOT RELEVANT FOR NOW");

	long double ldmax = -1.0 ;
	printf("Double\t\t   | %lu\t|%32s\t      |\n",
				sizeof(long double), "NOT RELEVANT FOR NOW");

	return 0;
}
