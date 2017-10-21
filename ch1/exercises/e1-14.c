#include <stdio.h>

/* prints histogram of characters entered igoring case */
main() {
	int chars[36], i = 0, maxCnt = 0;
	char c = 0;

	/* set counts to 0 */
	for(i = 0; i < 36; ++i) {
		chars[i] = 0;
	}

	/* gets count for each character */
	while((c = getchar()) != EOF) {	// gets users input
		int curr = 0; // keeps count of current count for use in histograms Y acciss
		if (c >= '0' && c <= '9') {	// if user inputes number increment its count
			curr = ++chars[c-'0'];
		} else if (c >= 'a' && c <= 'z') { // if user inputs lower case letter increment letters count
			curr = ++chars[c - 'a' + 10]; 
		} else if (c >= 'A' && c <= 'Z') { // if user inputs upper case letter increment letters count
			curr = ++chars['Z' - c + 20];
		}
		if(maxCnt < curr) {	// updates most frequent character count
			maxCnt = curr;
		}
	}

	/* prints histogram rows */
	for(; maxCnt > 0; --maxCnt) {
		printf("%3d", maxCnt); // prints Y axis of histogram
		for(i = 0; i < 36; ++i) {	// traverses through character counts
			if(chars[i] >=  maxCnt) {	// prints * if character count is greater than Y axis
				printf(" * ");
			} else {		// prints psace if character count is lesser than Y axis
				printf("   ");
			}
		}
		printf("\n");
	}

	/* prints histograms X axis */
	printf("   ");
	for(i = 0; i < 36; ++i){
		int c = i + '0';
		if (i >= 10) {	// gets letters for X axis
			c =  i - 10 + 'A';
		}
		printf(" %c ", c);	// prints X axis value
	}
	printf("\n");
}	
