#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode { /* the tree node */
	char	*word;	/* points to the text */
	int	count;	/* number of occurance */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* right child */
};

struct tnode *addtree (struct tnode *, char *);
void treeprint (struct tnode *);
int getword (char *, int);
struct tnode *talloc (void);
char *strDup (char *);

char *buf, *bufStart;

int main (void) {
	bufStart = buf = malloc(MAXWORD * sizeof(char));
	struct tnode *root;
	char *word = malloc(MAXWORD);

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(*word)) {
			root = addtree (root, word);
		}

	treeprint (root);
	free (buf);
	return 0;
}

/* getword: get next word or character from input */
int getword (char *word, int lim) {
	int c, getch (void);
	void ungetch (int);

	char *w = word;

	while (isspace(c = getch()));

	if (c != EOF)
		*w++ = c;

	if (!isalpha (c)) {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; ++w)
		if (!isalnum(*w = getch())) {
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

/* treeprint: in-order print of tree p */
void treeprint (struct tnode *p) {
	if (p) {
		treeprint (p->left);
		printf("%4d %s \n", p->count, p->word);
		treeprint (p->right);
		free (p);
	}
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree (struct tnode *p, char *w) {
	int cond;

	if(!p) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word	= strdup(w);
		p->count	= 1;
		p->left = p->right = NULL;
	} else if (!(cond = strcmp(w, p->word)))
		p->count++;	/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else				/* greater than into right subtree */
		p->right = addtree (p->right, w);

	return p;
}

struct tnode *talloc (void) {
	return malloc(sizeof(struct tnode));
}

char *strDup (char *s) {
	char *p;

	p = malloc(strlen(s) + 1); /* +1 for '\0' */
	if (p)
		strcpy (p, s);

	return p;
}
