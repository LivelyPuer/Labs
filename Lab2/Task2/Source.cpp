#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float square, price, result;
	printf("Введите площадь квартиры в квадратных метрах=");
	scanf_s("%f", &square);
	printf("Введите стоимость одного квадратного метра в рублях=");
	scanf_s("%f", &price);
	result = square * price;
	printf("Стоимость квартиры %f кв. м со стоимостью одного кв. м %f руб. =%f руб.\n", square, price, result);

	return 0;
}