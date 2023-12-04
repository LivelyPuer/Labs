#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

// по заданным n, a находит ряд n элементов из a^n_i 
int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	int n, a, i = 1;
	printf("n = ");
	scanf_s("%d", &n);
	printf("a = ");
	scanf_s("%d", &a);
	do {
		printf("%d ", (int)pow(a, i));
		i += 1;
	} while (i <= n);
	return 0;
}