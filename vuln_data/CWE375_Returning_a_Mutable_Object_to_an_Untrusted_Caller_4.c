#include <stdio.h>
#include <string.h>

typedef struct {
    char data[100];
} MutableData;

MutableData* getMutableData() {
    static MutableData mutableData;
    strcpy(mutableData.data, "Initial data");
    return &mutableData;
}

MutableData* getSafeMutableData() {
    MutableData* clonedData = malloc(sizeof(MutableData));
    if (clonedData != NULL) {
        strcpy(clonedData->data, "Initial data");
    }
    return clonedData;
}

int main() {
    MutableData* unsafeData = getMutableData();
    MutableData* safeData = getSafeMutableData();

    printf("Unsafe Data: %s\n", unsafeData->data);
    printf("Safe Data: %s\n", safeData->data);

    strcpy(unsafeData->data, "Modified by untrusted caller");
    strcpy(safeData->data, "Modified by untrusted caller");

    printf("Unsafe Data after modification: %s\n", unsafeData->data);
    printf("Safe Data after modification: %s\n", safeData->data);

    free(safeData);

    return 0;
}