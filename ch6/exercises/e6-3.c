#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN		100
#define MAXLiNEs	100

struct line {
	int num;
	struct line *next;
};

struct tnode {
	char *word;
	struct line *lines;
	struct tnode *left;
	struct tnode *right;
};

char noiseword[125][15] = { 
	"a",		"about",		"after",		"all",	"also",
	"an",		"another",	"any",		"are",	"as",
	"and",	"at",
	"be",			"because",	"been",	"before",	"being",
	"between",	"bug",		"both",	"by",
	"came",	"can",	"come",	"could",
	"did",	"do",
	"each",	"even",
	"for",	"from",	"further",	"furthermore",
	"get",	"got",
	"had",	"has",		"have",	"her",	"here",		
	"him",	"himself",	"his",	"how",	"hi",		
	"however",
	"i",		"if",		"in",		"into",	"is",
	"it",		"its",	"indeed",
	"just",
	"like",
	"made",		"many",	"me",		"might",	"more", 
	"moreover", "most",	"much",	"must",	"my",
	"never",	"not",	"now",
	"of",		"on",		"only",	"other",	"our",
	"out",	"or",		"over",
	"said",	"same",	"see",	"should",	"since",
	"she",	"some",	"still",	"such",
	"take",	"than",	"that",	"the",		"their", 
	"them",	"then",	"there", "these",		"therefore",
	"they",	"this",	"those", "through",	"to", 
	"too",	"thus",
	"under", "up",
	"very",
	"was",	"way",	"we",		"well",	"were", 
	"what",	"when",	"where", "which", "while",
	"who",	"will",	"with",	"would",
	"you",	"your"
};


struct tnode	*addtree		(struct tnode *,	char *, int);
void				treeprint	(struct tnode *);
int				getLine		(char*);
void				clearBuf		(void);

int main (void) {
	struct tnode *root;
	char *word = malloc (MAXLEN);

	int lineCnt = 1, i = 0;
	for (;getLine (word) > 0; ++lineCnt) {
		i = 0;
		for (;*(word+i) != '\0';  ++i) {
			for (; isalpha (*(word + i)); ++i);


			if (isspace(*(word + i)) || ispunct(*(word+i)) || *(word + i) == '\0') {
				if (isNoiseWord(word))
					break; 

				*(word + i) = '\0';
				root = addtree (root, word, lineCnt);
				word += i+1;
				for (;isspace(*word); ++word);

				i = ~0;
			}
		}	
	}

	treeprint (root);

	return 0;
}

int isNoiseWord (char *s) {
	int size = sizeof(noiseword) / sizeof(*noiseword);
	int i = 0;
	void strToLower (char *);
	strToLower(s);

	for(; i < size; ++i)
		if (!(strcmp(s, *(noiseword + i))))
			return i + 1;
	
	return 0;
}

void strToLower (char *s) {
	for (;*s;++s)
		*s |= 0x20;
}


int getLine (char *s) {
	int i = 0;

	for (; i < len && (*s = getchar()) != EOF && *s != '\n'; ++i, ++s);

	*s = '\0';

	return i;
}

void treeprint (struct tnode *p) {
	if (p) {
		treeprint (p->left);
		printf ("%s occures at lines :\n\t", p->word);
		struct line *pnode = 0, *cnode = p->lines;
			
		printf("%d", p->lines->num);
		if (cnode->next) {
			pnode = cnode;
			cnode = cnode->next;
			for (;cnode; pnode = cnode, cnode = cnode->next) printf (", %d", cnode->num);
		}
	
		printf ("\n");
		treeprint (p->right);
		free (p);
	}
}

struct tnode *addtree (struct tnode *p, char *w, int line) {
	int cond = 0; 
	if (!p) {
		p = malloc (sizeof(struct tnode));
		p->word = strdup(w);

		p->lines = malloc(sizeof(struct line));
		p->lines->num = line;
		p->lines->next = 0;
		p->left = p->right = NULL;
	} else if (!(cond = strcmp (w, p->word))) {
		struct line *pnode = 0, *cnode = p->lines, *newNode = malloc(sizeof(struct line));

		pnode = cnode;
		for (;cnode->next; pnode = cnode, cnode = cnode->next);
		
		newNode->num	= line;
		newNode->next	= NULL;
		cnode->next = newNode;

	} else if (cond < 0)
		p->left	= addtree(p->left,	w, line);
	else
		p->right	= addtree (p->right, w,	line); 

	return p;
}
