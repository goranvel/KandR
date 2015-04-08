#include <stdio.h>

#define MAXFILE	10000

int getLine(char line[]);
void removeComments(char line[]);
void removeLine(char line[], int pos);
void removeChars(char line[], int start, int end);

int main() {
	char line[MAXFILE];

	while(getLine(line) != 0){
		removeComments(line);
		printf("---------------------------------\n");
		printf(line);
	}
	return 0;
}

int getLine(char line[]) {
	int i;
	for(i = 0; i < MAXFILE && (line[i] = getchar()) != EOF; ++i);	
	line[i] = '\0';
	return i;		
}

void removeComments(char line[])	{
	int i = 0, k = 1;
	char isString = 0, isComment = 0;
	while(line[i] != '\0') {
		if(line[i] == '\"' && !isString && !isComment) {
			isString = 1;
		} else if(line[i] == '\"' && isString)
			isString = 0;
	
		if(line[i] == 47 && !isString && !isComment) {
			if(line[i+1] == 47){
				removeLine(line, i);
			} else if (line[i+k] == '*') {
				while(line[i+k+1] != '*' && line[i+k+2] != 47) {
					++k;
				}
				k+=3;
				if(line[i+k] == '\n') {
					++k;
				}
				removeChars(line, i, i+k);\
				k = 1;
			}
			--i;
		}
		++i;
	}	
}

void removeLine(char line[], int pos){ 
	int i = pos;
	while(line[i++] != '\n') ;

	while(line[i] != '\0')
		line[pos++] = line[i++];

	line[pos] = '\0';

}

void removeChars(char line[], int start, int end) {
	while(line[end] != '\0') {
		line[start++] = line[end++];
	}
	line[start] = '\0';	

}
