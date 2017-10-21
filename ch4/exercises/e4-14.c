#include <stdio.h>

#define swap(t,x,y) \
	t temp = x; \
	x = y; \
	y = temp;

int main(void) {
	int a = 5, b = 7;
	printf("%d %d\n", a, b);

	swap(int, a, b)

	printf("%d %d\n", a, b);

	return 0;
}
