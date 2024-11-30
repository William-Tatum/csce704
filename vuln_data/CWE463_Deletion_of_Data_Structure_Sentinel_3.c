#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* sentinel;
} SafeList;

SafeList* createList() {
    SafeList* list = (SafeList*)malloc(sizeof(SafeList));
    list->head = NULL;
    list->sentinel = (Node*)malloc(sizeof(Node));
    list->sentinel->next = NULL;
    return list;
}

void addToList(SafeList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void removeNode(SafeList* list, int data) {
    Node** current = &list->head;
    while (*current && (*current)->data != data) {
        current = &(*current)->next;
    }
    if (*current) {
        Node* tempNode = *current;
        *current = tempNode->next;
        free(tempNode);
    }
}

void deleteList(SafeList* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current && current != list->sentinel) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list->sentinel);
    free(list);
}

int main() {
    SafeList* list = createList();
    addToList(list, 1);
    addToList(list, 2);
    removeNode(list, 2);
    deleteList(list);
    return 0;
}