#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fgets (char *s, int n, FILE *iop);
int fgetLine (char *line, int max, FILE *iop);


int main (void) {
	char *file1 = "file1.txt";
	char *file2 = "file2.txt";
	FILE *f1 = fopen (file1, "r");
	FILE *f2 = fopen (file2, "r");

	char *f1line = malloc (1000 * sizeof (char));
	char *f2line = malloc (1000 * sizeof (char));

	int i = 0;
	for (;fgetLine (f1line, 1000, f1) &&
				fgetLine (f2line, 1000, f2);
					++i)
		if (strcmp (f1line, f2line)) {
			printf("File <%s> and <%s> differ on line %i\n", file1, file2, i + 1);
			printf("%s\t> %s", file1, f1line);
			printf("vs.\n");
			printf("%s\t> %s", file2, f2line);
			return 0;
		}

	printf ("Files <%s> and <%s> do not differ\n", file1, file2);

	return 0;
}

char *fgets (char *s, int n, FILE *iop) {
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = fgetc (iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;

	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

int fgetLine (char *line, int max, FILE *iop) {
	return fgets (line, max, iop) == NULL ? 0 : strlen (line);
}
