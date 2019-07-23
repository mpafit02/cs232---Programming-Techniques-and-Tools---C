/** @file Tree.h
 *  @brief Implements tree
 *
 *  Implements tree in order to solve the n-puzzle game
 *
 *  @version 1.0
 *  @author Marios Pafitis
 *  @bugs No known bugs
 */
#ifndef TREE_H
#define TREE_H
#include "Tree_Node.h"

typedef struct {
	int size;
	TREE_NODE *head;
} TREE;

/** @brief Initializes a Tree
 *
 *	This function creates and initializes a tree
 *
 * 	@param **tree the pointer in the tree we are going to create and initialize
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int initTree(TREE **);

/** @brief Frees the tree
 *
 *	This function frees the tree with post order recursion
 *
 *	@param *node the head of the tree
 * 	@param N the size of the puzzle
 * 	@return void
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
void freeTree(int N, TREE_NODE *node);

#endif
