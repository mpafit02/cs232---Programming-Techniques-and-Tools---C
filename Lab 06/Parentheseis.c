#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Structs
typedef struct node {
	char value;
	struct node *next;
} NODE;

typedef struct {
	int size;
	NODE *top;
} STACK;

// Methods
int initStack(STACK **stack);
int push(STACK *stack, char val);
int pop(STACK *stack, char *val);
int isEmpty(STACK *stack);
int match(char a, char b);

int main() {
	STACK *stack;
	initStack(&stack);
	char str[] = "[()]{}{[()()]()}";
	printf("\nString: %s\n", str);
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
			push(stack, str[i]);
		} else {
			char c = stack->top->value;
			pop(stack, &c);
			if (isEmpty(stack) == -1) {
				printf("Error!");
			} else if (match(c, str[i])) {
				printf("\nMatch %c and %c.", c, str[i]);
			} else {
				printf("\nNot match %c and %c.", c, str[i]);
				exit(-1);
			}
		}
		i++;
	}
	printf("\n\nFinished!\n");
	return 0;
}

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

int push(STACK *stack, char val) {
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

int pop(STACK *stack, char *val) {
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
int match(char a, char b) {
	return ((a == '(' && b == ')') || (a == '[' && b == ']')
			|| (a == '{' && b == '}'));
}
