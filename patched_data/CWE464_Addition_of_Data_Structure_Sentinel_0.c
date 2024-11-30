#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append_node(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void print_list(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void free_list(Node* node) {
    Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    append_node(&head, 1);
    append_node(&head, 2);
    append_node(&head, 3);
    append_node(&head, 0);
    print_list(head);
    free_list(head);
    return 0;
}