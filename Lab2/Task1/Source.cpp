#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float h, g = 9.8f, t;
	printf("Введите высоту в метрах=");
	scanf_s("%f", &h);
	t = sqrtf(2 * h / g);
	printf("Предмет с высоты %f метров\n", h);
	printf("Он коснется земли через %f секунд \n", t);
	return 0;
}