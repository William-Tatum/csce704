#include <stdio.h>
#include <string.h>

typedef struct {
    char sensitive_data[50];
} PrivateDataStructure;

PrivateDataStructure private_data = {"Sensitive Information"};

PrivateDataStructure* getPrivateData() {
    return &private_data;
}

int main() {
    PrivateDataStructure* data = getPrivateData();
    
    printf("Before Modification: %s\n", data->sensitive_data);

    strcpy(data->sensitive_data, "Modified Data");

    printf("After Modification: %s\n", private_data.sensitive_data);

    return 0;
}