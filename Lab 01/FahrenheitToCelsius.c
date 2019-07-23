/** @file FtoC.c
 *  @brief Converts Fahrenheit to Celsius
 *
 *  This program ask the user to enter a number representing the degrees
 *  Fahrenheit, and converts it in degrees Celsius.
 *
 *  @author Marios Pafitis
 *  @bug No known bugs.
 */

#include <stdio.h>		/* needed for printf(), scanf() */

/* Constants declaration */
#define		FACTOR_1	5.0/9.0
#define		FACTOR_2	32

int main() {
	/* Variables declaration */
	float Vathmoi_C, Vathmoi_F;

	/* Read data from the user */
	printf("Dwse bathmous Fahrenheit: ");
	scanf("%f", &Vathmoi_F);

	/* Converting Celsius to Fahrenheit */
	Vathmoi_C = FACTOR_1 * (Vathmoi_F - FACTOR_2);

	/* Printing results */
	printf("%.2f vathmoi Fahrenheit antistoixoun se %.2f vathmous Celsius\n",
			Vathmoi_F, Vathmoi_C);

	return 0;
}
