#include <stdio.h>
#include <string.h>

void copyBuffer(char *dest, const char *src, size_t len) {
    size_t destSize = 10;
    if (len > destSize) {
        len = destSize;
    }
    memcpy(dest, src, len);
}

int main() {
    char source[] = "This is a source string.";
    char destination[10];
    size_t length = 25; 
    copyBuffer(destination, source, length);
    printf("Destination: %s\n", destination);
    return 0;
}