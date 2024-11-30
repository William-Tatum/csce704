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
    list->head = NULL;
    list->sentinel = (Node*)malloc(sizeof(Node));
    list->sentinel->next = NULL;
    return list;
}

void append(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->sentinel;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != list->sentinel) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(LinkedList* list, int value) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current != list->sentinel) {
        if (current->data == value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != list->sentinel) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList* list = createList();
    append(list, 1);
    append(list, 2);
    append(list, 3);
    printList(list);
    deleteNode(list, 2);
    printList(list);
    return 0;
}