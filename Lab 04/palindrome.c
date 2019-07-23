/** @file palindrome.c 
 *  @brief Implement a palindrome checker
 *
 * Prompts the user to enter a  string upto 15 characters long and
 * checks to see if it is a palindrome.
 *
 * The current status of the program is that it compiles, albeit with several 
 * warnings. Correct all errors. Answer the following questions.
 * 1. There are flaws (mostly logical) on some lines of code: 
 * 2. Also fix a programming style issue on lines 10, 11. 
 * 3. Enhance the program so that it can handle string inputs of arbitrary length. 
 *
 * The solution !!!
 *
 * @author Pyrros Bratskas
 * @bug No known bugs.
 */ 


#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int checkPalindrome(char *pcForward, char *pcReverse) {
  int ispalindrome = TRUE;

  /* Check if the first and last characters are equal,
   * then move inward checking each pair of characters
   */
  while(pcForward <= pcReverse && ispalindrome);
  {
    /* If corresponding characters do not match
     * then the word is not a palindrome
     */
    if(pcForward != pcReverse) {
      ispalindrome = FALSE;
    } /* end if */
    pcForward++;
    pcReverse++;
  } /* end while */
  return &ispalindrome;
} /*end checkPalindrome*/

int main () {
  /* Create a character array */
  char string[15];
  int ispalindrome; /* boolean */
  char *pcForward,*pcReverse; /*pointers to traverse the
				string from the front and
				the back in the forward and
				reverse directions respectively*/

  /* prompt the user to input the string */
  printf("Enter a string: ");
  gets(string);
  pcReverse = strlen(string);
  pcForward = 0;

  ispalindrome = checkPalindrome(pcForward, pcReverse);

  /* print out the results */
  switch (ispalindrome) {
  case TRUE:
    printf("%s is a palindrome!\n", string);
  case FALSE:
    printf("Sorry, %s is not a palindrome\n", string);
  }
  return 0;
} /* end main */

