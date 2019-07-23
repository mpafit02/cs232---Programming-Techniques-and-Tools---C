/** @file CtoF.c
 *  @brief Converts Celsius to Fahrenheit
 *
 *  This program ask the user to enter a number representing the degrees 
 *  Celsius, and converts it in degrees Fahrenheit.
 *
 *  @author Pyrros Bratskas
 *  @author Pavlos Antoniou
 *  @bug No known bugs.
 */


#include <stdio.h>		/* needed for printf(), scanf() */					 

/* Constants declaration */
#define		FACTOR_1	9.0/5.0 
#define		FACTOR_2	32 

int main()
{
  /* Variables declaration */ 
  float Vathmoi_C, Vathmoi_F;   
  
  /* Read data from the user */
  printf("Dwse bathmous Celsius: ");
  scanf("%f",&Vathmoi_C);
  
  /* Converting Celsius to Fahrenheit */
  Vathmoi_F = FACTOR_1*Vathmoi_C + FACTOR_2;
  
  /* Printing results */
  printf("%.2f vathmoi Celsius antistoixoun se %.2f vathmous Fahrenheit\n", \
                                                    Vathmoi_C, Vathmoi_F);
  
  return 0;
}


