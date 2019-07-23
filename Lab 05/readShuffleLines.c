#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2

int main() {
	char str[512];
	char **array2D = (char **) malloc(SIZE * sizeof(char *));
	if (array2D == NULL) {
		printf("Error creating array!");
		exit(-1);
	}
	int counter = 0, i;

	while (fgets(str, 512, stdin) != NULL) {
		if (counter >= sizeof(array2D) / sizeof(array2D[0])) {
			char **array2DTemp = (char **) realloc(array2D,
					2 * sizeof(array2D) / sizeof(array2D[0]));
			if (array2DTemp == NULL) {
				printf("Error expanding array!");
				exit(-1);
			}
			array2D = array2DTemp;
		}
		array2D[counter] = (char *) malloc(strlen(str) * sizeof(char));
		strcpy(array2D[counter], str);
		counter++;
	}
	printf("\nReverse it:\n");
	for (i = counter - 1; i >= 0; i--) {
		printf("%s", array2D[i]);
		free(array2D[i]);
	}
	free(array2D);
	return 0;
}
