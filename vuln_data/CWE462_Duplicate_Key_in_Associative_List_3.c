#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KeyValue {
    char *key;
    char *value;
    struct KeyValue *next;
} KeyValue;

typedef struct AssocList {
    KeyValue *head;
} AssocList;

AssocList *initializeList() {
    AssocList *list = (AssocList *)malloc(sizeof(AssocList));
    list->head = NULL;
    return list;
}

int containsKey(AssocList *list, const char *key) {
    KeyValue *current = list->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void addUniqueKeyValue(AssocList *list, const char *key, const char *value) {
    if (containsKey(list, key)) {
        printf("Error: Duplicate key '%s'\n", key);
        return;
    }
    KeyValue *newNode = (KeyValue *)malloc(sizeof(KeyValue));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = list->head;
    list->head = newNode;
}

void freeList(AssocList *list) {
    KeyValue *current = list->head;
    while (current) {
        KeyValue *toFree = current;
        current = current->next;
        free(toFree->key);
        free(toFree->value);
        free(toFree);
    }
    free(list);
}

int main() {
    AssocList *myList = initializeList();
    addUniqueKeyValue(myList, "key1", "value1");
    addUniqueKeyValue(myList, "key2", "value2");
    addUniqueKeyValue(myList, "key1", "value3");
    freeList(myList);
    return 0;
}