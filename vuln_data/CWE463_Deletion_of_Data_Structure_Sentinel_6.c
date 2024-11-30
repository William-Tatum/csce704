#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* sentinel;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    Node* sentinelNode = (Node*)malloc(sizeof(Node));
    sentinelNode->next = NULL;
    list->head = sentinelNode;
    list->sentinel = sentinelNode;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->sentinel;
    Node* current = list->head;
    while (current->next != list->sentinel) {
        current = current->next;
    }
    current->next = newNode;
}

void safeDeleteNode(LinkedList* list, int data) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current != list->sentinel && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current != list->sentinel) {
        if (prev) {
            prev->next = current->next;
        }
        free(current);
    }
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    while (current != list->sentinel) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list->sentinel);
    free(list);
}

int main() {
    LinkedList* list = createList();
    addNode(list, 10);
    addNode(list, 20);
    safeDeleteNode(list, 10);
    safeDeleteNode(list, 20);
    freeList(list);
    return 0;
}