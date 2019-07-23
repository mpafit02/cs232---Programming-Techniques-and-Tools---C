/** @file pointers.c
 *  @brief Pointers and tables
 *
 * This program reads a table of integers and calculates using a 
 * function tha number of positives, negatives and zero elements 
 * in the table. 
 *
 * @author Your name here
 * @bug No known bugs.
 */ 


#include <stdio.h>

/* Macro declaration */
#define MAX_SIZE 10

/* Write below the prototype of function counting() */


/* Write below the definition of function counting() */

int main()
{
  /* Variable declaration */
  int size, num_pos, num_neg, num_zero, count;
  
  /* Dilwste ton pinaka table. SIMPLIRWSTE ANALOGWS */

  
  /* Diavasma dedomenwn */
  printf("Dose to megethos toy pinaka (metaksi 1 kai %d): ", MAX_SIZE); 
  scanf("%d", &size);
  
  /*Elegxos orthotitas megethous pinaka */
  if(size<1 || size>MAX_SIZE)
    exit(-1);
  
  /* Kataskevi pinaka. SIMPLIRWSTE ANALOGWS*/
  printf("Tha dwseis %d akeraious arithmous, ena-ena tin fora\n",size);                
  
  
  /* Ektypwsh pinaka. SIMPLIRWSTE ANALOGWS */
  printf("\nEktyposi pinaka:\n");

  
  /* Kalesma synarthshs. SIMPLIRWSTE ANALOGWS */

  
  /* Ektypwsh apotelesmatos */
  printf("O pinakas periexei %d thetikous(o) arithmous,\n", num_pos);
  printf("%d arnhtikous arithmous(o), kai %d arithmous(o) iso me mhden.\n", num_neg, num_zero);
  
  return(0);
} 


