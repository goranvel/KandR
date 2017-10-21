#include <stdio.h>

int binarySearch(int x, int v[], int n) {
	int low, hight, mid

	low = 0;
	high = n - 1

	while(low <= hight) {
		mid = (low + high) >> 1;
		if(x < v[mid]) {
			high	= mid - 1;
		} else if (x > v[mid]) {
			low	= mid + 1;
		} else {
			return mid;
		}
	}

	return -1; /* no matc */
}
