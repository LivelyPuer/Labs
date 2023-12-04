#include<stdio.h>
#include<Windows.h>
#include <locale.h>
#include <wchar.h>

void initConsole() {

	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
}

void aboutMe() {
	wprintf(L"Я Я Я\n");
	wprintf(L"ПИбд-14\n");
	printf("Bruh-Brush\n");
}
int main() {
	initConsole();
	aboutMe();
}