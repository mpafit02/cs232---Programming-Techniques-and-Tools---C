#ifndef STACK_H
#define STACK_H
#include "Node.h"

typedef struct {
	int size;
	NODE *top;
} STACK;


// Methods
int initStack(STACK **stack);
int push(STACK *stack, int val);
int pop(STACK *stack, int *val);
int isEmpty(STACK *stack);

#endif
