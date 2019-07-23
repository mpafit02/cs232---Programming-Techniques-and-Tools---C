/** @file pagerank.c
 * 	@brief Implements Page Ranking
 *
 *	This algorithm implements Page Ranking. It can handles 20 web hosts
 *	It reads two files, one for the hostnames and one for the hostgraph.
 *	It reads each file and implements the Page rank algorithm.
 *
 *	Note: In order to compile you have to add the argument "-lm" for the Math library
 *
 *	@version 1.0
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 512 // String MAX_SIZE
#define N 20 // Total number of web hosts
#define D 0.85 // Paragon Aposvesis
#define SIZE 2 // The starting size for malloc

//Methods Declaration
int OCalc(int, int, int **);
int OiCalc(int, int, int **);
void ICalc(int size, int I[size][size], int Is[size], int h, int n,
		int **hostgraph);
void PrCalc(int size, double d, int n, int I[size][size], int Is[size],
		int O[size], int Oi[size][size], double Pr[size]);
int efklidiaDistance(int n, int size, double PrOld[size], double Pr[size]);
double normPagerank(int size, int hi, int n, double Pr[size]);

/** @brief The Page Ranking Algorithm
 *
 *	This function combines the methods in order to implement the page ranking
 *	algorithm. It takes as input two files, the hostnames and the hostgraph.
 *
 * 	@param argc the number of the words in the command
 * 	@param **argv the array with the words in the command
 * 	@return int
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int main(int argc, char **argv) {
	char filename1[MAX_SIZE]; // The hostnames file
	char filename2[MAX_SIZE]; // The hostgraph file
	char str[MAX_SIZE]; // General use character array
	char **hostnames = (char **) malloc(SIZE * sizeof(char*)); // The hostnames
	int **hostgraph; // The hostgraph
	int destinations[N][N]; // The destinations for each src
	int hostCounter = 0, srcCounter = 0, destCounter = 0, i, j, n;
	int O[N], Oi[N][N], I[N][N], Is[N];
	int size = SIZE;
	double Pr[N], normPr[N];

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

	// Read data from file1 (hostname)
	char name[MAX_SIZE];
	int id;
	while (fscanf(fp1, "%d %s", &id, name) != EOF) {
		if (hostCounter >= size) {
			size *= 2;
			char **array2DTemp = (char **) realloc(hostnames,
					size * sizeof(char *));
			if (array2DTemp == NULL) {
				printf("Error expanding array!");
				exit(-1);
			}
			hostnames = array2DTemp;
		}
		hostnames[hostCounter] = (char *) malloc(
				strlen(name) * sizeof(char) + 2);
		strcpy(hostnames[hostCounter], name);
		hostCounter++;
	}

	//Create malloc for hostgraph, the I, O, Oi table and Pr
	hostgraph = (int **) malloc(hostCounter * sizeof(int *));
	for (i = 0; i < hostCounter; i++) {
		hostgraph[i] = (int *) malloc(hostCounter * sizeof(int));
		memset(hostgraph[i], 0, hostCounter * sizeof(int));
	}

	// If the size is bigger than N it stops the program
	if (hostCounter >= N) {
		printf("\nThe maximum size I can handle is %d.\n", N);
		exit(-1);
	}

	// Read data from file2 (hostgraph)
	int src = 0;
	while (fscanf(fp2, "%s", str) != EOF) {
		// Check if the string is null
		if (str != NULL) {
			// Check if the string is '->'
			if ((str[0] == '-') && (str[1] == '>')) {
				// Ignore
			} else {
				// Check if the string has the character ':'
				int i, isDestLink = 0, splitPos = 0;
				for (i = 0; i < strlen(str); i++) {
					if (str[i] == ':') {
						isDestLink = 1;
						splitPos = i;
					}
				}
				if (isDestLink) {
					// Convert string to int
					int dest = 0, nlinks = 0;
					for (i = 0; i < splitPos; i++) {
						// Convert string to int (dest)
						int num = 1;
						for (j = 0; j < i; j++) {
							num *= 10;
						}
						dest *= num;
						dest += (str[i] - '0');
					}
					for (i = splitPos + 1; i < strlen(str); i++) {
						// Convert string to int (nlinks)
						int num = 1;
						for (j = splitPos + 1; j < i; j++) {
							num *= 10;
						}
						nlinks *= num;
						nlinks += (str[i] - '0');
					}
					destinations[src][dest] = dest;
					hostgraph[src][dest] = nlinks;
				} else {
					// Convert string to int (src)
					src = 0;
					for (i = 0; i < strlen(str); i++) {
						int num = 1;
						for (j = 0; j < i; j++) {
							num *= 10;
						}
						src *= num;
						src += (str[i] - '0');
					}
					destinations[src][0] = 0;
				}
			}
		}
	}

	// Close files
	fclose(fp1);
	fclose(fp2);

	// Calculate PageRank
	n = hostCounter; //	Total number of hostnames

	//Print Oij
	printf("\n+++ Start of printing structure Oij +++");
	printf("\nThe structure of each line is: ");
	printf("\nsrc -> dest1:nlinks1 dest2:nlinks2 ... destk:nlinksk\n");
	for (i = 0; i < n; i++) {
		printf("\n%d -> ", i);
		for (j = 0; j < n; j++) {
			if (hostgraph[i][j] != 0) {
				printf("%d:%d ", destinations[i][j], hostgraph[i][j]);
			}
		}
	}
	printf("\n\n--- End of printing structure Oij ---");

	// Calculate O(hj), Oi(hj), I(hi)
	for (i = 0; i < n; i++) {
		O[i] = OCalc(i, n, hostgraph);
		ICalc(N, I, Is, i, n, hostgraph);
		for (j = 0; j < n; j++) {
			Oi[i][j] = OiCalc(i, j, hostgraph);
		}
	}

	// Print Oi
	printf("\n\n+++ Start of printing structure Oj +++");
	printf("\nThe structure of each line is: ");
	printf("\nsrc ==> links_total\n");
	for (i = 0; i < n; i++) {
		printf("\n%d ==> %d ", i, O[i]);
	}
	printf("\n\n--- End of printing structure Oj ---");

	// Print I
	printf("\n\n+++ Start of printing structure Iij +++");
	printf("\nThe structure of each line is: ");
	printf("\ndest <== hosts_total hostid1 hostid2 ... hostidk\n");
	for (i = 0; i < n; i++) {
		printf("\n%d <== %d ", i, Is[i]);
		for (j = 0; j < Is[i]; j++) {
			printf("%d ", I[i][j]);
		}
	}
	printf("\n\n--- End of printing structure Iij ---");

//	// Print to see the Iterations
//	printf("\n\nIteration: 0");
//	for (i = 0; i < n; i++) {
//		Pr[i] = 1.0;
//		printf("\nh%d %.3f", i, Pr[i]);
//	}

	// Initialize Page Rank to 1
	for (i = 0; i < n; i++) {
		Pr[i] = 1.0;
	}

	// Calculate Pr
	PrCalc(N, D, n, I, Is, O, Oi, Pr);

	// Calculate Norm Page Rank
	for (i = 0; i < n; i++) {
		normPr[i] = normPagerank(N, i, n, Pr);
	}
	// Print Pr
	printf("\n\n+++ Start of printing PR +++");
	printf("\n\nhost_id\t\thost_name\thost_rank\tnorm_host_rank");
	for (i = 0; i < n; i++) {
		printf("\n%d\t\t%s\t\t%.3f\t\t%.2f", i, hostnames[i], Pr[i], normPr[i]);
	}
	printf("\n\n--- End of printing structure PR ---\n\n");

	// Free malloc
	for (i = 0; i < hostCounter; i++) {
		free(hostnames[i]);
		free(hostgraph[i]);
	}
	free(hostnames);
	free(hostgraph);
	return 0;
}

/** @brief Total number of hyperlinks to the host
 *
 *	This function calculates the total number of hyperlinks for a host.
 *	It uses the hostgraph that we read at the beggining of the proces.
 *
 * 	@param h the host
 * 	@param n the total number of the hosts
 * 	@param hostgraph the array with the hostgraphs
 * 	@return sum the sum of the hyperlinks
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int OCalc(int h, int n, int **hostgraph) {
	int i, sum = 0;
	for (i = 0; i < n; i++) {
		sum += hostgraph[h][i];
	}
	return sum;
}

/** @brief Number of hyperlinks from the host j to the host i
 *
 *	This return the number of hyperlinks from the host j to
 *	the host i. It uses the array hostgraph.
 *
 * 	@param hi the host i
 * 	@param hj the host j
 * 	@param hostgraph the array with the hostgraphs
 * 	@return int the number of hyperlinks
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int OiCalc(int hi, int hj, int **hostgraph) {
	return hostgraph[hj][hi];
}

/** @brief Number of hosts with hyperlinks the host i
 *
 *	This calculates the number of hosts with hyperlinks to a specific host.
 *
 *	@param size The maximum size I can handle
 * 	@param I the array to save the numbers of hosts
 * 	@param Is the array to save the counter for each I
 * 	@param h the host i
 * 	@param n the total number of the hosts
 * 	@param hostgraph the array with the hostgraphs
 * 	@return void
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
void ICalc(int size, int I[size][size], int Is[size], int h, int n,
		int **hostgraph) {
	int i;
	Is[h] = 0;
	for (i = 0; i < n; i++) {
		if (hostgraph[i][h] != 0) {
			I[h][Is[h]] = i;
			Is[h]++;
		}
	}
}

/** @brief Page Rank calculate
 *
 *	This calculates the Page Rank for every host.
 *
 *	@param size The maximum size I can handle
 * 	@param d Paragon Aposvesis
 * 	@param n the total number of the hosts
 * 	@param O the array with the number of hyperlinks from the host j to the host i
 * 	@param Oi the array with the number of hosts with hyperlinks to the host i
 * 	@param I the array to save the numbers of hosts
 * 	@param Is the array to save the counter for each I
 * 	@param Pr the array with the Page Rankings
 * 	@return void
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
void PrCalc(int size, double d, int n, int I[size][size], int Is[size],
		int O[size], int Oi[size][size], double Pr[size]) {
	int i, j, finished = 0;
	int counter = 0;
	double PrOld[n];
	while (!finished) {
		for (i = 0; i < n; i++) {
			PrOld[i] = Pr[i];
		}
		for (i = 0; i < n; i++) {
			double sum = 0.0;
			for (j = 0; j < Is[i]; j++) {
				int hj = I[i][j];
				sum += (PrOld[hj] * Oi[i][hj]) / O[hj];
			}
			Pr[i] = ((1 - d) / n) + d * sum;
		}
		counter++;
		finished = 1;
		if (efklidiaDistance(n, size, PrOld, Pr) == 0) {
			finished = 0;
//			// Print to see the Iterations
//			printf("\n\nIteration: %d", counter);
//			for (i = 0; i < n; i++) {
//				printf("\nh%d %.3f", i, Pr[i]);
//			}
		} else {
			for (i = 0; i < n; i++) {
				Pr[i] = PrOld[i];
			}
			counter--;
		}
	}
}

/** @brief Efklidia Distance
 *
 *	This calculates the Efklidia Distance of two arrays with recursion
 *
 * 	@param n the total number of the hosts
 *	@param size The maximum size I can handle
 * 	@param PrOld the array with the Page Rankings in the previous state
 * 	@param Pr the array with the Page Rankings
 * 	@return int (0/1) if it is finished
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
int efklidiaDistance(int n, int size, double PrOld[size], double Pr[size]) {
	int i, j;
	double result, sum = 0;
	for (i = 0; i < n; i++) {
		sum += pow((PrOld[i] - Pr[i]), 2);
	}
	result = sqrt(sum);
	if (result < 0.01) {
		return 1;
	}
	return 0;
}

/** @brief Normal Page Rank
 *
 *	This calculates the  Normal Page Rank
 *
 *	@param size The maximum size I can handle
 * 	@param hi the host i
 * 	@param n the total number of the hosts
 * 	@param Pr the array with the Page Rankings
 * 	@return double the normal page rank
 *	@author Marios Pafitis
 * 	@bug No known bugs.
 */
double normPagerank(int size, int hi, int n, double Pr[size]) {
	int i;
	double sum = 0;
	for (i = 0; i < n; i++) {
		sum += *(Pr + i);
	}
	return *(Pr + hi) / sum;
}
