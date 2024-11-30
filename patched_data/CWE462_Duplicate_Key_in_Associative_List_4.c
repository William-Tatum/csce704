#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

Node* findKey(Node *head, const char *key) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int insert(Node **head, const char *key, const char *value) {
    if (findKey(*head, key) != NULL) {
        return 0;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return 0;

    newNode->key = strdup(key);
    if (newNode->key == NULL) {
        free(newNode);
        return 0;
    }

    newNode->value = strdup(value);
    if (newNode->value == NULL) {
        free(newNode->key);
        free(newNode);
        return 0;
    }

    newNode->next = *head;
    *head = newNode;
    return 1;
}

void freeList(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
}

int main() {
    Node *alist = NULL;
    if (!insert(&alist, "key1", "value1")) {
        printf("Duplicate key found or error occurred: key1\n");
    }
    if (!insert(&alist, "key1", "value2")) {
        printf("Duplicate key found or error occurred: key1\n");
    }
    freeList(alist);
    return 0;
}