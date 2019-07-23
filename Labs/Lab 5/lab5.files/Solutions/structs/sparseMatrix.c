/** @file sparseMatrix.c
 * @brief This program models a sparse matrix
 *
 * This program models a sparse matrix using a vector
 * the same data structure.
 *
 * @author Pavlos Antoniou
 * @bug No known bug
 */

#include <stdio.h>

#define MAX_TERMS 101 /* maximum number of terms +1*/
#define FALSE 0
#define TRUE 1


typedef struct {
  int col;
  int row;
  int value;
} term;


/* Function prototypes */
int readMatrix(term []);
void printMatrix(term [], int);
int search(term [],int, int);


/** @brief read values into the sparse matrix
 *
 * A matrix element is represented by its row, its column and its value. It is 
 * saved in an 1D array of structs term.
 *
 * @param mat The array where matrix elelements are read
 * @return The number of elements
 */
int readMatrix(term mat[]) {
  int size = 0;
  int col,row,value;

  printf("Col,Row,Value(-1,-1,-1 to quit):");
  scanf("%d,%d,%d", &mat[size].col, &mat[size].row,&mat[size].value);
  
  while (mat[size].col!= -1) {
    size++;
    printf("Col,Row,Value: (-1,-1,-1 to quit):");
    scanf("%d,%d,%d", &mat[size].col, &mat[size].row, &mat[size].value);
  }
  return size;
}


/** @brief Print out the sparse matrix
 *
 * A matrix element is represented by its row, its column and its value. 
 *
 * @param mat The array with matrix elelements
 * @param size The size of matrix
 * @return void
 */
void printMatrix(term mat[], int size) {
  int i;
  for (i =0; i< size; i++)
    printf("[%d, %d, %d]\n",mat[i].col,mat[i].row, mat[i].value);
}


/** @brief search for the key in the sparse matrix
 *
 * Search an element using the value as a key. It finds the first element 
 * with such a value
 *
 * @param mat The array with matrix elelements
 * @param size The size of matrix
 * @param key The value to search
 * @return True if found, false otherwise
 */
int search(term mat[], int size, int key) {
  int i;
  for (i = 0; i < size;i++)
    if (key == mat[i].value) return TRUE;
  return FALSE;
}


int main () {
  
  term a[MAX_TERMS];
  int size;
  int key;
  
  size = readMatrix(a);
  
  printMatrix(a,size);
  
  printf("Search for: ");
  scanf("%d", &key);
  
  if (search(a,size,key))
    printf("%d is in the sparse matrix.", key);
  else
    printf("%d was not found.", key);
  
  return 0;
}




   
