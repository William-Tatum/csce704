#include <stdio.h>
#include <string.h>

#define DEST_SIZE 10

void copyBuffer(char *source) {
    char destination[DEST_SIZE];
    if (strlen(source) >= DEST_SIZE) {
        printf("Source size is too large.\n");
        return;
    }
    strncpy(destination, source, DEST_SIZE - 1);
    destination[DEST_SIZE - 1] = '\0';
    printf("Copied data: %s\n", destination);
}

int main() {
    char sourceBuffer[20] = "This is a long buffer";
    copyBuffer(sourceBuffer);
    return 0;
}