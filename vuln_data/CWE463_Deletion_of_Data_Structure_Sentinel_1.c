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
    list->sentinel = sentinelNode;
    list->head = sentinelNode;
    return list;
}

void safeAppend(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->sentinel;
    if (list->head == list->sentinel) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != list->sentinel) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteList(LinkedList* list) {
    Node* current = list->head;
    while (current != list->sentinel) {
        Node* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    free(list->sentinel);
    free(list);
}

int main() {
    LinkedList* myList = createList();
    safeAppend(myList, 10);
    safeAppend(myList, 20);
    deleteList(myList);
    return 0;
}