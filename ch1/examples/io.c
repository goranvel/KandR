#include <stdio.h>

/*
	Gets input and redirects it into output
*/

int main() {
	char c;

	c = getchar();
	while(c != EOF){
		putchar(c);
		c = getchar();
		if(c == EOF){
			printf("EXITING\n");
		}
	}
}
