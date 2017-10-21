#include <stdio.h>

/* shellsort(); sort v[0] ... v[n-1] into increasing order */
void shellsort(int v[], int n);

int main(void) {
	int arr[10] = {3,8,1,5,7,2,6,9,4,0};

	shellsort(arr, 10);
	return 0;
}

void printArray( int arr[], int n) {
	int i = 0;
	for(i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/* shellsort(): sort v[0] ... v[n-1] into increasing order */
void shellsort(int v[], int n) {
	int gap, i, j, temp;

	for (gap = n >> 1; gap > 0; gap >>= 1) {
		for( i = gap; i < n; ++i) {
			for(j = i - gap; j >= 0 && v[j] > v[j+gap];  j -= gap) {
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
//				printf("j = i - gap %d ", j);
				printArray(v, n);
				printf("%d j = i - gap; j -= gap >= 0 && v[j] > v[j+gap]\n", j);
			}
			printf("%d i = gap; ++i < n\n", i);
		}
		printf("%d gap = n/2; gap /= 2 > 0\n", gap);
	}
}
