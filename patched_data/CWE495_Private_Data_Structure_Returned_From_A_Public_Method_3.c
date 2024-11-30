#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} PrivateData;

static PrivateData private_data_instance;

// Controlled access to retrieve a copy of the private data
PrivateData getPrivateDataCopy() {
    return private_data_instance; // Return a copy to prevent modification
}

// Controlled function to set private data
void setPrivateData(int id, const char* name) {
    if (name != NULL && strlen(name) < sizeof(private_data_instance.name)) {
        private_data_instance.id = id;
        strncpy(private_data_instance.name, name, sizeof(private_data_instance.name) - 1);
        private_data_instance.name[sizeof(private_data_instance.name) - 1] = '\0'; // Ensuring null-termination
    }
}

int main() {
    setPrivateData(1, "Sensitive Name");
    
    PrivateData data = getPrivateDataCopy();
    
    printf("ID: %d, Name: %s\n", data.id, data.name);
    
    return 0;
}