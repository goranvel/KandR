#include <stdio.h>

char* strncpy(char *, const char *, size_t);
char* strncat(char *, const char *, size_t);
int strncmp(char *, const char *, size_t);

int main(void) {
	char a[15] = "Hello ";
	char b[15] = "Hello yellow";//" olleH";
	char c[15];	
	printf("%d \n", strncmp(a, b, 10));
	strncpy(c, b, 10);
	printf("%s>\n", c);
	strncat(a, b, 10);
	printf("%s<\n", a);

	return 0;
}

char* strncpy(char *s, const char *t, size_t n) {
	int i = 0;
	for(i = 0; i < n && (*s = *t); ++s, ++t, ++i);
	
	*s = '\0';	
	return s - i;
}

char* strncat(char *s, const char *t, size_t n) {
	int i = 0;
	char *a = s;
	while(*++s);
	for(i = 0; i < n && (*s = *t); ++s, ++t, ++i);

	*s = '\0';
	return a;
}

int strncmp(char *s, const char *t, size_t n) {
	int i = 0;

	for(i = 0; *s == *t && i < n; ++s, ++t, ++i);

	return *s - *t;
}
