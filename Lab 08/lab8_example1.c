#include <stdio.h>

//For each function below, write one macro doeing the "same" thing 
//#define max <write the macro code here>
//#define sqr <write the macro code here>
//#define abs <write the macro code here>
#define max(x,y) ((x) > (y)) ? (x) : (y)
#define sqr(x) (x) * (x)
#define abs(x) ((x) > 0) ? (x) : -(x)

#define int_max2(x,y) ((int)(x) > (int)(y)) ? (int)(x) : (int)(y)
#define int_sqr2(x) (int)(x) * (int)(x)
#define int_abs2(x) ((int)(x) > 0) ? (int)(x) : -(int)(x)

int int_max(int x, int y) {
	return x > y ? x : y;
}
int int_sqr(int x) {
	return x * x;
}
int int_abs(int x) {
	return x > 0 ? x : -x;
}

int main(void) {

	int a, b;
	float c, d;

	a = 3;
	b = -7;

	c = 3.5;
	d = -7.5;

	// Arguments: variables (or literals)
	printf("\n");
	printf("Arguments: variables (or literals)\n");
	printf("\n");
	printf("    max of %d, %d, is %d\n", a, b, max(a, b));
	printf("int_max of %d, %d, is %d\n", a, b, int_max(a, b));
	printf("\n");
	printf("    sqr of %d is %d\n", b, sqr(b));
	printf("int_sqr of %d is %d\n", b, int_sqr(b));
	printf("\n");
	printf("    abs of %d is %d\n", b, abs(b));
	printf("int_abs of %d is %d\n", b, int_abs(b));
	printf("\n");
	printf("\n");

	// Arguments: variable or literal type mismatches

	printf("Arguments: variable or literal type mismatches\n");
	printf("\n");
	printf("    max of %.1f, %.1f, is %.1f\n", c, d, max(c, d));
	printf("int_max of %.1f, %.1f, is %d\n", c, d, int_max(c, d));
	printf("\n");
	printf("    sqr of %.1f is %.1f\n", d, sqr(d));
	printf("int_sqr of %.1f is %d\n", d, int_sqr(d));
	printf("\n");
	printf("    abs of %.1f is %.1f\n", d, abs(d));
	printf("int_abs of %.1f is %d\n", d, int_abs(d));
	printf("\n");
	printf("\n");

	// Arguments: expressions

	printf("Arguments: expressions\n");
	printf("\n");
	printf("    max of %d, %d, is %d\n", a + b, a * b, max(a + b, a * b));
	printf("int_max of %d, %d, is %d\n", a + b, a * b, int_max(a + b, a * b));
	printf("\n");
	printf("    sqr of %d is %d\n", a + b, sqr(a + b));
	printf("int_sqr of %d is %d\n", a + b, int_sqr(a + b));
	printf("\n");
	printf("    abs of %d is %d\n", a + b, abs(a + b));
	printf("int_abs of %d is %d\n", a + b, int_abs(a + b));
	printf("\n");
	printf("\n");

	// Arguments: expressions with side effects

	printf("Arguments: expressions with side effects\n");
	printf("\n");
	printf("    max of %d, %d, is %d\n", 4, -6, max(++a, ++b));
	a = 3;
	b = -7;
	printf("int_max of %d, %d, is %d\n", 4, -6, int_max(++a, ++b));
	printf("\n");
	a = 3;
	b = -7;
	printf("    sqr of %d is %d\n", -6, sqr(++b));
	a = 3;
	b = -7;
	printf("int_sqr of %d is %d\n", -6, int_sqr(++b));
	printf("\n");
	a = 3;
	b = -7;
	printf("    abs of %d is %d\n", -6, abs(++b));
	a = 3;
	b = -7;
	printf("int_abs of %d is %d\n", -6, int_abs(++b));
	printf("\n");
	printf("\n");

}
