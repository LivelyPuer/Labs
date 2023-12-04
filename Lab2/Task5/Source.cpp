#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float x1, y1, x2, y2, result;
	printf("Поиск градусной меры угла между двумя векторами на плоскости\n");
	printf("Введите через пробел координаты 1ого ветора: ");
	scanf_s("%f %f", &x1, &y1);
	printf("Введите через пробел координаты 1ого ветора: ");
	scanf_s("%f %f", &x2, &y2);
	result = (x1 * x2 + y1 * y2) / (sqrtf(powf(x1, 2) + powf(y1, 2)) * sqrtf(powf(x2, 2) + powf(y2, 2)));
	result = acosf(result) * 180 / 3.14f;
	printf("Угол между веторами (%f, %f) и (%f, %f) равен %f градусов", x1, y1, x2, y2, result);

	return 0;
}