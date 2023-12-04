#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float U, R, I;
	printf("Анализ электрической сети (Вычисление силы тока по напряжению и сопротивлению)\n");
	printf("Введите напряжение сети в В: ");
	scanf_s("%f", &U);
	printf("Введите сопротивление сети в Ом: ");
	scanf_s("%f", &R);
	I = U / R;
	printf("Сила тока в электрической сети с напряжением %f В и сопротивлением %f Ом равна %f А", U, R, I);

	return 0;
}