#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *data;
    size_t length;
} MutableString;

MutableString* createMutableString(const char *input) {
    MutableString *mutableStr = malloc(sizeof(MutableString));
    mutableStr->length = strlen(input);
    mutableStr->data = malloc(mutableStr->length + 1);
    strcpy(mutableStr->data, input);
    return mutableStr;
}

MutableString* getMutableStringCopy(MutableString *original) {
    MutableString *copy = malloc(sizeof(MutableString));
    copy->length = original->length;
    copy->data = malloc(original->length + 1);
    strcpy(copy->data, original->data);
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