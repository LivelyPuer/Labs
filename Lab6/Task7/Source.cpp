#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
// студент откладывает по capital руб каждый месяц, сколькор будет у него рублей через n месяцев
int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	int res = 0, capital, n, i = 1;
	printf("capital = ");
	scanf_s("%d", &capital);
	printf("n = ");
	scanf_s("%d", &n);
	res += capital;
	printf("%d RUB in 0 year\n", res);
	do {
		res += capital;
		printf("%d RUB in %d year\n", res, i);
		i += 1;
	} while (i <= n);
}