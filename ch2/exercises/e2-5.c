#include <stdio.h>

/* any(): returns first occurance of any character from s2 in s1 */
int any(char s1[], char s2[]);

int main(void) {
	printf("%d\n", any("dbbedefe", "ed"));
}

/* any(): returns first occurance of any character from s2 in s1 */
int any(char s1[], char s2[]) {
	int i, j;
	for(i = 0; s1[i] != '\0'; ++i) {
		for(j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j);

		if (s1[i] == s2[j]) {
			return i;
		}
	}
	
	return -1;
}
