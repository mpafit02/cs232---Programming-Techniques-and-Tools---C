#include <stdio.h>

int main() {
	int num1, num2;
	int counter = 0;
	int remainder = 0;
	printf("Dose 1st number: ");
	scanf("%d", &num1);
	printf("Dose 2nd number: ");
	scanf("%d", &num2);
	if (num1 > num2) {
		while (num1 >= num2) {
			num1 = num1 - num2;
			counter++;
		}
		remainder = num1;
	} else {
		while (num2 > num1) {
			num2 = num2 - num1;
			counter++;
		}
		remainder = num2;
	}
	printf("Result %d: ", counter);
	printf("Remainder %d: ", remainder);
	return 0;
}
