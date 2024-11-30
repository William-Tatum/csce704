#include <stdio.h>

char* getStringOutsideBuffer(char* buffer, int size) {
    if (size < 0) {
        return NULL;
    }
    // Error: returning a pointer outside the buffer
    return buffer + size + 10;
}

int main() {
    char data[10] = "Hello";
    char* result = getStringOutsideBuffer(data, sizeof(data));
    if(result != NULL) {
        printf("%s\n", result);
    }
    return 0;
}