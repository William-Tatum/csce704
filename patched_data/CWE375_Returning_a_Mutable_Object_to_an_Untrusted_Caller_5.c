#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *data;
    size_t length;
} MutableObject;

void initialize(MutableObject *obj, const char *str) {
    obj->length = strlen(str);
    obj->data = (char *)malloc(obj->length + 1);
    if (obj->data != NULL) {
        strncpy(obj->data, str, obj->length);
        obj->data[obj->length] = '\0';
    }
}

MutableObject getMutableObjectCopy(MutableObject *obj) {
    MutableObject copy;
    copy.length = obj->length;
    copy.data = (char *)malloc(copy.length + 1);
    if (copy.data != NULL) {
        strncpy(copy.data, obj->data, copy.length);
        copy.data[copy.length] = '\0';
    }
    return copy;
}

int main() {
    MutableObject original;
    initialize(&original, "secure data");
    MutableObject copy = getMutableObjectCopy(&original);
    printf("Original: %s\n", original.data);
    printf("Copy: %s\n", copy.data);
    free(original.data);
    free(copy.data);
    return 0;
}