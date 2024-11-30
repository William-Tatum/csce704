#include <stdio.h>
#include <string.h>

typedef struct {
    char sensitive_data[50];
} PrivateDataStructure;

static PrivateDataStructure private_data = {"Sensitive Information"};

const PrivateDataStructure* getPrivateData() {
    return &private_data;
}

int main() {
    const PrivateDataStructure* data = getPrivateData();
    
    printf("Sensitive Data: %s\n", data->sensitive_data);

    // Do not allow modification of sensitive data directly through the pointer

    return 0;
}