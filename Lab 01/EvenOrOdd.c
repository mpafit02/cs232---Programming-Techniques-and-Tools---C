/** @file FtoC.c
 *  @brief Finds if  a number is even or odd
 *
 *  This program ask the user to enter an integer number and it represents if it is
 *  even or odd.
 *
 *  @author Marios Pafitis
 *  @bug No known bugs.
 */

#include <stdio.h> /* Standard Input and Output*/

int main() {
	int num1;
	printf("Dose number: ");
	scanf("%d", &num1);
	if (num1 % 2 == 0) {
		printf("O arithmos einai even.");
	} else {
		printf("O arithmos einai odd.");
	}
	return 0;
}
