#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void prependSentinel(Node** head, int sentinelValue) {
    Node* sentinelNode = createNode(sentinelValue);
    sentinelNode->next = *head;
    *head = sentinelNode;
}

void safeAppendNode(Node** head, int data, int sentinelValue) {
    if (data == sentinelValue) {
        fprintf(stderr, "Error: Attempted to append sentinel value\n");
        return;
    }
    appendNode(head, data);
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int sentinelValue = -1;
    prependSentinel(&head, sentinelValue);
    safeAppendNode(&head, 10, sentinelValue);
    safeAppendNode(&head, sentinelValue, sentinelValue);
    safeAppendNode(&head, 20, sentinelValue);
    printList(head);
    freeList(head);
    return 0;
}