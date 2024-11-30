#include <stdio.h>
#include <string.h>

void untrustedMethod(char *data) {
    strcpy(data, "Modified by untrustedMethod");
}

int main() {
    char mutableData[100] = "Original Data";
    char clonedData[100];
    
    strcpy(clonedData, mutableData);
    untrustedMethod(clonedData);
    
    printf("Original data: %s\n", mutableData);
    printf("Cloned data: %s\n", clonedData);
    
    return 0;
}