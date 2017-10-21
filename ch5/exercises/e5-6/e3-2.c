#include <stdio.h>
#include <stdlib.h>

void escape(char *s, char *t);
void unescape(char *s);

int main(void) {
	char *in		= malloc(12*sizeof(char));
	char *out	= malloc(12*sizeof(char));
	char *a = in;

	*in++ = 'a';
	*in++ = '\t';
	*in++ = '\n';
	*in++ = 'c';
	*in++ = '\b';
	*in++ = '\0';
	*in++ = 'e';
	*in++ = '\\';
	*in++ = 'f';
	*in++ = EOF;
	*in = '\0';
	in = a;
	printf ("in %s\n", in);
	escape (out, in);
	printf ("%s\n", out);

	unescape (out);
	printf ("%s\n", out);
	escape (in, out);
	printf ("%s\n", in);

	return 0;
}

void escape (char *s, char *t) {
	int i = 0, j = 0;
	for(; *t != EOF; ++t)
		switch (*t)  {
			case '\n':
				*s++ = '\\';
				*s++ = 'n';
				break;
			case '\b':
				*s++ = '\\';
				*s++ = 'b';
				break;
			case '\t':
				*s++ = '\\';
				*s++ = 't';
				break;
			case '\0':
				*s++ = '\\';
				*s++ = '0';
			case '\\':
				*s++ = '\\';
				*s++ = '\\';
			default :
				*s++ = *t;
		}
	*s = EOF;
}

void unescape (char *in) {
	char *step = in;
	for(;*step != EOF; ++step)
		switch (*step) {
			case '\\' :
				switch (*++step) {
					case 'n' :
						*in++ = '\n'; 
						break;
					case 't' :
						*in++ = '\t';
						break;
					case 'b'	:
						*in++ = '\b';
						break;
					case '0' :
						*in++ = '\0';
						break;
					case '\\' :
						*in++ = '\\';
						break;
					default :
						*in++ = *step;
						break;
				} 
				break;
			default :
				*in++ = *step;
				break;
		}

	*in = '\0';
}
