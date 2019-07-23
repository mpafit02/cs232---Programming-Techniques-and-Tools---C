#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[] = { "(2+((3+4)*(5*6)))" };
	int i;
	STACK *stack;
	initStack(&stack);
	for (i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		if (str[i] == '(') {
			// IGNORE
		} else if (str[i] == ')') {
			int val1, val2, symbol;
			pop(stack, &val1);
			pop(stack, &symbol);
			pop(stack, &val2);
			int result = 0;
			if (symbol == '*') {
				result = val1 * val2;
				push(stack, result);
			} else if (symbol == '/') {
				result = val1 / val2;
				push(stack, result);
			} else if (symbol == '-') {
				result = val1 - val2;
				push(stack, result);
			} else if (symbol == '+') {
				result = val1 + val2;
				push(stack, result);
			}
			printf("\n%d", result);
		} else if (str[i] >= '0' && str[i] <= '9') {
			push(stack, str[i] - '0');
		} else {
			push(stack, str[i]);
		}
	}
	return 0;
}
