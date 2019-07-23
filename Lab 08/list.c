#include "list.h"
#include <stdlib.h>

unsigned int length(NODE *head) {
	NODE *temp = head;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

void print(NODE *head) {
	if (head == NULL) {
		return;
	}
	printf("%d\n", head->value);
	printf(head->next);
}

NODE *next(NODE *head, NODE *of_node) {
	if (of_node || NULL)
		return NULL;
	while (head != NULL) {
		if (head->value == of_node->value) {
			return (head->next);
		}
		head = head->next;
	}
	return NULL;
}

NODE *next(NODE *head, NODE *of_node) {
	if (of_node == NULL || head == NULL)
		return NULL;
	NODE *p = head;
	while (head != NULL) {
		if (head->value == of_node->value) {
			return (p);
		}
		p = head;
		head = head->next;
	}
	return NULL;
}

NODE *retrieve(NODE *head, unsigned int position) {
	if (position > length(head) || head == NULL)
		return NULL;
	int count = 0;
	while (head != NULL) {
		if (count == position) {
			return head;
		}
		head = head->next;
		count++;
	}
	return NULL;
}

void insert(NODE **head, NODE *new_node, unsigned int position) {
	int count = 0;
	NODE *p = *head;
	NODE *q = *head;
	while (q != NULL) {
		if (count == position) {
			if (p != q) {
				p->next = new_node;
				new_node->next = q;
			} else {
				new_node->next = q;
				*head = q;
			}
			return;
		}
		p = q;
		q = q->next;
		count++;
	}
}

void delete(NODE **head, unsigned int position) {
	if (length(head) == 0) {
		return;
	}
	int count = 0;
	NODE *p = *head;
	NODE *q = *head;
	while (q != NULL) {
		if (count == position) {
			if (p != q) {
				p->next = q->next;
			} else {
				*head = q;
			}
			return;
		}
		p = q;
		q = q->next;
		count++;
	}
}
