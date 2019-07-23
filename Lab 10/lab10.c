#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char sex;
	char name[10];
}__attribute__((packed)) PERSON;

int main() {

	PERSON *p1 = (PERSON *) malloc(sizeof(PERSON));
	strcpy(p1->name, "Helen");
	p1->sex = 'F';
	p1->id = 12345678;

	printf("\nWrite started!");
	FILE *fp = fopen("user.db", "wb");
	fwrite(p1, sizeof(PERSON), 1, fp);
	fclose(fp);
	printf("\nWrite finished!");
	printf("\nRead started!");
	fp = fopen("user.db", "rb");
	PERSON *p2 = (PERSON *) malloc(sizeof(PERSON));
	fread(p2, sizeof(PERSON), 1, fp);
	printf("\nRead finished!");
	printf("\np2 id: %d", p2->id);
	printf("\np2 name: %s", p2->name);
	printf("\np2 sex: %c", p2->sex);
	return 0;
}
