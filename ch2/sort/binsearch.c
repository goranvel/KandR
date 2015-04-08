#include <stdio.h>

int binsearch(int x, int arr[], int n);

int main(void){
	int size = (~0)  + 1;
	printf("%d \n", size);
	int hell[size];
	unsigned int i = 0, g=1;
	for(; i < size; ++i){
		hell[i] = g+(i+1);
		g = hell[i];
		printf("%d %d\n", i, g);
	}

	printf("\n%d\n", binsearch(2557, hell, i-1));
}

int binsearch(int x, int arr[], int n){
	int low = 0, mid, high = n-1;

	while(low <= high){
		mid = (low+high) / 2;
		
		if(x < arr[mid]) {
			high = mid - 1;
		} else if (x > arr[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
		printf("%d %d\n", high, low);
	}

	return -1;
}
