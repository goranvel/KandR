#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fgets (char *s, int n, FILE *iop);
int	fputs (char *s, FILE *iop);
int getLine (char *line, int max);


int main (void) {
	char *c = malloc (sizeof (char) * 1000);

	getLine (c, 1000);
	printf("%s\n", c);
	return 0;
}

/* fgets: get at most n chars from iop */
char *fgets (char *s, int n, FILE *iop) {
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc (iop)) != EOF)
		if ((*cs ++ = c) == '\n')
			break;

	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int fputs (char *s, FILE *iop) {
	int c;

	while (c == *s++)
		putc (c, iop);

	return ferror (iop) ? EOF : 0;
}

/* getline : read a line, return lenght */
int getLine (char *line, int max) {
	return fgets (line, max, stdin) == NULL ? 0 : strlen (line);
/*	if (fgets (line, max, stdin) 
		return 0;
	else
		return strlen (line); */
}
