#include <stdio.h>

int hToI(char a[]);
 
int main(void) {
	char *c = "fFff";
	printf("%d \n", hToI(c));
}

int hToI(char str[]) {
	unsigned i = 0, val = 0;
	if(str[0] == '0' && (str[1] == 'x' || str[1] == 'X')){
		i+=2;
	}
	while(str[i] != '\0') {
		val = val << 4;
		if(str[i] > '0' && str[i] < '9') {
		 	val = val + ((unsigned) str[i]) - '0';
		} else if (str[i] > 'a' && str[i] < 'z') {
			val = val + ((unsigned) str[i]) - 'a' + 10;
		} else if (str[i] > 'A' && str[i] < 'Z') {
			val = val + ((unsigned) str[i]) - 'A' + 10;
		} else {
			return -1;
		}
		++i;
	}
	return val;
		
}
