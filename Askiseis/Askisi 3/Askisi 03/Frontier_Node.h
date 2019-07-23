#include "Tree_Node.h"

#ifndef FRONTIER_NODE_H
#define FRONTIER_NODE_H

typedef struct frontier_node {
	TREE_NODE *leaf;
	struct frontier_node *next;
	struct frontier_node *previous;
} FRONTIER_NODE;

#endif
