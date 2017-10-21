#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES	5000 /* max #lines to be sorted */

#define TO_LOWER(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + 'a' - 'A' : (x))

char	**lineptr;  /* pointers to text lines */

int	readlines	(char **lineptr,	int nlines);
void	writelines	(char **lineptr,	int nlines);
void	qSort			(char **lineptr,	int left,	int right,	
												int(*comp)(const char *, const char *));
int	getLine		(char *line,		int len);

int	rstrcmp		(const char *a, const char *b); 
int	numcmp		(const char *a, const char *b);
int	rnumcmp		(const char *a, const char *b);
int	foldcmp		(const char *a, const char *b);
int	rfoldcmp		(const char *a, const char *b);
int	foldnumcmp	(const char *a, const char *b);
int	rfoldnumcmp	(const char *a, const char *b);


void toLower (const char *in, char *out);

/* sort input lines */
int main (int argc, char **argv) {
	lineptr = malloc(sizeof(char *) * MAXLINES);

	int nlines; /* number of input lines read */
	int numeric = 0; /* 1 if numeric sort */
	char rev = 0, num = 0, fold = 0;
	int (*comp)(const char *, const char *);
	comp = strcmp;

	int i = 0;
/*	if (argc > 1 && strcmp(*++argv, "-n") == 0)
		numeric = 1; */


	while (*++argv)
		if (**argv == '-') {
			i = 1;
			while (*(*argv + i) != '\0') {
				switch (*(*argv + i)) {
					case 'n' :
						num = 1;
						break;
					case 'r' :
						rev = 1;
						break;
					case 'f' :
						fold = 1;
						break;
					default : {
						num	= 0;
						rev	= 0;
						fold	= 0;
					}
				}

				++i;
			}
		}

	if (num)
		if(rev)
			comp = rnumcmp;
		else
			comp = numcmp;
	else if (rev)
		if (fold)
			comp = rfoldcmp;
		else
			comp = rstrcmp;
	else if (fold)
		comp = foldcmp;
		
	if	((nlines = readlines(lineptr, MAXLINES)) >= 0 ) {
		qSort(lineptr, 0, nlines - 1, comp);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("ERROR: input too bit to sort\n");
		return 1;
	}
	free (lineptr);
}

/* readlines: read input lines */
int readlines(char **lineptr, int maxlines) {
	int len, nlines;
	char *p, *line = malloc(sizeof(char) * MAXLINES);
	nlines = 0;
	while((len = getLine(line, MAXLINES)) > 0) {
		if(nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else {
			strcpy(p, line);
			*(lineptr+nlines) = p;
			nlines++;
		}
	}
	
	return nlines;
}

/* writelines: write ouptut lines */
void writelines(char **lineptr, int nlines) {
	while (nlines-- > 0)
		printf("%s\n", *lineptr++); // */
} 

int getLine (char *s, int len) {
	int i = 0;
	for(;(*s = getchar()) != EOF && *s != '\n' && i < len; ++i, ++s);

	*s = '\0';
	s = s - i;
	return i;
}

/* gsort: sort v[left] ... v[right] into increasing order */
void qSort (char **v, int left, int right, int (*comp) (const char *, const char *)) {
	int i, last;
	void swap(char **v, int i, int j);

	if (left >= right) /* do nothing if array contains fewwer than two elements */ 
		return;

	swap(v, left, (left + right) >> 1);

	last = left;
	for ( i = left + 1; i <= right; ++i) {
 		if (comp(*(v+i), *(v+left)) < 0)
			swap(v, ++last, i);
	}

	swap(v, left, last);
	qSort(v, left, last-1, comp);
	qSort(v, last+1, right, comp); 
}

/* numcmp: compare s1 and s2 numerically */
int numcmp (const char *s1, const char *s2) {
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/* reverse numcmp */
int rnumcmp (const char *s, const char *t) {
	return numcmp (t, s);
}

/* reverse strcmp */
int rstrcmp(const char *s, const char *t) {
	return strcmp(t, s);
}

/* floding strcmp */
int foldcmp (const char *s, const char *t) {
	int i = 0;
	for (; TO_LOWER(*(s + i)) == TO_LOWER(*(t + i)); ++i)
		if(!*s || !*t)
			return 0;

	return TO_LOWER(*(s + i)) - TO_LOWER(*(t + i));
}

int rfoldcmp (const char *s, const char *t) {
	return foldcmp(t, s);
}

/* svap: interchange v[i] and v[j] */
void swap (char **v, int i, int j) {
	char *temp;
	temp = *(v+i);
	*(v+i) = *(v+j);
	*(v+j) = temp;
}
