#include <stdio.h>

unsigned short swap_bytes(unsigned short i);

int main() {
	unsigned short x = 0x0A0F;
	x = swap_bytes(x);
	printf("%x", x);
	return 0;
}

unsigned short swap_bytes(unsigned short i) {
	unsigned short a = i >> 8;
	unsigned short b = i << 8;
	return a | b;
}
