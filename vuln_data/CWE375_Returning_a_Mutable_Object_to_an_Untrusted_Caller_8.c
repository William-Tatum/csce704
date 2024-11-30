#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char data[100];
} MutableObject;

void cloneMutableObject(MutableObject *dest, MutableObject *src) {
    memcpy(dest->data, src->data, sizeof(src->data));
}

MutableObject getImmutableData() {
    MutableObject original;
    strcpy(original.data, "Sensitive data");

    MutableObject clone;
    cloneMutableObject(&clone, &original);

    return clone;
}

int main() {
    MutableObject data = getImmutableData();
    printf("Data: %s\n", data.data);
    return 0;
}