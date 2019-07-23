#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	char odd_even; // ‘o’ or ‘e’ as values
	struct node *next;
} NODE;

typedef struct {
	NODE *head;
	NODE *tail;
	int size;
} LIST;

int main() {
	printf("\nBinary Write");
	LIST *list = (LIST *) malloc(sizeof(LIST));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	int i;
	for (i = 0; i < 5; i++) {
		if (list->size == 0) {
			list->head = (NODE *) malloc(sizeof(NODE));
			list->head->value = i;
			list->head->odd_even = 'e';
			list->head->next = NULL;
			list->tail = list->head;
		} else {
			NODE *n = (NODE *) malloc(sizeof(NODE));
			n->value = i;
			if (i % 2 == 0) {
				n->odd_even = 'e';
			} else {
				n->odd_even = 'o';
			}
			n->next = NULL;
			list->tail->next = n;
			list->tail = n;
		}
		list->size++;
	}
	NODE *temp = list->head;
	int count = 0;
	while (temp != NULL) {
		printf("\n%d: %d", count, temp->value);
		printf("\n%d: %c", count, temp->odd_even);
		printf("\n");
		temp = temp->next;
		count++;
	}

	FILE *fp = fopen("ask7.db", "wb");
	fwrite(list, sizeof(LIST), 1, fp);
	fclose(fp);

	printf("\nBinary Read");
	LIST *list2 = (LIST *) malloc(sizeof(LIST));
	fp = fopen("ask7.db", "rb");
	fread(list2, sizeof(LIST), 1, fp);
	fclose(fp);

	NODE *temp2 = list2->head;
	count = 0;
	while (temp2 != NULL) {
		printf("\n%d: %d", count, temp2->value);
		printf("\n%d: %c", count, temp2->odd_even);
		printf("\n");
		temp2 = temp2->next;
		count++;
	}
	return 0;
}
