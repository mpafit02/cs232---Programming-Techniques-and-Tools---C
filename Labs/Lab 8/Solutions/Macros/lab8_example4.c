#include <stdio.h>

// No parentheses needed around macro parameters as both are supposed to be 
// lvalues. Also, = operator has the lowest precedence.
#define swap(type,x,y) { type x ## y = x; x = y; y = x ## y; }

int main(void)
{
	int a, b;
	float c, d;
	
	a = 3;
	b = -7;
	
	c = 3.5;
	d = -2.5;
	
	swap(int,a,b); // Semicolon interpreted as empty command.
	swap(float,c,d)// Lack of semicolon does not cause a compilation error.
	
	printf("a = %d, b = %d", a, b);
	printf("c = %f.1, d = %f.1", c, d);

}
