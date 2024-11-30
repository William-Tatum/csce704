#include <stdio.h>
#include <string.h>

void untrustedMethod(char *data, size_t size) {
    strncpy(data, "Modified by untrusted method", size - 1);
    data[size - 1] = '\0'; // Ensure null-termination
}

int main() {
    char originalData[100] = "Original Data";
    char clonedData[100];
    
    strncpy(clonedData, originalData, sizeof(clonedData) - 1);
    clonedData[sizeof(clonedData) - 1] = '\0'; // Ensure null-termination
    
    untrustedMethod(clonedData, sizeof(clonedData));
    
    printf("Original Data: %s\n", originalData);
    printf("Cloned Data: %s\n", clonedData);
    
    return 0;
}