#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM	10000

int binarySearch1(int x, int *v, int n); /* K & R */
int binarySearch2(int x, int *v, int n); /* conditional statement */
int binarySearch3(int x, int *v, int n);

int main (void) {
	int i = 0, j = 0;

	int *arr = malloc(MAX_NUM * sizeof(int));
	int *testArr = malloc(MAX_NUM * sizeof(int));

	int *arr2 = arr, *testArr2 = testArr;

	int timer = 0, timer1 = 0, timer2 = 0, timer3 = 0;
	for (arr = arr2; (arr - arr2) < MAX_NUM; ++arr) {
		for (testArr = testArr2 ;(testArr - testArr2) < MAX_NUM; ++testArr)
			*testArr = rand() % MAX_NUM;

		for (arr = arr2; (arr - arr2) < MAX_NUM; ++arr) 
			*arr = i;


		for(testArr = testArr2, timer = clock(); (testArr - testArr2) < MAX_NUM; ++testArr)
			binarySearch1(*testArr, arr, MAX_NUM);
		timer1 += clock() - timer; 

		for(testArr = testArr2, timer = clock(); (testArr - testArr2) < MAX_NUM; ++testArr);
			binarySearch2(*testArr, arr, MAX_NUM);
		timer2 += clock() - timer;

		for(testArr = testArr2, timer = clock(); (testArr - testArr2) < MAX_NUM; ++testArr)
			binarySearch3(*testArr, arr, MAX_NUM);
		timer3 += clock() - timer;
	} 

	printf("\nTimer 1: %d\n", timer1);

	printf("\nTimer 2: %d\n", timer2);

	printf("\nTimer 3: %d\n", timer3);

	return 0;
}

int binarySearch1(int x, int *v, int n) {
	int low = 0, high = n - 1, mid = (high + low) >> 1;
	while ( low < high ) {
		mid = (low + high) >> 1;
		if (x < *(v + mid)) {
			high = mid - 1; }
		else if (x > *(v + mid))
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

int binarySearch2 (int x, int *v, int n) {
	int low = 0, high = n - 1, mid = (high + low) >> 1;
	while (x != *(v + mid) && low < high) {
		high	= x < *(v + mid) ? mid - 1 : high;
		low	= x > *(v + mid) ? mid + 1 : low;
		mid	= (low + high) >> 1;
	}

	if (*(v + mid) == x)
		return mid;

	return -1;
}

int binarySearch3 (int x, int *v, int n) {
	int low = 0, high = n - 1, mid = (high + low) >> 1;
	while (x != *(v + mid) && low < high) {
		if (x < *(v + mid))
			high = mid;
		else
			low = mid + 1;

		mid = (low + high) >> 1;
	}

	if(*(v + mid) == x) {
		return mid;
	}

	return -1;
}
