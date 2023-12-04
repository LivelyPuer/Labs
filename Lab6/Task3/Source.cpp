#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	int capital, percent, n = 10, i = 1;
	printf("capital = ");
	scanf_s("%d", &capital);
	printf("percent = ");
	scanf_s("%d", &percent);
	printf("%d RUB in 0 year\n", capital);
	do {
		capital += capital * ((float)percent / 100);
		printf("%d RUB in %d year\n", capital, i);
		i += 1;
	} while (i <= n);
}