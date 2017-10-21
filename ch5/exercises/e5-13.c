#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getLine (char *line, int len);

void tail (char *line, int lineCnt);

int main (int argc, char **argv) {
	int lineCnt = 10;
	char *line = malloc(MAXLINE);

	if (argc == 2 && **(argv + 1) == '-')
		lineCnt = atoi(*(argv + 1)  + 1);

	while(getLine(line, MAXLINE))
		tail(line, lineCnt);

	printf("%s \n", line);
	
	return 0;
}

int getLine(char *line, int cnt) {
	char *start = line;
	for(; line - start < MAXLINE && (*line = getchar()) != EOF; ++line);

	*line = '\0';

	return line - start;
}

void tail (char *line, int lineCnt) {
	printf("--- %d \n", lineCnt);
	char *lines = line;
	int cnt = 0;
	while (*line++) {
		if (*line == '\n') {
			++cnt;
		//	lines = line;
		}

		if (cnt > lineCnt) {
			while (cnt > lineCnt) {
				lines++;

				if (*lines == '\n') {
					--cnt;
				}
			}
		}
	}

	printf("%s\n", lines); 
}
