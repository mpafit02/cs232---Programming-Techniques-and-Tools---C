/** @file Queue.c
 *  @brief Implements a queue
 *
 *  Implements a queue in order to be used for solving the n-puzzle game.
 *
 *  @version 1.0
 *  @author Marios Pafitis
 *  @bugs No known bugs
 */
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/** @brief Initializes a Queue
 *
 *	This function creates and initializes a queue
 *
 * 	@param **queue the pointer in the queue we are going to create and initialize
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int initQueue(QUEUE **queue) {
	*queue = (QUEUE *) malloc(sizeof(QUEUE));
	if (*queue == NULL) {
		return EXIT_FAILURE;
	}
	(*queue)->size = 0;
	(*queue)->frontier_head = NULL;
	(*queue)->frontier_tail = NULL;
	return EXIT_SUCCESS;
}

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
int enQueue(QUEUE *queue, TREE_NODE *treeNode) {
	if (queue == NULL) {
		return EXIT_FAILURE;
	}
	FRONTIER_NODE *fnode = (FRONTIER_NODE *) malloc(sizeof(FRONTIER_NODE));
	if (fnode == NULL) {
		return EXIT_FAILURE;
	}
	fnode->leaf = treeNode;
	fnode->next = NULL;
	fnode->previous = NULL;
	if (queue->size == 0) {
		queue->frontier_head = fnode;
		queue->frontier_tail = fnode;
	} else {
		fnode->previous = queue->frontier_tail;
		queue->frontier_tail->next = fnode;
		queue->frontier_tail = fnode;
	}
	(queue->size)++;
	return EXIT_SUCCESS;
}

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
int deQueue(QUEUE *queue, TREE_NODE **retVal) {
	if (queue == NULL) {
		return EXIT_FAILURE;
	}
	if (queue->size == 0) {
		*retVal = NULL;
		return EXIT_FAILURE;
	}
	FRONTIER_NODE *fnode = queue->frontier_head;
	*retVal = fnode->leaf;
	if (queue->size == 1) {
		queue->frontier_head = NULL;
		queue->frontier_tail = NULL;
	} else {
		queue->frontier_head = queue->frontier_head->next;
		queue->frontier_head->previous = NULL;
	}
	(queue->size)--;
	free(fnode);
	return EXIT_SUCCESS;
}

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
int insertSorted(QUEUE *queue, TREE_NODE *treeNode) {
	if (queue == NULL) {
		return EXIT_FAILURE;
	}
	FRONTIER_NODE *fnode = (FRONTIER_NODE *) malloc(sizeof(FRONTIER_NODE));
	if (fnode == NULL) {
		return EXIT_FAILURE;
	}
	fnode->leaf = treeNode;
	fnode->next = NULL;
	fnode->previous = NULL;
	if (queue->size == 0) {
		queue->frontier_head = fnode;
		queue->frontier_tail = fnode;
	} else {
		FRONTIER_NODE *p = queue->frontier_head;
		FRONTIER_NODE *q = queue->frontier_head;
		while ((q != NULL) && (q->leaf->h <= treeNode->h)) {
			p = q;
			q = q->next;
		}
		if (p == q) {
			fnode->next = queue->frontier_head;
			queue->frontier_head = fnode;
		} else {
			p->next = fnode;
			fnode->previous = p;
			fnode->next = q;
			if (q != NULL) {
				q->previous = fnode;
				queue->frontier_tail = fnode;
			}
		}
	}
	(queue->size)++;
	return EXIT_SUCCESS;
}

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
int insertAStar(QUEUE *queue, TREE_NODE *treeNode) {
	if (queue == NULL) {
		return EXIT_FAILURE;
	}
	FRONTIER_NODE *fnode = (FRONTIER_NODE *) malloc(sizeof(FRONTIER_NODE));
	if (fnode == NULL) {
		return EXIT_FAILURE;
	}
	fnode->leaf = treeNode;
	fnode->next = NULL;
	fnode->previous = NULL;
	if (queue->size == 0) {
		queue->frontier_head = fnode;
		queue->frontier_tail = fnode;
	} else {
		FRONTIER_NODE *p = queue->frontier_head;
		FRONTIER_NODE *q = queue->frontier_head;
		while ((q != NULL)
				&& ((q->leaf->h + q->leaf->g) <= (treeNode->h + treeNode->g))) {
			if ((q->leaf->h + q->leaf->g) == (treeNode->h + treeNode->g)) {
				if (q->leaf->g <= treeNode->g) {
					break;
				} else {
					p = q;
					q = q->next;
				}
			} else {
				p = q;
				q = q->next;
			}
		}
		if (p == q) {
			fnode->next = queue->frontier_head;
			queue->frontier_head = fnode;
		} else {
			p->next = fnode;
			fnode->previous = p;
			fnode->next = q;
			if (q != NULL) {
				q->previous = fnode;
				queue->frontier_tail = fnode;
			}
		}
	}
	(queue->size)++;
	return EXIT_SUCCESS;
}
#ifdef DEBUG

int main() {
	printf("\nTest Queue:\n");
	QUEUE *queue = (QUEUE*) malloc(sizeof(QUEUE));
	initQueue(&queue);
	int ***puzzle = (int***) malloc(4 * sizeof(int**));
	int i, j, k,N = 3;
	for (i = 0; i < 5; i++) {
		puzzle[i] = (int**) malloc(sizeof(int*));
		for (j = 0; j < N; j++) {
			puzzle[i][j] = (int*) malloc(sizeof(int));
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				puzzle[i][j][k] = i;
			}
		}
		TREE_NODE *temp = (TREE_NODE*) malloc(sizeof(TREE_NODE));
		temp->puzzle = puzzle[i];
		if (i == 0) {
			temp->h = 5;
			temp->g = 0;
		} else if (i == 1) {
			temp->h = 3;
			temp->g = 2;
		} else if (i == 2) {
			temp->h = 6;
			temp->g = 1;
		} else if (i == 3) {
			temp->h = 5;
			temp->g = 2;
		} else if (i == 4) {
			temp->h = 4;
			temp->g = 2;
		}
		//insertSorted(queue, temp);
		insertAStar(queue, temp);
	}
	TREE_NODE *temp = NULL;
	for (i = 0; i < 5; i++) {
		deQueue(queue, &temp);
		if(temp != NULL) {
			for (j = 0; j < N; j++) {
				printf("\n");
				for (k = 0; k < N; k++) {
					printf("%d ", temp->puzzle[j][k]);
				}
			}
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
#endif
