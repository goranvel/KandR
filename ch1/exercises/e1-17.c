#include <stdio.h>

#define MAXLEN		1000
#define PRINTABLE	80

/* gets a single line of code */
int getLine(char s[]);
/* prints line longer than PRINTABLE */
void printLongs(char lines[]);
/* gets size of given string */
int getSize(char s[]);

/* this program prints line longer than PRINTABLE */
int main() {
	char line[MAXLEN];
	
	while(getLine(line) != 0) {
		printLongs(line);
	}
		
}

/* gets a slingle line of code
	parameter character array */
int getLine(char s[]) {
	int i = 0;
	for(i = 0; 
			(s[i] = getchar()) != EOF && s[i] != '\n' && i < MAXLEN - 1;
				++i);
	s[i] = '\0';

	return i;
}

/* Prints line that is longer than PRINTABLE */
void printLongs(char longLines[]) {
	if(getSize(longLines) < PRINTABLE){
		return;
	} 
	printf("%s\n", longLines);
}

/* Gets size of a string str */
int getSize(char str[]) {
	int i;
	for(i = 0; str[i] != '\0' && i < MAXLEN; ++i);

	return i;
}
