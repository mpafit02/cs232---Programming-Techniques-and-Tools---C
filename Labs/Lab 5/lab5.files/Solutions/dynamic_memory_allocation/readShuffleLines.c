/** @file readShuffleLines.c
 *  @brief The solution of exercise 2 of EPL132 Lab13
 *
 * The program reads from the user lines from standard input until end-of-file, 
 * shuffles them randomly, and print them in stdout.
 *
 *  @author Teaching Assistant
 *  @bug 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum {INITIAL_ARRAY_LENGTH = 2};
enum {MAX_LINE_LENGTH = 100};

int main(void) {
  char **lines;
  char line[MAX_LINE_LENGTH];
  int lineCount;
  int arrayLength;
  int randomIndex;

  arrayLength = INITIAL_ARRAY_LENGTH;
  lines = (char**)malloc(arrayLength * sizeof(char*));
  lineCount = 0;

  while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
    if (lineCount == arrayLength) {
      arrayLength *= 2;
      lines = (char**)realloc(lines, arrayLength * sizeof(char*));
    }
    
    lines[lineCount] = (char*)malloc(strlen(line) + 1);
    strcpy(lines[lineCount], line);
    lineCount++;
  }

  srand(time(NULL));

  while (lineCount > 0) {
    randomIndex = rand() % lineCount;
    printf("%s", lines[randomIndex]);
    free(lines[randomIndex]);
    lines[randomIndex] = lines[lineCount-1];
    lineCount--;
  }

  free(lines);

  return 0;
}
