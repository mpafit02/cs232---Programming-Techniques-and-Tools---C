/**
 * @brief Kenken puzzle game with an auto solver
 *
 * As a player you can import a Kenken puzzle of a specific size. You can choose either
 * to solve it by yourself or to let the computer to solve it for you. The program, performs
 * validations based on the Kenken puzzles rules for each value of the player. It checks if
 * the value is unique in the specific row and column. Also, it checks if the value is valid for
 * the specific cage. If the player choose to let the computer solve the puzzle then the puzzle
 * is solved by a technique we call "Backtracking Recursion".
 *
 * @version 1.0
 * @author Marios Pafitis
 * @bug No known bugs.
 *
 */

// Imported libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum size I can handle
#define N 9

// Methods declaration
void printPuzzle(int size, int len, int kenken[len][len], char cages[len][len]);
void writePuzzle(char filename[100], int size, int len, int kenken[len][len],
		char cages[len][len]);
int readPuzzle(char filename[100], int len, int kenken[len][len],
		char cages[len][len], int restrictions[100]);
int isSolved(int size, int len, int kenken[len][len]);
void play(char filename[100], int size, int len, int kenken[len][len],
		char cages[len][len], int restrictions[100]);
int checkInput(int i, int j, int val, int size, int len, int kenken[len][len],
		char cages[len][len], int restrictions[100]);
int solver(int i, int j, int last_i, int last_j, int size, int len,
		int kenken[len][len], char cages[len][len], int restrictions[100]);

/**
 * @brief Combines all the methods
 *
 * First it calls the method to read the content of the puzzle passing as argument the
 * filename. Then if the user choose to solve it by himself it calls the method play().
 * If the user choose to let the computer solve it then it calls the recursive function
 * solver() in order to solve the puzzle by a technique that we call "Backtracking Recursion"
 *
 * @param argc the number of the words in the command
 * @param **argv the array with the words in the command
 * @version 1.0
 * @author Marios Pafitis
 * @return int
 * @bug No known bugs.
 *
 *
 */
int main(int argc, char **argv) {
	// Initialize variables
	int kenken[N][N] = { 0 };
	int restrictions[100] = { 0 };
	char cages[N][N] = { ' ' };
	char filename[100] = { ' ' };
	// In case of a wrong command format
	if (argc != 3) {
		printf("\nError: Wrong command format!\n");
		exit(-1);
	}
	// Copy the name of the file in the character array filename
	strcpy(filename, argv[argc - 1]);
	// Read the puzzle from the file and set the size of the kenken puzzle
	const int size = readPuzzle(filename, N, kenken, cages, restrictions);
	// Check if the user wants to solve the puzzle or to let the computer solve it
	if (strcmp(argv[1], "-i") == 0) {
		printPuzzle(size, N, kenken, cages);
		play(filename, size, N, kenken, cages, restrictions);
	} else if (strcmp(argv[1], "-s") == 0) {
		if (solver(0, 0, 0, 0, size, N, kenken, cages, restrictions)) {
			printf("\n\n***Game solved***");
			printPuzzle(size, N, kenken, cages);
		} else {
			printf("\nError: No solution for this puzzle!\n");
			exit(-1);
		}
	} else {
		printf(
				"\nImportant: Choose '-i' to play mode, '-s' to see the solution.\n");
		exit(-1);
	}
	return 0;
}
/**
 * @brief Print the Puzzle
 *
 * Print the Kenken puzzle on screen with the cages character and the value of the specific cell
 *
 * @param size the size of the Kenken puzzle
 * @param len the maximum length I can handle
 * @param kenken a two dimensional array of the puzzle's values
 * @param cages a two dimensional array that specifies the cage character of each cell
 * @author Marios Pafitis
 * @return Void.
 * @bug No known bugs.
 *
 *
 */
void printPuzzle(int size, int len, int kenken[len][len], char cages[len][len]) {
	printf("\n");
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (k = 0; k < size; k++) {
			printf("+------");
		}
		printf("+\n|");
		for (j = 0; j < size; j++) {
			printf("  %d%c  |", kenken[i][j], cages[i][j]);
		}
		printf("\n");
		if (i == size - 1) {
			for (k = 0; k < size; k++) {
				printf("+------");
			}
			printf("+\n");
		}
	}
}

/**
 * @brief Read the Puzzle
 *
 * Read the Kenken puzzle from a file. More specific it reads the cages and the restriction for each cage.
 * First tries to open the file. In case of not success it ends the program. It reads the size of the Kenken
 * puzzle which is the first number of the file. It read the restrictions of the cages and adds them in a
 * table called restrictions. Then it reads the the row and the column of each cell that is part of a cage and
 * add them in a two dimensional array called cages.
 *
 * @param filename and array of characters which represents the filename that we are going to read our Kenken puzzle
 * @param len the maximum length I can handle
 * @param kenken a two dimensional array of the puzzle's values
 * @param cages a two dimensional array that specifies the cage character of each cell
 * @param restrictions an array of the restrictions for each cage
 * @return size the size of our Kenken puzzle
 * @author Marios Pafitis
 * @bug No known bugs.
 *
 *
 */
int readPuzzle(char filename[100], int len, int kenken[len][len],
		char cages[len][len], int restrictions[100]) {
	char str[100];
	int size = -1, count = 0, character = 96, lim_count = 0;
	FILE *fp;
	fp = fopen(filename, "r");
// Check if file exists
	if (fp == NULL) {
		// Case of error while opening the file
		printf("An error occurred while opening the file.\n");
		exit(-1);
	}
// Read the size
	fscanf(fp, "%s", str);
	size = (int) (str[0] - '0');
// Check if the size is bellow 10
	if (size > len || size <= 1) {
		printf(
				"\nError: The maximum size that I can handle is %d and the minimum 2.\n",
				len);
		exit(-1);
	}
	printf("\n");
	// Read Data from the input file
	while (fscanf(fp, "%s", str) != EOF) {
		if (str[0] != '(') {
			int i, j;
			for (i = 0; i < strlen(str) - 1; i++) {
				int num = 1;
				for (j = 0; j < i; j++) {
					num *= 10;
				}
				restrictions[count] *= num;
				restrictions[count] += (str[i] - '0');
			}
			++count;
			restrictions[count] = str[strlen(str) - 1];
			++count;
			++character;
			if (character > 122) { // character > 'z'
				printf(
						"\nError: The maximum size of cells that I can handle is 26!.\n",
						len);
				exit(-1);
			}
			printf("%c=%d%c ", character, restrictions[count - 2],
					(char) restrictions[count - 1]);
		} else {
			int x = str[1] - '0' - 1;
			int y = str[3] - '0' - 1;
			cages[x][y] = (char) character;
		}
	}

	fclose(fp);
	return size;
}

/**
 * @brief Check if the Puzzle is Solved
 *
 * Check if all the cells are not zero
 *
 * @param size the size of the Kenken puzzle
 * @param len the maximum length I can handle
 * @param kenken a two dimensional array of the puzzle's values
 * @return 1 if is solved
 * @author Marios Pafitis
 * @bug No known bugs.
 *
 *
 */
int isSolved(int size, int len, int kenken[len][len]) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (kenken[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

/**
 * @brief Writes the Kenken puzzle in a file
 *
 * It creates an output filename based on the input filename. For example if the input filename
 * was kk4x4.txt the output will be out-kk4x4.txt
 *
 * @param filename and array of characters which represents the filename that we are going to read our Kenken puzzle
 * @param size the size of the Kenken puzzle
 * @param len the maximum length I can handle
 * @param kenken a two dimensional array of the puzzle's values
 * @param cages a two dimensional array that specifies the cage character of each cell
 * @author Marios Pafitis
 * @return Void.
 * @bug No known bugs.
 *
 *
 */
void writePuzzle(char filename[100], int size, int len, int kenken[len][len],
		char cages[len][len]) {
// Create the output file name
	char outFilename[100];
	strcpy(outFilename, "out-");
	strcat(outFilename, filename);
	FILE *fp = fopen(outFilename, "w");
// Save the kenken puzzle in the new output file
	if (fp) {
		int i, j, k;
		for (i = 0; i < size; i++) {
			for (k = 0; k < size; k++) {
				fprintf(fp, "+------");
			}
			fprintf(fp, "+\n|");
			for (j = 0; j < size; j++) {
				fprintf(fp, "  %d%c  |", kenken[i][j], cages[i][j]);
			}
			fprintf(fp, "\n");
			if (i == size - 1) {
				for (k = 0; k < size; k++) {
					fprintf(fp, "+------");
				}
				fprintf(fp, "+\n");
			}
		}
		fclose(fp);
		printf("\nYour game has been saved successfully!\n");
	} else { // Case of error while opening the file
		printf("\nAn error occurred while creating the file.\n");
	}
}

/**
 * @brief Check if the input is valid
 *
 * It checks if the input in the specific cell is valid. Valid means that it is unique in the specific row and column.
 * Also if it completes the cage, the sum or the mul must pe equal with the restriction.
 *
 * @param i position in column
 * @param j position in row
 * @param val the value for the specific cell
 * @param size the size of the Kenken puzzle
 * @param len the maximum length I can handle
 * @param kenken a two dimensional array of the puzzle's values
 * @param cages a two dimensional array that specifies the cage character of each cell
 * @param restrictions an array of the restrictions for each cage
 * @return 1/0 the inputs is valid or not
 * @author Marios Pafitis
 * @bug No known bugs.
 *
 *
 */
int checkInput(int i, int j, int val, int size, int len, int kenken[len][len],
		char cages[len][len], int restrictions[100]) {
// i and j are from 1 to 4
	i = i - 1;
	j = j - 1;
// Check if the number exists in that column
	int k;
	for (k = 0; k < size; k++) {
		if (kenken[k][j] == val) {
			return 0;
		}
	}
// Check if the number exists in that row
	for (k = 0; k < size; k++) {
		if (kenken[i][k] == val) {
			return 0;
		}
	}
	char c = cages[i][j]; // The character of the cage
	int pos = c - 97;	// The position in the restriction array
	int total = restrictions[pos * 2];	// The value in the restrictions array
	int result, areAllFilled = 1;// result of the cage, if all the cells in the same cage are filled
	char symbol = (char) restrictions[pos * 2 + 1]; // The symbol of the cage
// Check if the number is not correct for the specific cage
// Case 1: all cells in the cage are filled but they are not equal with the result
// Case 2: the current cells in the cage are over the wanted amount
	if (symbol == '+') {
		result = 0;
	} else {
		result = 1;
	}
	int m;
	for (k = 0; k < size; k++) {
		for (m = 0; m < size; m++) {
			if (cages[k][m] == c) {
				if (((i == k) && (j == m))) {
					if (symbol == '+') {
						result += val;
					} else {
						result *= val;
					}
				} else {
					if (kenken[k][m] == 0) {
						areAllFilled = 0;
					}
					if (symbol == '+') {
						result += kenken[k][m];
					} else {
						result *= kenken[k][m];
					}
				}
			}
		}
	}
	// If the cage is full but the restriction is not correct or if the sum/mul of the cage is more than the restriction
	if ((areAllFilled && (result != total))
			|| (!areAllFilled && (result > total))) {
		return 0;
	}
	return 1;
}

/**
 * @brief Read the player's value for a cell
 *
 * This method reads the value for a cell from the player. The format of the command must be
 * i,j=val. The program check if the format is correct. If the val is equal with zero, then we
 * remove the value of the specific cell. If the format of the command is 0,0=0 then the puzzle
 * is saved in the file and the game ends. This method ends when the puzzle is solved.
 *
 * @param filename and array of characters which represents the filename that we are going to read our Kenken puzzle
 * @param size the size of the Kenken puzzle
 * @param len the maximum length I can handle
 * @param kenken a two dimensional array of the puzzle's values
 * @param cages a two dimensional array that specifies the cage character of each cell
 * @param restrictions an array of the restrictions for each cage
 * @return Void.
 * @author Marios Pafitis
 * @bug No known bugs.
 *
 *
 */
void play(char filename[100], int size, int len, int kenken[len][len],
		char cages[len][len], int restrictions[100]) {
	int solved = 0;
// Call isSolved() method to check if puzzled is solved
	while (!solved) {
		printf("\n\nEnter your command in the following format:\n");
		printf(">i,j=val: for entering val at position (i,j)\n");
		printf(">i,j=0 : for clearing cell (i,j)\n");
		printf(">0,0=0 : for saving and ending the game\n");
		printf("Notice: i,j,val numbering is from [1..%d]\n", size);
		printf(">");
		int i, j, val;
		if (scanf("%d,%d=%d", &i, &j, &val) != 3) {
			while (getchar() != '\n') {
			};
			printf("\nWrong format of command\n");
		} else {
// Check method for validation
			if ((i == 0) && (j == 0) && (val == 0)) {
				writePuzzle(filename, size, len, kenken, cages);
				exit(-1);
				// End program and save puzzle
			} else {
				// Check if the input is correct
				if ((i >= 1 && i <= size) && (j >= 1 && j <= size)
						&& (val >= 0 && val <= size)) {
					if (val == 0) {
						kenken[i - 1][j - 1] = 0;
						printf("\nValue cleared!\n");
					} else {
						// check if the input is valid for the specific position
						if (checkInput(i, j, val, size, len, kenken, cages,
								restrictions)) {
							if (kenken[i - 1][j - 1] == 0) {
								kenken[i - 1][j - 1] = val;
								printf("\nValue inserted!\n\n");
								solved = isSolved(size, len, kenken);
								if (solved) {
									printf("***Game solved***");
								} else {
									printf(
											"***This is not a valid Kenken puzzle***");
								}
							} else {
								printf("\nError: Cell is occupied!\n");
							}
						} else {
							printf("\nError: Illegal value insertion!\n");
						}
					}
				} else {
					printf("\nError: Out of puzzles's size!\n");
				}
			}
		}
		printPuzzle(size, len, kenken, cages);
	}
}
/**
 * @brief Auto solves the puzzle
 *
 * The solver is a method that uses "Backtrack Recursion" algorithm in order to solve the
 * Kenken puzzle more efficiently. The code was inspired from the website:
 * "http://nifty.stanford.edu/2018/reed-nifty-remixes/Boggle/KenKen.html". In general the
 * algorithm adds the values in the cells one by one. In case that the value is valid we
 * continue in the next cell. If a value has a conflict we increase the value and try again.
 * If each value of that cell is not correct that means we have an issue in a previous step.
 * So we return back (backtracking) to a previous cell and try the next value. This is a very
 * fast solution as it takes lass than a millisecond in order to solve a 4x4 Kenken puzzle.
 *
 * @param i position in column
 * @param j position in row
 * @param last_i previous position in column
 * @param last_j previous position in row
 * @param size the size of the Kenken puzzle
 * @param len the maximum length I can handle
 * @param kenken a two dimensional array of the puzzle's values
 * @param cages a two dimensional array that specifies the cage character of each cell
 * @param restrictions an array of the restrictions for each cage
 * @return 1 if the puzzle is solved succesfuly
 * @author Marios Pafitis
 * @bug No known bugs.
 *
 *
 */
int solver(int i, int j, int last_i, int last_j, int size, int len,
		int kenken[len][len], char cages[len][len], int restrictions[100]) {
	// Check if the puzzle does not have zeros
	if (isSolved(size, len, kenken)) {
		return 1;
	}
	int returnValue = 0;
	int val = 1;
	while ((returnValue == 0) && (val <= size)) {
		// Check if the value is correct for the current position
		if (checkInput(i + 1, j + 1, val, size, N, kenken, cages, restrictions)
				== 1) {
			kenken[i][j] = val;
			last_j = j; // Store j
			last_i = i;	// Store i
			// Move to the next cell
			j++;
			if (j >= size) {
				j = 0;
				i++;
			}
			// Call again the recursion
			returnValue = solver(i, j, last_i, last_j, size, N, kenken, cages,
					restrictions);
			// If the value is not correct change the value of the previous cell
			if (returnValue == 0) {
				kenken[i][j] = 0;
				i = last_i;
				j = last_j;
			} else {
				return 1;
			}
		}
		val++;
	}
	return returnValue;
}
