#include <stdio.h>

/*
	Gets input and redirects it into output
*/

int main() {
	char c;

	while((c = getchar()) != EOF){
		putchar(c);
	}
}
