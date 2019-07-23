/** @file fun_struct_sol.c
 *  @brief Exercise on structs
 *
 *  Working with structs in C
 *
 *  @author Teaching Assistant
 *  @bug 
 */

/* ensomatosi vivliothikwn */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Dilosi statherwn */
#define NUM_STUDENTS 5
#define NUM_EXAMS 3

/* Orismos toy synthetoy typou students. SIMPLIRWSTE ANALOGWS */
typedef struct {
	int grade;
} grade;

typedef struct {
	int id;
	char name[20];
	char surname[20];
	grade ergasies;
	grade endiamesi;
	grade final;
	double mesos;

} students;
/* Epikefalides synartisewn. SIMPLIRWSTE ANALOGWS */
void read_students(students *studentsArr, int *numstud);
void evaluate_final(students *studentsArr, int numstud);
void print_students(students *studentsArr, int numstud);
/* Orismoi synartisewn. SIMPLIRWSTE ANALOGWS */

int main() {
	/* Dilosi metavlitwn */
	int numstud = 0, i;
	char str[20];
	/* Dilosi metavlitwn typoy students. SIMPLIRWSTE ANALOGWS */
	students *studentsArr = (students *) malloc(2 * sizeof(students));
	/* Klisi synartisewn. SIMPLIRWSTE ANALOGWS */
	read_students(studentsArr, &numstud);
	evaluate_final(studentsArr, numstud);
	print_students(studentsArr, numstud);
	return (0);
}

void read_students(students *studentsArr, int *numstud) {
	int size = 0, i, temp;
	printf("Dwse to plithos twn foititwn (metaxy 1 kai 5) : ");
	scanf("%d", &size);
	if (size < 1 || size > 5) {
		printf("\nWrong size input.\n");
		exit(-1);
	}
	*numstud = size;
	studentsArr = (students *) realloc(studentsArr, size * sizeof(students));
	for (i = 0; i < size; i++) {
		printf("id: ");
		scanf("%d", &studentsArr[i].id);
		printf("name: ");
		scanf("%s", &studentsArr[i].name);
		printf("surname: ");
		scanf("%s", &studentsArr[i].surname);
		printf("Ergasies: ");
		scanf("%d", &temp);
		if (temp > 0 && temp <= 10) {
			studentsArr[i].ergasies.grade = temp;
		} else {
			printf("Error");
			exit(-1);
		}
		printf("Endiamesi: ");
		scanf("%d", &temp);
		if (temp > 0 && temp <= 10) {
			studentsArr[i].endiamesi.grade = temp;
		} else {
			printf("Error");
			exit(-1);
		}
		printf("Final: ");
		scanf("%d", &temp);
		if (temp > 0 && temp <= 10) {
			studentsArr[i].final.grade = temp;
		} else {
			printf("Error");
			exit(-1);
		}
	}
}

void evaluate_final(students *studentsArr, int numstud) {
	int i;
	for (i = 0; i < numstud; i++) {
		studentsArr[i].mesos = 1.0
				* (studentsArr[i].ergasies.grade
						+ studentsArr[i].endiamesi.grade
						+ studentsArr[i].final.grade) / NUM_EXAMS;
		printf("mesos: %.2f\n", studentsArr[i].mesos);
	}
}

void print_students(students *studentsArr, int numstud) {
	printf("\n\n");
	int i;
	for (i = 0; i < numstud; i++) {

	}
	printf("\n\n");
}
