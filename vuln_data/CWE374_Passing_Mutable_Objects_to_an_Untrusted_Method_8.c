#include <stdio.h>
#include <string.h>

void untrustedMethod(char *data) {
    strcpy(data, "Modified by untrusted method");
}

int main() {
    char originalData[100] = "Original Data";
    char clonedData[100];
    
    strcpy(clonedData, originalData);
    
    untrustedMethod(clonedData);
    
    printf("Original Data: %s\n", originalData);
    printf("Cloned Data: %s\n", clonedData);
    
    return 0;
}