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
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->sentinel = (Node*)malloc(sizeof(Node));
    if (list->sentinel == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    list->sentinel->next = NULL;
    return list;
}

void safeAddNode(LinkedList* list, int value) {
    if (list == NULL) {
        fprintf(stderr, "Invalid list\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void safeRemoveNode(LinkedList* list, int value) {
    if (list == NULL) {
        fprintf(stderr, "Invalid list\n");
        return;
    }
    Node* current = list->head;
    Node* previous = NULL;
    while (current != NULL && current != list->sentinel) {
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
    if (list == NULL) {
        return;
    }
    Node* current = list->head;
    while (current != NULL && current != list->sentinel) {
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