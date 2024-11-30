#include <stdio.h>
#include <string.h>

#define MAX_KEYS 100
#define KEY_SIZE 50
#define VALUE_SIZE 100

typedef struct {
    char key[KEY_SIZE];
    char value[VALUE_SIZE];
} KeyValuePair;

int findKey(KeyValuePair *list, int size, const char *key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

int addKeyValue(KeyValuePair *list, int *size, const char *key, const char *value) {
    if (*size >= MAX_KEYS) {
        return -1;
    }
    int index = findKey(list, *size, key);
    if (index != -1) {
        return -1;
    }
    if (strlen(key) >= KEY_SIZE || strlen(value) >= VALUE_SIZE) {
        return -1;
    }
    strncpy(list[*size].key, key, KEY_SIZE - 1);
    list[*size].key[KEY_SIZE - 1] = '\0';
    strncpy(list[*size].value, value, VALUE_SIZE - 1);
    list[*size].value[VALUE_SIZE - 1] = '\0';
    (*size)++;
    return 0;
}

int main() {
    KeyValuePair list[MAX_KEYS];
    int size = 0;

    if (addKeyValue(list, &size, "key1", "value1") == 0) {
        printf("Added: key1, value1\n");
    } else {
        printf("Failed to add: key1, value1\n");
    }

    if (addKeyValue(list, &size, "key1", "value2") == 0) {
        printf("Added: key1, value2\n");
    } else {
        printf("Failed to add: key1, value2\n");
    }

    return 0;
}