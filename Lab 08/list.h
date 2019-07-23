#ifndef LIST_H
#define LIST_H

typedef struct node {
	int value;
	struct node *next;
} NODE;

typedef struct {
	NODE *head;
} LIST;

void delete(NODE **head, unsigned int position);
void insert(NODE **head, NODE *new_node, unsigned int position);
NODE *retrieve(NODE *head, unsigned int position);
NODE *next(NODE *head, NODE *of_node);
NODE *next(NODE *head, NODE *of_node);
void print(NODE *head);
unsigned int length(NODE *head);

#endif
