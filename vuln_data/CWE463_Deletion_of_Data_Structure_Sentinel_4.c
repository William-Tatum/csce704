#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* sentinel;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->sentinel = (Node*)malloc(sizeof(Node));
    list->sentinel->next = NULL;
    return list;
}

void safeAddNode(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void safeRemoveNode(LinkedList* list, int value) {
    Node* current = list->head;
    Node* previous = NULL;
    while (current != list->sentinel && current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != list->sentinel && current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list->sentinel);
    free(list);
}

int main() {
    LinkedList* list = createList();
    safeAddNode(list, 10);
    safeRemoveNode(list, 10);
    freeList(list);
    return 0;
}