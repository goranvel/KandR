#include <stdio.h>
#include <stdlib.h>

int main(void){
	int  i;
	char c = 45;

	i = c;
	c = i;

	printf("%d %d %c\n", sizeof(c), c, c);
}
