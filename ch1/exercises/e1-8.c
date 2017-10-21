#include <stdio.h>

/* counts whitespace characters */
main() {
	int spn = 0, nln = 0, tn = 0;;
	char c = 0;

	/* counts each white space */
	while((c=getchar()) != EOF){
		if( c == '\n' ) {				/* counts new line */
			++nln;
		} else if( c == '\t' ) {	/* counts tab */
			++tn;
		} else if( c == ' ' ) {		/* counts spaces */
			++spn;
		}
	}
	
	/* prints count of each white space */
	printf("      | count\n");
	printf("------+------\n");
	printf("Space | %4d\n", spn);
	printf("Lines | %4d\n", nln);
	printf("Tabs  | %4d\n", tn);
	printf("------+------\n");
	printf("Total | %4d\n", spn + nln + tn);
} 
