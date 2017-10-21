#include <stdio.h>
#include <stdlib.h>

#define ALLOC4FILE(a,b) ({\
	FILE* start = (a); \
	fseek((a), 0L, SEEK_SET);\
	(b) = malloc(sizeof(char) * ((a) - start)); \
	rewind ((a));\
})


int main (int argc, char** argv) {
	if (argc < 2) {
		printf ("USAGE: print <file1> <file2> .... <file>\n");
		return -1;
	}

	void readFile (FILE *f, char *c);

	FILE *file = fopen (*++argv, "r");
	char *content;

	int page = 1;

	do {
		ALLOC4FILE (file, content);
		readFile (file, content);
		printf("_____________________ PAGE:  %d ________________\n", page);
		printf("\n%s", content);
		printf("****************** END OF PAGE:  %d ************\n\f\r", page);
		++page;
	} while (*++argv);

	return 0;
}

void readFile (FILE *f, char *c) {
	for (;(*c = getc(f)) != EOF; ++c);

	*c = '\0';
}
