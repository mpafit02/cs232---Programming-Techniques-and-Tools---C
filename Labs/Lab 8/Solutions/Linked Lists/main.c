#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
