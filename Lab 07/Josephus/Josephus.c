#include <stdio.h>
#include "Queue.h"

#define N 10
#define M 3

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
