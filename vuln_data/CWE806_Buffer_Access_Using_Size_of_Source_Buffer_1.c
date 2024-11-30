#include <stdio.h>
#include <string.h>

void bufferOverflowExample(char *source) {
    char destination[10];
    strncpy(destination, source, sizeof(destination));
    destination[sizeof(destination) - 1] = '\0';
    printf("Destination Buffer: %s\n", destination);
}

int main() {
    char sourceBuffer[20] = "This is a long string.";
    bufferOverflowExample(sourceBuffer);
    return 0;
}