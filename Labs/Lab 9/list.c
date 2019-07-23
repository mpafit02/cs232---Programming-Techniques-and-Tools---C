#include <stdio.h>
#include <stdlib.h>
#include "list.h"


Node *insert_end(Node *head, int val) {
  Node *pre = NULL, *cur;
  Node *newNode = (Node*)malloc(sizeof(Node));
  
  if (!newNode) 
    return head;
  
  newNode->data = val;

  cur = head;
  while (cur) {
    pre = cur;
    cur = cur->next;
  }
  
  if (pre)
    pre->next = newNode;
  
  newNode->next = cur;
  
  if (!pre)
    head = newNode;
  
  return head;
}



Node *insert_sorted(Node *head, int val) {
  Node *pre = NULL, *cur;
  Node *n = (Node*)malloc(sizeof(Node));

  if (!n) 
    return head;

  n->data = val;
  
  cur = head;
  while (cur) {
    if (cur->data > n->data)
      break;
    
    pre = cur;
    cur = cur->next;
  }
  
  if (pre)
    pre->next = n;
  
  n->next = cur;
  
  if (!pre)
    head = n;
  
  return head;
}

void print_same(Node *head1, Node *head2) {
  while (head1) {
    if(head1->data == head2->data)
      printf("%d ", head1->data);
    head1 = head1->next;
    head2 = head2->next;
  }
  
  printf("\n");
}

void print_recursive(Node *head) {
  if (head) {
    printf("%d ", head->data);
    print_recursive(head->next);
  }
}


int compareLinkedList(Node *node1, Node *node2) {
  if (!node1 && !node2)
    return 1;
  if (!node1 || !node2)
    return 0;
  else
    if (node1->data != node2->data)
      return 0;
    else
      return compareLinkedList(node1->next, node2->next);
}

#ifdef DEBUG

int main(void) {
  
  int num = 0;
  Node *head1=NULL, *head2=NULL;
  
  while (num != -1) {
    printf("Please give a positive integer (-1 to terminate): ");
    scanf("%d", &num);
    if (num == -1) break;
    
    head1 = insert_end(head1, num);
    head2 = insert_sorted(head2, num);
  }	
  
  print_recursive(head1);
  printf("\n");
  print_recursive(head2);
  printf("\n");
  print_same(head1, head2);

  if (compareLinkedList(head1, head2))
    printf("\nThe lists are the same\n");
  else
    printf("\nThe lists are not the same\n");
  
  return 0;
}

#endif
