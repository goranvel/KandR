#include <stdio.h>

#define ARR_SIZE 10

void qsort(int v[], int left, int right);
void printMyR(int v[]);

int main(void) {
	int v[] = {2, 5, 1, 9, 7, 3, 8, 4, 6, 0};
	printMyR(v);
	printf("\n");
	qsort(v, 0, ARR_SIZE - 1);

	return 0;
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right) { /* do noting if array contains fewer than two elements */
		return;
	}

	swap(v, left, (left+right) >> 1); /* move partition elemeto */
	last = left;							 /* to v[0] */
	if(right == ARR_SIZE - 1) {
		printMyR(v);
		printf("\n");
	}
	for (i = left + 1; i<= right; ++i) { /* partion */
		if (v[i] < v[left]) {
			swap(v, ++last, i); 
			printf(">> last=%d i=%d \n", last, i);
		}
		printMyR(v);
		printf(" left = %d, right = %d, last = %d\n", left, right, last);
	} 

	swap(v, left, last); /* restore partition elements */

	printf("\n\n\n");
	qsort(v, left, last - 1);
	qsort(v, last + 1, right); 
}

void swap(int v[], int i, int j) {
	printf("swapping %d %d\n", v[i], v[j]);
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void printMyR(int v[]) {
	int i = 0; 
	for (; i < ARR_SIZE; ++i) {
		printf("%d", v[i]);
		if(i < ARR_SIZE - 1) {
			printf(", ");
		}
	}   
	printf("");
}
