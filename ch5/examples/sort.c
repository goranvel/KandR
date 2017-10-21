#include <stdio.h>
#include <string.h>

#define MAXLINES	5000 /* max #lines to be sorted */
#define MAXLINE	1000 /* max length of any input line */

char *lineptr[MAXLINE];  /* pointers to text lines */

int	readlines	(char *lineptr[], int nlines);
void	writelines	(char *lineptr[],	 int nlines);
void	qSort			(char *lineptr[], int left, int right);
int	getLine		(char *, int);
char	*alloc		(int);

/* sort input lines */
int main (void) {
	int nlines; /* number of input lines read */
	
	if((nlines = readlines(lineptr, MAXLINE)) >= 0) {
		qSort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("ERROR: input too bit to sort\n");
		return 1;
	}
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLINE];
	nlines = 0;
	while((len = getLine(line, MAXLINE)) > 0) {
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
//			line[len - 1] = '\0';	/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	
	return nlines;
}

/* writelines: write ouptut lines */
void writelines(char *lineptr[], int nlines) {
//
/*
	int i = 0;
	for(;i < nlines; ++i)
		printf("%d %s\n", i, lineptr[i]);
//
// /
*/
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

char *alloc(int n) { /* return pointer to n character */
	static char allocbuf[MAXLINE]; /* STORAGE FOR ALLOC */
	static int pos = 0;
	if (n > MAXLINE) {
		return NULL;
	} else {
		pos += n + 1;
		return allocbuf + pos - n - 1;
	}
}

/* gsort: sort v[left] ... v[right] into increasing order */
void qSort (char *v[], int left, int right) {
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) /* do nothing if array contains fewwer
							than two elements*/ 
		return;

	swap(v, left, (left + right) >> 1);
	last = left;
	for ( i = left + 1; i <= right; ++i)
 		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);
	qSort(v, left, last-1);
	qSort(v, last+1, right);
}

/* svap: interchange v[i] and v[j] */
void swap (char *v[], int i, int j) {
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
