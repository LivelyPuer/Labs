#include<stdio.h>

int main() {
	int a, b, c, d, e, r;
	printf("Input 5 numbers: ");
	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("Output sum 5 numbers: ");
	r = a + b + c + d + e;
	printf("%d", r);
}