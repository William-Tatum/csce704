#include <stdio.h>
#include <string.h>

char* getStringInsideBuffer(char* buffer, int size) {
    // Check for non-negative and meaningful size
    if (size < 0 || size > strlen(buffer)) {
        return NULL;
    }
    return buffer + size;
}

int main() {
    char data[10] = "Hello";
    char* result = getStringInsideBuffer(data, 2); // Example call within bounds
    if(result != NULL) {
        printf("%s\n", result);
    }
    return 0;
}