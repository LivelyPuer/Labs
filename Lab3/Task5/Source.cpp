#include <stdio.h>
#include <Windows.h>
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int temp;
	printf("Оценка стоимости жевачи по рублю\nВведите цену жевачки на этот момент: ");
	scanf_s("%d", &temp);
	if (temp < 1) {
		printf("дёшего");
	}
	else if (temp == 1) {
		printf("нормально");
	}
	else if (temp < 3) {
		printf("дорого");
	}
	else {
		printf("ужасно дорого");
	}

	return 0;
}