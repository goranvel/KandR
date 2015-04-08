#include <stdio.h>
int upperToLower(char c);

int main(void) {
	printf("%c", upperToLower('A'));
	
	return 0;
}

int upperToLower(char c){
/*	if(c>='A' && c<='Z'){
		return c + 'a' - 'A';
	} else {
		return c;
	}
*/
	return  (c >= 'A' && c<='Z') ?  c + 'a' - 'A' : c;
}
