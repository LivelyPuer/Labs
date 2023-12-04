#include <stdio.h>
#include <Windows.h>
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b;
	printf("Введите 2 числа через пробел: ");
	scanf_s("%d %d", &a, &b);
	if (a > b) {
		printf("Большее число: %d\nМеньшее число: %d\n", a, b);
	}
	else if (a == b) {
		printf("Числа %d и %d равны", a, b);
	}
	else {
		printf("Большее число: %d\nМеньшее число: %d\n", b, a);
	}


	return 0;
}