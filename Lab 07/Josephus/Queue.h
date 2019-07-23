#ifndef QUEUE_H
#define QUEUE_H

typedef struct node {
	int data;
	struct node *next;
} NODE;

typedef struct {
	NODE *head;
	NODE *tail;
	int size;
} QUEUE;

void initQueue(QUEUE **);
int enqueue(QUEUE *, int);
NODE* dequeue(QUEUE *);

#endif
