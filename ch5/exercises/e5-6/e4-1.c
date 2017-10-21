#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int strrindex(char *s, char *t);
int getLine(char *s, int lim);
int getSize(char *s, int maxLen);

int main(void) {
	char *s = malloc(sizeof(char)*MAXLEN);

	getLine(s, MAXLEN);
	printf("Output %s, %d\n", s, strrindex(s, "peh"));

	return 0;
}

int strrindex (char *s, char *t) {
	char *end = s + getSize(s, MAXLEN) - 1, *tt;
	int tSize = getSize(t, MAXLEN);
	for(; s < end; --end) {
		printf("in\n");
		for (tt = t + tSize - 1; tt > t && *tt == *end; --end, --tt);

		if(tt == t)
			return end - s;
	}
	return -1;
}

int getLine (char *s, int lim) {
	char *start = s;
	for (;(*start = getchar()) != EOF && *start != '\n' && start - s < lim; ++start);

	*start = '\0';
	return start - s;
}

int getSize(char *s, int lim){
	printf("%s i \n", s);	
	int i = 0;
	for (; *s != '\0' && i < lim; ++i, ++s);
	return i;
}
