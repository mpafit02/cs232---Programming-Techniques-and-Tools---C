

/* enswmatwsh vivliothikwn */
#include <stdio.h>

/* Protwtypa synarthsewn  - SYMPLHRWSTE ANALOGA */
int athroisma(int x, int y);
int diafora(int x, int y);
void typwsi();

/* Orismos synartisewn - SYMPLHRWSTE ANALOGA  */
int athroisma(int a, int b) {
	int sum;
	sum = a + b;
	return sum;
}

int diafora(int a, int b) {
	int diff;
	diff = a - b;
	return diff;
}

void typwsi(int a, int b) {
	printf("\nTo athroisma einai %d\n", a);
	printf("\nH diafora einai %d\n", b);
}

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
