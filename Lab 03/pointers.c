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
//void counting(int, int, int, int, int);


void counting(int size, int *p, int *pos, int *neg, int *zero) {
	for (int i = 0; i < size; i++) {
		if (*(p + i) < 0) {
			++*neg;
		} else if (*(p + i) > 0) {
			++*pos;
		} else {
			++*zero;
		}
	}
}

/* Write below the definition of function counting() */

int main() {
	/* Variable declaration */
	int size, num_pos, num_neg, num_zero, count;
	int *p;
	num_pos = 0;
	num_neg = 0;
	num_zero = 0;
	/* Dilwste ton pinaka table. SIMPLIRWSTE ANALOGWS */
	int arr[MAX_SIZE];
	p = arr;

	/* Diavasma dedomenwn */
	printf("Dose to megethos toy pinaka (metaksi 1 kai %d): ", MAX_SIZE);
	scanf("%d", &size);

	/*Elegxos orthotitas megethous pinaka */
	if (size < 1 || size > MAX_SIZE) {
		return (0);
	}

	/* Kataskevi pinaka. SIMPLIRWSTE ANALOGWS*/

	printf("Tha dwseis %d akeraious arithmous, ena-ena tin fora\n", size);

	for (int i = 0; i < size; i++) {
		printf("Dwse arithmo %d: ", i);
		scanf("%d", p + i); // to scanf dexete diefthinsi
	}

	/* Ektypwsh pinaka. SIMPLIRWSTE ANALOGWS */
	printf("\nEktyposi pinaka:\n");

	for (int i = 0; i < size; i++) {
		printf("table[%d] = %d\n", i, *(p + i)); // thelei diefthinsi to printf
	}

	/* Kalesma synarthshs. SIMPLIRWSTE ANALOGWS */

	counting(size, p, &num_pos, &num_neg, &num_zero);

	/* Ektypwsh apotelesmatos */
	printf("O pinakas periexei %d thetikous(o) arithmous,\n", num_pos);
	printf("%d arnhtikous arithmous(o), kai %d arithmous(o) iso me mhden.\n",
			num_neg, num_zero);

	return (0);
}
