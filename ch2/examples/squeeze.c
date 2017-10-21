#include <stdio.h>

/* squeeze : delete all c from s */
void squeeze(char s[], int c);

int main(void) {
	char s[10] = "abcdeffgh";
	squeeze(s, 'f');
	printf("%s\n", s);

	return 0;
}
void squeeze(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++){
		if(s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}
