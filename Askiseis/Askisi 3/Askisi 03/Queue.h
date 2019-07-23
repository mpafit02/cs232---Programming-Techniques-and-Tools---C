#include "Tree_Node.h"
#include "Frontier_Node.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
	int size;
	FRONTIER_NODE *frontier_head;
	FRONTIER_NODE *frontier_tail;
} QUEUE;

int initQueue(QUEUE **);
int enQueue(QUEUE *, TREE_NODE *);
int deQueue(QUEUE *, TREE_NODE **);
int insertSorted(QUEUE *, TREE_NODE *);
int insertAStar(QUEUE *, TREE_NODE *);

#endif
