/** @file Tree.c
 *  @brief Implements tree
 *
 *  Implements tree in order to solve the n-puzzle game
 *
 *  @version 1.0
 *  @author Marios Pafitis
 *  @bugs No known bugs
 */
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

int initTree(TREE **tree) {
	*tree = (TREE *) malloc(sizeof(TREE));
	if (*tree == NULL) {
		return EXIT_FAILURE;
	}
	(*tree)->size = 0;
	(*tree)->head = NULL;
	return EXIT_SUCCESS;
}

void freeTree(int N, TREE_NODE *node) {
	if (node == NULL) {
		return;
	} else {
		freeTree(N, node->children[0]);
		freeTree(N, node->children[1]);
		freeTree(N, node->children[2]);
		freeTree(N, node->children[3]);
		if (node->puzzle != NULL) {
			int i;
			for (i = 0; i < N; i++) {
				free(node->puzzle[i]);
			}
			free(node->puzzle);
		}
		if (node->path != NULL)
			free(node->path);
		free(node);
	}
}

#ifdef DEBUG

int main() {
	TREE *tree = NULL;
	initTree(&tree);
	TREE_NODE *node = (TREE_NODE *) malloc(sizeof(TREE_NODE));
	int i, j;
	int**puzzle = (int **) malloc(sizeof(int*));
	for (i = 0; i < 3; i++) {
		puzzle[i] = (int *) malloc(sizeof(int));
		for (j = 0; j < 3; j++) {
			puzzle[i][j] = i;
		}
	}
	node->puzzle = puzzle;
	tree->head = node;
	tree->size = 1;
	printf("\n\nCreated\n");
	freeTree(3, tree->head);
	printf("\nFree\n\n");
	return 0;
}
#endif
