#include <stdio.h>

#define TAB_SPACE 8
#define MAXLINE	1000

int getLine(char line[]);
int detab(char line[],int start);

main() {
	char input[MAXLINE];
	int len;
	
	while((len=getLine(input)) != 0) {
		printf("%s\n", input);
	}
}

int getLine(char line[]){
	int i = 0;
	for(;i < MAXLINE && (line[i] = getchar()) != EOF && line[i] != '\n'; ++i){
		if(line[i] == '\t') {
			i = detab(line, i);
		}
	}

	line[i] = '\0';
	if(line[0] == '\n'){
		return 0;
	}

	return i;
}

int detab(char line[], int pos) {
	while(pos % TAB_SPACE) {
		line[pos++] = '*';
	}

	return pos-1;
}
