#include <stdio.h>

#define MAXINPUT	10000

int	getLine(char line[]);
char	checkForErrors(line);

int main() {
	char line[MAXINPUT];
	while(getLine(line)) {
		checkForErrors(line);
	}

	return 0;
}

int getLine(char line[]) {
	int i;

	for(i = 0; i < MAXINPUT && (line[i] = getchar()) != EOF; ++i);

	return i;
}

char checForErrors(
