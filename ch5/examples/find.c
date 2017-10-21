#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine( char *line, int max);

int main(int argc, char *argv[]) {
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: find patern\n");
	else
		while (getLine(line, MAXLINE) > 0 )
			if (strstr(line, argv[1]) != NULL) {
				printf("Found: %s at %d\n", line, found);
				++found;
			}

	return found;
}

int getLine(char *line, int max) {
	int i = 0;
	for (; (*line = getchar()) != EOF && *line != '\n' && i < max; ++i, ++line);

	*line = '\0';
	line = line - i;
	return i;
}
