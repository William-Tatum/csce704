#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTINEL -1

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* addNode(Node* head, int value) {
    if (value == SENTINEL) {
        printf("Error: Attempted to add sentinel value.\n");
        return head;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

Node* freeList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    head = addNode(head, 5);
    head = addNode(head, 10);
    head = addNode(head, SENTINEL); 
    head = addNode(head, 20);
    printList(head);
    head = freeList(head);
    return 0;
}