/** @file Queue.h
 *  @brief Implements a queue
 *
 *  Implements a queue in order to be used for solving the n-puzzle game.
 *
 *  @version 1.0
 *  @author Marios Pafitis
 *  @bugs No known bugs
 */
#include "Tree_Node.h"
#include "Frontier_Node.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
	int size;
	FRONTIER_NODE *frontier_head;
	FRONTIER_NODE *frontier_tail;
} QUEUE;

/** @brief Initializes a Queue
 *
 *	This function creates and initializes a queue
 *
 * 	@param **queue the pointer in the queue we are going to create and initialize
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int initQueue(QUEUE **);

/** @brief Adds a new element in the queue
 *
 *	This function adds a new element in the tail of the queue
 *
 * 	@param **queue the pointer in the queue we are going to create and initialize
 * 	@param **treeNode the new element we want to add in the queue
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int enQueue(QUEUE *, TREE_NODE *);

/** @brief Removes the first element from the queue
 *
 *	This function removes the element from the head of the queue.
 *
 * 	@param **queue the pointer in the queue we are going to create and initialize
 * 	@param **retVal the TREE_NODE element we are going to return
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int deQueue(QUEUE *, TREE_NODE **);

/** @brief Adds a new element in the ascending order queue
 *
 *	This function adds a new element in the queue but in a specific position in order
 *	for the queue to be in ascending order. The value for comparison is the heuristic value
 *
 * 	@param **queue the pointer in the queue we are going to create and initialize
 * 	@param **treeNode the new element we want to add in the queue
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int insertSorted(QUEUE *, TREE_NODE *);

/** @brief Adds a new element in the ascending order queue
 *
 *	This function adds a new element in the queue but in a specific position in order
 *	for the queue to be in ascending order. The value for comparison is the heuristic value + the
 *	depht of the treeNode in the tree.
 *
 * 	@param **queue the pointer in the queue we are going to create and initialize
 * 	@param **treeNode the new element we want to add in the queue
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int insertAStar(QUEUE *, TREE_NODE *);

#endif
