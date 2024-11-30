#include <stdio.h>
#include <string.h>

#define MAX_KEYS 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair pairs[MAX_KEYS];
    int count;
} AssociativeList;

int findKeyIndex(AssociativeList *alist, const char *key) {
    for (int i = 0; i < alist->count; i++) {
        if (strcmp(alist->pairs[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

int insertKeyValue(AssociativeList *alist, const char *key, const char *value) {
    if (alist->count >= MAX_KEYS) {
        return -1;
    }
    int existingKeyIndex = findKeyIndex(alist, key);
    if (existingKeyIndex != -1) {
        return -1;
    }
    strcpy(alist->pairs[alist->count].key, key);
    strcpy(alist->pairs[alist->count].value, value);
    alist->count++;
    return 0;
}

void printAssociativeList(AssociativeList *alist) {
    for (int i = 0; i < alist->count; i++) {
        printf("Key: %s, Value: %s\n", alist->pairs[i].key, alist->pairs[i].value);
    }
}

int main() {
    AssociativeList alist;
    alist.count = 0;

    insertKeyValue(&alist, "key1", "value1");
    insertKeyValue(&alist, "key2", "value2");
    if (insertKeyValue(&alist, "key2", "value3") == -1) {
        printf("Error: Duplicate key insertion attempted\n");
    }
    printAssociativeList(&alist);

    return 0;
}