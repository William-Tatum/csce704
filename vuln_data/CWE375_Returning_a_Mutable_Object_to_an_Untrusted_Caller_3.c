#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
} MutableData;

MutableData* cloneMutableData(MutableData *original) {
    MutableData *clone = (MutableData *)malloc(sizeof(MutableData));
    if (clone == NULL) exit(1);
    clone->data = (char *)malloc(strlen(original->data) + 1);
    if (clone->data == NULL) exit(1);
    strcpy(clone->data, original->data);
    return clone;
}

MutableData* safeGetMutableData(MutableData *original) {
    return cloneMutableData(original);
}

int main() {
    MutableData original;
    original.data = "Sensitive Information";
    MutableData *safeCopy = safeGetMutableData(&original);
    printf("Safe Copy Data: %s\n", safeCopy->data);
    free(safeCopy->data);
    free(safeCopy);
    return 0;
}