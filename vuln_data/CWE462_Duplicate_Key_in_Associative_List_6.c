#include <stdio.h>
#include <string.h>

#define MAX_KEYS 100
#define KEY_SIZE 50
#define VALUE_SIZE 50

typedef struct {
    char key[KEY_SIZE];
    char value[VALUE_SIZE];
} AssocEntry;

typedef struct {
    AssocEntry entries[MAX_KEYS];
    int size;
} AssocList;

int addEntry(AssocList *list, const char *key, const char *value) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->entries[i].key, key) == 0) {
            return -1;
        }
    }
    if (list->size < MAX_KEYS) {
        strncpy(list->entries[list->size].key, key, KEY_SIZE);
        strncpy(list->entries[list->size].value, value, VALUE_SIZE);
        list->size++;
        return 0;
    }
    return -1;
}

int main() {
    AssocList list;
    list.size = 0;
    if (addEntry(&list, "key1", "value1") != 0) {
        printf("Duplicate key or list full\n");
    }
    if (addEntry(&list, "key2", "value2") != 0) {
        printf("Duplicate key or list full\n");
    }
    if (addEntry(&list, "key1", "value3") != 0) {
        printf("Duplicate key or list full\n");
    }
    return 0;
}