#include <stdio.h>
#include <string.h>

void untrustedMethod(char *data, size_t size) {
    strncpy(data, "Modified by untrustedMethod", size - 1);
    data[size - 1] = '\0';
}

int main() {
    char mutableData[100] = "Original Data";
    char clonedData[100];
    
    strncpy(clonedData, mutableData, sizeof(clonedData) - 1);
    clonedData[sizeof(clonedData) - 1] = '\0';
    
    untrustedMethod(clonedData, sizeof(clonedData));
    
    printf("Original data: %s\n", mutableData);
    printf("Cloned data: %s\n", clonedData);
    
    return 0;
}