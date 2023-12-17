//
// Created by maxim on 05.12.23.
//

#include <stdio.h>

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return fact(n - 1) * n;
}

void task1() {
    printf("%d", fact(5));
}

void f1(int n) {
    printf("%d ", n);
    if (n > 1) {
        f1(n - 2);
    }
}

void f2(int n) {
    if (n > 1) {
        f2(n - 2);
    }
    printf("%d ", n);
}

void f3(int n) {
    printf("%d ", n);
    if (n == 1) {
        return;
    }
    if (n > 1) {
        f3(n - 2);
    }
    printf("%d ", n);
}

void task2() {
    f1(11);
    printf("FINISH 1\n");
    f2(11);
    printf("FINISH 2\n");
    f3(11);
    printf("FINISH 3\n");
}

void task3() {
    f1(7);
    printf("FINISH 1\n");
    f2(7);
    printf("FINISH 2\n");
    f3(7);
    printf("FINISH 3\n");
}

void recEGE1(int n) {
    if (n >= 1) {
        printf(" %d", n);
        recEGE1(n - 1);
        recEGE1(n - 1);
    }
}

void task4() {
    recEGE1(3);
}

void f1_task5(int n) {
    if (n > 2) {
        printf("%d\n", n) ;
        f1_task5(n - 3);
        f1_task5(n - 4);
    }
}

void task5() {
    f1_task5(10);
}

void f2_task6(int n) {
    printf("%d\n", n);
    if (n < 5) {
        f2_task6(n + 1);
        f2_task6(n + 3);
    }
}
void task6() {
    f2_task6(1);
}

void g3(int n);

void f3_task7(int n) {
    if (n > 0) g3(n - 1);
    }
void g3(int n) {
    printf("*");
    if (n > 1) f3_task7(n - 3);
}
void task7() {
    f3_task7(11);
}