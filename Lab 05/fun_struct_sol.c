/** @file fun_struct_sol.c
 *  @brief The solution of 2nd exercise of EPL232 Lab5
 *
 *  Working with structs in C
 *
 *  @author Teaching Assistant
 *  @bug 
 */


/* ensomatosi vivliothikwn */
#include <stdio.h>

/* Dilosi statherwn */
#define NUM_STUDENTS 5
#define NUM_EXAMS 3

/* Orismos toy synthetoy typou students. SIMPLIRWSTE ANALOGWS */
typedef struct {
	int id;
	char name[20];
	char surname[20];
	float vathmoi[NUM_EXAMS];
	float mesos;
} student;

/* Epikefalides synartisewn. SIMPLIRWSTE ANALOGWS */

/** @brief Read students data from the user
 *
 *
 *
 * @param *s a pointer to the struct representing the table of students
 * @param *num a pointer to the number of students to be read
 * @return void
 */
void read_students(student *s, int *num);


/** @brief Calculates the averages of students grades
 *
 * num parameter must be less than or equal to NUM_STUDENTS
 *
 * @param *s a pointer to the struct representing the table of students
 * @param num  the number of students
 * @return void
 */
void evaluate_final(student *s, int num);


/** @brief Prints students infor;ation
 *
 * num parameter must be less than or equal to NUM_STUDENTS
 *
 * @param *s a pointer to the struct representing the table of students
 * @param num the number of students
 * @return void
 */
void print_students(student *s, int num);


/* Orismoi synartisewn. SIMPLIRWSTE ANALOGWS */
void read_students(student *s, int *num) {
	int i, j;

        printf("Dwse to plithos twn foititwn (metaxy 1 kai %d) : ", NUM_STUDENTS);
        scanf("%d", num);

        if((*num<1) || (*num>NUM_STUDENTS))
                exit(0);

        for(i=0; i<*num; i++) {
		printf("Foititis %d\n", i+1);
                printf("Arithmos tavtotitas: ");
                scanf("%d", &((s+i)->id)); 
		// ENALLAKTIKA H PANW ENTOLI MPOREI NA GINEI ETSI:
		//scanf("%d", &(s[i].id));
                
		printf("Onoma: ");
                scanf("%s", (s+i)->name);
		// ENALLAKTIKA H PANW ENTOLI MPOREI NA GINEI ETSI:
		//scanf("%s", s[i].name);
                
		printf("Epitheto: ");
                scanf("%s", (s+i)->surname);
                for(j=0; j<NUM_EXAMS; j++) {
                        printf("%dos vathmos foititi: ",j+1);
                        scanf("%f", &((s+i)->vathmoi[j]));
			while((s+i)->vathmoi[j]<0 || (s+i)->vathmoi[j]>10) {
				printf("Edwses lathos vathmo. Xanadwse %do vathmo foititi: ",j+1);
				scanf("%f", &((s+i)->vathmoi[j]));
			}
                }
        }

}

void evaluate_final(student *s, int num) {
	int i,j;
	for(i=0; i<num; i++) {
		s[i].mesos=0;
		//(s+i)->mesos=0;
               	for(j=0; j<NUM_EXAMS; j++)
			s[i].mesos += s[i].vathmoi[j];
			//(s+i)->mesos += (s+i)->vathmoi[j];
		s[i].mesos /= NUM_EXAMS;
		//(s+i)->mesos /= NUM_EXAMS;
	}
}

void print_students(student *s, int num) {
	int i,j; 

	for(i=0; i<num; i++) {
                printf("------------------------------------\n");
		printf("Arithmos tavtotitas %dou foititi: %d\n", i+1, s[i].id);
                printf("Onoma foititi: %s\n", s[i].name);
                printf("Epitheto foititi: %s\n", s[i].surname);
                printf("Vathmoi foititi: ");
                for(j=0; j<NUM_EXAMS; j++) {
                        printf("%.2f ", s[i].vathmoi[j]);
                }
		printf("\nMesos oros mathimatwn foititi: %.2f\n", s[i].mesos);
        }
        printf("------------------------------------\n");

}


int main() {
	/* Dilosi metavlitwn */
	int numstud;

	/* Dilosi metavlitwn typoy students. SIMPLIRWSTE ANALOGWS */
	student students[NUM_STUDENTS];

	/* Klisi synartisewn. SIMPLIRWSTE ANALOGWS */
	read_students(students, &numstud);
	evaluate_final(students, numstud);
	print_students(students, numstud);

	return(0);
}
