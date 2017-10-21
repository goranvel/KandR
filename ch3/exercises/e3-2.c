#include <stdio.h>

#define MAX_LINE 1000;

/* copies string from t to s with replaceing escape characters
		from:
			tab			'\t' to '\\' + 't'
			newline		'\n' to '\\' + 'n'
			backspace	'\n' to '\\' + 'b'
*/
void escape(char s[], char t[]);
/* oposite of above converts escape characters into real characters */
void unescape(char s[], char t[]);

int main(void) {
	char in[10], out[10];
	in[0] = 'a';
	in[1] = '\t';
	in[2] = 'b';
	in[3] = '\n';
	in[4] = 'c';
	in[5] = '\b';
	in[6] = 'd';
	in[7] = '\0';

	printf("%s\n", in);	
	escape(out, in);
	printf("%s\n", out);

	unescape(in, out);
	printf("%s\n", in);

	return 0;
}

void escape(char s[], char t[]) {
	int i = 0, j = 0;
	while(t[i] != '\0') {
		switch (t[i]) {
			case '\n' :
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t' :
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\b' :
				s[j++] = '\\';
				s[j++] = 'b';
				break;
			default	 :
				s[j++] = t[i];
				break;
		}
		++i;
	}
	s[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i = 0, j = 0;
	while(t[i] != '\0') {
		switch (t[i]) {
			case '\\' :	
				switch (t[++i]) {
					case 'n' :
						s[j++] = '\n';	
						break;
					case 't' :
						s[j++] = '\t';
						break;
					case 'b' :
						s[j++] = '\b';
						break;
					default	 :
						s[j++] = t[i];
						break;
				}
				break;
			default :
				s[j++] = t[i];
				break;
		}
		++i;
	}
		
	s[j] = '\0';
}

