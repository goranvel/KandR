#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

void expand(char *s1, char *s2);
int isLetter(char c);

int main(void) {
	char unexp[]	= "helloa-zasdlfkjsldafA-Z0-9";
	char *exp	= malloc(sizeof(char) * MAX_LEN);
	
	printf("%s\n", unexp);

	expand (unexp, exp);
	printf("%s\n", exp);

	return 0;
}

void expand(char *s1, char *s2) {
	char start = 0, end = 0;
	
	for (; *s1 != '\0'; ++s1) {
		if(*s1 == '-')
			++s1;
		*s2++ = *s1;

		if (*(s1 + 1) == '-' && isLetter(*s1) && isLetter(*s1 + 2))
			for(;(*s2 = ++*s1) < *(s1+2); ++s2);
	}
	*s2 = '\0';
}

int isLetter (char c) {
	if ((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
				(c >= '0' && c <= '9')) {
		return 1;
	}
	return 0;
}
