#ifndef PUZZLE_H
#define PUZZLE_H
#include "Queue.h"
#include "Tree.h"

void swap(int *, int *);
int readInFile(char *, int *, TREE *);
int isSolved(int, int **);
int ***findChilds(int N, TREE_NODE *);
int **createPuzzle(int, int**);
int solver(int, int, TREE *tree, char *);
int checkIfTheSame(int, TREE_NODE *, int **);
void findDistance(int, TREE_NODE *);
#endif
