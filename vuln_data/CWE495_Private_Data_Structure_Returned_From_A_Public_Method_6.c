#include <stdio.h>
#include <string.h>

typedef struct {
    char data[100];
} PrivateData;

PrivateData privateDataInstance;

void initData() {
    strcpy(privateDataInstance.data, "Sensitive Information");
}

PrivateData* getPrivateData() {
    return &privateDataInstance; // Vulnerable: returns a reference to private data
}

int main() {
    initData();
    PrivateData* externalAccess = getPrivateData();
    printf("Data: %s\n", externalAccess->data);
    strcpy(externalAccess->data, "Tampered Data");
    printf("Data: %s\n", privateDataInstance.data);
    return 0;
}