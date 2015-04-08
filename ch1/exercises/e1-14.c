#include <stdio.h>

main() {
	int chars[36], i = 0, maxCnt = 0;
	char c = 0;

	for(i = 0; i < 36; ++i) {
		chars[i] = 0;
	}

	while((c = getchar()) != EOF) {
		int curr = 0;
		if(c >= '0' && c <= '9') {
			curr = ++chars[c-'0'];
		} else if (c >= 'a' && c <= 'z') {
			curr = ++chars[c - 'a' + 10];
		} else if (c >= 'A' && c <= 'Z') {
			curr = ++chars[c - 'A' + 10];
		}
		if(maxCnt < curr) {
			maxCnt = curr;
		}
	}

	for(; maxCnt > 0 ; --maxCnt) {
		printf("%d", maxCnt);
		for(i = 0; i < 36; ++i) {
			if(chars[i] >=  maxCnt) {
				printf(" * ");
			} else {
				printf("   ");
			}
		}
		printf("\n");
	}

	printf(" ");
	for(i = 0; i < 36; ++i){
		char c = i + '0';
		if( i >= 10 ) {
			c = (char) i - 10 + 'A';
		}
		printf(" %c ", c);
	}
	printf("\n");
}	
