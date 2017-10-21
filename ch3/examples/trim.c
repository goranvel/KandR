#include <stdio.h>
#include <string.h>
/* trim(): remove trailing blanks, tabs, newlines */
int trim(char s[]);

int main(void){
	char s1[2] = "";
	char s2[10] = "   ";

	printf("<%s>\n", s1);	
	trim(s1);
	printf("<%s>\n\n", s1);

	printf("<%s>\n", s2);	
	trim(s2);
	printf("<%s>\n", s2);

	return 0;
}

/* trim(): remove trailing blanks, tabs, newlines */
int trim(char s[]) {
	int n;
	for(n = strlen(s) - 1; n >= 0; --n) 
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;

	s[n+1] = '\0';
	

	return n;
}
