#include <stdlib.h>
#include "Queue.h"

#define SUCCESS 1
#define FAILURE 0

void initQueue(QUEUE **q) {
	*q = (QUEUE *) malloc(sizeof(QUEUE));
	(*q)->head = NULL;
	(*q)->tail = NULL;
	(*q)->size = 0;
}

NODE * dequeue(QUEUE *q) {
	NODE * n = NULL;
	n = (NODE *) malloc(sizeof(NODE));
	(q->size)--;
	if (q->size == 0) {
		return NULL;
	} else {
		n = q->head;
		q->head = q->head->next;
		return n;
	}
}

int enqueue(QUEUE *q, int val) {
	NODE * n = NULL;
	n = (NODE *) malloc(sizeof(NODE));
	if (n == NULL) {
		return FAILURE;
	}
	n->data = val;
	n->next = NULL;
	if (q->size == 0) {
		q->head = n;
		q->tail = n;
	} else {
		q->tail->next = n;
		q->tail = q->tail->next;
	}
	(q->size)++;
	return SUCCESS;
}

#ifdef DEBUG
int main() {

	return 0;
}
#endif
