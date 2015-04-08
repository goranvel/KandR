#include <stdio.h>

#define MAX_INPUT	1000
#define LINELEN	10

int getLine(char line[]);
void foldLine(char line[], int lineLen);

void main() {
	char line[MAX_INPUT];
	int lineLen = 0;	
	while((lineLen = getLine(line)) != 0) {
		if(lineLen > LINELEN) {
			foldLine(line, lineLen);
		}
		printf("\n%s\n", line);
	}

	return 0;
}	

int getLine(char line[]) {
	int i = 0;
	for(;(line[i] = getchar()) != EOF && i < MAX_INPUT; ++i);
	
	line[i] = '\0';

	return i;
}

void foldLine(char line[], int lineLen) {
	int i = 0, j = 0;
	while(i < lineLen) {
		if(i % LINELEN == 0) {
			if (line[i] == ' ' || line[i] == '-' || line[i] == '\t') {
				printf("%d\n", i);
				line[i] = '\n';
			} else {
				for(j = lineLen; j >= i-1; --j) { 
					line[j+1] = line[j];
				}
				line[i-1] = '-';
				line[i]	 = 
				line[lineLen+1] = '\0';
			}
		}
		++i;
	}
}
