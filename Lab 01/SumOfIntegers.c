/** @file FtoC.c
 *  @brief Adds two integers
 *
 *  This program ask the user to enter two integer numbers and it represents the sum of them.
 *
 *  @author Marios Pafitis
 *  @bug No known bugs.
 */

#include <stdio.h> /*needed for printf() and scanf() */

int main() {
	int num1, num2;
	printf("Dose 1st number: ");
	scanf("%d", &num1);
	printf("Dose 2nd number: ");
	scanf("%d", &num2);
	printf("To athroisma einai: %d", num1 + num2);
	return 0;
}
