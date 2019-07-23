#include <stdio.h>
#include <string.h>

int main() {
	char *p;
	int *pi;
	char a[] = "abcdef";
	p = "abcdef";
	printf("%d\n%d\n%d\n%d\n%d\n", sizeof(pi), sizeof(p), strlen(p), sizeof(a),
			strlen(a));
	printf("%s\n%s\n", p, a);
	return 0;
}
