/** @file puzzle.c
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
#include "puzzle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief The main method
 *
 *	This method is the main method of the program. It combines the functions in order to solve the n-puzzle.
 *	It reads a file which is the puzzle unsolved and it can solve the puzzle with three different algorithms.
 *	The solving method depends from the argv[1] of the input command.
 *
 * 	@param argc the size of the argv array
 * 	@param **argv the user input in the command line
 * 	@return int Success or Failure
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int main(int argc, char **argv) {
// Variables
	char *solvingMethod, *inFile, *outFile;
	int N;

// Check if command is correct
	if (argc != 4) {
		printf("\n\nWrong command format!\n\n");
		exit(-1);
	}

// Read command
	solvingMethod = argv[1];
	inFile = argv[2];
	outFile = argv[3];

// Check if command is correct
	if (strcmp(solvingMethod, "breadth") && strcmp(solvingMethod, "best")
			&& strcmp(solvingMethod, "a-star")) {
		printf("\n\nWrong command format!\n\n");
		exit(-1);
	}

#ifdef DEBUG1
	printf("\n%s\n%s\n%s\n", solvingMethod, inFile, outFile);
#endif

// Read input file
	TREE *tree = NULL;
// Initialize tree
	if (initTree(&tree) == EXIT_FAILURE) {
		// Case of error while creating the tree
		printf("An error occurred while creating the tree.\n");
		return EXIT_FAILURE;
	}
	if (readInFile(inFile, &N, tree) == EXIT_FAILURE) {
		printf("\n\nProblem reading the file!\n\n");
		exit(-1);
	}
#ifdef DEBUG1
	printf("\nThe puzzle:\n");
	int i, j;
	for (i = 0; i < N; i++) {
		printf("\n");
		for (j = 0; j < N; j++) {
			printf("%d ", tree->head->puzzle[i][j]);
		}
	}
	printf("\n");
	printf("\nSize of puzzle is %dx%d\n", N, N);
	printf((isSolved(N, tree->head->puzzle) ? "\nThe puzzle is solved!\n": "\nThe puzzle is not solved!\n"));
	tree->head->puzzle[0][0] = 1;
	tree->head->puzzle[0][1] = 2;
	tree->head->puzzle[0][2] = 3;
	tree->head->puzzle[1][0] = 4;
	tree->head->puzzle[1][1] = 5;
	tree->head->puzzle[1][2] = 6;
	tree->head->puzzle[2][0] = 7;
	tree->head->puzzle[2][1] = 8;
	tree->head->puzzle[2][2] = 0;
	printf("\nThe puzzle:\n");
	for (i = 0; i < N; i++) {
		printf("\n");
		for (j = 0; j < N; j++) {
			printf("%d ", tree->head->puzzle[i][j]);
		}
	}
	printf("\n");
	printf((isSolved(N, tree->head->puzzle) ? "\nThe puzzle is solved!\n": "\nThe puzzle is not solved!\n"));
#endif

// Call the correct solving method
	int method = 0;
	if (strcmp(solvingMethod, "breadth") == 0) {
		method = 0;
	} else if (strcmp(solvingMethod, "best") == 0) {
		method = 1;
	} else if (strcmp(solvingMethod, "a-star") == 0) {
		method = 2;
	}
	solver(method, N, tree, outFile);
	return 0;
}

int readInFile(char *inFile, int *N, TREE *tree) {
	FILE *fp = fopen(inFile, "r");
// Check if file exists
	if (fp == NULL) {
		// Case of error while opening the file
		printf("An error occurred while opening the file.\n");
		return EXIT_FAILURE;
	}
	tree->head = (TREE_NODE *) malloc(sizeof(TREE_NODE));
	if (tree->head == NULL) {
		// Case of error while creating the bead of the tree
		printf("An error occurred while creating the head of the tree.\n");
		return EXIT_FAILURE;
	}
// Read file input
	int *temp = (int *) malloc(sizeof(int) * 100);
	int **puzzle = NULL;
	int i, j, k;
	if (temp == NULL) {
		return EXIT_FAILURE;
	}
	char ch;
	int num, line = 0, counter = 0, sizeSet = 0, previousWasNumber = 0;
	while (1) {
		// Reads the character where the seeker is currently
		ch = fgetc(fp);
		if (ch >= 48 && ch <= 57) {
			num = atoi(&ch);
			if (previousWasNumber == 1) {
				counter--;
				if (sizeSet == 0) {
					temp[counter] = temp[counter] * 10 + num;
				} else {
					puzzle[line][counter] = puzzle[line][counter] * 10 + num;
				}
				counter++;
			} else {
				if (sizeSet == 0) {
					temp[counter] = num;
				} else {
					puzzle[line][counter] = num;
				}
				previousWasNumber = 1;
				counter++;
			}
		} else if (ch == '\n') {
			previousWasNumber = 0;
			line++;
			if (sizeSet == 0) {
				*N = counter;
				puzzle = (int **) malloc(counter * sizeof(int*));
				if (puzzle == NULL) {
					return EXIT_FAILURE;
				}
				for (i = 0; i < counter; i++) {
					puzzle[i] = (int *) malloc(counter * sizeof(int));
					if (puzzle[i] == NULL) {
						return EXIT_FAILURE;
					}
				}
				for (i = 0; i < counter; i++) {
					puzzle[0][i] = temp[i];
				}
				sizeSet = 1;
			}
			counter = 0;
		} else {
			previousWasNumber = 0;
		}
		// If EOF is encountered then break out of the while loop
		if (ch == EOF) {
			break;
		}
	}
	if (puzzle == NULL) {
		return EXIT_FAILURE;
	}
	//Check if the puzzle is valid, all the numbers are different
	counter = *N;
	int *checkArray = (int *) malloc(counter * counter * sizeof(int));
	for (i = 0; i < (counter * counter); i++) {
		checkArray[i] = i;
	}
	for (i = 0; i < counter; i++) {
		for (j = 0; j < counter; j++) {
			for (k = 0; k < (counter * counter); k++) {
				if (checkArray[k] == puzzle[i][j]) {
					checkArray[k] = -1;
					break;
				}
			}
		}
	}
	for (i = 0; i < (counter * counter); i++) {
		if (checkArray[i] != -1) {
			printf("\nNot correct format of the puzzle");
			return EXIT_FAILURE;
		}
	}
	fclose(fp);
	free(checkArray);
	tree->head->puzzle = puzzle;
	tree->head->parent = NULL;
	tree->head->g = 0;
	tree->head->h = 0;
	tree->head->path = NULL;
	findDistance(*N, tree->head);
	tree->size = 1;
	free(temp);
#ifdef DEBUG2
	printf("\nThe puzzle:\n");
	int i, j;
	for (i = 0; i < *N; i++) {
		printf("\n");
		for (j = 0; j < *N; j++) {
			printf("%d ", puzzle[i][j]);
		}
	}
	printf("\n");
#endif
	return EXIT_SUCCESS;
}

int solver(int method, int N, TREE *tree, char * outFile) {
	int i, j;
	if (method == 0) {
		printf("\nSolving with Breadth method\n");
	} else if (method == 1) {
		printf("\nSolving with Best method\n");
	} else if (method == 2) {
		printf("\nSolving with A-Star method\n");
	}
	QUEUE *queue = NULL;
	initQueue(&queue);
	if (queue == NULL) {
		return EXIT_FAILURE;
	}
	enQueue(queue, tree->head);
	// Screen Output
	printf("\nOriginal\n");
	for (i = 0; i < N; i++) {
		printf("\n");
		for (j = 0; j < N; j++) {
			printf("%d ", tree->head->puzzle[i][j]);
		}
	}
	printf("\n");
	printf("\nSolving..\n");
	while (queue->size != 0) {
		if (isSolved(N, queue->frontier_head->leaf->puzzle) == EXIT_SUCCESS) { // Puzzle is Solved
			printf("\nPath\n\n");
			printf("%d\n", queue->frontier_head->leaf->g);
			for (i = 0; i < queue->frontier_head->leaf->g; i++) {
				switch (queue->frontier_head->leaf->path[i]) {
				case 0:
					printf("right\n");
					break;
				case 1:
					printf("down\n");
					break;
				case 2:
					printf("left\n");
					break;
				case 3:
					printf("up\n");
					break;
				}
			}
			printf("\n");
			printf("\nSolved\n");
			for (i = 0; i < N; i++) {
				printf("\n");
				for (j = 0; j < N; j++) {
					printf("%d ", queue->frontier_head->leaf->puzzle[i][j]);
				}
			}
			printf("\n");
			printf("\n");
			// Write the output to the file
			FILE *fp = fopen(outFile, "w");
			// Check if file exists
			if (fp == NULL) {
				// Case of error while opening the file
				printf("An error occurred while opening the file.\n");
				return EXIT_FAILURE;
			}
			fprintf(fp, "%d\n", queue->frontier_head->leaf->g);
			for (i = 0; i < queue->frontier_head->leaf->g; i++) {
				switch (queue->frontier_head->leaf->path[i]) {
				case 0:
					fprintf(fp, "right\n");
					break;
				case 1:
					fprintf(fp, "down\n");
					break;
				case 2:
					fprintf(fp, "left\n");
					break;
				case 3:
					fprintf(fp, "up\n");
					break;
				}
			}
			fclose(fp);
			printf("\nFree some space\n");
			freeTree(N, tree->head);
			free(tree);
			TREE_NODE *temp;
			while (queue->size != 0) {
				deQueue(queue, &temp);
			}
			free(queue);
			printf("\nAll good and free\n\n");
			return EXIT_SUCCESS;
		}
		TREE_NODE *treeNode = NULL;
		deQueue(queue, &treeNode);
		int ***puz = findChilds(N, treeNode);
#ifdef DEBUG3
		int k;
		printf("\nDequeue: \n");
		for (j = 0; j < N; j++) {
			printf("\n");
			for (k = 0; k < N; k++) {
				printf("%d ", treeNode->puzzle[j][k]);
			}
		}
		printf("\n");
		printf("\n---\n");
		printf("\n---Enqueue:--- \n");
#endif
		for (i = 0; i < 4; i++) {
			if (puz[i] == NULL) {
				treeNode->children[i] = NULL;
			} else {
				if (checkIfTheSame(N, treeNode, puz[i]) == EXIT_SUCCESS) { // Add the new puzzle
					treeNode->children[i] = (TREE_NODE*) malloc(
							sizeof(TREE_NODE));
					if (treeNode->children[i] == NULL) {
						printf("Error: Can't create new child");
						exit(-1);
					}
					treeNode->children[i]->path = (int*) malloc(
							(treeNode->g + 1) * sizeof(int));
					if (treeNode->children[i]->path == NULL) {
						printf("Error: Can't create new path");
						exit(-1);
					}
					treeNode->children[i]->g = treeNode->g + 1;
					for (j = 0; j < treeNode->g; j++) {
						treeNode->children[i]->path[j] = treeNode->path[j];
					}
					treeNode->children[i]->path[j] = i;
					treeNode->children[i]->puzzle = puz[i];
					treeNode->children[i]->parent = treeNode;
					if (method == 0) { // Breadth
						enQueue(queue, treeNode->children[i]);
					} else if (method == 1) { // Best
						findDistance(N, treeNode->children[i]);
						insertSorted(queue, treeNode->children[i]);
					} else if (method == 2) { // A Star
						findDistance(N, treeNode->children[i]);
						insertAStar(queue, treeNode->children[i]);
					}
#ifdef DEBUG4
					for (j = 0; j < N; j++) {
						printf("\n");
						for (k = 0; k < N; k++) {
							printf("%d ", puz[i][j][k]);
						}
					}
					printf("\n");
#endif
				} else {
					treeNode->children[i] = NULL;
				}
			}
		}
	}
	printf("\nUnable to find a solution!\n");
	printf("\nFree some space\n");
	freeTree(N, tree->head);
	TREE_NODE *temp;
	while (queue->size != 0) {
		deQueue(queue, &temp);
	}
	free(tree);
	free(queue);
	printf("\nAll good and free\n\n");
	return EXIT_FAILURE;
#ifdef DEBUG5
	TREE_NODE *head = tree->head;
	int m;
	for (i = 0; i < 2; i++) {
		printf("\nHead\n");
		for (k = 0; k < N; k++) {
			printf("\n");
			for (m = 0; m < N; m++) {
				printf("%d ", head->puzzle[k][m]);
			}
		}
		printf("\n");
		for (j = 0; j < 4; j++) {
			printf("\nChildren %d\n", j);
			if (head->children[j] != NULL) {
				for (k = 0; k < N; k++) {
					printf("\n");
					for (m = 0; m < N; m++) {
						printf("%d ", head->children[j]->puzzle[k][m]);
					}
				}
			}
			printf("\n");
		}
		head = head->children[0];
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < N; j++) {
			printf("\n");
			for (k = 0; k < N; k++) {
				if (puz[i] != NULL) {
					printf("%d ", puz[i][j][k]);
				}
			}
		}
		printf("\n");
	}
#endif
}

int *** findChilds(int N, TREE_NODE *treeNode) {
	int ***puz = (int ***) malloc(4 * N * N * sizeof(int**));
	int **puzzle = treeNode->puzzle;
	int i, j, iZero = 0, jZero = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (treeNode->puzzle[i][j] == 0) {
				iZero = i;
				jZero = j;
			}
		}
	}
// Create the possible puzzles
	int n = N - 1; // Just to keep it clean
	if ((iZero == 0) && (jZero == 0)) { //Left Up Corner
		puz[0] = createPuzzle(N, puzzle);
		puz[1] = createPuzzle(N, puzzle);
		swap(&puz[0][iZero][jZero], &puz[0][iZero][jZero + 1]); // Move Right
		swap(&puz[1][iZero][jZero], &puz[1][iZero + 1][jZero]); // Move Down
		puz[2] = NULL;
		puz[3] = NULL;
	} else if ((iZero == n) && (jZero == 0)) { //Left Down Corner
		puz[0] = createPuzzle(N, puzzle);
		puz[3] = createPuzzle(N, puzzle);
		swap(&puz[0][iZero][jZero], &puz[0][iZero][jZero + 1]); // Move Right
		swap(&puz[3][iZero][jZero], &puz[3][iZero - 1][jZero]); // Move Up
		puz[1] = NULL;
		puz[2] = NULL;
	} else if ((iZero == 0) && (jZero == n)) { //Right Up Corner
		puz[1] = createPuzzle(N, puzzle);
		puz[2] = createPuzzle(N, puzzle);
		swap(&puz[1][iZero][jZero], &puz[1][iZero + 1][jZero]); // Move Down
		swap(&puz[2][iZero][jZero], &puz[2][iZero][jZero - 1]); // Move Left
		puz[0] = NULL;
		puz[3] = NULL;
	} else if ((iZero == n) && (jZero == n)) { //Right Down Corner
		puz[2] = createPuzzle(N, puzzle);
		puz[3] = createPuzzle(N, puzzle);
		swap(&puz[2][iZero][jZero], &puz[2][iZero][jZero - 1]); // Move Left
		swap(&puz[3][iZero][jZero], &puz[3][iZero - 1][jZero]); // Move Up
		puz[0] = NULL;
		puz[1] = NULL;
	} else if (jZero == 0) { //Left Side
		puz[0] = createPuzzle(N, puzzle);
		puz[1] = createPuzzle(N, puzzle);
		puz[3] = createPuzzle(N, puzzle);
		swap(&puz[0][iZero][jZero], &puz[0][iZero][jZero + 1]); // Move Right
		swap(&puz[1][iZero][jZero], &puz[1][iZero + 1][jZero]); // Move Down
		swap(&puz[3][iZero][jZero], &puz[3][iZero - 1][jZero]); // Move Up
		puz[2] = NULL;
	} else if (jZero == n) { //Right Side
		puz[1] = createPuzzle(N, puzzle);
		puz[2] = createPuzzle(N, puzzle);
		puz[3] = createPuzzle(N, puzzle);
		swap(&puz[1][iZero][jZero], &puz[1][iZero + 1][jZero]); // Move Down
		swap(&puz[2][iZero][jZero], &puz[2][iZero][jZero - 1]); // Move Left
		swap(&puz[3][iZero][jZero], &puz[3][iZero - 1][jZero]); // Move Up
		puz[0] = NULL;
	} else if (iZero == 0) { //Up Side
		puz[0] = createPuzzle(N, puzzle);
		puz[1] = createPuzzle(N, puzzle);
		puz[2] = createPuzzle(N, puzzle);
		swap(&puz[0][iZero][jZero], &puz[0][iZero][jZero + 1]); // Move Right
		swap(&puz[1][iZero][jZero], &puz[1][iZero + 1][jZero]); // Move Down
		swap(&puz[2][iZero][jZero], &puz[2][iZero][jZero - 1]); // Move Left
		puz[3] = NULL;
	} else if (iZero == n) { //Down Side
		puz[0] = createPuzzle(N, puzzle);
		puz[2] = createPuzzle(N, puzzle);
		puz[3] = createPuzzle(N, puzzle);
		swap(&puz[0][iZero][jZero], &puz[0][iZero][jZero + 1]); // Move Right
		swap(&puz[2][iZero][jZero], &puz[2][iZero][jZero - 1]); // Move Left
		swap(&puz[3][iZero][jZero], &puz[3][iZero - 1][jZero]); // Move Up
		puz[1] = NULL;
	} else { //Middle
		puz[0] = createPuzzle(N, puzzle);
		puz[1] = createPuzzle(N, puzzle);
		puz[2] = createPuzzle(N, puzzle);
		puz[3] = createPuzzle(N, puzzle);
		swap(&puz[0][iZero][jZero], &puz[0][iZero][jZero + 1]); // Move Right
		swap(&puz[1][iZero][jZero], &puz[1][iZero + 1][jZero]); // Move Down
		swap(&puz[2][iZero][jZero], &puz[2][iZero][jZero - 1]); // Move Left
		swap(&puz[3][iZero][jZero], &puz[3][iZero - 1][jZero]); // Move Up
	}
	return puz;
}

int isSolved(int N, int **puzzle) {
	int i, j;
	if (puzzle[N - 1][N - 1] != 0) {
		return EXIT_FAILURE;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if ((i == N - 1) && (j = N - 1)) {
				if (puzzle[i][j] != 0) {
					return EXIT_FAILURE;
				}
			} else if (puzzle[i][j] != (i * N + j + 1)) {
				return EXIT_FAILURE;
			}
		}
	}
	return EXIT_SUCCESS;
}

void findDistance(int N, TREE_NODE *treeNode) {
	int i, j, i2, j2, sum = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (treeNode->puzzle[i][j] != 0) {
				i2 = (treeNode->puzzle[i][j] - 1) / N;
				j2 = (treeNode->puzzle[i][j] - 1) % N;
				// Calculate abs value
				i2 = (i - i2) < 0 ? (i - i2) * (-1) : (i - i2);
				j2 = (j - j2) < 0 ? (j - j2) * (-1) : (j - j2);
				sum += i2 + j2;
			}
		}
	}
	treeNode->h = sum;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int checkIfTheSame(int N, TREE_NODE *treeNode, int**puzzle) {
	if (puzzle == NULL) {
		printf("Error: Puzzle is NULL");
		exit(-1);
	}
	int ** temp;
	int i, j, same;
	while (treeNode != NULL) {
		temp = treeNode->puzzle;
		same = 1;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (puzzle[i][j] != temp[i][j]) {
					same = 0;
				}
			}
		}
		if (same == 1) {
			return EXIT_FAILURE;
		}
		treeNode = treeNode->parent;
	}
	return EXIT_SUCCESS;
}

int ** createPuzzle(int N, int**puzzle) {
	int **new = (int **) malloc(N * sizeof(int*));
	if (new == NULL) {
		printf("\nError: Can't create new puzzle\n");
		exit(-1);
	}
	int i, j;
	for (i = 0; i < N; i++) {
		new[i] = (int *) malloc(N * sizeof(int));
		if (new[i] == NULL) {
			printf("\nError: Can't create new puzzle\n");
			exit(-1);
		}
		for (j = 0; j < N; j++) {
			new[i][j] = puzzle[i][j];
		}
	}
	return new;
}
