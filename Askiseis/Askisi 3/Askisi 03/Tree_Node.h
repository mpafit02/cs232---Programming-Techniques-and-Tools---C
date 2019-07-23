#ifndef TREE_NODE_H
#define TREE_NODE_H

typedef struct tree_node {
	int **puzzle;
	int g;
	int h;
	struct tree_node *parent;
	struct tree_node *children[4];
	int *path;
} TREE_NODE;

#endif
