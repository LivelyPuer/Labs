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
    printf("1) Фрактал n = 5 \n");
    printf("2) Что-то с f(11)\n");
    printf("3) Что-то с f(7)\n");
    printf("4) EGE\n");
    printf("5) EGE\n");
    printf("6) EGE\n");
    printf("7) EGE f & g\n");
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
            default:
                return 0;
        }
    }
    while (c != 0);
    return 0;
}