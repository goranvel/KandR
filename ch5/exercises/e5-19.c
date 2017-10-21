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

	int type;
	char *temp = malloc(MAXTOKEN);

	while (gettoken() != EOF) {
		strcpy(out, token);
		printf("o %s t %s\n", out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS) {
				if (strncmp (out + strlen(out) - 2, "()", 2))
					strcat (out, token);
			} else if (type =='*') {
				sprintf (temp, "(*%s)", out);
				strcpy (out, temp);
			} else if (type == NAME) {
				printf("%s %s <<\n", token, out);
				sprintf(temp, "%s %s", token, out);
				printf("%s \n", temp);
				strcpy(out, temp);
			} else 
				printf ("Invalid input at %s\n", token);

		printf("%s\n", out);
	}
	
	free(buf);
	free(token);
	free(name);
	free(datatype);
	free(out);
	free(temp);

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
	char c = (buf > bufStart) ? *--buf : getchar();
	
	if (c == EOF) {
		buf = bufStart;
		*buf = '\0';
	}
	

	return c;
}

void ungetch (int c) {
	(*buf++) = (c != EOF) ? c : '\0';
}
