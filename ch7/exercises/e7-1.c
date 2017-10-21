#include <stdio.h>
#include <ctype.h>

int main (int argc, char **argv) { /* lower: convert input into lower case */
	int c;

	int (*caseconv)(int) = tolower;
	if (!strcmp (argv[0], "./upper"))
		caseconv = toupper;

	while ((c = getchar()) != EOF)
		putchar (caseconv(c));

	return 0;
}
