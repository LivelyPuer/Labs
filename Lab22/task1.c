//
// Created by maxim on 04.12.23.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void task1() {
    char name[30];
    printf("Введите Ваше имя: ");
    fgets(name, 29, stdin);
    printf("Привет, %s", name);
}

void task2() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    printf("Используемая кодировка WINDOWS-1251 ");
#else
    printf("Используемая кодировка UTF-8\n");
#endif
    printf("Введите символ: ");
    int ch = 0;
    scanf("%d", &ch);
    for (int c = ch; c < ch + 19; c++) {
        printf("\"%c\" (%d)\n", c, c);
    }
}

void task3() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    printf("Используемая кодировка WINDOWS-1251 ");
#else
    printf("Используемая кодировка UTF-8\n");
#endif
    printf("Введите символ: ");
    int ch = 0;
    scanf("%d", &ch);
    for (int c = ch - 29; c < ch + 1; c++) {
        printf("\"%c\" (%d)\n", c, c);
    }
}

void task4() {
    char str[100];
    printf("Введите строку: ");
    fgets(str, 100, stdin);
    printf("Исходная: %s", str);
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            cnt++;
        }
    }
    printf("Пробелов: %d", cnt);
}

void task5() {
    char str[100];
    printf("Введите строку: ");
    fgets(str, 100, stdin);
    printf("Исходная: %s", str);
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            str[i] = "#";
        }
    }
    printf("Итоговая: %s", str);
}

int isDigitMy(char c) {
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

void task6() {
    char str[100];
    printf("Введите строку: ");
    fgets(str, 100, stdin);
    printf("Исходная: %s", str);
    for (int i = 0; i < strlen(str); i++) {
        if (isDigitMy(str[i])) {
            str[i] = "$";
        }
    }
    printf("Итоговая: %s", str);
}

int toUpperAll(int c) {
    int new_c = c;
    if (c >= 'a' && c <= 'z') {
        new_c = 'A' + (c - 'a');
    }
    if (c >= 'а' && c <= 'п') {
        new_c = 'А' + (c - 'а');
    }
    if (c >= 'р' && c <= 'я') {
        new_c = 'Р' + (c - 'р');
    }
    if (c == 'ё') {
        new_c = 'Ё';
    }
    return new_c;
}

void task7() {
    char str[100];
    printf("Введите строку: ");
    fgets(str, 100, stdin);
    printf("Исходная: %s", str);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toUpperAll(str[i]);
    }
    printf("Итоговая: %s", str);
}
int check_lower(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}
void task8() {
    char str[100];
    printf("Введите строку: ");
    fgets(str, 100, stdin);
    printf("Исходная: %s", str);
    for (int i = 0; i < strlen(str); i++) {
        if (check_lower(str[i])) {
            str[i] = "@";
        }
    }
    printf("Итоговая: %s", str);
}