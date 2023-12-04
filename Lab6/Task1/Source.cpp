#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);

	int n, i = 1;
	wprintf(L"n = ");
	scanf_s("%d", &n);
	do {
		printf("%d ", i);
		i += 1;
	} while (i <= n);
}