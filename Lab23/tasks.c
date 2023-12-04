#include <ctype.h>
#include <stdio.h>
#include <string.h>
//
// Created by maxim on 04.12.23.
//
#define _CRT_SECURE_NO_WARNINGS

#define MAX_LEN 80
char s[MAX_LEN];

void task1() {
    // Входной файл
    FILE* fin = fopen("c:\\Temp\\Lection12\\text1.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout;
    fout = fopen("c:\\Temp\\Lection12\\out1.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    // в цикле для всех строк
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {
                if (s[i] == '\t') // Если прочитан пробел
                    s[i] = '%'; // Заменяем его на '%’
            }
            // сохранить строку в выходной файл
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    // закрыли файлы
    fclose(fin);
    fclose(fout);

    printf("ЛР23 Задача 1 FINISH\n");
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

void task2() {
    // Входной файл
    FILE* fin = fopen("c:\\Temp\\Lection12\\text2.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout;
    fout = fopen("c:\\Temp\\Lection12\\out2.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    // в цикле для всех строк
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {
                s[i] = toUpperAll(s[i]); // Заменяем его на '%’
            }
            // сохранить строку в выходной файл
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    // закрыли файлы
    fclose(fin);
    fclose(fout);

    printf("ЛР23 Задача 2 FINISH\n");
}

void task3() {
    // Входной файл
    FILE* fin = fopen("c:\\Temp\\Lection12\\text3.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout;
    fout = fopen("c:\\Temp\\Lection12\\out3.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    int digits = 0;
    // в цикле для всех строк
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            digits = 0;
            for (int i = 0; s[i] != '\0'; i++) {
                if (isalpha(s[i])) {
                    digits = 1;
                }
            }
            // сохранить строку в выходной файл
            if (digits == 1) {
                strcat(s, "#");
            }
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    // закрыли файлы
    fclose(fin);
    fclose(fout);

    printf("ЛР23 Задача 3 FINISH\n");
}

int isalpha_my(unsigned char ch) {
    if (isalpha(ch))
        return 1;

    // ANSI кодировка!!!
    if (ch >= 192 && ch <= 223)
        return 1;
    if (ch >= 224 && ch <= 255)
        return 1;

    /*
    if (ch >= 'А' && ch <= 'Я') return 1;
    if (ch >= 'а' && ch <= 'п') return 1;
    if (ch >= 'р' && ch <= 'я')return 1;
    if (ch == 'ё' ) return 1;
    if (ch == 'Ё') return 1;*/

    return 0;
}

int getNextDelim(FILE* fp, char token[]) {
    int ch = getc(fp);
    if (ch == EOF) {
        return 0;
    }
    if (isalpha_my((unsigned char)ch)) {
        ungetc(ch, fp);
        return 0;
    }
    token[0] = (unsigned char)ch;
    token[1] = '\0';
    return 1;
}

int getNextWord(FILE* fp, char token[], int maxLen) {
    int i = 0;
    int ch;
    while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
        if (!isalpha_my((unsigned char)(ch))) {
            break;
        }
        token[i++] = ch;
    }
    ungetc(ch, fp);
    token[i] = '0';
    if (i == 0)
        return 0;
    return 1;
}

void task4() {
    int getNextDelim(FILE* fp, char token[]);
    int getNextWord(FILE* fp, char token[], int maxLen);

    char filename[] = "c:\\Temp\\Lection15\\text1.txt";

    // открываем файл с текстом
    FILE* fin = fopen(filename, "rt");
    if (fin == NULL) {
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filename);
        return;
    }
    char token[MAX_LEN];
    int res;

    // пока не конец файла
    while (!feof(fin)) {
        // пока есть разделитель - берем его
        while (getNextDelim(fin, token)) {
            // выводим разделитель в консоль
            printf("<DELIM>%s</DELIM>\n", token);
        }
        // если есть слово - берем его
        if (getNextWord(fin, token, MAX_LEN)) {
            // выводим слово в консоль
            printf("<WORD>%s</WORD>\n", token);
        }
    }

    // Закрываем файл с текстом
    fclose(fin);
    printf("END!!!\n");
}

void task5() {
    char filenameIn[] = "c:\\Temp\\Lection15\\text1.txt";
    char filenameHTML[] = "c:\\Temp\\Lection15\\text1_out.html";
    printf("BEGIN!!!\n");

    // открыть файл текстовый (ВХОДНОЙ)
    FILE* fin = fopen(filenameIn, "rt");
    if (fin == NULL) {
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filenameIn);
        return;
    }
    // открыть HTML файл (выходной файл)
    FILE* fout = fopen(filenameHTML, "wt");
    if (fout == NULL) {
        // закрываем ранее успешно открытый входной файл
        fclose(fin);
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filenameHTML);
        return;
    }


    // Выводим в выходной файл заголовок HTML документа
    fprintf(fout, "<!DOCTYPE html>");
    fprintf(fout, "<html>");
    fprintf(fout, "<head>");
    fprintf(fout, "<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
    fprintf(fout, "<title>HTML Document</title>");
    fprintf(fout, "</head>");
    fprintf(fout, "<body>");

    int ch;
    while ((ch = getc(fin)) != EOF) {
        // в HTML файл добавляем только что прочитанный
        // символ "КАК ЕСТЬ"
        fprintf(fout, "%c", ch);

        // если в тексте был символ новой строки –
        // в HTML добавляем тег <BR> - новая строка
        if (ch == '\n')
            fprintf(fout, "<br>");
    }

    // выводит в HTML завершающие теги документа HTML
    fprintf(fout, "</body>");
    fprintf(fout, "</html>");
    // Закрываем файл с текстом
    fclose(fin);

    // Закрываем HTML файл
    fclose(fout);
    printf("END!!!\n");
}

int isT(char c) {
    return c == ';';
}

void task6() {
    // Входной файл
    FILE* fin = fopen("c:\\Temp\\Lection12\\text6.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout;
    fout = fopen("c:\\Temp\\Lection12\\out6.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    int digits = 0;
    // в цикле для всех строк
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            digits = 0;
            for (int i = 0; s[i] != '\0'; i++) {
                if (isT(s[i])) {
                    digits++;
                }
            }
            char str[MAX_LEN];
            sprintf(str, "%d", digits);
            // сохранить строку в выходной файл
            if (digits != 0) {
                strcat(s, str);
            }
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    // закрыли файлы
    fclose(fin);
    fclose(fout);

    printf("ЛР23 Задача 6 FINISH\n");
}

char check_lower(char c) {
    if (c >= 'a' && c <= 'z') {
        return '@';
    }
    return c;
}

void task7() {
    // Входной файл
    FILE* fin = fopen("c:\\Temp\\Lection12\\text2.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout;
    fout = fopen("c:\\Temp\\Lection12\\out2.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    // в цикле для всех строк
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {
                s[i] = check_lower(s[i]); // Заменяем его на '%’
            }
            // сохранить строку в выходной файл
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    // закрыли файлы
    fclose(fin);
    fclose(fout);

    printf("ЛР23 Задача 7 FINISH\n");
}