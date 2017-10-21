#include <stdio.h>

/* squeeze(): removes any occurance of characters from s2 in s1 */
void squeeze(char s1[], char s2[]);

int main(void) {
	char s1[15] = "aabcdeefighiij";
	char s2[5] = "aei";

	squeeze(s1, s2);

	printf("%s \n", s1);

	return 0;
}

/* squeeze(): removes any occurance of characters from s2 in s1 */
/* void squeeze(char s1[], char s2[]) {
	int i = 0, j = 0, k = 0;
	for(i = 0; s2[i] != '\0'; ++i) {
		for(j = 0; s1[j] != '\0'; ++j) {
		//	printf("%3d\t%3d -- %c\t%c", i, j, s2[i], s1[j]);

			if(s2[i] == s1[j]) {
				k = j;
				while(s1[k] != '\0') {
					s1[k] = s1[++k];
				}
				s1[k] = '\0';
				--j;
			} 
		//	printf("\n");
		}
	}
} */


void squeeze (char s1[], char s2[]) {
	int i = 0, j = 0, k = 0;
	for (i = 0; s1[i + k] != '\0'; ++i) {
		for (j = 0; s1[i + k] != s2[j] && s2[j] != '\0'; ++j);

		for (; s1[i + k] == s2[j]; ++k);

		s1[i] = s1[i + k];
	}
	s1[i] = '\0';
}
