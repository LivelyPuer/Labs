#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <wchar.h>


void initConsole() {

    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
}
void task1() {
    int a = 1;
    do {
        printf("%d\t", a);
        a += 1;
    } while (a <= 10);
}
void task2() {
    int a = 10;
    do {
        printf("%d\t", a);
        a -= 1;
    } while (a >= 1);
}
void task11() {
    int a = 100;
    while (a >= 10) {
        printf("%d\t", a);
        a -= 10;
    }
}
void task12() {
    int a = 1000;
    while (a >= 100) {
        printf("%d\t", a);
        a -= 100;
    }
}
void task3() {
    int a = 1;
    int n = 1;
    do {
        printf("%d\t", a);
        a += 2;
        n += 1;
    } while (n <= 5);
}
void task20() {
    int a = 1000;
    while (a >= 0) {
        printf("%d\t", a);
        a -= 4;
    }
}
int main() {
    initConsole();
    int n;
    do {
        wprintf(L"\n");
        wprintf(L"\n");
        wprintf(L"Выберите операцию: \n");
        wprintf(L"1: вывести 1 .. 10 \n");
        wprintf(L"2: вывести 10 .. 11 \n");
        wprintf(L"3: 5 первых нечетных \n");
        wprintf(L"11: 100 .. 10 c шагом -10 \n");
        wprintf(L"12: 1000 .. 100 c шагом -100 \n");
        wprintf(L"20: 1000 .. 0 c шагом -4 \n");
        wprintf(L"\n");
        wprintf(L"0: Выйти\n");
        scanf_s("%d", &n);
        switch (n) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 11:
            task11();
            break;
        case 12:
            task12();
            break;
        case 20:
            task20();
            break;
        }
        

    } while (n != 0);
    return 0;

}