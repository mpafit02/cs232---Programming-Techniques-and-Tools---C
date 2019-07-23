#include <stdio.h>
#define N 10

void read(int *p, int size) {
	for (int i = 0; i < size; i++) {
		printf("Value[%d] : ", i);
		scanf("%d", p + i);
	}
}

void revert(int *p, int size) {
	for (int i = 0; i < size / 2; i++) {
		int temp = *(p + i);
		*(p + i) = *(p + size - i - 1);
		*(p + size - i - 1) = temp;
	}
}

void print(int *p, int size) {
	for (int i = 0; i < size; i++) {
		printf("table[%d] = %d\n", i, *(p + i));
	}
}

int main() {
	int arr[N];
	int *p;
	p = arr;
	read(p, N);
	revert(p, N);
	print(p, N);
	return 0;
}
