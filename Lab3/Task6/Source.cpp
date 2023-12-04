#include <stdio.h>
#include <Windows.h>
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int temp;
	printf("Оценка скорости езды по населённому пункту\nВведите скорость в км\\ч: ");
	scanf_s("%d", &temp);
	if (temp < 30) {
		printf("медленно");
	}
	else if (temp < 60) {
		printf("нормально");
	}
	else if (temp < 80) {
		printf("быстро");
	}
	else {
		printf("очень быстро");
	}

	return 0;
}