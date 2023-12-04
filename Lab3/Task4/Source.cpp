#include <stdio.h>
#include <Windows.h>
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int temp;
	printf("Оценка температуры на улице\nВведите температуру: ");
	scanf_s("%d", &temp);
	if (temp < 0) {
		printf("мороз");
	}
	else if (temp < 10) {
		printf("холодно");
	}
	else if (temp < 20) {
		printf("тепло");
	}
	else {
		printf("жарко");
	}

	return 0;
}