#include <stdio.h>

void squeeze (char *s1, char *s2);

int main (void) {
	char s1[] =  "aabcdeefghiij";
	char *s2 = "aei";

	squeeze(s1, s2);

	printf("%s \n", s1);

	return 0;
}

void squeeze (char *s1, char *s2) {
	int i = 0, j = 0;

	for (; *(s1 + j) != '\0'; ++s1) {
		for(i = 0; *(s1 + j) != *(s2 + i) && *(s2 + i) != '\n'; ++i);

		for(; *(s1 + j) == *(s2 + i); ++j);

		*s1 = *(s1 + j);
	}

	*s1 = '\0';
}
