#include <stdio.h>

/* prints histogram of hetters and characters */
main() {
	char c = 0;
	int words[30];
	int wordLen = 0, maxLen = 0, maxCnt = 0;

	int i = 0;
	for(i = 0; i < 30; ++i) {
		words[i] = 0;
	}

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			words[wordLen]++;
			if(words[wordLen] > maxCnt)
				maxCnt = words[wordLen];
			wordLen = 0;
		} else {
			wordLen++;
		}
		if(maxLen < wordLen)
			maxLen = wordLen;
	}

	for(; maxCnt > 0; --maxCnt) {
		printf("%d", maxCnt);
		for(i = 1; i <= maxLen; ++i) {
			if(words[i] >= maxCnt){
				printf(" - ");
			} else {
				printf("   ");
			}
		}
		printf("\n");
	}

	printf(" ");
	for(i = 1; i <= maxLen; ++i){
		printf(" %d ", i);
	}
	printf("\n");
}
