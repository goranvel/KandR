#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD	100

struct tnode { /* the tree node */
	struct	wnode	*wnode;	/* points to the text */
	char		*word;
	int		cnt;
	struct	tnode	*left;	/* left child */
	struct	tnode	*right;	/* right child */
};

struct wnode {
	char				*word;
	struct wnode	*next;
};

struct tnode *addtree (struct tnode *, char *);
void treeprint (struct tnode *);
struct tnode *talloc (void);
int isType (char *);
char *getWord	(char *, char *);
int getLine (char *, int);
void clearBuf (void);

char **buf;
struct tnode *root;
int startDif = 6;

char types[5][7] = {
	"char", 
	"double",
	"float",
	"int", 
	"struct"
};

int main (int argc, char **argv) {
	if (argc == 3 && !strcmp (*(argv + 1), "-c"))  {
		startDif = atoi (*(argv+2));
	} else {
		printf ("ERROR unknown argument(s)\n");
		return 1;
	}

	buf = malloc(MAXWORD * sizeof(char *));
	char *word = malloc(MAXWORD), *line = malloc(MAXWORD);

	root = NULL;

	int bufSize = 0, cnt = 0;
	while ((cnt = getLine(line, MAXWORD)) > 0) {
		line = getWord (line, word);

		if (isType(word)) {
			line = getWord (line, word);
			while (isspace(*line)) ++line;

			if (*line == '\n') {
				printf("ERROR:\tMissing ; at the end of line\n");
			} else if (*line == ';') {
				*(buf + bufSize++) = strdup (word);
				continue;
			} else if (*line == '(') {
				++line;
				while (*line != ')') {
					while (isspace(*line)) ++line;
					line = getWord (line, word);
					while (isspace(*line)) ++line;

					if (isType(word)) {
						line		= getWord (line, word);
						*(buf + bufSize++) = strdup(word);
					} else if (*line == ',')
						++line;
					else {
						printf ("Error has occured parameters need datatype");
						return 0;
					}
				}
			} else {
				*buf = strdup (word);

				while (*line != '\0' && *line != EOF && *line != ';') {
					while (isspace(*line)) ++line;
				
					if (*line != ',') { 
						clearBuf();
						printf ("paramenters must be separated by (,) comma\n");
						return -1;
					}

					++line;
					line = getWord (line, word);
					*(buf+(++bufSize)) = strdup (word);
				}
				++bufSize;
			} 
		} else {
			printf ("ERROR: Unknown input\n");
			return -1;
		}
	}

	if (!cnt) {
		printf ("ERROR: No input\n");
		return -1;
	}

	*(buf+bufSize) = NULL;
	printf("--> %d %s\n", bufSize, *(buf+1));

	for (;*buf; ++buf) {
		root = addtree (root, *buf);
	}
	clearBuf();

	treeprint (root);
//	free (buf);

	return 0;
}

int isType (char *word) {
	int size = sizeof (types)/sizeof (*types);
	int i = 0;

	for (; i < size; ++i)
		if (!(strcmp(word, *(types+i))))
			return i + 1;

	return 0;
}

char* getWord (char *line, char* word) {
	for (;isspace(*line); ++line);

	while (isalpha(*(line)) && *line != '\0') {
		*word++ = *line++;
	}
	
	*word = '\0';
	return line;
}

int getLine (char *s, int len) {
	int i = 0;

	for (; i < len && (*s = getchar()) != EOF && *s != '\n'; ++i, ++s);

	*s		 = '\n';
	*(s+1) = '\0';

	return i;
}

void clearBuf () {
	while (*buf != NULL)
		free (*buf++);
}

/* treeprint: in-order print of tree p */
void treeprint (struct tnode *p) {
	if (p) {
		struct wnode *cnode = p->wnode;
		treeprint (p->left);
		printf("\nbase = %s\n", p->word);
		printf("%s\n", cnode->word);
		
		while(cnode->next) {
			cnode = cnode->next;
			printf("%s\n", cnode->word);
		}

		treeprint (p->right);
		free (p);
	}
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree (struct tnode *p, char *w) {
	int cond = 0;
	if (!p) {	/* a new word has arrived */
		p = talloc();
		p->word = strndup(w, startDif);
		p->wnode = malloc(sizeof(struct wnode));
		p->wnode->word = strdup(w);
		p->left = p->right = NULL;
	} else if ((cond = strncmp (w, p->wnode->word, startDif)) == 0) {
		struct wnode *pnode = 0, *cnode = p->wnode, *newNode = malloc(sizeof(struct wnode));

		while (strcmp (w, cnode->word) > 0 && cnode->next) {
			pnode = cnode;
			cnode = cnode->next;
		}

		newNode->word = strdup(w);

		if (strcmp (w, cnode->word) < 0) {
			newNode->next = cnode;

			if(pnode) 
				pnode->next = newNode;
			else 
				p->wnode = newNode;

		} else {
			cnode->next = newNode;
			newNode->next = 0;
		} 
	} else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else if (cond > 0)	/* greater than into right subtree */
		p->right = addtree (p->right, w);


	return p;
}

struct tnode *talloc (void) {
	return malloc(sizeof(struct tnode));
}
