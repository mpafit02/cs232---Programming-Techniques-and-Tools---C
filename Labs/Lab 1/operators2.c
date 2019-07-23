/** @file operators2.c
 *  @brief Operator precedence and data types. Use of formatting.
 *
 *  This program performs various logical operations. Its purpose is 
 *  to demonstrate the importance and priority of operators, data types, 
 *  and the use of formatting.
 *
 *  @author Pavlos Antoniou
 *  @bug No known bugs.
 */


#include <stdio.h>

int main() {
    
  int a=1, b=1, c=0, d=0; 
             
  printf("a = %d, b = %d, c = %d, d = %d.\n", a, b, c, d);

  printf("a || b && c || d  = %d.\n", a || b && c || d);
  printf("(a||b) && c || d) = %d.\n", (a||b) && c || d);
  printf("a || (b&&c) || d  = %d.\n", a || (b&&c) || d);
  printf("a || b && (c||d)  = %d.\n", a || b && (c||d));

  return 0;
}
