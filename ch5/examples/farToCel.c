#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("%d *C", 5 * (atoi(argv[1]) - 32)/9);

	return 0;
}
