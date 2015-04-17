#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void) {
	char a[6] = "Hello";
	char b[6] = "world";

	squeeze(a, b);
	printf("%s \n", a);
}

void squeeze(char s1[], char s2[]) {
	int i = 0, j = 0, k = 0;
	for(; s2[i] != '\0'; ++i) {
		for(j = 0; s1[j] != '\0'; ++j) {
			if(s1[j] == s2[i]){
				for(k = j+1; s1[k] != '\0'; ++k) {
					s1[j++] = s1[k];	
				}
				s1[j] = '\0';
				--i;
			}	
		}
	}
}
