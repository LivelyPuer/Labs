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
    int n, m, i = 1, j = 1;
    wprintf(L"Введите m и n: ");
    scanf_s("%d %d", &n, &m);
    while (i <= n) {
        while (j <= m) {
            wprintf(L"%d%d\t", i, j);
            j += 1;
        }
        wprintf(L"\n");
        j = 1;
        i += 1;
    }
}
void task2() {
    int i = 10, j = 10;
    do {
        do {
            printf("%d\t", i * j);
            j -= 1;
        } while (j >= 1);
        wprintf(L"\n");
        i -= 1;
        j = 10;
    } while (i >= 1);
}
void task3() {
    int i = 1, j = 0;
    while (i <= 5) {
        while (j >= 0) {
            wprintf(L"%d ", j);
            j -= 1;
        }
        i += 1;
        j = i - 1;
        wprintf(L"\n");
    }
    wprintf(L"Вариант 4 \n");
    wprintf(L"5\n");
    wprintf(L"5 4\n");
    wprintf(L"5 4 3\n");
    wprintf(L"5 4 3 2\n");
    wprintf(L"5 4 3 2 1\n");
}
int main() {
    initConsole();
    int n;
    do {
        wprintf(L"\n");
        wprintf(L"\n");
        wprintf(L"Выберите операцию: \n");
        wprintf(L"1: таблица \n");
        wprintf(L"2: Пифагор \n");
        wprintf(L"3: Картинка \n");
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
        }


    } while (n != 0);
    return 0;

}