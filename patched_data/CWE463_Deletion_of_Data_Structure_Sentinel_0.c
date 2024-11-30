#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) exit(EXIT_FAILURE);
    list->head = NULL;
    return list;
}

void appendNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(EXIT_FAILURE);
    newNode->data = data;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void safeDeleteNode(LinkedList* list, int data) {
    if (list->head == NULL) return;
    
    Node* temp = list->head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return;
    
    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
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
    freeList(list);
    return 0;
}