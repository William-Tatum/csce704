#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char sensitiveData[MAX_SIZE];
} PrivateData;

PrivateData privateDataInstance;

void setPrivateData(const char *data) {
    strncpy(privateDataInstance.sensitiveData, data, MAX_SIZE - 1);
    privateDataInstance.sensitiveData[MAX_SIZE - 1] = '\0';
}

void printPrivateData() {
    printf("Sensitive Data: %s\n", privateDataInstance.sensitiveData);
}

int main() {
    setPrivateData("Secret Test Data");
    printPrivateData();

    // Trying to modify the data
    setPrivateData("Modified Data");
    printPrivateData();

    return 0;
}