/** @file operators3.c
 *  @brief Operator precedence and data types. Use of formatting.
 *
 *  This program performs various logical and arithmetic operations. 
 *  Its purpose is to demonstrate the importance and priority of operators, 
 *  data types, and the use of formatting.
 *
 *  @author Pavlos Antoniou
 *  @bug No known bugs.
 */


#include <stdio.h>

int main() {
  printf("Bonjour.\n");

  printf("-4-3*2-1 = %d\n", -4-3*2-1);

  printf("-5/2 = %d\n", -5/2);
  printf("2*-5/2 = %d\n", 2*-5/2);
  printf("4-5-3==2*-5/2+1 = %d\n", 4-5-3==2*-5/2+1);

  printf("1+3*8%3 = %d\n", 1+3*8%3);

  int n1 = 20, x1;
  x1 = n1++; printf("x1 = %d\n", x1);

  int n2 = 20, x2;
  x2 = ++n2; printf("x2 = %d\n", x2);

  printf("32&&2.3 = %d\n", 32&&2.3);

  printf("!65.34 = %d\n", !65.34);

  printf("0||!(32>12) = %d\n", 0||!(32>12));
  
  int X1, A=5, B=10, C=1; 
  X1 = ((2*A+3)*B+4);
  printf("X1 = %d\n", X1);

  int X2=3, Y=4; 
  X2 *= Y+1;
  printf("X2 = %d\n", X2);

  printf("Au revoir.\n");
  return (0);
}
