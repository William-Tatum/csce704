#include <stdio.h>
#include <string.h>

#define MAX_KEYS 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_KEYS];
    int size;
} AssocList;

int findKeyIndex(AssocList *list, const char *key) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->entries[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

int addEntry(AssocList *list, const char *key, const char *value) {
    if (findKeyIndex(list, key) != -1) {
        return -1;
    }
    if (list->size >= MAX_KEYS) {
        return -1;
    }
    strncpy(list->entries[list->size].key, key, MAX_KEY_LENGTH - 1);
    list->entries[list->size].key[MAX_KEY_LENGTH - 1] = '\0';
    strncpy(list->entries[list->size].value, value, MAX_VALUE_LENGTH - 1);
    list->entries[list->size].value[MAX_VALUE_LENGTH - 1] = '\0';
    list->size++;
    return 0;
}

int main() {
    AssocList list;
    list.size = 0;

    addEntry(&list, "key1", "value1");
    addEntry(&list, "key2", "value2");

    if (addEntry(&list, "key1", "value3") == -1) {
        printf("Duplicate key detected, entry not added.\n");
    }

    return 0;
}