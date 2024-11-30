#include <stdio.h>
#include <string.h>

void copyBuffer(char *dest, const char *src, size_t destSize) {
    size_t srcLen = strlen(src);
    size_t len = (srcLen < destSize - 1) ? srcLen : destSize - 1;
    memcpy(dest, src, len);
    dest[len] = '\0';
}

int main() {
    char source[] = "This is a source string.";
    char destination[10];
    copyBuffer(destination, source, sizeof(destination));
    printf("Destination: %s\n", destination);
    return 0;
}