#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define	MAXWORD 100

struct tnode {
	char		*word;
	int		count;
	struct	tnode *next;
	struct	tnode *prev;
	struct	tnode *left;
	struct	tnode *right;
};

struct	tnode	*addtree		(struct tnode *, char *);
void				treeprint	(struct tnode *);
int				getWord		(char *, int);

char				*buf, *bufStart;
struct	tnode *biggest;

int main (void) {
	bufStart	=	buf	= malloc (MAXWORD * sizeof(char));

	struct tnode	*root;
	char *word	= malloc(MAXWORD);

	root = NULL;
	while (getWord (word, MAXWORD) != EOF)
		if (isalpha (*word)) {
			root	= addtree	(root, word);
		}

	treeprint (biggest);
	free (buf);


	return 0;
}


int getWord (char *word, int lim) {
	int c, getch (void);
	void ungetch(int);
	
	char *w = word;
	
	while (isspace (c = getch()));
	
	if (c != EOF)
		*w++	= c;
	
	if (!isalpha (c))  {
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

void treeprint (struct tnode *p) {
	if (p) {
		printf ("%d %s \n", p->count, p->word);
		treeprint (p->next);
		free (p);
	}
}

struct tnode *addtree (struct tnode *p, char *w) {
	int cond;
	struct tnode *temp = NULL;

	if (!p) {
		p = malloc(sizeof(struct tnode));
		p->word	= strdup (w);
		p->count	= 1;
		p->left	= p->right = NULL ;// p->next	= NULL;

		if (biggest) {
			temp = biggest;
			for (;temp->next; temp = temp->next);
			temp->next = p;
			p->prev = temp;
		} else
			biggest = p;
	} else if (!(cond = strcmp (w, p->word))) {
		p->count++;
		temp = p;
		if (temp != biggest && temp->prev->count < temp->count)  {
			if (temp->prev)
				temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
	
			while (temp->prev && temp->prev->count < temp->count) {
				temp->next = temp->prev;
				temp->prev = temp->prev->prev;
				printf ("in %s\n", temp->word);

				if (temp->next == biggest)
					biggest = temp;
			}
		
			if (temp->prev)
				temp->prev->next = temp;

			temp->next->prev = temp;

		}
	} else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return p;
}
