#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float square, price1sqrt, salary, priceHome;
	printf("Введите площадь квартиры в квадратных метрах=");
	scanf_s("%f", &square);
	wprintf(L"Введите стоимость одного квадратного метра в рублях=");
	scanf_s("%f", &price1sqrt);
	wprintf(L"Введите Вашу зарплату в рублях для расчета накопитеьного плана=");
	scanf_s("%f", &salary);
	priceHome = square * price1sqrt;
	wprintf(L"Стоимость квартиры %f кв. м со стоимостью одного кв. м %f руб. =%f руб.\n", square, price1sqrt, priceHome);

	return 0;
}