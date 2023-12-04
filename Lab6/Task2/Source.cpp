#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	int n = 5, i = 0, res;
	do {
		res = powf(2, i);
		printf("2^%d = %d\n", i, res);
		i += 1;
	} while (i <= n);
}