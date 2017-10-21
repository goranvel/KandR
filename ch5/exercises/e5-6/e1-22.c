#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 1000
#define LINELEN	5
#define HASBREAK(c) ((c == ' ' || c == '-' || c == '\n'))


int getLine(char *line);
void foldLine(char *in);

int main(void) {
	char *in	= malloc(MAX_INPUT*sizeof(char));
	int lineLen	= 0;

	while((lineLen = getLine(in)) != 0) {
		printf("\nINPUT: \n%s", in);
		if (lineLen > LINELEN) {
			foldLine(in);
		}
		printf("\nOUTPUT: \n%s", in);
	}

	return 0;
}

int getLine(char *line) {
	int i = 0;
	for(;(*line = getchar()) != EOF && i < MAX_INPUT; ++line, ++i);
	*line = '\0';

	return i;
}


void foldLine(char *out) {
	char *in	= malloc(MAX_INPUT*sizeof(char));
	int k = 1;
	char *startOut = out, *startIn = in;
	while (*out != '\0') {
		*in++ = *out++;
	}
	*in = '\0';
	out = startOut;
	in	= startIn;
	
	out++;
	in++;
	while (*in != '\0') {
		if(*in == '\n') {
			k = 0;
		}

		if ((k % (LINELEN - 1) == 0 && HASBREAK(*in)) ||
				(k % (LINELEN - 2) == 0 && HASBREAK(*in))) {
			if (*in == ' ') {
				*out++ = '\n';
				++in;
				k = 0;
			} else if (*in == '-') {
				*out++ = '\n';
				k = 0;
			}
		} else if (k % (LINELEN - 1) == 0 && HASBREAK(*(in+2))) {
			if(*(in + 1) == ' ') {
				*out++ = '\n';
				++in;
				++k;
			} else if (*(in + 1) == '-') {
				*out++ = '\n';
				++k;
			} else {
				*out++ = '-';
				*out++ = '\n';
				++k;
			}
		} else if (k % LINELEN == 0 && *in != '\n' && !HASBREAK(*(in+1))) {
			if(*in == ' ') {
				*out++ = '\n';
				++in;
			} else if (*in == '-') {
				*out++ = '\n';
			} else {
				*out++ = '-';
				*out++ = '\n';
			}
			k = 0;
		}

		*out++ = *in++;
		++k;
	}
	*out = '\0';
}
