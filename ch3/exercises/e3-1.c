#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000

/* group of binary search functions */
int binarySearch1(int x, int v[], int n); /* K & R example */
int binarySearch2(int x, int v[], int n); /* one useing conditional expressions */
int binarySearch3(int x, int v[], int n); /* one using improved K & R example */

int main () {
	int i = 0, j = 0, arr[MAX_NUM], testArr[MAX_NUM];
	srand(time(NULL));

	int timer = 0, timer1 = 0, timer2 = 0, timer3 = 0;

	for(j = 0; j < MAX_NUM; ++j) {
		for(i = 0; i < MAX_NUM; ++i) {
			testArr[i] = rand() % 10000;
		}
		
		for(i = 0; i < MAX_NUM; ++i) {
			arr[i] = i;
		}

		for(i = 0, timer = clock(); i < MAX_NUM; ++i) {
			binarySearch1(testArr[i], arr, MAX_NUM);
		}
		timer1 += clock() - timer;

		for(i = 0, timer = clock(); i < MAX_NUM; ++i) {
			binarySearch2(testArr[i], arr, MAX_NUM);
		}
		timer2 += clock() - timer;

		for(i = 0, timer = clock(); i < MAX_NUM; ++i) {
			binarySearch3(testArr[i], arr, MAX_NUM);
		}
		timer3 += clock() - timer;
	}
	
	printf("\n%d\n", timer1); 

	printf("\n%d\n", timer2); 

	printf("\n%d\n", timer3); 
	return 0;
}

int binarySearch1(int x, int v[], int n) {
	int low = 0, high = n-1, mid = (high + low) >> 1;
	
	while(low <= high) {
		mid = (low+high) >> 1;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	
	return -1;
}

int binarySearch2(int x, int v[], int n) {
	int low = 0, high = n-1, mid = (high + low) >> 1;

	while(x != v[mid] && low < high) {
		high	= x < v[mid] ? mid - 1 : high;
		low	= x > v[mid] ? mid + 1 : low;
		mid	= (low + high) / 2;
	}

	
	if( v[mid] == x) {
		return mid;
	}

	return -1;
}

int binarySearch3(int x, int v[], int n) {
	int low = 0, high = n-1, mid = (high + low) >> 1, i = 0;

	while(x != v[mid] && low < high) {
		if( x < v[mid])
			high = mid;
		else 
			low = mid + 1;
		
		mid	= (low+high) >> 1;
		++i;
	}
	
	if( v[mid] == x) {
		return mid;
	}

	return -1;
}
