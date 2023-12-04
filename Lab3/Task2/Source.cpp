#include <stdio.h>
#include <Windows.h>
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int b, c, d, e, max;
	printf("Введите 5 числ через пробел: ");
	scanf_s("%d %d %d %d %d", &max, &b, &c, &d, &e);
	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}
	if (max < d) {
		max = d;
	}
	if (max < e) {
		max = e;
	}
	printf("Наибольшее число из списка: %d", max);

	return 0;
}