#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int privateData;
} PrivateDataStruct;

PrivateDataStruct* createPrivateDataStruct(int value) {
    PrivateDataStruct* pData = (PrivateDataStruct*)malloc(sizeof(PrivateDataStruct));
    if (pData != NULL) {
        pData->privateData = value;
    }
    return pData;
}

PrivateDataStruct* getPrivateDataStruct(PrivateDataStruct* original) {
    PrivateDataStruct* newStruct = (PrivateDataStruct*)malloc(sizeof(PrivateDataStruct));
    if (newStruct != NULL) {
        newStruct->privateData = original->privateData;
    }
    return newStruct;
}

int main() {
    PrivateDataStruct* pOriginal = createPrivateDataStruct(42);
    PrivateDataStruct* pNew = getPrivateDataStruct(pOriginal);

    if (pOriginal != NULL && pNew != NULL) {
        printf("Original Data: %d\n", pOriginal->privateData);
        printf("Copied Data: %d\n", pNew->privateData);
    }

    free(pOriginal);
    free(pNew);

    return 0;
}