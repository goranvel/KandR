#include <stdio.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strCat(char s[], char t[]);

int main(void) {
	char s[20] = "AbCdEfGh";
	char t[10] = "123459789";
	strCat(s, t); 
	printf("%s\n", s);
	return 0;
}

/* strcat: concatenate t to end of s; s must be big enought */
void strCat(char s[], char t[]) {
	int i, j;

	i = j = 0;
	while (s[i] != '\0') {  /* find end of s */
		i++;
	}

	while((s[i++] = t[j++]) != '\0');  /* copy t */
}
