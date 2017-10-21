#include <stdio.h>

# define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char* alloc(int);		/* return pointer to n characters */
void afree(char *);	/* free storage pointed by pointer */

int main(void) {
	char *p, a = 'A';
	p = alloc(sizeof(int));
	p = alloc(sizeof(int));

	printf("%c \n", a);

	afree(p);

	return;
}

char *alloc(int n) {			/* return pointer to n characters */
	printf("allocp %d \n", allocbuf+ ALLOCSIZE - allocp);

	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;	/* old p */
	} else						/* not enought room */
		return 0;
}

void afree(char *p) { /* free storage pointerd to by p */
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
