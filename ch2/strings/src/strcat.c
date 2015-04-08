#include <stdio.h>

void strCat(char ch1[], char ch2[]);

int main(void){
	char ch1[6] = "Hello";
	char ch2[9] = " world!\n";

	strCat(ch1, ch2);

	printf(ch1);
}

void strCat(char ch1[], char ch2[]){
	int i, j;

	i = j = 0;
	while(ch1[++i] != '\0');
	while((ch1[i++] = ch2[j++]) != '\0');
}
