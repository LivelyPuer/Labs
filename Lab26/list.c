#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void printList() {
    struct Node* ptr = first;
    while (ptr != NULL) {
        printf("(%d) -> ", ptr->data); // (ptr*).data
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void addToHead(int value) {
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->next = first;
    new_node->data = value;

    first = new_node;
}

int deleteFromHead() {
    int value = first->data;
    struct Node* del_node = first;
    first = first->next;
    free(del_node);
    return value;
}

int contains(int value) {
    struct Node* ptr = first;
    while (ptr != NULL) {
        if (ptr->data == value) {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

int sumList() {
    int res = 0;
    struct Node* ptr = first;
    while (ptr != NULL) {
        res += ptr->data;
        ptr = ptr->next;
    }
    return res;
}

int evenCount() {
    int res = 0;
    struct Node* ptr = first;
    while (ptr != NULL) {
        if (ptr->data % 2 == 0) {
            ++res;
        }
        ptr = ptr->next;
    }
    return res;
}


void clearList() {
    while (first != NULL) {
        struct Node* del_node = first;
        first = first->next;
        free(del_node);
    }
}

void oddsX10() {
    struct Node* ptr = first;
    while (ptr != NULL) {
        if (ptr->data % 2 != 0) {
            ptr->data = ptr->data * 10;
        }
        ptr = ptr->next;
    }
}
void elementIx100(int i) {
    struct Node* ptr = first;
    int index = 0;
    while (ptr != NULL) {
        if (index == i) {
            ptr->data = ptr->data * 100;
            return;
        }
        ptr = ptr->next;
        index++;
    }
}

void elementLeftIx100(int i) {
    struct Node* ptr = first;
    int index = 0;
    while (ptr != NULL) {
        if (index < i) {
            ptr->data = ptr->data * 100;
        }else {
            return;
        }
        ptr = ptr->next;
        index++;
    }
}
void elementRightIx2(int i) {
    struct Node* ptr = first;
    int index = 0;
    while (ptr != NULL) {
        if (index > i) {
            ptr->data = ptr->data * 2;
        }else {
            return;
        }
        ptr = ptr->next;
        index++;
    }
}