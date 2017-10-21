#include <stdio.h>

int any (char *s1, char *s2);

int main (void) {
	printf("%d\n", any("abcdefe", "ed"));

	return 0;
}

int any (char *s1, char *s2) {
	int i = 0, j = 0;
	for(; *s1 != '\0'; ++s1, ++i) {
		for(; *s2 != '\0' && *s1 != *(s2 + j); ++j);

		if (*s1 == *s2)
			return i;
	}

	return -1;
}
