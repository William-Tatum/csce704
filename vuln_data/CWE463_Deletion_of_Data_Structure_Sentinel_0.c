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

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = (Node*)malloc(sizeof(Node));
    list->tail->next = NULL;
    return list;
}

void appendNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->tail;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != list->tail) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void safeDeleteNode(LinkedList* list, int data) {
    if (list->head == NULL) return;
    
    Node* temp = list->head;
    Node* prev = NULL;

    while (temp != list->tail && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == list->tail) return;
    
    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != list->tail) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList* list = createLinkedList();
    appendNode(list, 1);
    appendNode(list, 2);
    appendNode(list, 3);
    printList(list);
    safeDeleteNode(list, 2);
    printList(list);
    safeDeleteNode(list, 3);
    printList(list);
    return 0;
}