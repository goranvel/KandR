#include <stdio.h>

int main() {
	char c=0;
	int nl=0;

	while((c = getchar()) != EOF)
		if(c == '\n')
			++nl;

	printf("%d\n", nl);
}
