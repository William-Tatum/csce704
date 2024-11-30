#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char data[100];
} MutableData;

MutableData* getMutableData() {
    static MutableData mutableData;
    strncpy(mutableData.data, "Initial data", sizeof(mutableData.data) - 1);
    mutableData.data[sizeof(mutableData.data) - 1] = '\0';
    return &mutableData;
}

MutableData* getSafeMutableData() {
    MutableData* clonedData = malloc(sizeof(MutableData));
    if (clonedData != NULL) {
        strncpy(clonedData->data, "Initial data", sizeof(clonedData->data) - 1);
        clonedData->data[sizeof(clonedData->data) - 1] = '\0';
    }
    return clonedData;
}

int main() {
    MutableData* unsafeData = getMutableData();
    MutableData* safeData = getSafeMutableData();

    printf("Unsafe Data: %s\n", unsafeData->data);
    printf("Safe Data: %s\n", safeData->data);

    free(safeData);

    return 0;
}