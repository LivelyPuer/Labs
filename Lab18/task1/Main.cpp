#include<stdio.h>

int main() {
	int a, b, c;
	printf("Input 3 numbers: ");
	scanf_s("%d%d%d", &a, &b, &c);
	printf("Output product 3 numbers: ");
	printf("%d", a * b * c);
}