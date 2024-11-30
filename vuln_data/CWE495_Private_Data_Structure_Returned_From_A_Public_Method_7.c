#include <stdio.h>
#include <string.h>

typedef struct {
    char sensitiveData[50];
} PrivateData;

PrivateData *getSensitiveData() {
    static PrivateData data;
    strcpy(data.sensitiveData, "This is very sensitive");
    return &data;
}

int main() {
    PrivateData *dataPtr = getSensitiveData();
    printf("Sensitive Data: %s\n", dataPtr->sensitiveData);

    strcpy(dataPtr->sensitiveData, "Compromised Data");
    printf("Compromised Sensitive Data: %s\n", dataPtr->sensitiveData);

    return 0;
}