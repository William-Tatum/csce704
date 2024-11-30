#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AssocList {
    char *key;
    char *value;
    struct AssocList *next;
} AssocList;

AssocList* insertAssoc(AssocList *head, const char *key, const char *value) {
    AssocList *current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            fprintf(stderr, "Error: Duplicate key '%s' detected. Insert operation aborted.\n", key);
            return head;
        }
        current = current->next;
    }
    AssocList *newNode = (AssocList *)malloc(sizeof(AssocList));
    if (newNode == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    if (newNode->key == NULL || newNode->value == NULL) {
        perror("strdup");
        free(newNode->key);
        free(newNode->value);
        free(newNode);
        exit(EXIT_FAILURE);
    }
    newNode->next = head;
    return newNode;
}

void freeAssocList(AssocList *head) {
    AssocList *current = head;
    while (current != NULL) {
        AssocList *temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

int main() {
    AssocList *alist = NULL;
    alist = insertAssoc(alist, "key1", "value1");
    alist = insertAssoc(alist, "key2", "value2");
    alist = insertAssoc(alist, "key1", "value3");
    freeAssocList(alist);
    return 0;
}