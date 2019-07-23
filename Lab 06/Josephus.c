#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define N 10
#define M 3

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

int main() {
	QUEUE *q;
	initQueue(&q);
	int i;
	for (i = 0; i < N; i++) {
		enqueue(q, i);
	}
	printf("\nCreated\n");
	printf("\nData:\n");
	NODE *n;
	for (i = 0; i < N; i++) {
		printf("%d ", (n = dequeue(q))->data);
		enqueue(q, n->data);
	}
	int count = 0;
	while (q->size > 1) {
		printf("\nData %d:\n", count);
		for (i = 0; i < q->size; i++) {
			printf("%d ", (n = dequeue(q))->data);
			enqueue(q, n->data);
		}
		NODE *n;
		for (i = 1; i <= M; i++) {
			if (i == M) {
				n = dequeue(q);
				printf("\nDequeue %d:\n", n->data);
			} else {
				n = dequeue(q);
				enqueue(q, n->data);
			}
		}
		count++;
	}
	return 0;
}

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

