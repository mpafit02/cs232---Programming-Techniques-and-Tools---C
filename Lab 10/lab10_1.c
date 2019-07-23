#include <stdio.h>

int main() {
	int x = 10;
	int y = -3;
	int z = 4;

	printf("\nX: %d", x);
	if (x & 0x80000000 != 0) {
		printf("\nNegative");
	} else {
		printf("\nPositive");
	}
	printf("\nY: %d", y);
	if (y & 0x80000000 != 0) {
		printf("\nNegative");
	} else {
		printf("\nPositive");
	}
	printf("\n");

	if ((x & 0x80000000) == (y & 0x80000000)) {
		printf("\nSame");
	} else {
		printf("\nNot same");
	}
	if ((x & 0x80000000) == (z & 0x80000000)) {
		printf("\nSame");
	} else {
		printf("\nNot same");
	}
	return 0;
}
