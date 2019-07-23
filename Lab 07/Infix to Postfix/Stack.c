#include "Stack.h"
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
int initStack(STACK **stack) {
	*stack = (STACK *) malloc(sizeof(STACK));
	if (*stack == NULL) {
		printf("\nError creating Stack!\n");
		exit(-1);
	}
	(*stack)->size = 0;
	(*stack)->top = NULL;
	return EXIT_SUCCESS;
}

int push(STACK *stack, int val) {
	NODE *n = NULL;
	n = (NODE *) malloc(sizeof(NODE));
	if (n == NULL) {
		printf("\nError creating Node!\n");
		return EXIT_FAILURE;
	}
	n->value = val;
	n->next = stack->top;
	stack->top = n;
	stack->size++;
	return EXIT_SUCCESS;
}

int pop(STACK *stack, int *val) {
	*val = stack->top->value;
	stack->top = stack->top->next;
	stack->size--;
	return EXIT_SUCCESS;
}

int isEmpty(STACK *stack) {
	if (stack->size == 0) {
		return 0;
	} else if (stack->size > 0) {
		return 1;
	} else {
		return -1;
	}
}
