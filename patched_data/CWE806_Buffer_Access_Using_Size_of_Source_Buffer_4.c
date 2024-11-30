#include <stdio.h>
#include <string.h>

void copyString(const char *source) {
    char dest[10];
    size_t length = strnlen(source, sizeof(dest) - 1);
    strncpy(dest, source, length);
    dest[length] = '\0';
    printf("Copied string: %s\n", dest);
}

int main() {
    char largeBuffer[50];
    memset(largeBuffer, 'A', sizeof(largeBuffer) - 1);
    largeBuffer[49] = '\0';
    copyString(largeBuffer);
    return 0;
}