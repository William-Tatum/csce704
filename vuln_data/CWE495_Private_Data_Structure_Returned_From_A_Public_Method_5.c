#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sensitiveData;
} PrivateData;

typedef struct {
    PrivateData *data;
} PublicStruct;

PrivateData *getPrivateData(PublicStruct *pubStruct) {
    return pubStruct->data;
}

int main() {
    PublicStruct pubStruct;
    PrivateData privateData;
    privateData.sensitiveData = 42;
    pubStruct.data = &privateData;
    
    PrivateData *exposedData = getPrivateData(&pubStruct);
    printf("Sensitive data: %d\n", exposedData->sensitiveData);

    exposedData->sensitiveData = 100;
    printf("Modified sensitive data: %d\n", pubStruct.data->sensitiveData);

    return 0;
}