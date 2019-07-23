#include <stdio.h>

int compute_sum_arithmetic_series(int smallest, int largest, int length);

int compute_sum_arithmetic_series(int smallest, int largest, int length)
{
  int sum;
  sum = (smallest + largest)*length/2;
  return sum;
}

int main()
{
  int smallest_element, sequence_length;
  int sum;				  
  int i;				 
  int largest_element;			  

  printf("Hello\n");
  printf("Enter a value of smallest element: ");
  scanf("%d",smallest_element);
  printf("Enter sequence length: ");
  scanf("%d",sequence_length);

  largest_element = smallest_element + sequence_length - 1;
  sum = compute_sum_arithmetic_series(smallest_element, largest_element, sequence_length);

  printf("The sum of the arithmetic sequence %d through %d is %d\n",
	 smallest_element, largest_element, sum);
  return 0;
}
