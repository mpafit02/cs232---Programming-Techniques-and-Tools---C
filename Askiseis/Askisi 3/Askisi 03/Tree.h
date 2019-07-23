#ifndef TREE_H
#define TREE_H
#include "Tree_Node.h"

typedef struct {
	int size;
	TREE_NODE *head;
} TREE;

int initTree(TREE **);

#endif
