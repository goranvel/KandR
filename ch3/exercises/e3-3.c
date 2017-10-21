#include <stdio.h>

#define MAX_LEN 1000
/* expand(): expand character range to all characters */
void expand(char s1[], char s2[]);
/* checks if character is alphabet or not */
int isLetter(char c);

int main(void) {
	char unexp[MAX_LEN] = "helloa-zaaaA-Z";
	char exp[MAX_LEN];

	expand(unexp, exp);
	printf("%s\n%s\n", unexp, exp);
	return 0;
}

/* expands character from range to all characters */
void expand(char s1[], char s2[]) {
	int i = 0, j = 0, k = 1;
	for(i = 0, j = 0; s1[i] != '\0';  ++i) {
		if(s1[i] == '-')
			++i;
		s2[j++] = s1[i];

		if (s1[i+1] == '-' && 
				isLetter(s1[i]) && 
					isLetter(s1[i+2])){
			for(;(s2[j] = s1[i] + k) < s1[i+2]; ++k, ++j);

			++i;
			k = 1;
		}
	}
	s2[j] = '\0';
}

int isLetter(char c) {
	if((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
				(c >= '0' && c <= '9')) {
		return 1;	
	}
	return 0;
}
