#include <stdio.h>
#include <string.h>

void untrustedFunction(char *data) {
    // Potentially malicious code altering the data
    strcpy(data, "Corrupted data!");
}

void processData(char *data) {
    char clonedData[100];
    strncpy(clonedData, data, sizeof(clonedData) - 1);
    clonedData[sizeof(clonedData) - 1] = '\0';
    untrustedFunction(clonedData);
    printf("Original data remains safe: %s\n", data);
    printf("Cloned data after untrusted function: %s\n", clonedData);
}

int main() {
    char originalData[100] = "Initial data";
    processData(originalData);
    return 0;
}