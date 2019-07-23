#include <stdio.h>

#define MAX_TERMS 101 /* maximum number of terms +1*/

// Structs
typedef struct {
	int col;
	int row;
	int value;
} term;

// Methods
int readMatrix(term[]);
void printMatrix(term[], int);
int search(term[], int, int);

int main() {
	term a[MAX_TERMS];
	int size;
	int key;

	size = readMatrix(a);

	printMatrix(a, size);

	printf("Search for: ");
	scanf("%d", &key);

	if (search(a, size, key))
		printf("%d is in the sparse matrix.", key);
	else
		printf("%d was not found.", key);

	return 0;
}

int readMatrix(term t[]) {
	int i, j, size = 0;
	scanf("%d,%d,%d", &t[size].col, &t[size].row, &t[size].value);
	while ((t->col != -1) && (t->row != -1) && (t->value != -1)) {
		size++;
		scanf("%d,%d,%d", &t[size].col, &t[size].row, &t[size].value);
	}
	return size;
}

void printMatrix(term t[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("[%d, %d, %d]\n", t[i].col, t[i].row, t[i].value);
	}
}

int search(term t[], int size, int val) {
	int i, found = 0;
	for (i = 0; i < size; i++) {
		if (t[i].value == val) {
			found = 1;
		}
	}
	return found;
}
