/** @file functions.c
 *  @brief A test file for EPL132-Lab3.
 *
 *  These empty function definitions are provided
 *  so that stdio will build without complaining.
 *  You will need to fill these functions in. This
 *  is the implementation of the console driver.
 *  Important details about its implementation
 *  should go in these comments.
 *
 *  @author Pavlos Antoniou
 *  @author Pyrros Bratskas
 *  @bug No know bugs.
 */

/* enswmatwsh vivliothikwn */
#include <stdio.h>

/* Protwtypa synarthsewn  - SYMPLHRWSTE ANALOGA */
int athroisma(int x, int y);
int diafora(int x, int y);
void typwsi(int a, int b);


/** @brief Adds two integer numbers and returns the sum.
 *
 *  You can add a more detailed description here explaining 
 *  how the functions works (for more complex functions).
 *
 *  @param a the first integer
 *  @param b the second integer
 *  @return The sum of a and b
 */
int athroisma(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}


/** @brief Adds two integer numbers and returns the sum.
 *
 *  You can add a more detailed description here explaining 
 *  how the functions works (for more complex functions).
 *
 *  @param a the first integer
 *  @param b the second integer
 *  @return The sum of a and b
 */
int diafora(int a, int b) {
	int diff;
	diff = a - b;
	return diff;
}


/** @brief Adds two integer numbers and returns the sum.
 *
 *  You can add a more detailed description here explaining 
 *  how the functions works (for more complex functions).
 *
 *  @param a the first integer
 *  @param b the second integer
 *  @return The sum of a and b
 */
void typwsi(int a, int b) {
	printf("\nTo athroisma einai %d\n", a);
	printf("\nH diafora einai %d\n", b);
}


/** @brief Program entrypoint.
 *  
 *  This is the entrypoint for your program.
 *  You will use this to test purposes.
 *
 * @return Should not return
 */
int main() {
  /* Dilosi metavlitwn */
  int num1, num2, sum, diff;
  
  /* Diavasma dedomenwn */
  printf("Tha dwseis dyo akeraious arithmous\n");                
  printf("Dwse prwto arithmo: ");
  scanf("%d", &num1);
  printf("Dwse deytero arithmo: ");
  scanf("%d", &num2);
  
  /* Kalesma synarthsewn - SYMPLHRWSTE ANALOGA  */
  sum = athroisma(num1, num2);
  diff = diafora(num1, num2);	
  typwsi(sum, diff);  

  return(0);
} 
