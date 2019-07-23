#include <stdio.h>
#include <stdlib.h>

void insertionSort(double *, int);
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!
int main() {
	int counter = 0, i;
	int n = 2;
	double num;
	double *arr = (double *) malloc(sizeof(double) * n);
	printf("Give me an element: ");
	while (scanf("%lf", &num) == 1) {
		if (counter == n) {
			n *= 2;
			double *temp;
			temp = (double *) realloc(arr, n * sizeof(arr) * sizeof(double));
			if (temp == NULL) {
				printf("\nUnable to reallocate the space of the array!");
				exit(-1);
			}
			arr = temp;
		}
		arr[counter] = num;
		counter++;
		printf("Give me an element: ");
	}
	insertionSort(arr, counter);
	for (i = 0; i < counter; i++) {
		printf("\n%.2lf ", *(arr + i));
	}
	free(arr);
	return 0;
}

void insertionSort(double *arr, int counter) {
	int i, j;
	for (i = 1; i < counter; i++) {
		for (j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				double temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
