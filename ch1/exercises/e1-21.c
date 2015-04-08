#include <stdio.h>

#define TAB_SPACE	7
#define MAXLINE	1000

int	getLine(char line[]);
void	entab(char line[]);

main() {
	char input[MAXLINE];
	int len;

	while((len = getLine(input)) != 0) {
		entab(input);
		printf("%s\n", input);
	}

	return 0;
}

int getLine(char line[]) {
	int i = 0, spaceLen = 0;
	for(; i < MAXLINE && (line[i] = getchar()) != EOF && line[i] != '\n'; ++i);

	line[i] = '\0';
	if(line[0] == '\n') {
		line[0] = '\0';
		return 0;
	}
}

void entab(char line[]){
	int i = 0, j = 0, k = 0;
	while(line[i] != '\0') {
		for(;line[i] != '*' && line[i] != '\0'; ++i);

		for(;line[i+j] == '*'; ++j) {
			printf("%d\n", i);
			if((i + j) % TAB_SPACE == 0) {
				line[i++] = '\t';
				while(line[i+k+j] != '\0') {
					line[i+k] = line[i+k+j];
					k++;
				}
				line[i+k] = '\0';
				k = 0;
				j = 0;
			}
		}
		++i;
	}
}
