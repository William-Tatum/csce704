#include <stdio.h>
#include <string.h>

typedef struct {
    char data[100];
} PrivateData;

PrivateData privateDataInstance;

void initData() {
    strcpy(privateDataInstance.data, "Sensitive Information");
}

void getPrivateDataCopy(char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "%s", privateDataInstance.data);
}

int main() {
    initData();
    char externalAccess[100];
    getPrivateDataCopy(externalAccess, sizeof(externalAccess));
    printf("Data: %s\n", externalAccess);
    snprintf(externalAccess, sizeof(externalAccess), "Tampered Data");
    printf("Data: %s\n", externalAccess);
    printf("Protected Data: %s\n", privateDataInstance.data);
    return 0;
}