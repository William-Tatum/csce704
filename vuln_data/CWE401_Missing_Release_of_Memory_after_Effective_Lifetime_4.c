#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handleData(const char *input) {
    char *buffer = (char *)malloc(256);
    if (buffer == NULL) return;
    
    strncpy(buffer, input, 255);
    buffer[255] = '\0';
    
    printf("Processed data: %s\n", buffer);
    
    // Missing call to free() for buffer
}

int main() {
    handleData("Sample data processing");
    return 0;
}