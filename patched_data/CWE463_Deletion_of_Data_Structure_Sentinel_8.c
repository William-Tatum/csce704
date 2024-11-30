#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int data) {
    if (!head) return createNode(data);

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    Node* newNode = createNode(data);
    if (!newNode) return head;
    current->next = newNode;
    return head;
}

void deleteNode(Node** head_ref, int key) {
    if (!head_ref || !(*head_ref)) return;

    Node* temp = *head_ref, *prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;

    if (prev) {
        prev->next = temp->next;
    } else {
        *head_ref = temp->next;
    }
    free(temp);
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("END\n");
}

int main() {
    Node sentinel = {0, NULL};
    Node* head = &sentinel;

    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);

    printList(head->next);

    deleteNode(&(head->next), 2);

    printList(head->next);

    return 0;
}