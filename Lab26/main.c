#include <stdio.h>
#include "list.h"

int main() {
    printf("Hello, World!\n");
    addToHead(10);
    addToHead(30);
    addToHead(15);
    addToHead(1);
    addToHead(3);

    printList();

    deleteFromHead();

    printList();
    if (contains(30) == 1) {
        printf("30 in list");
    }else {
        printf("30 not in list");
    }
    printf("sum: %d", sumList());
    printf("even: %d", evenCount());
    oddsX10();
    printList();
    elementIx100(2);
    printList();
    elementLeftIx100(3);
    printList();
    clearList();
    printList();


    return 0;
}
