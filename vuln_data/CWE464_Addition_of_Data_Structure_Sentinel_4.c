#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 10

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void addToData(int* data, int size, int value) {
    if (value == 0) return;
    for(int i = 0; i < size; i++) {
        if(data[i] == 0) {
            data[i] = value;
            return;
        }
    }
}

void appendToList(Node** head, int value) {
    if (value == -1) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
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
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int data[DATA_SIZE] = {0};
    addToData(data, DATA_SIZE, 5);
    addToData(data, DATA_SIZE, 0);  
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    Node* head = NULL;
    appendToList(&head, 3);
    appendToList(&head, -1); 
    printList(head);

    return 0;
}