#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIST_SIZE 10
#define KEY_MAX_LENGTH 50

typedef struct {
    char key[KEY_MAX_LENGTH];
    int value;
} AssocEntry;

typedef struct {
    AssocEntry entries[ALIST_SIZE];
    int size;
} AssocList;

int addEntry(AssocList *alist, const char *key, int value) {
    if (!alist || !key) {
        return 1;
    }
    for (int i = 0; i < alist->size; i++) {
        if (strcmp(alist->entries[i].key, key) == 0) {
            return 1;
        }
    }
    if (alist->size < ALIST_SIZE) {
        strncpy(alist->entries[alist->size].key, key, KEY_MAX_LENGTH - 1);
        alist->entries[alist->size].key[KEY_MAX_LENGTH - 1] = '\0';
        alist->entries[alist->size].value = value;
        alist->size++;
        return 0;
    }
    return 1;
}

int main() {
    AssocList alist = { .size = 0 };
    if (addEntry(&alist, "key1", 100)) {
        printf("Error: Duplicate or overflow\n");
    }
    if (addEntry(&alist, "key2", 200)) {
        printf("Error: Duplicate or overflow\n");
    }
    if (addEntry(&alist, "key1", 300)) {
        printf("Error: Duplicate or overflow\n");
    }
    for (int i = 0; i < alist.size; i++) {
        printf("Key: %s, Value: %d\n", alist.entries[i].key, alist.entries[i].value);
    }
    return 0;
}