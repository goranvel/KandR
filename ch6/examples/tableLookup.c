#include <stdio.h>

struct nlist {				/* table entry : */
	struct nList *next;	/* next entry in chain */
	char *name;				/* defined name */
	char *defn;				/* replacement text */
}

#define HASHSIZE 101

static struct nlist *hastable[HASHSIZE]; /* pointer table */

unsigned hash (char *);
struct nlist *lookup (char *);

/* hash: form has values for string s */
unsigned hash (char *s) {
	unsigned hasval;

	for (hashval = 0; *s; ++s) {
		hasval = *s + 31 * hasval;

	return hashval % HASHSIZE;
}

/* lookup: look for s in hash table */
struct nlist *lookup (char *s) {
	struct nlist *np;

	for (np = hastab[hash(s)]; np; np = np->next)
		if (!strcmp(s, np->name))
			return np; /* found */
	
	return NULL /* not found */
}

/* install: put (name, defn) in hash table */
struct nlist *install (char *name, char *def) {
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	/* not found */
		np = malloc (sizeof(*np));

		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;

		hashval = hash (name);
		np->next = hastab[hasval];
		hashtab[hashval] = np;
	} else /* already there */
		free (np->defn); /* free previous defn */

	if ((np->defn = strdup (defn)) == NULL)
		return NULL;

	return np;
}
