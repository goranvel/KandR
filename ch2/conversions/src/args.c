#include <stdio.h>

int main(void){
	double a = 3.2;
	printf("%d\n", sizeof(a));
	google(a);
}

void google(c){
	printf("%d\n", sizeof(c));
}
