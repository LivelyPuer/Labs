#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	int n, i = 1;
	printf("n = ");
	scanf_s("%d", &n);
	do {
		printf("%d ", 2 * i);
		i += 1;
	} while (i <= n);
}