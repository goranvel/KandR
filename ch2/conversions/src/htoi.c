#include <stdio.h>

int hToI(char hex[]);

int main(void){
	printf("%d\n", hToI("0x10F"));
}

int hToI(char hex[]){
	if(hex[0] != '0' && (hex[1] != 'x' || hex[1] != 'X')){
		printf("Invalid HEX value hex value has to start with 0x");
		return 0;
	}

	int i = 2, n = 0, charDif = 0;

	for(;hex[i] != '\0'; ++i){
		if((hex[i] >= 'a' && hex[i] <= 'f')){
			charDif = 'a' - '0' - 10;
		} else if(hex[i] >= 'A' && hex[i] <='F'){
			charDif = 'A' - '0' - 10;
		} else if(hex[i] >= '0' && hex[i] <= '9'){
			charDif = 0;
		} else {
			charDif = 999;
		}

		if(hex[i] - '0' - charDif < 0 || 
				hex[i] - '0' - charDif > 15){
			printf("invalid hex value hex values must be between 0 and 9 or A and F or a and f\n");
			return 0;
		}

		n = 16 * n + (hex[i] - '0' - charDif);
	}

	return n;
}
