#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
} PrivateData;

PrivateData private_data_instance;

PrivateData* getPrivateData() {
    return &private_data_instance; // Vulnerability: Exposing private data
}

int main() {
    PrivateData* data = getPrivateData();
    data->id = 1; // Unexpected modification
    snprintf(data->name, sizeof(data->name), "Sensitive Name");
    
    printf("ID: %d, Name: %s\n", data->id, data->name);
    
    return 0;
}