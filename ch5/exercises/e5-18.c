#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, ERROR };

/* dcl: parse a declarator */
void	dcl		(void);
/* dirdcl: pars a direct declarator */
void	dirdcl	(void);
int	gettoken (void);

int	tokentype;		/* type of last token */
char	*token;			/* last token string */
char	*name;			/* identifier name */
char	*datatype;		/* data type = char, int, etc. */
char	*out;				/* output string */
char	*buf, *bufStart;

int main (void) {
	bufStart = buf = malloc(MAXTOKEN);
	token		= malloc(MAXTOKEN);
	name		= malloc(MAXTOKEN);
	datatype	= malloc(MAXTOKEN);
	out		= malloc(100);

	while (gettoken() != EOF) {	/* 1st token on line */
		strcpy (datatype, token);	/* is the datataype */
		*out = '\0';
		dcl();	/* parse rest of line */

		if (tokentype != '\n')
			printf("\nsyntax errors\n");
		else
			printf("%s: %s %s\n", name, out, datatype);
	}
	
	free(buf);
	free(token);
	free(name);
	free(datatype);
	free(out);

	return 0;
}

int gettoken (void) { /* return next token */
	int c, getch(void);
	void ungetch (int);
	char *p = token;
	
	while ((c = getch()) == ' ' || c == '\t');

	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy (token, "()") ;
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']';);
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch());)
			*p++ = c;

		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

int getch (void) {
	char c =buf != bufStart ? *--buf : getchar();
	
	if (c == EOF) {
		buf = bufStart;
		*buf = '\0';
	}
	

	return c;
}

void ungetch (int c) {
	(*buf++) = (c != EOF) ? c : '\0';
}

void dcl(void){
	int ns;

	for (ns = 0; gettoken() == '*'; ++ns); /* count *'s */

	dirdcl();

	while (ns--)
		strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl (void) {
	int type;

	if (tokentype == '(') { /* ( dcl ) */
		dcl();

		if (tokentype != ')')
			printf("error: missing string )\n");
	} else if (tokentype == NAME) /* varirable name */
		strcpy (name, token);
	else
		printf ("error: expected name or (dcl)\n");

	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat (out, " function returning");
		else {
			strcat (out, " array");
			strcat (out, token);
			strcat (out, " of");
		}
}
