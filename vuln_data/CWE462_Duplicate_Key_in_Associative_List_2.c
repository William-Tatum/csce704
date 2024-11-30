#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char key[50];
    char value[50];
} KeyValuePair;

typedef struct {
    KeyValuePair pairs[MAX_SIZE];
    int size;
} AssociativeList;

int addToAssociativeList(AssociativeList *alist, const char *key, const char *value) {
    for (int i = 0; i < alist->size; i++) {
        if (strcmp(alist->pairs[i].key, key) == 0) {
            return 0;
        }
    }
    if (alist->size < MAX_SIZE) {
        strcpy(alist->pairs[alist->size].key, key);
        strcpy(alist->pairs[alist->size].value, value);
        alist->size++;
        return 1;
    }
    return 0;
}

int main() {
    AssociativeList alist = {.size = 0};

    addToAssociativeList(&alist, "key1", "value1");
    addToAssociativeList(&alist, "key2", "value2");
    addToAssociativeList(&alist, "key1", "value3");

    for (int i = 0; i < alist.size; i++) {
        printf("Key: %s, Value: %s\n", alist.pairs[i].key, alist.pairs[i].value);
    }

    return 0;
}