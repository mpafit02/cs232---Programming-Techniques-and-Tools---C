#ifndef __LIST_H__
#define __LIST_H__

typedef struct node_struct {
  float data;
  struct node_struct *next;
}Node;



/** 
 * @brief The length of a linked list
 * @param *head pointer to the first node of the list
 * @return Returns the length of the list
*/
unsigned int length(Node *head);


/** 
 * @brief Prints the elements of a linked list
 * @param *head pointer to the first node of the list
 * @return void
*/
void print(Node *head);


/** 
 * @brief Returns a pointer to the next node of another node passed as parameter
 * @param *head pointer to the first node of the list
 * @param *of_node pointer to the node
 * @return returns a pointer to the node next to of_node
*/
Node *next(Node *head, Node *of_node);


/** 
 * @brief Returns a pointer to the previous node of another node passed as parameter
 * @param *head pointer to the first node of the list
 * @param *of_node pointer to the node
 * @return returns a pointer to the node previous to of_node
*/
Node *previous(Node *head, Node *of_node);


/** 
 * @brief Returns a pointer to the node at a given position in the list
 * @param *head pointer to the first node of the list
 * @param position the position in the list
 * @return returns a pointer to the node found at a given position, NULL if not found
*/
Node *retrieve(Node *head, unsigned int position);


/** 
 * @brief Returns the position of an element in the list
 * @param *head pointer to the first node of the list
 * @param start_position the position from which the locate begins
 * @param value the value to be found
 * @return returns the position of value in the list
*/
unsigned int locate(Node *head, unsigned int start_position, float value);


/** 
 * @brief Inserts a new node in the list, in a given position
 * @param **head pointer to pointer to the first node of the list
 * @param *new_node the new node to be inserted
 * @param position the position to be inserted
 * @return void
*/
void insert(Node **head, Node *new_node, unsigned int position);


/** 
 * @brief Deletes a node from the list in a given position
 * @param **head pointer to pointer to the first node of the list
 * @param position the position of node to delete
 * @return void
*/
void delete(Node **head, unsigned int position);



#endif
