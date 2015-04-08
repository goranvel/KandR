#include <stdio.h>

#define MAXLEN		1000
#define PRINTABLE	80

int getLine(char s[]);
void printLongs(char lines[], int len);

int main() {
	char line[MAXLEN];
	int i, len;
	
	while((len = getLine(line)) != 0) {
		printLongs(line, len);
	}
		
}

int getLine(char s[]) {
	int i = 0;
	for(i = 0; 
			(s[i] = getchar()) != EOF && s[i] != '\n' && i < MAXLEN - 1;
				++i);
	s[i] = '\0';
	return i;
}

void printLongs(char longLines[], int lineLen) {
	if(lineLen < PRINTABLE){
		return;
	}

//	printf("%s\n", longLines);
}	
