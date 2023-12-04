#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include <string.h>

#define MAX_N 65356
#define MAX_M 65356

int lenn = 3, lenm = 3;
int arr[MAX_N][MAX_M];
char path[PATH_MAX] = "/home/maxim/CLionProjects/Labs/Lab20/";

int open_array(const char *file_name) {
    FILE *fin;
    fin = fopen(file_name, "rt");
    if (fin == NULL) {
        printf("file %s not exists\n", file_name);
        return 0;
    }
    fscanf(fin, "%d%d", &lenn, &lenm);
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            fscanf(fin, "%d", &arr[i][j]);
        }
    }
    fclose(fin);
    printf("seccessful opened %s\n", file_name);
    return 1;
}

int save_array(const char *file_name) {
    FILE *fin;
    fin = fopen(file_name, "wt");
    if (fin == NULL) {
        printf("file %s not exists\n", file_name);
        return 0;
    }
    fprintf(fin, "%d %d\n", lenn, lenm);
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            fprintf(fin, "%d ", arr[i][j]);
        }
    }
    fclose(fin);
    printf("seccessful saved %s\n", file_name);
    return 1;
}

void print_arr() {
    printf("length - [%d][%d]\n", lenn, lenm);
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void all_x10() {
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            arr[i][j] *= 10;
        }
    }
    printf("===>DONE<===\n");
}

void all_0() {
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            arr[i][j] = 0;
        }
    }
    printf("===>DONE<===\n");
}

void all_random() {
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            arr[i][j] = (int) (rand() % 100);
        }
    }
    printf("===>DONE<===\n");
}

void odd_x10() {
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            if (arr[i][j] % 2 == 0) {
                arr[i][j] *= 10;
            }
        }
    }
    printf("===>DONE<===\n");
}

int min_elem() {
    int m = MAX_M;
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            if (arr[i][j] < m) {
                m = arr[i][j];
            }
        }
    }
    return m;
}

int max_elem() {
    int m = -MAX_M;
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            if (arr[i][j] > m) {
                m = arr[i][j];
            }
        }
    }
    return m;
}
void trash(){
    int mi = min_elem(), ma = max_elem();
    int x, y;

    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            if (arr[i][j] == ma){
                x = i; y = j;
            }
        }
    }
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            if (i > x && j < y){
                arr[i][j] = mi;
            }
        }
    }
    printf("===>DONE<===\n");

}
void x10_div10() {
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            if (arr[i][j] % 10 == 0) {
                arr[i][j] /= 10;
            }
        }
    }
    printf("===>DONE<===\n");
}

void dub_rows(int n) {
    for (int i = lenn; i > n; i--) {
        for (int j = 0; j < lenm; j++) {
            arr[i][j] = arr[i - 1][j];
        }
    }
    lenn += 1;
    printf("===>DONE<===\n");
}


void del_rows(int n) {
    for (int i = n; i < lenn - 1; i++) {
        for (int j = 0; j < lenm; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    lenn -= 1;
    printf("===>DONE<===\n");
}

void input_arr() {
    int n, m;

    printf("n=");
    scanf("%d", &n);
    printf("m=");
    scanf("%d", &m);

    lenn = n, lenm = m;
    for (int i = 0; i < lenn; i++) {
        for (int j = 0; j < lenm; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("===>DONE<===\n");

}

void show_commands() {
    print_arr();
    printf("==========================\n");
    printf("1) Заполнить i * 10 + j\n");
    printf("2) Заполнить нулями\n");
    printf("3) Заполнить рандомом\n");
    printf("4) Все нечетные x10\n");
    printf("5) Все кратные x10 * 1/10\n");
    printf("6) Ввести массив\n");
    printf("7) Открыть массив\n");
    printf("8) Сохранить массив\n");
    printf("9) Удалить строку\n");
    printf("10) Продублировать строку\n");
    printf("11) 4 Вар\n");
}

int main() {
    char str[30];
    int tmp = 0;
    char lpath[PATH_MAX];
    int command = 0;
    while (1) {
        show_commands();
        scanf("%d", &command);
        switch (command) {
            case 1:
                all_x10();
                break;
            case 2:
                all_0();
                break;
            case 3:
                all_random();
                break;
            case 4:
                odd_x10();
                break;
            case 5:
                x10_div10();
                break;
            case 6:
                input_arr();
                break;
            case 7:
                strcpy(lpath, path);
                printf("Введите имя файла: ");
                scanf("%s", str);
                strcat(lpath, str);
                open_array(lpath);
                break;
            case 8:
                strcpy(lpath, path);
                printf("Введите имя файла: ");
                scanf("%s", str);
                strcat(lpath, str);
                save_array(lpath);
                break;
            case 9:
                printf("удалить строку №: ");
                scanf("%d", &tmp);
                del_rows(tmp);
                break;
            case 10:
                printf("дублировать строку №: ");
                scanf("%d", &tmp);
                dub_rows(tmp);
                break;
            case 11:
                trash();
                break;
            default:
                break;
        }
        if (command == 0) {
            break;
        }
    }

    return 0;
}
