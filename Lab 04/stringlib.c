/** @file stringlib.c
 *  @brief Implemets different operation on strings
 *
 * This program implements different operation on strings
 *
 * @author 
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>

// Macro for converting an uppercase character to lowercase.
#define lcase(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + ('a' - 'A') : (x))

/** @brief Returns the length of string cs, including the '\0' character
 *
 * @param cs The string
 * @return The string length 
 */
int strlength(const char *cs);

/** @brief Copies string ct to string s and returns s.
 *
 * @param cs The string to copy
 * @param ct The string to be copied
 * @return Returns the new string
 */
char *strcopy(char *s, const char *ct);

/** @brief Concatenates string ct to the end of string s. Returns s.
 *
 * @param cs The first string 
 * @param ct The string to concatenate to the first string
 * @return Returns the new string
 */
char *strconcat(char *s, const char *ct);

/** @brief Case INSENSITIVE comparison of two strings
 *
 * @param cs The first string 
 * @param ct The second string
 * @return Returns -1 if cs < ct, 0 if cs == ct and 1 if cs > ct.
 */
int strcompare(const char *cs, const char *ct);

/** @brief Substring finding
 *
 * @param cs The first string 
 * @param ct The second string
 * @return A pointer to the first occurrence of string ct in string cs, or NULL if not found.
 */
char *stringstring(const char *cs, const char *ct);

/** @brief String parsing
 *
 * @param cs The  string 
 * @return  Returns the numeric value of string cs.
 */
double val(const char *cs);

/*
 * Define the functions below
 */

int main(void) {

	char *s1 = "String";
	char *s2 = "ring";

	char *s3 = (char *) malloc(11 * sizeof(char));
	char *s4;
	int l, c;

	s3 = strcopy(s3, s1);
	printf("strcopy(s3, \"%s\") = \"%s\"\n", s1, s3);

	c = strcompare(s3, s1);
	printf("strcompare(\"%s\", \"%s\") = %d\n", s3, s1, c);

	s3 = strconcat(s3, s2);
	printf("strconcat(s3, \"%s\") = \"%s\"\n", s2, s3);

	l = strlength(s3);
	printf("strlength(\"%s\") = %d\n", s3, l);

	c = strcompare(s1, s2);
	printf("strcompare(\"%s\", \"%s\") = %d\n", s1, s2, c);

	c = strcompare(s2, s1);
	printf("strcompare(\"%s\", \"%s\") = %d\n", s2, s1, c);

	s4 = stringstring(s1, s2);
	printf("stringstring(\"%s\", \"%s\") = ", s1, s2);

	if (s4)
		printf("\"");

	printf("%s", s4 ? s4 : "NULL");

	if (s4)
		printf("\"");

	printf("\n");

	s4 = stringstring(s3, s1);
	printf("stringstring(\"%s\", \"%s\") = ", s3, s1);

	if (s4)
		printf("\"");

	printf("%s", s4 ? s4 : "NULL");

	if (s4)
		printf("\"");

	printf("\n");

	s4 = stringstring(s1, s3);
	printf("stringstring(\"%s\", \"%s\") = ", s1, s3);

	if (s4)
		printf("\"");

	printf("%s", s4 ? s4 : "NULL");

	if (s4)
		printf("\"");

	printf("\n");

	printf("val(\"%s\") = %lf\n", "+11111.000005", val("+11111.000005"));
	printf("val(\"%s\") = %lf\n", "-11111.000005", val("-11111.000005"));
	printf("val(\"%s\") = %lf\n", "11111.000005", val("11111.000005"));
	printf("val(\"%s\") = %lf\n", "12345", val("12345"));

	return 0;
}

int strlength(const char *cs) {
	int len = 0;
	for (len = 0; *cs != '\0'; cs++) {
		len++;
	}
	return len;
}

char *strcopy(char *s, const char *ct) {
	char *p = s;
	while (*ct != '\0') {
		*s = *ct;
		s++;
		ct++;
	}
	*s = '\0';
	return p;
}

char *strconcat(char *s, const char *ct) {
	char *p = s;
	while (*s != '\0') {
		s++;
	}
	while (*ct != '\0') {
		*s = *ct;
		s++;
		ct++;
	}
	*s = '\0';
	return p;
}

int strcompare(const char *cs, const char *ct) {
	if ((cs == NULL) && (ct == NULL)) {
		return 1;
	}
	if (((cs == NULL) && (ct != NULL)) || ((cs != NULL) && (ct == NULL))) {
		return 0;
	}
	int same = 1;
	while (*cs != '\0') {
		if ( lcase(*cs) != lcase(*ct)) {
			same = 0;
		}
		cs++;
		ct++;
	}
	return same;
}

char *stringstring(const char *cs, const char *ct) {
	if (strlength(ct) > strlength(cs)) {
		return NULL;
	}
	while (*cs != '\0') {
		if (*cs == *ct) {
			char *pcs = cs;
			char *pct = ct;
			int same = 1;
			while (*ct != '\0') {
				if (*cs != *ct) {
					same = 0;
				}
				ct++;
				cs++;
			}
			if (same) {
				return pcs;
			} else {
				cs = pcs;
				ct = pct;
			}
		}
		cs++;
	}
	return NULL;
}

double val(const char *cs) {
	double num = 0;
	double division = 1.0;
	int isNegative = 0;
	int isDecimal = 0;
	if (*cs == '+') {
		// ignore
		cs++;
	} else if (*cs == '-') {
		isNegative = 1;
		cs++;
	}
	while (*cs != '\0') {
		if (isDecimal) {
			division *= 10.0;
		}
		if (*cs == '.') {
			isDecimal = 1;
		} else {
			num *= 10;
			num += (*cs - '0');
		}
		cs++;
	}
	if(isDecimal){
		num = num / division;
	}
	if (isNegative) {
		num *= -1;
	}
	return num;
}
