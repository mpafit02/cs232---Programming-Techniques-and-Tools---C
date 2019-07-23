/** @file sedcmp.c
 * 	@brief Calculates SED Disstance
 *
 *	This program calculates the SED Distance between two strings.
 *	it recives the strings as input from two files. It has two
 *	implementations, one which is using recursion and it is a little
 *	bit slow, and another one that it uses an array and it is really fast.
 *	You can test the recursive version if you uncomment the function calcDistFor
 *	If you run the program you will see results from the array version. Both
 *	versions works as they should.
 *
 *	@version 1.0
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512

// Methods declaration
int calcDistRec(char *, char *, int, int);
int calcDistFor(char *, char *, int, int);
int minimum(int, int, int);

/**
 * @brief The SED algorithm
 *
 * The main method can call two functions two solve the distance problem
 * between two strings. First it reads two strings from the two files. You
 * have the choise inside the code if you want to call the function for the
 * recursion or the function for the array. Both versions work great. By default
 * the varsion of the array is active because it is faster than the recursive one.
 *
 * @param argc the number of the words in the command
 * @param **argv the array with the words in the command
 * @version 1.0
 * @author Marios Pafitis
 * @return int
 * @bug No known bugs.
 */
int main(int argc, char **argv) {
	char filename1[MAX_SIZE]; // 1st word file
	char filename2[MAX_SIZE]; // 2nd word file
	char str1[MAX_SIZE]; // 1st word
	char str2[MAX_SIZE]; // 2nd word
	int len_1 = 0, len_2 = 0; // Length of 1st and 2nd word

	// Read filenames
	strcpy(filename1, argv[argc - 2]);
	strcpy(filename2, argv[argc - 1]);

	// Read data from files
	FILE *fp1, *fp2;
	fp1 = fopen(filename1, "r");
	fp2 = fopen(filename2, "r");

	// Check if file exists
	if (fp1 == NULL) {
		// Case of error while opening the file
		printf("\nAn error occurred while opening the file.\n");
		exit(-1);
	}
	if (fp2 == NULL) {
		// Case of error while opening the file
		printf("\nAn error occurred while opening the file.\n");
		exit(-1);
	}

	// Read words
	fscanf(fp1, "%[^\n]", str1);
	fscanf(fp2, "%[^\n]", str2);

	// Close files
	fclose(fp1);
	fclose(fp2);

	// Set length of the words
	len_1 = strlen(str1);
	len_2 = strlen(str2);

	// Call the for loop algorithm
		printf("\nMinimum edits required to convert is %d\n\n", calcDistFor(str1, str2, len_1, len_2));

	// Call the recursive algorithm
//	printf("\nMinimum edits required to convert is %d\n\n",
//			calcDistRec(str1, str2, len_1, len_2));

	return 0;
}

/** @brief Implements Levenshtein Distance using for loops
 *
 *	Steps for implementing the algorithm:
 *	====================================
 *	Step 1: Set n to be the length of s.
 *			Set m to be the length of t.
 *			If n = 0, return m and exit.
 *			If m = 0, return n and exit.
 *			Construct a matrix containing 0..m rows and 0..n columns.
 *
 *	Step 2: Initialize the first row to 0..n.
 *			Initialize the first column to 0..m.
 *
 *	Step 3: Examine each character of s (i from 1 to n).
 *
 *	Step 4: Examine each character of t (j from 1 to m).
 *
 *	Step 5: If s[i] equals t[j], the cost is 0.
 *			If s[i] doesn't equal t[j], the cost is 1.
 *
 *	Step 6: Set cell d[i,j] of the matrix equal to the minimum of:
 *				a. The cell immediately above plus 1: d[i-1,j] + 1.
 *				b. The cell immediately to the left plus 1: d[i,j-1] + 1.
 *				c. The cell diagonally above and to the left plus the cost: d[i-1,j-1] + cost.
 *
 *	Step 7:	After the iteration steps (3, 4, 5, 6) are complete, the distance is found in cell d[n,m].
 *	=====================================
 *
 *	Algorithm pseudocode found in the website:
 *	https://people.cs.pitt.edu/~kirk/cs1501/Pruhs/Spring2006/assignments/editdistance/Levenshtein%20Distance.htm
 *
 *	@param str1 the first string
 *	@param str2 the second string
 *	@param len_1 the length of the first string
 *	@param len_2 the length of the second string
 *	@return The distance
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int calcDistFor(char *str1, char *str2, int len_1, int len_2) {
	// The distance
	int dist, i, j;
	// Empty words
	if (len_1 == 0) {
		return len_2;
	}
	if (len_2 == 0) {
		return len_1;
	}
	// Create an array
	int d[len_2][len_1];

	// Initialize array 1st column
	for (i = 0; i < len_2; i++) {
		d[i][0] = i;
	}

	// Initialize array 1st row
	for (i = 0; i < len_1; i++) {
		d[0][i] = i;
	}

	// Examine each character
	for (i = 1; i < len_2; i++) {
		for (j = 1; j < len_1; j++) {
			if (str2[i] == str1[j]) {
				dist = 0;
			} else {
				dist = 1;
			}
			d[i][j] = minimum(d[i - 1][j] + 1, d[i][j - 1] + 1,
					d[i - 1][j - 1] + dist);
		}
	}

//	// Presentation of the array
//	for (i = 0; i < len_2; i++) {
//		printf("\n");
//		for (j = 0; j < len_1; j++) {
//			printf("%2d ", d[i][j]);
//		}
//	}
//	printf("\n");

	// Return the minimum distance
	return d[len_2 - 1][len_1 - 1];
}

/** @brief Implements Levenshtein Distance using recursion
 *
 *	This algorithm is functional only for small strings. Because it is
 *	a recursive algorithm in each call of the function it calls 3 times
 *	again the same function. The algorithms grows exponentialy.
 *
 *	@param str1 the first string
 *	@param str2 the second string
 *	@param len_1 the length of the first string
 *	@param len_2 the length of the second string
 *	@return The distance
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int calcDistRec(char *str1, char *str2, int len_1, int len_2) {
	// The distance
	int dist;
	// Empty words
	if (len_1 == 0) {
		return len_2;
	}
	if (len_2 == 0) {
		return len_1;
	}

	// Calculate dist
	if (*(str1 + len_1 - 1) == *(str2 + len_2 - 1)) {
		dist = 0;
	} else {
		dist = 1;
	}

	// Retrun minimum
	return minimum(calcDistRec(str1, str2, len_1 - 1, len_2) + 1,
			calcDistRec(str1, str2, len_1, len_2 - 1) + 1,
			calcDistRec(str1, str2, len_1 - 1, len_2 - 1) + dist);
}
/** @brief Find the minimum of three numbers
 *
 *	A fast way to find the minimum of three numbers
 *
 *	@param d1 an integer
 *	@param d2 an integer
 *	@param d3 an integer
 *	@return The minimum of three numbers
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int minimum(int d1, int d2, int d3) {
	if ((d1 <= d2) && (d1 <= d3)) {
		return d1;
	} else if ((d2 <= d1) && (d2 <= d3)) {
		return d2;
	} else {
		return d3;
	}
}
