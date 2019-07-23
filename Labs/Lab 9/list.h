#ifndef __LIST_H__
#define __LIST_H__


typedef struct node_struct {
  int data;
  struct node_struct *next;
}Node;
 

/** 
 * @brief Inserts a new node in the end of the list
 * @param *head pointer to the first node of the list
 * @param val the integer to be inserted
 * @return returns the head of the list
*/
Node *insert_end(Node *head, int val);


/** 
 * @brief Inserts a new node in a sorted list
 * @param *head pointer to the first node of the list
 * @param val the integer to be inserted
 * @return returns the head of the list
*/
Node *insert_sorted(Node *head, int val);


/** 
 * @brief Prints the same elements of two lists
 * @param *head1 pointer to the first node of the first list
 * @param *head2 pointer to the first node of the second list
 * @return void
*/
void print_same(Node *head1, Node *head2);


/** 
 * @brief Prints recursiveley the elements of the list
 * @param *head pointer to the first node of the first list
 * @return void
*/
void print_recursive(Node *head);


/** 
 * @brief Compares recursiveley the elements of two lists
 * @param *head1 pointer to the first node of the first list
 * @param *head2 pointer to the first node of the second list
 * @return true if lists are the same, false otherwise
*/
int compareLinkedList(Node *head1, Node *head2);

#endif
