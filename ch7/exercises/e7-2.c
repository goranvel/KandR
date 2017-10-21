#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN	256
#define CAPACITY	300 

#define IS_GRAPHIC(a) ((a) > 32 && (a) < 127)

/* Gets one line of input from user */
int getLine (unsigned char *s);
void format (unsigned char *s);

int main (void) {
	unsigned char *word = malloc (sizeof (char) * CAPACITY);
	printf ("%x\n", word);
	if (getLine(word) >= 0)
		format (word);
	else
		printf ("ERROR");

	return 0;
}

int getLine (unsigned char *s) {
/*	int i = 0, capacity = CAPACITY;
	char *temp;
	FILE *fp = fopen ("test.txt", "r");

	for (;(*s = fgetc(fp)) != '\n' && *(s - 1) != '\r' && i < MAX_LEN; ++i, ++s) {
/ *		if (i >= capacity) {
			capacity <<= 1;

			temp = realloc(s, capacity * sizeof(char));
			if(!temp) {
				free(s);
				printf("ERROR: Memory reallocation error");
				return -1;
			}
			s = temp;
		} * /
		putchar(
	}

	printf ("%d\n", i); */

	int i = 0;
	for (; i <= 256; ++i, ++s)
		*s = i;

	*s++ = '\r';
	*s++ = '\n';
	*s = '\0';
	return i;
}

void format (unsigned char *s) {
	// go through characters
	int i = 0;
	for (; *(s + 2) != '\0' || *(s + 1) != '\n' || *s != '\r'; ++s, ++i) {
		printf("%d ", i);
		if (IS_GRAPHIC (*(s - 1)))
			putchar (*s - 1);
		else
			printf ("0x%002x", *(s - 1));

		printf ("\n");
	}
	printf ("DONE");
}
