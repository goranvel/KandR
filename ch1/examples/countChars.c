#include <stdio.h>

/** @file
*	 @brief 
*  count character in input;
*	1st version 
*/
void cc() {
	long nc = 0;

	while(getchar() != EOF) {
		++nc;
	}
	
	printf("%ld\n", nc);
}

/** DOX TEST
*/
