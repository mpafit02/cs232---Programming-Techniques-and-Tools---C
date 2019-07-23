/** @file dynamicArray.c
 *  @brief The solution of lab exercise of EPL132 Lab13
 *
 * The program read from the user an integer number representing the array size.
 * Then, it allocates memory for these array elelemnts, reads from the user and 
 * prints these elements. Finally it deallocates memory.
 *
 *  @author Teaching Assistant
 *  @bug 
 */
#include <stdio.h>
#include <stdlib.h>


int *get_numbers(int);

int *get_numbers(int size) {
  int *block;
  
  block = (int *) malloc(size * sizeof(int));
  
  return block;
}

int main() {
  int count;
  int i;
  int cont;
  int *number;
  
  cont = 1;
  
  while (cont == 1) {
    printf("How many integer numbers? ");
    scanf("%d", &count);
    
    number = get_numbers(count);
    
    for (i = 0; i < count; i++)	{
      printf("Enter number[%d] ", i+1);
      scanf("%d", number+i);
    }
    
    printf("Continue (0=No)? ");
    scanf("%d", &cont); 
  }
  
  free(number);
  number = NULL;
  
  return 0;
}
