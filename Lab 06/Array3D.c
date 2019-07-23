#include <stdio.h>
#include <stdlib.h>

int main() {
	int ***arr3D = (int ***) malloc(4 * sizeof(int **));
	int i, j, k;

	// Create array
	for (i = 0; i < 4; i++) {
		arr3D[i] = (int **) malloc(5 * sizeof(int *));
		for (j = 0; j < 5; j++) {
			arr3D[i][j] = (int *) malloc(3 * sizeof(int));
		}
	}

	// Set array
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 3; k++) {
				arr3D[i][j][k] = i + j + k;
			}
		}
	}

	// Print array
	for (i = 0; i < 4; i++) {
		printf("\n");
		for (j = 0; j < 5; j++) {
			printf("\n");
			for (k = 0; k < 3; k++) {
				printf("(%d, %d, %d) = %d  ", i, j, k, arr3D[i][j][k]);
			}
		}
	}
	printf("\n");
	printf("\n");
	// Free array
	for (j = 0; j < 5; j++) {
		free(arr3D[i][j]);
	}
	for (i = 0; i < 4; i++) {
		free(arr3D[i]);
	}
	free(arr3D);
	return 0;
}
