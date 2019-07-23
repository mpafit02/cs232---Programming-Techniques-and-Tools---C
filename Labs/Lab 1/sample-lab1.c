/** @file sample-lab2.c
 *  @brief A sample program to illustrate some concepts fro EPL132-Lab2
 *
 *  This program implements a crazy way to print to standard output
 *
 *  @author Pyrros Bratskas
 *  @bug No known bugs.
 */

#include <stdio.h>   /* needed for printf(), scanf(), sprintf() */
#include <string.h>  /* needed for strlen() */
#include <unistd.h>  /* needed for write() */

#define MAX  10

int foo(int y);

int foo(int y) {
  return y*y;
}


main() {
  
  int x, i;
  char buf[10];
  
  for(i = 0; i < MAX; i++) {
    x = foo(i);
    sprintf(buf, "%d", x);
    write(0, buf, strlen(buf));
    buf[0] = '\n';
    write(0, buf, 1);
  }
  
}
