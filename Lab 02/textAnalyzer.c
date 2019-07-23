#include <stdio.h>
#include <string.h>
#define FILE_SIZE 2048

int main() {
	char ofilename[21];
	char content[FILE_SIZE];
	char words[FILE_SIZE][20];
	FILE *fp;
	char filename[20];
	int whiteSpaces = 0, letters = 0;

	printf("Please enter the name of the input file: ");
	scanf("%s", filename);
	fp = fopen(filename, "r");

	if (fp) {
		char c;
		int whitespace = 0;
		int letters = 0;
		int digitCounter = 0;
		int numbers = 0;
		int other = 0;
		while (c != EOF) {
			c = fgetc(fp);
			if (c == ' ') {
				++whitespace;
				digitCounter = 0;
			} else if (c == '\n') {
				digitCounter = 0;
				++other;
			} else {
				if (c >= 48 && c <= 57) {
					++numbers;
				} else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
					++letters;
				} else {
					++other;
				}
				words[whitespace][digitCounter] = c;
				digitCounter++;
			}
		}
		for (int i = 0; i < whitespace; i++) {
			for (int j = i + 1; j < whitespace - 1; j++) {
				int e = strcmp(words[i], words[j]);
				if (e > 0) {
					char temp[20];
					strcpy(temp, words[j]);
					strcpy(words[j], words[i]);
					strcpy(words[i], temp);
				}
			}
		}

		printf("Please enter the name of the output file: ");
		scanf("%s", ofilename);
		fp = fopen(ofilename, "w");
		fprintf(fp, "Statistics for file: %s\n", filename);
		fprintf(fp, "-------------------------------------------------\n\n");
		int total = whitespace + letters + other + numbers;
		fprintf(fp, "Total # of characters in file: %d\n", total);
		fprintf(fp, "Letters %d %f %\n", letters,
				(letters * 100) / ((float) total));
		fprintf(fp, "White space %d %f %\n", whitespace,
				(whitespace * 100) / ((float) total));
		fprintf(fp, "Digits %d %f %\n", numbers, (numbers * 100) / ((float) total));
		fprintf(fp, "Other characters %d %f %\n", other, (other * 100) / ((float) total));
		fprintf(fp, "Total # of words in file: %d\n", whitespace);
		fprintf(fp, "The words of file.txt in alphabetical order:\n");
		for (int i = 0; i < whitespace; i++) {
			fprintf(fp, "%s\n", words[i]);
		}
		printf("Processing complete.");
	} else {
		printf("An error occurred while opening the file.\n");
	}
	fclose(fp);

	return 0;
}

