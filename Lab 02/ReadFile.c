#include <stdio.h> /* Standard Input and Output*/

void readNumbers();
void largestNumber();
void printAll();
int x[20];
int max = 0;

int main() {
	readNumbers();
	largestNumber();
	printAll();
	return 0;
}

void readNumbers() {
	FILE *fp;
	int a;
	fp = fopen("data.txt", "r");
	for (int i = 0; i < 20; i++) {
		fscanf(fp, "%d", &a);
		x[i] = a;
	}
	fclose(fp);
}

void largestNumber() {
	for (int i = 0; i < 20; i++) {
		if (x[i] > max) {
			max = x[i];
		}
	}
}

void printAll(){
	FILE *fp;
	fp = fopen("output.txt", "w");
	for (int i = 0; i < 20; i++) {
		fprintf(fp, "%d\n", x[i]);
	}
	fprintf(fp, "Maximum: %d", max);
	fclose(fp);
}
