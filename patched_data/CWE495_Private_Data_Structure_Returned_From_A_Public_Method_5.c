#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sensitiveData;
} PrivateData;

typedef struct {
    PrivateData *data;
} PublicStruct;

int getSensitiveData(PublicStruct *pubStruct) {
    if (pubStruct && pubStruct->data) {
        return pubStruct->data->sensitiveData;
    }
    return -1; // Return an error code or handle error as needed
}

void setSensitiveData(PublicStruct *pubStruct, int newValue) {
    if (pubStruct && pubStruct->data) {
        pubStruct->data->sensitiveData = newValue;
    }
}

int main() {
    PublicStruct pubStruct;
    PrivateData privateData;
    privateData.sensitiveData = 42;
    pubStruct.data = &privateData;

    int sensitiveValue = getSensitiveData(&pubStruct);
    if (sensitiveValue != -1) {
        printf("Sensitive data: %d\n", sensitiveValue);
    }

    setSensitiveData(&pubStruct, 100);
    sensitiveValue = getSensitiveData(&pubStruct);
    if (sensitiveValue != -1) {
        printf("Modified sensitive data: %d\n", sensitiveValue);
    }

    return 0;
}