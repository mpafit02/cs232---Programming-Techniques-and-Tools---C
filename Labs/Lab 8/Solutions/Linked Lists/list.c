#include <stdio.h>
#include <stdlib.h>
#include "list.h"


unsigned int length(Node *head) {
  unsigned int l = 0;
  
  while (head){
    l++;
    head = head->next;
  }
  
  return l;
}

void print(Node *head) {
  while (head) {
    printf("%f\n", head->data);
    head = head->next;
  }
}

Node *next(Node *head, Node *of_node) {
  if (head && of_node)
    
    return of_node->next;
  
  else
    
    return NULL;
}

Node *previous(Node *head, Node *of_node) {
  if (head && of_node) {
    Node *pre = NULL;
    Node *cur = head;
    
    while (cur != of_node && cur) {
      pre = cur;
      cur = cur->next;
    }
    
    return pre;
  }	
  else
    
    return NULL;
}

Node *retrieve(Node *head, unsigned int position) {
  unsigned int cur_position = 0;
  
  while (head && cur_position < position) {
    head = head->next;
    cur_position++;
  }
  
  return head;
}

unsigned int locate(Node *head, unsigned int start_position, float value) {
  Node *first = retrieve(head, start_position);
  unsigned int position = start_position;
  
  while (first)	{
    if (first->data == value)
      
      return position;
    
    position++;
    first = first->next;
  }
  
  return position;
}

void insert(Node **head, Node *new_node, unsigned int position) {
  if (head && new_node)	{
    if (*head == NULL || position == 0)	{
      if (*head)
	
	new_node->next = *head;
      
      else
	
	new_node->next = NULL;
      
      *head = new_node;
    }	
    else {
      unsigned int cur_position = 0;
      Node *pre = NULL;
      Node *cur = *head;
      
      while (cur && cur_position < position) {
	cur_position++;
	pre = cur;
	cur = cur->next;
      }
      
      if (pre)
	
	pre->next = new_node;
      
      new_node->next = cur;
      
    }
    
  }
}

void delete(Node **head, unsigned int position) {
  if (head) {
    unsigned int cur_position = 0;
    Node *pre = NULL;
    Node *cur = *head;
    
    while (cur && cur_position < position) {
      cur_position++;
      pre = cur;
      cur = cur->next;
    }
    
    if (cur) {
      if (pre)
	
	pre->next = cur->next;
      
      else
	
	*head = cur->next;
      
      free(cur);
      
    }
    
  }
}


#ifdef DEBUG

int main(void) {
  float f;
  int i;
  
  Node *head = NULL;
  Node *n;
  
  for (i = 0; i < 10; i++) {
    f = -i * 0.5;
    n = (Node *) malloc(sizeof(Node));
    
    n->data = f;
    
    insert(&head, n, 0);
  }
  
  for (i = 0; i < 10; i++) {
    f = 5 + i * 0.5;
    n = (Node *) malloc(sizeof(Node));
    
    n->data = f;
    
    insert(&head, n, length(head));
  }
	
  for (i = 1; i <= 5; i++) {
    f = i;
    n = (Node *) malloc(sizeof(Node));
    
    n->data = f;
    
    insert(&head, n, 10);
  }
  
  print(head);
  
  printf("Length of list %u\n", length(head));
  
  for (i = 1; i <= 5; i++) {
    delete(&head, 10);
  }
  
  print(head);
  
  printf("Length of list %u\n", length(head));
  
  for (i = 0; i < 10; i++) {	
    delete(&head, length(head)-1);
  }
  
  print(head);
  
  printf("Length of list %u\n", length(head));
  
  for (i = 0; i < 10; i++) {	
    delete(&head, length(head)-1);
  }
  
  print(head);
  
  printf("Length of list %u\n", 0);
}

#endif
