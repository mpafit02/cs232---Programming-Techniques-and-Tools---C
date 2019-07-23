#include <stdlib.h>
#include <stdio.h>

#define write(type,expr) print_ ## type(expr)
#define read(type,lvalue) scan_ ## type(&(lvalue))

print_char(char e) { printf("%c", e); }
print_short(short e) { printf("%d", e); }
print_int(int e) { printf("%d", e); }
print_long(long e) { printf("%ld", e); }
print_float(float e) { printf("%f", e); }
print_double(double e) { printf("%lf", e); }

scan_char(char *e) { scanf("%c", e); }
scan_short(short *e) { scanf("%d", e); }
scan_int(int *e) { scanf("%d", e); }
scan_long(long *e) { scanf("%dl", e); }
scan_float(float *e) { scanf("%f", e); }
scan_double(double *e) { scanf("%lf", e); }

int main(void)
{
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;
	
	printf("Please enter a character : ");
	read(char,c);
	write(char,c);
	printf("\n");
	
	printf("Please enter a short integer : ");
	read(short,s);
	write(short,s);
	printf("\n");
	
	printf("Please enter an integer : ");
	read(int,i);
	write(int,i);
	printf("\n");
	
	printf("Please enter a long integer : ");
	read(long,l);
	write(long,l);
	printf("\n");
	
	printf("Please enter a single precision floating point number : ");
	read(float,f);
	write(float,f);
	printf("\n");
	
	printf("Please enter a double precision floating point number : ");
	read(double,d);
	write(double,d);
	printf("\n");
	
}
