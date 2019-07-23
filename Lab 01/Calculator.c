#include <stdio.h>

int main(){
	int num1, num2;
	char operator;
	printf("Dose 1st number: ");
	scanf("%d", &num1);
	printf("Dose 2nd number: ");
	scanf("%d", &num2);
	printf("Dose operator: ");
	scanf(" %c", &operator);
	if(operator == '-'){
		printf("Sum is: %d", num1 - num2);
	}else if(operator == '+'){
		printf("Sum is: %d", num1 + num2);
	}else if(operator == '*'){
		printf("Sum is: %d", num1 * num2);
	}else if(operator == '/'){
		printf("Sum is: %d", num1 / num2);
	}else{
		printf("Wrong operator!");
	}
	return 0;
}
