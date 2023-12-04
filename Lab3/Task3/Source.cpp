#include <stdio.h>
#include <Windows.h>
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int temp;
	printf("Оценка температуры помещения зимой\nВведите температуру помещения: ");
	scanf_s("%d", &temp);
	if (temp < 18) {
		printf("холодно");
	}
	else if (temp < 22) {
		printf("прохладно");
	}
	else if (temp < 26) {
		printf("тепло");
	}
	else {
		printf("жарко");
	}


	return 0;
}