#include <stdio.h>
#include <stdlib.h>

int main(){

	int num1, num2;
	printf("Dose 1st number: ");
	scanf("%d", &num1);
	printf("Dose 2nd number: ");
	scanf("%d", &num2);
	if((num1 < 0 && abs(num1) > num2)||(num2 < 0 && abs(num2) > num1)){
		printf("Is Negative!");
	}else{
		printf("Is Positive!");
	}
	return 0;
}
