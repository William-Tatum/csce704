#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *data;
    size_t length;
} MutableString;

MutableString* createMutableString(const char *input) {
    MutableString *mutableStr = malloc(sizeof(MutableString));
    if (mutableStr == NULL) {
        perror("Failed to allocate memory for MutableString structure");
        exit(EXIT_FAILURE);
    }
    mutableStr->length = strlen(input);
    mutableStr->data = malloc(mutableStr->length + 1);
    if (mutableStr->data == NULL) {
        free(mutableStr);
        perror("Failed to allocate memory for data");
        exit(EXIT_FAILURE);
    }
    strncpy(mutableStr->data, input, mutableStr->length + 1);
    return mutableStr;
}

MutableString* getMutableStringCopy(MutableString *original) {
    if (original == NULL) {
        fprintf(stderr, "Received null pointer for original MutableString\n");
        exit(EXIT_FAILURE);
    }
    MutableString *copy = malloc(sizeof(MutableString));
    if (copy == NULL) {
        perror("Failed to allocate memory for MutableString copy");
        exit(EXIT_FAILURE);
    }
    copy->length = original->length;
    copy->data = malloc(copy->length + 1);
    if (copy->data == NULL) {
        free(copy);
        perror("Failed to allocate memory for data copy");
        exit(EXIT_FAILURE);
    }
    strncpy(copy->data, original->data, copy->length + 1);
    return copy;
}

int main() {
    MutableString *original = createMutableString("Sensitive Data");
    MutableString *safeCopy = getMutableStringCopy(original);
    printf("Original: %s, Copy: %s\n", original->data, safeCopy->data);
    free(original->data);
    free(original);
    free(safeCopy->data);
    free(safeCopy);
    return 0;
}