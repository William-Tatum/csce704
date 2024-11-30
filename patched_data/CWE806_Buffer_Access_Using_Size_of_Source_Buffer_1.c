#include <stdio.h>
#include <string.h>

void bufferOverflowExample(const char *source) {
    char destination[10];
    strncpy(destination, source, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';
    printf("Destination Buffer: %s\n", destination);
}

int main() {
    const char sourceBuffer[] = "This is a long string.";
    bufferOverflowExample(sourceBuffer);
    return 0;
}