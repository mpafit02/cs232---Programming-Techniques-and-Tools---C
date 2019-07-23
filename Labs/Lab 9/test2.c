#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
  // free in not called
  char *waste = (char *)malloc(SIZE *sizeof(char));

  // uninitialized pointer
  int *a;
  printf("%d\n", *a);

  // write past end of array
  waste[SIZE] = 0;

  return 0;
}
