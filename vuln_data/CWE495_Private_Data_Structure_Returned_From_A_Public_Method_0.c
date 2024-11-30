#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char sensitiveData[MAX_SIZE];
} PrivateData;

PrivateData privateDataInstance;

PrivateData* getPrivateData() {
    return &privateDataInstance;
}

int main() {
    strcpy(privateDataInstance.sensitiveData, "Secret Test Data");

    PrivateData *exposedData = getPrivateData();
    printf("Sensitive Data: %s\n", exposedData->sensitiveData);

    strcpy(exposedData->sensitiveData, "Modified Data");
    printf("Modified Data: %s\n", privateDataInstance.sensitiveData);

    return 0;
}