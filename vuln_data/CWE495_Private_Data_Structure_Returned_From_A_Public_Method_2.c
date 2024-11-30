#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sensitiveData;
} PrivateData;

typedef struct {
    PrivateData *privateData;
} PublicStruct;

PrivateData* getPrivateData(PublicStruct *pubStruct) {
    PrivateData *copy = malloc(sizeof(PrivateData));
    if (copy == NULL) {
        return NULL;
    }
    copy->sensitiveData = pubStruct->privateData->sensitiveData;
    return copy;
}

void freePrivateData(PrivateData *data) {
    free(data);
}

int main() {
    PrivateData privateData = {42};
    PublicStruct pubStruct = {&privateData};

    PrivateData *receivedData = getPrivateData(&pubStruct);
    if (receivedData != NULL) {
        printf("Sensitive Data: %d\n", receivedData->sensitiveData);
        freePrivateData(receivedData);
    }

    return 0;
}