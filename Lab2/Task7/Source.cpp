#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float promotion, dividends, time;
	printf("Расчёт окупаемости акции дивидендами\n");
	printf("Введите цену акции в рублях: ");
	scanf_s("%f", &promotion);
	printf("Введите процент дивидендов от акции в процентах: ");
	scanf_s("%f", &dividends);
	time = promotion / (promotion * (dividends / 100));
	printf("Акция стоимостью в %f рублей и дивидендами в %f %% окупится через %f лет", promotion, dividends, time);

	return 0;
}