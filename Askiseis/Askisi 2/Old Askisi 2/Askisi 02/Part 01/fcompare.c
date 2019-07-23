/** @file fcompare.c
 * 	@brief Implements File Comparison
 *
 *	This program implements string line per line comparison between two files.
 *	Also it gives you options how you want to present the output in the command line
 *	It uses the libraries stdio.h , stdlib.h , string. h. The maximum line it can
 *	handles in comparison and line length is 100.
 *
 *	@version 1.0
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum size I can handle
#define STR_SIZE 512
#define MAX_SIZE 100
#define SIZE 2

// Methods declaration
char *lowerCase(char *str);

/**
 * @brief The algorithm of string comparing
 *
 * The main method reads the two filenames. It opens the files and read them.
 * it saves line by line in two, 2 dimensional character arrays, one for each
 * file. Then it compares row per row of the one array to the other. If one line
 * is not the same with the other it prints it in the display. You have the option
 * to choose the presentation of your program. You have the options "/nc", "/s" and
 * "/ln" to give as an argument when you run the program in command line. The option
 * "/nc" ignores the capitalization between comparosons of lines. The option "/s"
 * printd more compact the output. For example if you have lines from 2 to 5 not the
 * same, this option will not print all the lines. It will print 2 is not tha same
 * Down to the line 5. If you select the option "/ln" the output is numbering each line.
 * Finaly, if the two files they don't have the same amount of lines it printf the
 * diference of them at the end of the execution.
 *
 * @param argc the number of the words in the command
 * @param **argv the array with the words in the command
 * @version 1.0
 * @author Marios Pafitis
 * @return int
 * @bug No known bugs.
 */
int main(int argc, char **argv) {
	int i, showLines = 0, printCompact = 0, ignoreCapitals = 0,
			lineCounter1 = 0, lineCounter2 = 0, notSameCounter = 0,
			isContinuously = 0, lines = 0, diferenceInLines = 0,
			largestFile = 0, characterCounter = 0;
	char c;
	char filename1[STR_SIZE] = { ' ' };
	char filename2[STR_SIZE] = { ' ' };
	char sentences1[MAX_SIZE][STR_SIZE];
	char sentences2[MAX_SIZE][STR_SIZE];
	int sameSentences[STR_SIZE] = { 0 };
	char str1[STR_SIZE], str2[STR_SIZE];
	FILE *fp1, *fp2;

	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "/nc") == 0) {
			ignoreCapitals = 1;
		} else if (strcmp(argv[i], "/s") == 0) {
			printCompact = 1;
		} else if (strcmp(argv[i], "/ln") == 0) {
			showLines = 1;
		}
	}

	strcpy(filename1, argv[argc - 2]);
	strcpy(filename2, argv[argc - 1]);

	// Read Files
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
	// Read sentences from file1
	while (fgets(str1, STR_SIZE, fp1) != NULL) {
		str1[strlen(str1) - 1] = '\0'; // Remove new line character
		if (lineCounter1 >= MAX_SIZE) {
			printf("\nThe maximum size I can handle is %d\n", MAX_SIZE);
			exit(-1);
		}
		strcpy(sentences1[lineCounter1], str1);
		lineCounter1++;
	}
	// Close file 1
	fclose(fp1);

	// Read sentences from file2
	while (fgets(str2, STR_SIZE, fp2) != NULL) {
		str2[strlen(str2) - 1] = '\0'; // Remove new line character
		if (lineCounter2 >= MAX_SIZE) {
			printf("\nThe maximum size I can handle is %d\n", MAX_SIZE);
			exit(-1);
		}
		strcpy(sentences2[lineCounter2], str2);
		lineCounter2++;
	}
	// Close file 2
	fclose(fp2);

	// Check which file has more lines
	if (lineCounter1 > lineCounter2) {
		diferenceInLines = lineCounter1 - lineCounter2;
		largestFile = 1;
		lines = lineCounter2;
	} else if (lineCounter1 < lineCounter2) {
		diferenceInLines = lineCounter2 - lineCounter1;
		largestFile = 2;
		lines = lineCounter1;
	} else {
		lines = lineCounter1;
	}

	// Check which lines are the same
	for (i = 0; i < lines; i++) {
		sameSentences[i] = 1;
		if (ignoreCapitals) { // In case we don't care about the capitalization
			if (strcmp(lowerCase(sentences1[i]), lowerCase(sentences2[i]))) { // Not the same
				sameSentences[i] = 0;
			}
		} else { // In case we care about the capitalization
			if (strcmp(sentences1[i], sentences2[i])) { // Not the same
				sameSentences[i] = 0;
			}
		}
	}
	printf("\n");
	for (i = 0; i < lines; i++) {
		if (!sameSentences[i]) {
			if (printCompact) { // In case we selected to print more compact
				int j = i;
				int count = 0;
				while ((j < lines) && (!sameSentences[j])) {
					count++;
					j++;
				}
				if (count <= 1) {
					for (j = i; j < i + count; j++) {
						if (showLines) { // In case we want to print the line number
							printf("%d: ", (j + 1));
							printf("%s\n", sentences1[j]);
							printf("%d: ", (j + 1));
							printf("%s\n", sentences2[j]);
						} else { // In case we don't want to print the line number
							printf("%s\n", sentences1[j]);
							printf("%s\n", sentences2[j]);
						}
					}
				} else {
					if (showLines) { // In case we want to print the line number
						printf("%d: ", (i + 1));
						printf("%s\n", sentences1[i]);
						printf("%d: ", (i + 1));
						printf("%s\n", sentences2[i]);
						printf("Down to\n");
						printf("%d: ", (i + count));
						printf("%s\n", sentences1[i + count - 1]);
						printf("%d: ", (i + count));
						printf("%s\n", sentences2[i + count - 1]);
					} else { // In case we don't want to print the line number
						printf("%s\n", sentences1[i]);
						printf("%s\n", sentences2[i]);
						printf("Down to\n");
						printf("%s\n", sentences1[i + count - 1]);
						printf("%s\n", sentences2[i + count - 1]);
					}
				}
				i += count;
			} else {
				if (showLines) { // In case we want to print the line number
					printf("%d: ", (i + 1));
					printf("%s\n", sentences1[i]);
					printf("%d: ", (i + 1));
					printf("%s\n", sentences2[i]);
				} else { // In case we don't want to print the line number
					printf("%s\n", sentences1[i]);
					printf("%s\n", sentences2[i]);
				}
			}
		}
	}

	// Prints the diference of the line number.
	if (diferenceInLines) {
		if (largestFile == 2) {
			printf("\n* The second file has %d more line(s) than the first.\n",
					diferenceInLines);
		} else {
			printf("\n* The first file has %d more line(s) than the second.\n",
					diferenceInLines);
		}
	}

	return 0;
}

/**
 * @brief Converts a string to lower case
 *
 * Converts a string to lower case whatever is the content
 *
 * @param *str the array of the characters (string)
 * @return char * the string in lower case
 * @author Marios Pafitis
 * @bug No known bugs.
 */
char *lowerCase(char *str) {
	char *newStr = str;
	char *p = newStr;
	int i = 0;
	while (*str) { // For every character in the string
		if ((*str >= 'A') && (*str <= 'Z')) {
			*newStr = *str + ('a' - 'A');
		} else {
			*newStr = *str;
		}
		i++;
		str++;
		newStr++;
	}
	return p;
}
