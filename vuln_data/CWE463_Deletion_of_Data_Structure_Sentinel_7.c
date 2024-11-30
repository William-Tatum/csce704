#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = (Node*)malloc(sizeof(Node));
    if (!list->tail) {
        free(list);
        return NULL;
    }
    list->tail->next = NULL;
    return list;
}

void safeAddNode(LinkedList* list, int data) {
    if (!list) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = data;
    newNode->next = list->tail;
    if (!list->head) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != list->tail) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(LinkedList* list) {
    if (!list || !list->head) return;
    Node* current = list->head;
    while (current != list->tail) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(LinkedList* list) {
    if (!list) return;
    Node* current = list->head;
    while (current != list->tail) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list->tail);
    free(list);
}

int main() {
    LinkedList* list = createList();
    if (!list) exit(1);
    safeAddNode(list, 1);
    safeAddNode(list, 2);
    safeAddNode(list, 3);
    printList(list);
    freeList(list);
    return 0;
}