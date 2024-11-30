#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char data[100];
} MutableObject;

void cloneMutableObject(MutableObject *dest, const MutableObject *src) {
    memcpy(dest->data, src->data, sizeof(dest->data));
}

MutableObject getImmutableData() {
    MutableObject original;
    strncpy(original.data, "Sensitive data", sizeof(original.data) - 1);
    original.data[sizeof(original.data) - 1] = '\0';

    MutableObject clone;
    cloneMutableObject(&clone, &original);

    return clone;
}

int main() {
    MutableObject data = getImmutableData();
    printf("Data: %s\n", data.data);
    return 0;
}