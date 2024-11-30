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

void appendNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->sentinel;

    if (list->head == NULL) {
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
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list->sentinel);
    free(list);
}

void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != list->sentinel) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("END\n");
}

int main() {
    LinkedList* list = createList();
    appendNode(list, 10);
    appendNode(list, 20);
    appendNode(list, 30);
    printList(list);
    deleteList(list);
    return 0;
}