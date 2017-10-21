#include <unistd.h>
#include <stdio.h>

#undef getchar

int main (void) {
	int getchar(void), c;

	while ((c = getchar()) != EOF)
		write (0, &c, 1);

	return 0;
}


int getchar (void) {
	char c = 0;

	return (read (0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
