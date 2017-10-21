#include <stdio.h>

int main (int argc, char **argv) {
	FILE *fp;
	void filecopy (FILE *, FILE *);

	// added
	char *prog = *argv; /* program name for errors */

	if (argc == 1) /* no args; copy standard input */
		filecopy (stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf (stderr, "%s cat: can't open file %s\n", *prog, *argv);
				// printf ("cat: can't open file %s\n", *argv);
				exit (1); // return 1;
			} else {
				filecopy (fp, stdout);
				fclose (fp);
			}
	
	if(ferror(stdout)) {
		fprintf (stderr, "%s: error writting stdout\n", prog);
		exit (2);
	}

	
	exit(0); // return 0;
}

/* filecopy: copy files ifp to file ofp */
void filecopy (FILE *ifp, FILE *ofp) {
	int c;

	while ((c = getc (ifp)) != EOF)
		putc (c, ofp);
}
