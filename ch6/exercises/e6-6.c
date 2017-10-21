#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct nlist {				/* table entry  */
	struct nList *next;	/* next entry in chain */
	char *name;				/* defined name */
	char *defn;				/* replacement text */
};

#define HASHSIZE	101
#define MAXWORD	100

char		*buf, *bufStart;
static	struct	nlist *hashtab [HASHSIZE]; /* pointer table */

unsigned	hash	(char *);
struct	nlist *lookup (char *);
struct	nlist *install (char *, char *);

int		getWord	(char *, int);
void		udef		(char *);
int		getch		(void);
void		ungetch	(int);

int main	(void) {
	bufStart	= buf =	malloc (MAXWORD * sizeof(char));

	char	*word	=	malloc (MAXWORD * sizeof(char));

	while (getWord (word, MAXWORD) != EOF) {
		if (lookup(word)) {
			word = (lookup(word))->defn;
		} else if (!strcmp (word, "#define")) {
			char valCh[5];

			getWord	( word,	MAXWORD );
			getWord	( valCh, MAXWORD );
			// put value into hashtab
			install	( word,	valCh );
		} else if (!strcmp(word, "#udef")) {
			getWord	( word, MAXWORD );
			udef (word);
		}
	}
	
	free (buf);
	return 0;
}
		
/* hash: form has values for string s */
unsigned hash (char *s) {
	unsigned hashval;

	for (hashval = 0; *s; ++s)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

/* lookup: look for s in hash table */
struct nlist *lookup(char *s) {
	struct nlist *np;
	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->name) == 0)
			return np;

	return NULL;
}

/* install: put (name, defn) in hash table */
struct nlist *install (char *name, char *defn) {
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	/* not found */
		np = malloc (sizeof(*np));

		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;

		hashval = hash (name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}// else /* already there */
//		free (np->defn); /* free previous defn */

	if ((np->defn = strdup (defn)) == NULL)
		return NULL;

	return np;
}

/* udef: undefines #define macro */
void udef (char *name) {
	struct nlist *np, *p;
	np = hashtab[hash(*name)];
	p = np->next;
	for (;p != NULL && !strcmp(p->name, *name); p = p->next);

	if (np->next != NULL) {
		p = np->next;
		np->next = p->next;
		free (p);
	}
}

int getWord (char *word, int lim) {
	int	c,	getch (void);
	void		ungetch(int);

	char *w = word;
	
	while (isspace (c = getch()));

	if (c != EOF)
		*w++ = c;

	if (!isalpha (c) && c != '#') {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; ++w)
		if (!isalpha (*w = getch())) {
			ungetch(*w);
			break;
		}


	*w = '\0';
	return *word;
}

int getch (void) {
	return buf != bufStart ? *--buf : getchar();
}

void ungetch (int c) {
	*buf++ = (c != EOF) ? c : '\0';
}
