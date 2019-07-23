#include <stdio.h>

int main() {
	int A[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90 };
	int * p = A;
	printf("*p+2 = %d\n", *p + 2);
	printf("*(p+2) = %d\n", *(p + 2));
	printf("&p+1 = %p\n", &p + 1);
	printf("p+1 = %p\n", p + 1);
	printf("&A[4]-3 = %p\n", &A[4] - 3);
	printf("A+3 = %p\n", A + 3);
	printf("&A[7]-p = %p\n", &A[7] - p);
	printf("p+(*p-10) = %p\n", p + (*p - 10));
	return 0;
}
