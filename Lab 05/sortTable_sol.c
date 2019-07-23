/** @file sortTable.c
 *  @brief The solution of exercise 5 of EPL232 Lab5
 *
 * The program read numbers from stdin, and write them in ascending order to
 * stdout. It uses an array and the insertion sort algorithm to sort the array. 
 * The initial number of elements in the array is 2, and the final array size 
 * unknown.
 *
 *  @bug No known bugs
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* The initial number of elements in the array. */
enum {
	INITIAL_ARRAY_LENGTH = 2
};

/* The factor by which the array should grow. */
enum {
	ARRAY_GROWTH_FACTOR = 2
};

/** @brief 
 *
 * Grow the memory chunk pointed to by pdChunk so it can store iArrayLength
 * elements of type double.  Return the address of the new memory chunk, or NULL
 * if not enough memory is available. 
 *
 * @param pdChunk Points to the memory where the elements will be stored
 * @param iArrayLength the number of elements to store
 * @return The address of the new memory chunk
 */
static double *grow(double *pdChunk, int iArrayLength) {
	size_t uiNewSize;
	double *pdNewChunk;

	//assert(pdChunk != NULL);
	if (pdChunk == NULL) {
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	uiNewSize = (size_t) iArrayLength * sizeof(double);
	pdNewChunk = (double*) realloc(pdChunk, uiNewSize);

	return pdNewChunk;
}

/** @brief Sort pdNumbers[0..iCount-1] in ascending order.
 *
 * Uses insertion sort algorithm to sort the table
 *
 * @param pdNumbers The table to sort
 * @param iCount The table size
 * @return void 
 */
static void insertionSort(double *pdNumbers, int iCount) {
	int i1;
	int i2;
	double dTemp;

	//assert(pdNumbers != NULL);
	if (pdNumbers == NULL) {
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	//assert(iCount >= 0);
	if (iCount < 0) {
		fprintf(stderr, "Wrong table size\n");
		exit(EXIT_FAILURE);
	}

	for (i1 = 1; i1 < iCount; i1++)
		for (i2 = i1; i2 > 0; i2--)
			if (pdNumbers[i2] < pdNumbers[i2 - 1]) {
				dTemp = pdNumbers[i2];
				pdNumbers[i2] = pdNumbers[i2 - 1];
				pdNumbers[i2 - 1] = dTemp;
			}
}

/* Read numbers from stdin, and write them in ascending order to
 stdout.  If not enough memory is available, then write an error
 message to stderr and exit with EXIT_FAILURE.  Otherwise return 0. */

int main(void) {
	double *pdNumbers;
	int iCount;
	int iArrayLength;
	double dNumber;
	int i;

	/* Dynamically allocate an array. */

	iArrayLength = INITIAL_ARRAY_LENGTH;
	pdNumbers = (double*) calloc((size_t) iArrayLength, sizeof(double));
	if (pdNumbers == NULL) {
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	/* Read the numbers into the array. */

	iCount = 0;
	printf("Give element (Ctrl+d to stop) :");

	while (scanf("%lf", &dNumber) != EOF) {
		if (iCount == iArrayLength) {
			iArrayLength *= ARRAY_GROWTH_FACTOR;
			pdNumbers = grow(pdNumbers, iArrayLength);
			if (pdNumbers == NULL) {
				fprintf(stderr, "Not enough memory\n");
				exit(EXIT_FAILURE);
			}
		}
		pdNumbers[iCount] = dNumber;
		iCount++;
		printf("Give element (Ctrl+d to stop) :");
	}

	/* Sort the array. */

	insertionSort(pdNumbers, iCount);

	/* Write the numbers from the array. */

	printf("\n\nThe array sorted by insertion sort\n");
	for (i = 0; i < iCount; i++)
		printf("%g\n", pdNumbers[i]);

	/* Free the array. */

	free(pdNumbers);

	return 0;
}
