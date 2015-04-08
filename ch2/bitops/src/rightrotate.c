#include <stdio.h>

char rightrotate(char x, int n);

int main(void){
	printf("%d\n", rightrotate(-5, 3));

	return 0;
}

char rightrotate(char x, int n){
	return (x << ((sizeof(x) << 3) - n)) | (((unsigned char) x) >> n);
}
