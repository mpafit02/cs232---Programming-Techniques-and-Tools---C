/** @file puzzle.h
 *  @brief Solves n-puzzle
 *
 *  This program solves the n-puzzle game. It can solve it with three different algorithms. The breadth-first
 *  algorithm, the best algorithm and the a-star algorithm. It can handles puzzles greater than or equal to
 *  size 2. It takes as input an unsolved n-puzzle and it creates a file with the steps for the solution of the puzzle.
 *
 *  @version 1.0
 *  @author Marios Pafitis
 *  @bugs No known bugs
 */
#ifndef PUZZLE_H
#define PUZZLE_H
#include "Queue.h"
#include "Tree.h"

/** @brief Swap two pointers
 *
 *	This function swaps two pointers
 *
 * 	@param *a the first pointer
 * 	@param *b the second pointer
 * 	@return void
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
void swap(int *, int *);

/** @brief Read input file
 *
 *	This function read the input file which is the layout of the puzzle at the beginning
 *
 * 	@param *inFile the filename
 * 	@param N the size of the puzzle
 * 	@param *tree the tree with the puzzles
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int readInFile(char *, int *, TREE *);

/** @brief Check if the puzzle is solved
 *
 *	This function returns 1 if the puzzle is solved otherwise it returns 0
 *
 * 	@param N the size of the puzzle
 * 	@param **puzzle the puzzle
 * 	@return 1 if puzzle is solved and 0 if the puzzle is not solved
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int isSolved(int, int **);

/** @brief Creates the possible children puzzles of a tree node
 *
 *	This function creates all the possible nodes of the tree node. The children are either two, three or four.
 *	It depends if the zero is in a corner in a side or in the middle. In case of less tha four children the,
 *	child is going to be null. The order is for i = 0 the Right Move, i = 1 the Down Move, i = 2 the Left Move,
 *	i = 3 the Up Move.
 *
 * 	@param N the size of the puzzle
 * 	@param *treeNode the parent node of the puzzle in this tree
 * 	@return int *** a four dimensional array with the four new puzzles
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int ***findChilds(int N, TREE_NODE *);

/** @brief Create and copy a puzzle
 *
 *	This function creates a puzzle and copies the parent
 *
 * 	@param **puzzle the parent puzzle we are going to copy
 * 	@param N the size of the puzzle
 * 	@return int ** the new puzzle we have created
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int **createPuzzle(int, int**);

/** @brief Solves the puzzle
 *
 *	This function solves a puzzle with size greater than 2. It can solve the puzzle wither with breadth algorithm,
 *	or with the best algorithm or with the a-star algorithm. YOu can select the method from this choices:
 *	method = 0 -> breadth solving method
 *	method = 1 -> best solving method
 *	method = 2 -> a-star solving method
 *
 *	The breadth method is the slowest but it finds the shortest solving path.
 *	The best method is vary fast but it doesn't find the shortest path always.
 *	The a-star method it the fastest and it finds always the shortest path, but the steps might be different from
 *	the breadth solving method.
 *
 * 	@param method the solving method
 * 	@param N the size of the puzzle
 * 	@param *tree the tree with the puzzles
 * 	@param *outFile the path of the output file
 * 	@return int returns EXIT_SUCCESS if it could found a solution or EXIT_FAILURE if it couldn't find a solution
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int solver(int, int, TREE *tree, char *);

/** @brief Checks if we are the same with one of our parents
 *
 *	This function checks if a puzzle is the same with one of its parents
 *
 * 	@param **puzzle the parent puzzle we are going to copy
 * 	@param N the size of the puzzle
 * 	@param *treeNode the parent node of the puzzle in this tree
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int checkIfTheSame(int, TREE_NODE *, int **);

/** @brief Find Heuristic Distance
 *
 *	This function finds the heuristic distance of a puzzle. Is using the manchatan
 *	algorithm to calculate the sum of the distances from the correct position of every
 *	element.
 *
 * 	@param N the size of the puzzle
 * 	@param *treeNode the node we want to find the distance
 * 	@return void
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
void findDistance(int, TREE_NODE *);
#endif
