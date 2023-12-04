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
    printf("1) \\t в %% \n");
    printf("2) Все большие\n");
    printf("3) # в конец, если есть буквы\n");
    printf("4) Токенизация\n");
    printf("5) HTML\n");
    printf("6) Кол-во ; в тексте\n");
    printf("7) Маленькие буква в @\n");
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
            default:
                return 0;
        }
    }
    while (c != 0);
    return 0;
}