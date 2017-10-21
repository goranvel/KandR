#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES		5000 /* max #lines to be sorted */
#define DELIMINATOR	' '

#define TO_LOWER(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + 'a' - 'A' : (x))

char	**lineptr;  /* pointers to text lines */
int	fieldStart;

int	readlines	(char **lineptr,	int nlines);
void	writelines	(char **lineptr,	int nlines);
void	qSort			(char **lineptr,	int left,	int right,	
												int(*comp)(const char *, const char *));
int	getLine		(char *line,		int len);

int	rstrcmp			(const char *a, const char *b); 
int	numcmp			(const char *a, const char *b);
int	rnumcmp			(const char *a, const char *b);
int	foldcmp			(const char *a, const char *b);
int	rfoldcmp			(const char *a, const char *b);
int	foldnumcmp		(const char *a, const char *b);
int	rfoldnumcmp		(const char *a, const char *b);
int	diccmp			(const char *a, const char *b);
int	rdiccmp			(const char *a, const char *b);
int	folddiccmp		(const char *a, const char *b);
int	rfolddiccmp		(const char *a, const char *b);
int	fieldcmp			(const char *a, const char *b);
int	rfieldcmp		(const char *a, const char *b);
int	foldfieldcmp	(const char *a, const char *b);
int	rfoldfieldcmp	(const char *a, const char *b);
int	numfieldcmp		(const char *a, const char *b);
int	rnumfieldcmp	(const char *a, const char *b);

void	toLower			(char *s);

/* sort input lines */
int main (int argc, char **argv) {
	lineptr = malloc(sizeof(char *) * MAXLINES);

	int nlines; /* number of input lines read */
	int numeric = 0; /* 1 if numeric sort */
	char rev = 0, num = 0, fold = 0, dict = 0, field = 0;
	int (*comp)(const char *, const char *);
	comp = strcmp;

	int i = 1; // n = 0;

	while (*++argv)
		if (**argv == '-')
			if (isdigit(*(*argv + 1))) {
				for (;*(*argv + i); ++i) 
					if(!isdigit(*(*argv + i))) 
						printf("\nCharacter %c and follwing characters would be ignored\n\n", *(*argv + i));

				fieldStart = atoi(*argv + 1);
				comp = fieldcmp;
				field = 1;
			} else if(isalpha(*(*argv + 1))) {
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
							printf("Error has occured no command %s\n", *argv);
							return -1;
						}
					}
					++i;
				} 
			} else {
				printf("Error has occured\n");
			}

		if (num)
			if(rev)
				if(rev & field)
					comp = rnumfieldcmp;
				else 
					comp = rnumcmp;
			else if (field)
				comp = numfieldcmp;
			else
				comp = numcmp;
		else if (rev)
			if (fold) 
				if (dict)
					comp = rfolddiccmp; 
				else if (field)
					comp = rfoldfieldcmp;
				else	
					comp = rfoldcmp;
			else if (dict)
				comp = rdiccmp;
			else if (field)
				comp = rfieldcmp;
			else
				comp = rstrcmp;
		else if (fold)
			if (dict)
				comp = folddiccmp;
			else if (field)
				comp = foldfieldcmp;
			else
				comp = foldcmp;
		else if (dict)
			comp = diccmp;
		else if (field)
			comp = fieldcmp;

	if( (nlines = readlines(lineptr, MAXLINES)) >= 0 ) {
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
	int len, nlines = 0;
	char *p, *line = malloc(sizeof(char) * MAXLINES);

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
	for (;nlines-- > 0; ++lineptr) {
		printf("%s\n", *lineptr); // */
		free (*lineptr);
	}
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
	for (; TO_LOWER(*(s + i)) == TO_LOWER(*(t + i)) && *(s + i) && *(t + i); ++i)

	return TO_LOWER(*(s + i)) - TO_LOWER(*(t + i));
}

int rfoldcmp (const char *s, const char *t) {
	return foldcmp(t, s);
}

int diccmp (const char *s, const char *t) {
	int i = 0, j = 0;

	for (;!(isspace(*(s + i)) || isalpha(*(s + i)) || isdigit(*(s + i))); ++i);
	for (;!(isspace(*(t + j)) || isalpha(*(t + j)) || isdigit(*(t + j))); ++j);

	for (; *(s + i) == *(t + j) && *(s + i) && *(t + j); ++i, ++j) {
		for (;*(s + i + 1) && 
				!(isspace(*(s + i + 1)) || isalpha(*(s + i + 1)) || isdigit(*(s + i + 1))); 
					++i);
		for (;*(t + j + 1) && 
				!(isspace(*(t + j + 1)) || isalpha(*(t + j + 1)) || isdigit(*(t + j + 1))); 
					++j); 
	}
	return *(s + i) - *(t + j);
}

int rdiccmp (const char *s, const char *t) {
	return diccmp(t, s);
}

int folddiccmp (const char *s, const char *t) {
	int i = 0, j = 0;

	if(!(isspace(*(s + i)) || isalpha(*(s + i)) || isdigit(*(s + i))))
		++i;
	if(!(isspace(*(t + j)) || isalpha(*(t + j)) || isdigit(*(t + j))))
		++j;

	for (; TO_LOWER(*(s + i)) == TO_LOWER(*(t + j)) && *(s + i) & *(t + j); ++i, ++j) {
		if(!(isspace(*(s + i + 1)) || isalpha(*(s + i + 1)) || isdigit(*(s + i + 1))))
			++i;
		if(!(isspace(*(t + j + 1)) || isalpha(*(t + j + 1)) || isdigit(*(t + j + 1))))
			++j;
	}
	return TO_LOWER(*(s + i)) - TO_LOWER(*(t + j));
}

int rfolddiccmp (const char *s, const char *t) {
	return folddiccmp(t, s);
}

int fieldcmp (const char *s, const char *t) {
	char	*s1;
	char	*t1;
	int	i = 0, j = 0, k = 0;

	for (i = 0; *(s + i) && k < fieldStart - 1; ++i)
		if (*(s + i) == DELIMINATOR)
			++k;

	for (j = 0; *(s + i + j) && *(s + i + j) != DELIMINATOR; ++j);
		
	s1 = malloc(j*sizeof(char));

	for (k = 0; k < j; ++k)
		*(s1 + k) = *(s + i + k);

	*(s1 + k) = '\0';

	k = 0;
	for (i = 0; *(t + i) && k < fieldStart - 1; ++i)
		if (*(t + i) == DELIMINATOR)
			++k;

	for (j = 0; *(t + i + j) && *(t + i + j) != DELIMINATOR; ++j);
		
	t1 = malloc(j*sizeof(char));

	for (k = 0; k < j; ++k)
		*(t1 + k) = *(t + i + k);

	*(t1 + k) = '\0';

	printf("s = %s t = %s\n", s1, t1);
	return strcmp(s1, t1);; 
} 

int rfieldcmp (const char *s, const char *t) {
	return foldfieldcmp(t, s);
}

int foldfieldcmp (const char *s, const char *t) {
	char	*s1;
	char	*t1;
	int	i = 0, j = 0, k = 0;

	for (i = 0; *(s + i) && k < fieldStart - 1; ++i)
		if (*(s + i) == DELIMINATOR) 
			++k;

	for (j = 0; *(s + i + j) && *(s + i + j) != DELIMINATOR; ++j);
		
	s1 = malloc(j*sizeof(char));

	for (k = 0; k < j; ++k)
		*(s1 + k) = *(s + i + k);

	*(s1 + k) = '\0';

	k = 0;
	for (i = 0; *(t + i) && k < fieldStart - 1; ++i)
		if (*(t + i) == DELIMINATOR)
			++k;

	for (j = 0; *(t + i + j) && *(t + i + j) != DELIMINATOR; ++j);
		
	t1 = malloc(j*sizeof(char));

	for (k = 0; k < j; ++k)
		*(t1 + k) = *(t + i + k);

	*(t1 + k) = '\0';
	toLower(s1);
	toLower(t1);
	return strcmp(s1, t1);
}

int rfoldfieldcmp (const char *s, const char *t) {
	return foldfieldcmp(t, s);
}

int numfieldcmp (const char *s, const char *t) {
	char	*s1;
	char	*t1;
	int	i = 0, j = 0, k = 0;

	for (i = 0; *(s + i) && k < fieldStart - 1; ++i)
		if (*(s + i) == DELIMINATOR)
			++k;

	for (j = 0; *(s + i + j) && *(s + i + j) != DELIMINATOR; ++j);
		
	s1 = malloc(j*sizeof(char));

	for (k = 0; k < j; ++k)
		*(s1 + k) = *(s + i + k);
	
	k = 0;
	for (i = 0; *(t + i) && k < fieldStart - 1; ++i)
		if (*(t + i) == DELIMINATOR)
			++k;

	for (j = 0; *(t + i + j) && *(t + i + j) != DELIMINATOR; ++j);
		
	t1 = malloc(j*sizeof(char));

	for (k = 0; k < j; ++k)
		*(t1 + k) = *(t + i + k);
	
	return numcmp(s1, t1); 
} 

int rnumfieldcmp (const char *s, const char *t) {
	return foldfieldcmp(t, s);
}

void toLower (char *s) {
	int i = 0;
	for (; *(s + i); ++i) {
		*(s + i) = TO_LOWER(*(s + i));
	} 

	*(s + i) = '\0';
}

/* svap: interchange v[i] and v[j] */
void swap (char **v, int i, int j) {
	char *temp;
	temp = *(v+i);
	*(v+i) = *(v+j);
	*(v+j) = temp;
}
