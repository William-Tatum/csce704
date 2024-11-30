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
    if (list == NULL) {
        perror("Failed to allocate LinkedList");
        exit(EXIT_FAILURE);
    }
    Node* sentinelNode = (Node*)malloc(sizeof(Node));
    if (sentinelNode == NULL) {
        perror("Failed to allocate sentinel Node");
        free(list);
        exit(EXIT_FAILURE);
    }
    sentinelNode->next = NULL;
    list->head = sentinelNode;
    list->sentinel = sentinelNode;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate new Node");
        exit(EXIT_FAILURE);
    }
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
        } else {
            list->head = current->next;
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