#include <stdio.h>

#define MAX_INPUT	1000
#define LINELEN	5 

/* gets a single line of input */
int getLine(char line[]);
/* folds long line into LINELEN long lines */
void foldLine(char in[], char out[]);
/* checks if character is ' ' or '-' or '\n' */
int hasBreaker(char c);

/* demonstrates folding lines */
/* I Went for old style type writter folding line praktices just for fun
 * todays go back till you hit new line would be easier to implement and
 * is more beautiful but less chalenging. I aslo opted for version that
 * would not break word right after first or second character
 */
main() {
	char in[MAX_INPUT];
	char out[MAX_INPUT];

	int lineLen = 0;	
	while((lineLen = getLine(in)) != 0) {
		printf("\nINPUT:\n%s\n", in);
	
		if(lineLen > LINELEN) {
			foldLine(in, out);
		}

		printf("\nOUTPUT:\n%s\n", out);
	}

	return 0;
}	

/* gets a single line */
int getLine(char line[]) {
	int i = 0;
 	for(;(line[i] = getchar()) != EOF && i < MAX_INPUT; ++i);
	line[i] = '\0';

	return i;
}

/* Folds a line into LINELEN long lines, all lines are equal lenth
	long word is split into 2 with - at the end of first part */
void foldLine(char in[], char out[]) {
	int i = 0, j = 0, k = 1;
	out[j++] = in[i++];
	while(in[i] != '\0') {
		if(in[i] == '\n') {
			k = 0;
		}

		/* folds line on space if it is 1 or 2 characters before perfect line lenght
				or folds line at wanted LENGHT unless LENGHT + 2 is a space
		*/	
		if ((k % (LINELEN - 1) == 0 && hasBreaker(in[i])) ||		// if break is 1 or 2 characters before desired
				(k % (LINELEN - 2) == 0 && hasBreaker(in[i]))) {	// line length
			if (in[i] == ' ') { // if space replace it with NEW LINE
				out[j++] = '\n';
				++i;
				k = 0;
			} else if (in[i] == '-') { // if there is a '-' add new line after it
				out[j++] = in[i++];
				out[j++] = '\n';
				k = 0;
			}
		} else if ( k % (LINELEN - 1) == 0 &&  // if input has at least 2 characters beyond
							hasBreaker(in[i+2]) ) {		// desirable line lenght
			if(in[i+1] == ' ') {
				out[j++] = '\n';
				++i;
				++k;
			} else if (in[i+1] == '-') {
				out[j++] = '\n';
				++k;
			} else {
				out[j++] = '-';
				out[j++] = '\n';
				++k;
			}
		} else if (k % LINELEN == 0 && in[i] != '\n' && !hasBreaker(in[i+1])) {
			if(in[i] == ' ') {
				out[j++] = '\n';
				++i;
			} else if (in[i] == '-') {
				out[j++] = in[i++];
				out[j++] = '\n';
			} else {
				out[j++] = '-';
				out[j++] = '\n';
			}
			k = 0;
		} 

		out[j++] = in[i++];
		k++;
	}
	out[j] = '\0';
}

/* Helper function to check if line has good place to break it into 2 lines */
int hasBreaker(char c) {
	return (c == ' ' || c == '-' || c == '\n');
}
