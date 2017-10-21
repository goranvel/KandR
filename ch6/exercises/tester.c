#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
char *buf = malloc(100);
int len = 100;
char *s = buf;
int i = 0;
for (i = 0 ; i < len && (*(s + i) = getchar()) != EOF && *(s + i) != '\n' ; ++i);
*(s + i) = '\0';
printf("'%s'\n", buf);
	return 0;
}
