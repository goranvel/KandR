#include <stdio.h>

void squeezeIt(char s1[], char s2[]);

int main(void){
	char c1[7] = "abcded\n", c2[3] = "ad";

	squeezeIt(c1, c2);

	printf(c1);

	return 0;
}

void squeezeIt(char s1[], char s2[]){
	int i, j, k;
	i = j = k = 0;

	char out[10];

	for(i = 0; s1[i] != '\0'; ++i){
		for(j = 0; s2[j] != '\0'; ++j){
			for(;s1[i+k] == s2[j]; ++k);
		}
		s1[i] = s1[i+k];
	}
}
