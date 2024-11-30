#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail; // sentinel node marking the end of the list
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = (Node*)malloc(sizeof(Node));
    list->tail->next = NULL;
    return list;
}

void safeDeleteListNode(LinkedList* list, int value) {
    if (list == NULL || list->head == NULL) return;
    Node* current = list->head;
    Node* prev = NULL;
    while (current != list->tail && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current != list->tail) {
        if (prev == NULL) {
            list->head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

void destroyList(LinkedList* list) {
    if (list == NULL) return;
    Node* current = list->head;
    while (current != list->tail) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list->tail);
    free(list);
}

int main() {
    LinkedList* list = createList();
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 10;
    newNode->next = list->tail;
    list->head = newNode;
    safeDeleteListNode(list, 10);
    destroyList(list);
    return 0;
}