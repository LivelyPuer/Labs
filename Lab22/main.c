#include <stdio.h>
#include <ctype.h>
#include "tasks.h"

void change_codec() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <Windows.h>
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
}

void show_tasks() {
    printf("Выберите задание:\n");
    printf("1) Задача 1.1 – Hello по русски!\n");
    printf("2) Вывести на экран 20 символов с кодами от CH до CH+19\n");
    printf("3) Вывести на экран 20 символов с кодами от CH до CH-30\n");
    printf("4) Кол-во пробелов\n");
    printf("5) Все пробелы на #\n");
    printf("6) myDigit() числа в $\n");
    printf("7) myUpper()\n");
    printf("8) Маленькие буква в @\n");
}

int main() {
    change_codec();
    int c;
    do {
        show_tasks();
        printf("\nНомер задания: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
                break;
            case 8:
                task8();
                break;
            default:
                return 0;
        }
    }
    while (c != 0);
    return 0;
}
