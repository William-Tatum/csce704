#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pair {
    char *key;
    char *value;
    struct Pair *next;
} Pair;

typedef struct {
    Pair *head;
} AssocList;

AssocList* createAssocList() {
    AssocList *list = (AssocList*)malloc(sizeof(AssocList));
    list->head = NULL;
    return list;
}

int addKeyValue(AssocList *list, const char *key, const char *value) {
    Pair *current = list->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 0;
        }
        current = current->next;
    }
    Pair *newPair = (Pair*)malloc(sizeof(Pair));
    newPair->key = strdup(key);
    newPair->value = strdup(value);
    newPair->next = list->head;
    list->head = newPair;
    return 1;
}

char* findValue(AssocList *list, const char *key) {
    Pair *current = list->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void freeAssocList(AssocList *list) {
    Pair *current = list->head;
    while (current != NULL) {
        Pair *next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    AssocList *list = createAssocList();
    addKeyValue(list, "key1", "value1");
    if (!addKeyValue(list, "key1", "value2")) {
        printf("Duplicate key detected.\n");
    }
    char *value = findValue(list, "key1");
    if (value != NULL) {
        printf("Value for key1: %s\n", value);
    }
    freeAssocList(list);
    return 0;
}