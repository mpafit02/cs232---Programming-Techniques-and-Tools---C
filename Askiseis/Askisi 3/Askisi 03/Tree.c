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

/** @brief Initializes a Tree
 *
 *	This function creates and initializes a tree
 *
 * 	@param **tree the pointer in the tree we are going to create and initialize
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int initTree(TREE **tree) {
	*tree = (TREE *) malloc(sizeof(TREE));
	if (*tree == NULL) {
		return EXIT_FAILURE;
	}
	(*tree)->size = 0;
	(*tree)->head = NULL;
	return EXIT_SUCCESS;
}
